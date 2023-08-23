// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: simulation_control.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Simulationcontrol {

  /// <summary>Holder for reflection information generated from simulation_control.proto</summary>
  public static partial class SimulationControlReflection {

    #region Descriptor
    /// <summary>File descriptor for simulation_control.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static SimulationControlReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "ChhzaW11bGF0aW9uX2NvbnRyb2wucHJvdG8SEXNpbXVsYXRpb25jb250cm9s",
            "IjwKC1N0ZXBSZXF1ZXN0EhUKDXRvdGFsVGltZVNlY3MYASABKA0SFgoOdG90",
            "YWxUaW1lTnNlY3MYAiABKA0iHwoMU3RlcFJlc3BvbnNlEg8KB3N1Y2Nlc3MY",
            "ASABKAgiOgoTU2V0U3RhcnRUaW1lUmVxdWVzdBIQCgh0aW1lU2VjcxgBIAEo",
            "DRIRCgl0aW1lTnNlY3MYAiABKA0iJwoUU2V0U3RhcnRUaW1lUmVzcG9uc2US",
            "DwoHc3VjY2VzcxgBIAEoCDLBAQoRU2ltdWxhdGlvbkNvbnRyb2wSSQoEU3Rl",
            "cBIeLnNpbXVsYXRpb25jb250cm9sLlN0ZXBSZXF1ZXN0Gh8uc2ltdWxhdGlv",
            "bmNvbnRyb2wuU3RlcFJlc3BvbnNlIgASYQoMU2V0U3RhcnRUaW1lEiYuc2lt",
            "dWxhdGlvbmNvbnRyb2wuU2V0U3RhcnRUaW1lUmVxdWVzdBonLnNpbXVsYXRp",
            "b25jb250cm9sLlNldFN0YXJ0VGltZVJlc3BvbnNlIgBiBnByb3RvMw=="));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { },
          new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Simulationcontrol.StepRequest), global::Simulationcontrol.StepRequest.Parser, new[]{ "TotalTimeSecs", "TotalTimeNsecs" }, null, null, null),
            new pbr::GeneratedClrTypeInfo(typeof(global::Simulationcontrol.StepResponse), global::Simulationcontrol.StepResponse.Parser, new[]{ "Success" }, null, null, null),
            new pbr::GeneratedClrTypeInfo(typeof(global::Simulationcontrol.SetStartTimeRequest), global::Simulationcontrol.SetStartTimeRequest.Parser, new[]{ "TimeSecs", "TimeNsecs" }, null, null, null),
            new pbr::GeneratedClrTypeInfo(typeof(global::Simulationcontrol.SetStartTimeResponse), global::Simulationcontrol.SetStartTimeResponse.Parser, new[]{ "Success" }, null, null, null)
          }));
    }
    #endregion

  }
  #region Messages
  public sealed partial class StepRequest : pb::IMessage<StepRequest> {
    private static readonly pb::MessageParser<StepRequest> _parser = new pb::MessageParser<StepRequest>(() => new StepRequest());
    private pb::UnknownFieldSet _unknownFields;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pb::MessageParser<StepRequest> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Simulationcontrol.SimulationControlReflection.Descriptor.MessageTypes[0]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public StepRequest() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public StepRequest(StepRequest other) : this() {
      totalTimeSecs_ = other.totalTimeSecs_;
      totalTimeNsecs_ = other.totalTimeNsecs_;
      _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public StepRequest Clone() {
      return new StepRequest(this);
    }

    /// <summary>Field number for the "totalTimeSecs" field.</summary>
    public const int TotalTimeSecsFieldNumber = 1;
    private uint totalTimeSecs_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public uint TotalTimeSecs {
      get { return totalTimeSecs_; }
      set {
        totalTimeSecs_ = value;
      }
    }

    /// <summary>Field number for the "totalTimeNsecs" field.</summary>
    public const int TotalTimeNsecsFieldNumber = 2;
    private uint totalTimeNsecs_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public uint TotalTimeNsecs {
      get { return totalTimeNsecs_; }
      set {
        totalTimeNsecs_ = value;
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override bool Equals(object other) {
      return Equals(other as StepRequest);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public bool Equals(StepRequest other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (TotalTimeSecs != other.TotalTimeSecs) return false;
      if (TotalTimeNsecs != other.TotalTimeNsecs) return false;
      return Equals(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override int GetHashCode() {
      int hash = 1;
      if (TotalTimeSecs != 0) hash ^= TotalTimeSecs.GetHashCode();
      if (TotalTimeNsecs != 0) hash ^= TotalTimeNsecs.GetHashCode();
      if (_unknownFields != null) {
        hash ^= _unknownFields.GetHashCode();
      }
      return hash;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void WriteTo(pb::CodedOutputStream output) {
      if (TotalTimeSecs != 0) {
        output.WriteRawTag(8);
        output.WriteUInt32(TotalTimeSecs);
      }
      if (TotalTimeNsecs != 0) {
        output.WriteRawTag(16);
        output.WriteUInt32(TotalTimeNsecs);
      }
      if (_unknownFields != null) {
        _unknownFields.WriteTo(output);
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public int CalculateSize() {
      int size = 0;
      if (TotalTimeSecs != 0) {
        size += 1 + pb::CodedOutputStream.ComputeUInt32Size(TotalTimeSecs);
      }
      if (TotalTimeNsecs != 0) {
        size += 1 + pb::CodedOutputStream.ComputeUInt32Size(TotalTimeNsecs);
      }
      if (_unknownFields != null) {
        size += _unknownFields.CalculateSize();
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(StepRequest other) {
      if (other == null) {
        return;
      }
      if (other.TotalTimeSecs != 0) {
        TotalTimeSecs = other.TotalTimeSecs;
      }
      if (other.TotalTimeNsecs != 0) {
        TotalTimeNsecs = other.TotalTimeNsecs;
      }
      _unknownFields = pb::UnknownFieldSet.MergeFrom(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(pb::CodedInputStream input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, input);
            break;
          case 8: {
            TotalTimeSecs = input.ReadUInt32();
            break;
          }
          case 16: {
            TotalTimeNsecs = input.ReadUInt32();
            break;
          }
        }
      }
    }

  }

  public sealed partial class StepResponse : pb::IMessage<StepResponse> {
    private static readonly pb::MessageParser<StepResponse> _parser = new pb::MessageParser<StepResponse>(() => new StepResponse());
    private pb::UnknownFieldSet _unknownFields;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pb::MessageParser<StepResponse> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Simulationcontrol.SimulationControlReflection.Descriptor.MessageTypes[1]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public StepResponse() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public StepResponse(StepResponse other) : this() {
      success_ = other.success_;
      _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public StepResponse Clone() {
      return new StepResponse(this);
    }

    /// <summary>Field number for the "success" field.</summary>
    public const int SuccessFieldNumber = 1;
    private bool success_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public bool Success {
      get { return success_; }
      set {
        success_ = value;
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override bool Equals(object other) {
      return Equals(other as StepResponse);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public bool Equals(StepResponse other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (Success != other.Success) return false;
      return Equals(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override int GetHashCode() {
      int hash = 1;
      if (Success != false) hash ^= Success.GetHashCode();
      if (_unknownFields != null) {
        hash ^= _unknownFields.GetHashCode();
      }
      return hash;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void WriteTo(pb::CodedOutputStream output) {
      if (Success != false) {
        output.WriteRawTag(8);
        output.WriteBool(Success);
      }
      if (_unknownFields != null) {
        _unknownFields.WriteTo(output);
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public int CalculateSize() {
      int size = 0;
      if (Success != false) {
        size += 1 + 1;
      }
      if (_unknownFields != null) {
        size += _unknownFields.CalculateSize();
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(StepResponse other) {
      if (other == null) {
        return;
      }
      if (other.Success != false) {
        Success = other.Success;
      }
      _unknownFields = pb::UnknownFieldSet.MergeFrom(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(pb::CodedInputStream input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, input);
            break;
          case 8: {
            Success = input.ReadBool();
            break;
          }
        }
      }
    }

  }

  public sealed partial class SetStartTimeRequest : pb::IMessage<SetStartTimeRequest> {
    private static readonly pb::MessageParser<SetStartTimeRequest> _parser = new pb::MessageParser<SetStartTimeRequest>(() => new SetStartTimeRequest());
    private pb::UnknownFieldSet _unknownFields;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pb::MessageParser<SetStartTimeRequest> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Simulationcontrol.SimulationControlReflection.Descriptor.MessageTypes[2]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public SetStartTimeRequest() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public SetStartTimeRequest(SetStartTimeRequest other) : this() {
      timeSecs_ = other.timeSecs_;
      timeNsecs_ = other.timeNsecs_;
      _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public SetStartTimeRequest Clone() {
      return new SetStartTimeRequest(this);
    }

    /// <summary>Field number for the "timeSecs" field.</summary>
    public const int TimeSecsFieldNumber = 1;
    private uint timeSecs_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public uint TimeSecs {
      get { return timeSecs_; }
      set {
        timeSecs_ = value;
      }
    }

    /// <summary>Field number for the "timeNsecs" field.</summary>
    public const int TimeNsecsFieldNumber = 2;
    private uint timeNsecs_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public uint TimeNsecs {
      get { return timeNsecs_; }
      set {
        timeNsecs_ = value;
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override bool Equals(object other) {
      return Equals(other as SetStartTimeRequest);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public bool Equals(SetStartTimeRequest other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (TimeSecs != other.TimeSecs) return false;
      if (TimeNsecs != other.TimeNsecs) return false;
      return Equals(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override int GetHashCode() {
      int hash = 1;
      if (TimeSecs != 0) hash ^= TimeSecs.GetHashCode();
      if (TimeNsecs != 0) hash ^= TimeNsecs.GetHashCode();
      if (_unknownFields != null) {
        hash ^= _unknownFields.GetHashCode();
      }
      return hash;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void WriteTo(pb::CodedOutputStream output) {
      if (TimeSecs != 0) {
        output.WriteRawTag(8);
        output.WriteUInt32(TimeSecs);
      }
      if (TimeNsecs != 0) {
        output.WriteRawTag(16);
        output.WriteUInt32(TimeNsecs);
      }
      if (_unknownFields != null) {
        _unknownFields.WriteTo(output);
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public int CalculateSize() {
      int size = 0;
      if (TimeSecs != 0) {
        size += 1 + pb::CodedOutputStream.ComputeUInt32Size(TimeSecs);
      }
      if (TimeNsecs != 0) {
        size += 1 + pb::CodedOutputStream.ComputeUInt32Size(TimeNsecs);
      }
      if (_unknownFields != null) {
        size += _unknownFields.CalculateSize();
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(SetStartTimeRequest other) {
      if (other == null) {
        return;
      }
      if (other.TimeSecs != 0) {
        TimeSecs = other.TimeSecs;
      }
      if (other.TimeNsecs != 0) {
        TimeNsecs = other.TimeNsecs;
      }
      _unknownFields = pb::UnknownFieldSet.MergeFrom(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(pb::CodedInputStream input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, input);
            break;
          case 8: {
            TimeSecs = input.ReadUInt32();
            break;
          }
          case 16: {
            TimeNsecs = input.ReadUInt32();
            break;
          }
        }
      }
    }

  }

  public sealed partial class SetStartTimeResponse : pb::IMessage<SetStartTimeResponse> {
    private static readonly pb::MessageParser<SetStartTimeResponse> _parser = new pb::MessageParser<SetStartTimeResponse>(() => new SetStartTimeResponse());
    private pb::UnknownFieldSet _unknownFields;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pb::MessageParser<SetStartTimeResponse> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Simulationcontrol.SimulationControlReflection.Descriptor.MessageTypes[3]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public SetStartTimeResponse() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public SetStartTimeResponse(SetStartTimeResponse other) : this() {
      success_ = other.success_;
      _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public SetStartTimeResponse Clone() {
      return new SetStartTimeResponse(this);
    }

    /// <summary>Field number for the "success" field.</summary>
    public const int SuccessFieldNumber = 1;
    private bool success_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public bool Success {
      get { return success_; }
      set {
        success_ = value;
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override bool Equals(object other) {
      return Equals(other as SetStartTimeResponse);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public bool Equals(SetStartTimeResponse other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (Success != other.Success) return false;
      return Equals(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override int GetHashCode() {
      int hash = 1;
      if (Success != false) hash ^= Success.GetHashCode();
      if (_unknownFields != null) {
        hash ^= _unknownFields.GetHashCode();
      }
      return hash;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void WriteTo(pb::CodedOutputStream output) {
      if (Success != false) {
        output.WriteRawTag(8);
        output.WriteBool(Success);
      }
      if (_unknownFields != null) {
        _unknownFields.WriteTo(output);
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public int CalculateSize() {
      int size = 0;
      if (Success != false) {
        size += 1 + 1;
      }
      if (_unknownFields != null) {
        size += _unknownFields.CalculateSize();
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(SetStartTimeResponse other) {
      if (other == null) {
        return;
      }
      if (other.Success != false) {
        Success = other.Success;
      }
      _unknownFields = pb::UnknownFieldSet.MergeFrom(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(pb::CodedInputStream input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, input);
            break;
          case 8: {
            Success = input.ReadBool();
            break;
          }
        }
      }
    }

  }

  #endregion

}

#endregion Designer generated code
