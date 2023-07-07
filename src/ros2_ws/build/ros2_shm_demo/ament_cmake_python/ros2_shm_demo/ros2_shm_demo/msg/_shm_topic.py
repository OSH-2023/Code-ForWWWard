# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros2_shm_demo:msg/ShmTopic.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'data'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ShmTopic(type):
    """Metaclass of message 'ShmTopic'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'MAX_SIZE': 255,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros2_shm_demo')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros2_shm_demo.msg.ShmTopic')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__shm_topic
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__shm_topic
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__shm_topic
            cls._TYPE_SUPPORT = module.type_support_msg__msg__shm_topic
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__shm_topic

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'MAX_SIZE': cls.__constants['MAX_SIZE'],
        }

    @property
    def MAX_SIZE(self):
        """Message constant 'MAX_SIZE'."""
        return Metaclass_ShmTopic.__constants['MAX_SIZE']


class ShmTopic(metaclass=Metaclass_ShmTopic):
    """
    Message class 'ShmTopic'.

    Constants:
      MAX_SIZE
    """

    __slots__ = [
        '_data',
        '_size',
        '_counter',
    ]

    _fields_and_field_types = {
        'data': 'uint8[256]',
        'size': 'uint8',
        'counter': 'uint64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 256),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'data' not in kwargs:
            self.data = numpy.zeros(256, dtype=numpy.uint8)
        else:
            self.data = numpy.array(kwargs.get('data'), dtype=numpy.uint8)
            assert self.data.shape == (256, )
        self.size = kwargs.get('size', int())
        self.counter = kwargs.get('counter', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if all(self.data != other.data):
            return False
        if self.size != other.size:
            return False
        if self.counter != other.counter:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def data(self):
        """Message field 'data'."""
        return self._data

    @data.setter
    def data(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'data' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 256, \
                "The 'data' numpy.ndarray() must have a size of 256"
            self._data = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 256 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'data' field must be a set or sequence with length 256 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._data = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def size(self):
        """Message field 'size'."""
        return self._size

    @size.setter
    def size(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'size' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'size' field must be an unsigned integer in [0, 255]"
        self._size = value

    @builtins.property
    def counter(self):
        """Message field 'counter'."""
        return self._counter

    @counter.setter
    def counter(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'counter' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'counter' field must be an unsigned integer in [0, 18446744073709551615]"
        self._counter = value
