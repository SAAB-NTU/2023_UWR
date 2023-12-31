# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: std.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='std.proto',
  package='std',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=_b('\n\tstd.proto\x12\x03std\"\x07\n\x05\x45mpty\"\"\n\x0fStandardRequest\x12\x0f\n\x07\x61\x64\x64ress\x18\x01 \x01(\t\",\n\x06Header\x12\x11\n\ttimestamp\x18\x01 \x01(\x01\x12\x0f\n\x07\x66rameId\x18\x02 \x01(\t\"\x1c\n\x0c\x46loat32Array\x12\x0c\n\x04\x64\x61ta\x18\x01 \x03(\x02\"7\n\tColorRGBA\x12\t\n\x01r\x18\x01 \x01(\x02\x12\t\n\x01g\x18\x02 \x01(\x02\x12\t\n\x01\x62\x18\x03 \x01(\x02\x12\t\n\x01\x61\x18\x04 \x01(\x02\x62\x06proto3')
)




_EMPTY = _descriptor.Descriptor(
  name='Empty',
  full_name='std.Empty',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=18,
  serialized_end=25,
)


_STANDARDREQUEST = _descriptor.Descriptor(
  name='StandardRequest',
  full_name='std.StandardRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='address', full_name='std.StandardRequest.address', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=27,
  serialized_end=61,
)


_HEADER = _descriptor.Descriptor(
  name='Header',
  full_name='std.Header',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='timestamp', full_name='std.Header.timestamp', index=0,
      number=1, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='frameId', full_name='std.Header.frameId', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=63,
  serialized_end=107,
)


_FLOAT32ARRAY = _descriptor.Descriptor(
  name='Float32Array',
  full_name='std.Float32Array',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='data', full_name='std.Float32Array.data', index=0,
      number=1, type=2, cpp_type=6, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=109,
  serialized_end=137,
)


_COLORRGBA = _descriptor.Descriptor(
  name='ColorRGBA',
  full_name='std.ColorRGBA',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='r', full_name='std.ColorRGBA.r', index=0,
      number=1, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='g', full_name='std.ColorRGBA.g', index=1,
      number=2, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='b', full_name='std.ColorRGBA.b', index=2,
      number=3, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='a', full_name='std.ColorRGBA.a', index=3,
      number=4, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=139,
  serialized_end=194,
)

DESCRIPTOR.message_types_by_name['Empty'] = _EMPTY
DESCRIPTOR.message_types_by_name['StandardRequest'] = _STANDARDREQUEST
DESCRIPTOR.message_types_by_name['Header'] = _HEADER
DESCRIPTOR.message_types_by_name['Float32Array'] = _FLOAT32ARRAY
DESCRIPTOR.message_types_by_name['ColorRGBA'] = _COLORRGBA
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Empty = _reflection.GeneratedProtocolMessageType('Empty', (_message.Message,), dict(
  DESCRIPTOR = _EMPTY,
  __module__ = 'std_pb2'
  # @@protoc_insertion_point(class_scope:std.Empty)
  ))
_sym_db.RegisterMessage(Empty)

StandardRequest = _reflection.GeneratedProtocolMessageType('StandardRequest', (_message.Message,), dict(
  DESCRIPTOR = _STANDARDREQUEST,
  __module__ = 'std_pb2'
  # @@protoc_insertion_point(class_scope:std.StandardRequest)
  ))
_sym_db.RegisterMessage(StandardRequest)

Header = _reflection.GeneratedProtocolMessageType('Header', (_message.Message,), dict(
  DESCRIPTOR = _HEADER,
  __module__ = 'std_pb2'
  # @@protoc_insertion_point(class_scope:std.Header)
  ))
_sym_db.RegisterMessage(Header)

Float32Array = _reflection.GeneratedProtocolMessageType('Float32Array', (_message.Message,), dict(
  DESCRIPTOR = _FLOAT32ARRAY,
  __module__ = 'std_pb2'
  # @@protoc_insertion_point(class_scope:std.Float32Array)
  ))
_sym_db.RegisterMessage(Float32Array)

ColorRGBA = _reflection.GeneratedProtocolMessageType('ColorRGBA', (_message.Message,), dict(
  DESCRIPTOR = _COLORRGBA,
  __module__ = 'std_pb2'
  # @@protoc_insertion_point(class_scope:std.ColorRGBA)
  ))
_sym_db.RegisterMessage(ColorRGBA)


# @@protoc_insertion_point(module_scope)
