#include "ros2_shm_demo/msg/shm_topic.hpp"

#include "iceoryx_posh/popo/untyped_subscriber.hpp"
#include "iceoryx_posh/runtime/posh_runtime.hpp"
//#include "iceoryx_utils/posix_wrapper/signal_handler.hpp"
#include "iceoryx_hoofs/posix_wrapper/signal_handler.hpp"

#include <iostream>

constexpr uint32_t DDS_IOX_HEADER_SIZE = 56;
using ROSTopic = ros2_shm_demo::msg::ShmTopic;

bool shutdown1 = false;
constexpr char APP_NAME[] = "iox-ros2-subscriber";

static void sigHandler(int) {
  // caught SIGINT or SIGTERM, now exit gracefully
  shutdown1 = true;
}

int main() {
  // register sigHandler
  auto signalIntGuard =
      iox::posix::registerSignalHandler(iox::posix::Signal::INT, sigHandler);
  auto signalTermGuard =
      iox::posix::registerSignalHandler(iox::posix::Signal::TERM, sigHandler);

  // initialize runtime
  iox::runtime::PoshRuntime::initRuntime(APP_NAME);

  // initialize subscriber
  iox::popo::UntypedSubscriber subscriber(
      {"DDS_CYCLONE", "ros2_shm_demo::msg::dds_::ShmTopic_", "rt/chatter"});

  auto state = subscriber.getSubscriptionState();

  if (state == iox::SubscribeState::SUBSCRIBED) {
    std::cout << "iox subscriber: Subscribed to "
                 "ros2_shm_demo::msg::dds_::ShmTopic_ rt/chatter"
              << std::endl;
  }

  while (!shutdown1) {
    subscriber.take()
        .and_then([&](const void *payload) {
          auto *payloadWithoutDDSHeader =
              reinterpret_cast<const uint8_t *>(payload) + DDS_IOX_HEADER_SIZE;

          const ROSTopic *sample =
              reinterpret_cast<const ROSTopic *>(payloadWithoutDDSHeader);
          auto data = reinterpret_cast<const char *>(sample->data.data());

          std::cout << "iox subscriber: Received " << data << " "
                    << sample->counter << std::endl;

          subscriber.release(payload);
        })
        .or_else([](auto &result) {
          if (result != iox::popo::ChunkReceiveResult::NO_CHUNK_AVAILABLE) {
            std::cout << "Error receiving chunk." << std::endl;
          }
        });

    // use polling for simplicity
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return (EXIT_SUCCESS);
}
