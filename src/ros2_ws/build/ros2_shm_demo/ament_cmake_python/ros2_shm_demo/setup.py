from setuptools import find_packages
from setuptools import setup

setup(
    name='ros2_shm_demo',
    version='0.14.3',
    packages=find_packages(
        include=('ros2_shm_demo', 'ros2_shm_demo.*')),
)
