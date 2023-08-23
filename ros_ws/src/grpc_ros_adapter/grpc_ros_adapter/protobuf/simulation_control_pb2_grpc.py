# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

import simulation_control_pb2 as simulation__control__pb2


class SimulationControlStub(object):
  # missing associated documentation comment in .proto file
  pass

  def __init__(self, channel):
    """Constructor.

    Args:
      channel: A grpc.Channel.
    """
    self.Step = channel.unary_unary(
        '/simulationcontrol.SimulationControl/Step',
        request_serializer=simulation__control__pb2.StepRequest.SerializeToString,
        response_deserializer=simulation__control__pb2.StepResponse.FromString,
        )
    self.SetStartTime = channel.unary_unary(
        '/simulationcontrol.SimulationControl/SetStartTime',
        request_serializer=simulation__control__pb2.SetStartTimeRequest.SerializeToString,
        response_deserializer=simulation__control__pb2.SetStartTimeResponse.FromString,
        )


class SimulationControlServicer(object):
  # missing associated documentation comment in .proto file
  pass

  def Step(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def SetStartTime(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')


def add_SimulationControlServicer_to_server(servicer, server):
  rpc_method_handlers = {
      'Step': grpc.unary_unary_rpc_method_handler(
          servicer.Step,
          request_deserializer=simulation__control__pb2.StepRequest.FromString,
          response_serializer=simulation__control__pb2.StepResponse.SerializeToString,
      ),
      'SetStartTime': grpc.unary_unary_rpc_method_handler(
          servicer.SetStartTime,
          request_deserializer=simulation__control__pb2.SetStartTimeRequest.FromString,
          response_serializer=simulation__control__pb2.SetStartTimeResponse.SerializeToString,
      ),
  }
  generic_handler = grpc.method_handlers_generic_handler(
      'simulationcontrol.SimulationControl', rpc_method_handlers)
  server.add_generic_rpc_handlers((generic_handler,))
