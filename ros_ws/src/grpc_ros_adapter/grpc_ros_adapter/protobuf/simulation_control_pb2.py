# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: simulation_control.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='simulation_control.proto',
  package='simulationcontrol',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=_b('\n\x18simulation_control.proto\x12\x11simulationcontrol\"<\n\x0bStepRequest\x12\x15\n\rtotalTimeSecs\x18\x01 \x01(\r\x12\x16\n\x0etotalTimeNsecs\x18\x02 \x01(\r\"\x1f\n\x0cStepResponse\x12\x0f\n\x07success\x18\x01 \x01(\x08\":\n\x13SetStartTimeRequest\x12\x10\n\x08timeSecs\x18\x01 \x01(\r\x12\x11\n\ttimeNsecs\x18\x02 \x01(\r\"\'\n\x14SetStartTimeResponse\x12\x0f\n\x07success\x18\x01 \x01(\x08\x32\xc1\x01\n\x11SimulationControl\x12I\n\x04Step\x12\x1e.simulationcontrol.StepRequest\x1a\x1f.simulationcontrol.StepResponse\"\x00\x12\x61\n\x0cSetStartTime\x12&.simulationcontrol.SetStartTimeRequest\x1a\'.simulationcontrol.SetStartTimeResponse\"\x00\x62\x06proto3')
)




_STEPREQUEST = _descriptor.Descriptor(
  name='StepRequest',
  full_name='simulationcontrol.StepRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='totalTimeSecs', full_name='simulationcontrol.StepRequest.totalTimeSecs', index=0,
      number=1, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='totalTimeNsecs', full_name='simulationcontrol.StepRequest.totalTimeNsecs', index=1,
      number=2, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
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
  serialized_start=47,
  serialized_end=107,
)


_STEPRESPONSE = _descriptor.Descriptor(
  name='StepResponse',
  full_name='simulationcontrol.StepResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='success', full_name='simulationcontrol.StepResponse.success', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
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
  serialized_end=140,
)


_SETSTARTTIMEREQUEST = _descriptor.Descriptor(
  name='SetStartTimeRequest',
  full_name='simulationcontrol.SetStartTimeRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='timeSecs', full_name='simulationcontrol.SetStartTimeRequest.timeSecs', index=0,
      number=1, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='timeNsecs', full_name='simulationcontrol.SetStartTimeRequest.timeNsecs', index=1,
      number=2, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
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
  serialized_start=142,
  serialized_end=200,
)


_SETSTARTTIMERESPONSE = _descriptor.Descriptor(
  name='SetStartTimeResponse',
  full_name='simulationcontrol.SetStartTimeResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='success', full_name='simulationcontrol.SetStartTimeResponse.success', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
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
  serialized_start=202,
  serialized_end=241,
)

DESCRIPTOR.message_types_by_name['StepRequest'] = _STEPREQUEST
DESCRIPTOR.message_types_by_name['StepResponse'] = _STEPRESPONSE
DESCRIPTOR.message_types_by_name['SetStartTimeRequest'] = _SETSTARTTIMEREQUEST
DESCRIPTOR.message_types_by_name['SetStartTimeResponse'] = _SETSTARTTIMERESPONSE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

StepRequest = _reflection.GeneratedProtocolMessageType('StepRequest', (_message.Message,), dict(
  DESCRIPTOR = _STEPREQUEST,
  __module__ = 'simulation_control_pb2'
  # @@protoc_insertion_point(class_scope:simulationcontrol.StepRequest)
  ))
_sym_db.RegisterMessage(StepRequest)

StepResponse = _reflection.GeneratedProtocolMessageType('StepResponse', (_message.Message,), dict(
  DESCRIPTOR = _STEPRESPONSE,
  __module__ = 'simulation_control_pb2'
  # @@protoc_insertion_point(class_scope:simulationcontrol.StepResponse)
  ))
_sym_db.RegisterMessage(StepResponse)

SetStartTimeRequest = _reflection.GeneratedProtocolMessageType('SetStartTimeRequest', (_message.Message,), dict(
  DESCRIPTOR = _SETSTARTTIMEREQUEST,
  __module__ = 'simulation_control_pb2'
  # @@protoc_insertion_point(class_scope:simulationcontrol.SetStartTimeRequest)
  ))
_sym_db.RegisterMessage(SetStartTimeRequest)

SetStartTimeResponse = _reflection.GeneratedProtocolMessageType('SetStartTimeResponse', (_message.Message,), dict(
  DESCRIPTOR = _SETSTARTTIMERESPONSE,
  __module__ = 'simulation_control_pb2'
  # @@protoc_insertion_point(class_scope:simulationcontrol.SetStartTimeResponse)
  ))
_sym_db.RegisterMessage(SetStartTimeResponse)



_SIMULATIONCONTROL = _descriptor.ServiceDescriptor(
  name='SimulationControl',
  full_name='simulationcontrol.SimulationControl',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=244,
  serialized_end=437,
  methods=[
  _descriptor.MethodDescriptor(
    name='Step',
    full_name='simulationcontrol.SimulationControl.Step',
    index=0,
    containing_service=None,
    input_type=_STEPREQUEST,
    output_type=_STEPRESPONSE,
    serialized_options=None,
  ),
  _descriptor.MethodDescriptor(
    name='SetStartTime',
    full_name='simulationcontrol.SimulationControl.SetStartTime',
    index=1,
    containing_service=None,
    input_type=_SETSTARTTIMEREQUEST,
    output_type=_SETSTARTTIMERESPONSE,
    serialized_options=None,
  ),
])
_sym_db.RegisterServiceDescriptor(_SIMULATIONCONTROL)

DESCRIPTOR.services_by_name['SimulationControl'] = _SIMULATIONCONTROL

# @@protoc_insertion_point(module_scope)
