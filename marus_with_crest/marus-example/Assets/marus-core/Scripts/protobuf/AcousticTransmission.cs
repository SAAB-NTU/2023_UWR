// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: acoustic_transmission.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Acoustictransmission {

  /// <summary>Holder for reflection information generated from acoustic_transmission.proto</summary>
  public static partial class AcousticTransmissionReflection {

    #region Descriptor
    /// <summary>File descriptor for acoustic_transmission.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static AcousticTransmissionReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "ChthY291c3RpY190cmFuc21pc3Npb24ucHJvdG8SFGFjb3VzdGljdHJhbnNt",
            "aXNzaW9uGgxsYWJ1c3QucHJvdG8aCXN0ZC5wcm90byIhCg5Db21tYW5kUmVx",
            "dWVzdBIPCgdhZGRyZXNzGAEgASgJIpEBChBBY291c3RpY1Jlc3BvbnNlEg8K",
            "B2FkZHJlc3MYASABKAkSDwoHc3VjY2VzcxgCIAEoCBIrCgdwYXlsb2FkGAMg",
            "ASgLMhgubGFidXN0Lk5hbm9tb2RlbVBheWxvYWRIABInCgVyYW5nZRgEIAEo",
            "CzIWLmxhYnVzdC5OYW5vbW9kZW1SYW5nZUgAQgUKA21zZyJNCg9BY291c3Rp",
            "Y1JlcXVlc3QSDwoHc3VjY2VzcxgBIAEoCBIpCgdyZXF1ZXN0GAIgASgLMhgu",
            "bGFidXN0Lk5hbm9tb2RlbVJlcXVlc3Qy0AEKFEFjb3VzdGljVHJhbnNtaXNz",
            "aW9uEmkKFlN0cmVhbUFjb3VzdGljUmVxdWVzdHMSJC5hY291c3RpY3RyYW5z",
            "bWlzc2lvbi5Db21tYW5kUmVxdWVzdBolLmFjb3VzdGljdHJhbnNtaXNzaW9u",
            "LkFjb3VzdGljUmVxdWVzdCIAMAESTQoVUmV0dXJuQWNvdXN0aWNQYXlsb2Fk",
            "EiYuYWNvdXN0aWN0cmFuc21pc3Npb24uQWNvdXN0aWNSZXNwb25zZRoKLnN0",
            "ZC5FbXB0eSIAYgZwcm90bzM="));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { global::Labust.LabustReflection.Descriptor, global::Std.StdReflection.Descriptor, },
          new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Acoustictransmission.CommandRequest), global::Acoustictransmission.CommandRequest.Parser, new[]{ "Address" }, null, null, null),
            new pbr::GeneratedClrTypeInfo(typeof(global::Acoustictransmission.AcousticResponse), global::Acoustictransmission.AcousticResponse.Parser, new[]{ "Address", "Success", "Payload", "Range" }, new[]{ "Msg" }, null, null),
            new pbr::GeneratedClrTypeInfo(typeof(global::Acoustictransmission.AcousticRequest), global::Acoustictransmission.AcousticRequest.Parser, new[]{ "Success", "Request" }, null, null, null)
          }));
    }
    #endregion

  }
  #region Messages
  public sealed partial class CommandRequest : pb::IMessage<CommandRequest> {
    private static readonly pb::MessageParser<CommandRequest> _parser = new pb::MessageParser<CommandRequest>(() => new CommandRequest());
    private pb::UnknownFieldSet _unknownFields;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pb::MessageParser<CommandRequest> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Acoustictransmission.AcousticTransmissionReflection.Descriptor.MessageTypes[0]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public CommandRequest() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public CommandRequest(CommandRequest other) : this() {
      address_ = other.address_;
      _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public CommandRequest Clone() {
      return new CommandRequest(this);
    }

    /// <summary>Field number for the "address" field.</summary>
    public const int AddressFieldNumber = 1;
    private string address_ = "";
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public string Address {
      get { return address_; }
      set {
        address_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override bool Equals(object other) {
      return Equals(other as CommandRequest);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public bool Equals(CommandRequest other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (Address != other.Address) return false;
      return Equals(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override int GetHashCode() {
      int hash = 1;
      if (Address.Length != 0) hash ^= Address.GetHashCode();
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
      if (Address.Length != 0) {
        output.WriteRawTag(10);
        output.WriteString(Address);
      }
      if (_unknownFields != null) {
        _unknownFields.WriteTo(output);
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public int CalculateSize() {
      int size = 0;
      if (Address.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(Address);
      }
      if (_unknownFields != null) {
        size += _unknownFields.CalculateSize();
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(CommandRequest other) {
      if (other == null) {
        return;
      }
      if (other.Address.Length != 0) {
        Address = other.Address;
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
          case 10: {
            Address = input.ReadString();
            break;
          }
        }
      }
    }

  }

  public sealed partial class AcousticResponse : pb::IMessage<AcousticResponse> {
    private static readonly pb::MessageParser<AcousticResponse> _parser = new pb::MessageParser<AcousticResponse>(() => new AcousticResponse());
    private pb::UnknownFieldSet _unknownFields;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pb::MessageParser<AcousticResponse> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Acoustictransmission.AcousticTransmissionReflection.Descriptor.MessageTypes[1]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public AcousticResponse() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public AcousticResponse(AcousticResponse other) : this() {
      address_ = other.address_;
      success_ = other.success_;
      switch (other.MsgCase) {
        case MsgOneofCase.Payload:
          Payload = other.Payload.Clone();
          break;
        case MsgOneofCase.Range:
          Range = other.Range.Clone();
          break;
      }

      _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public AcousticResponse Clone() {
      return new AcousticResponse(this);
    }

    /// <summary>Field number for the "address" field.</summary>
    public const int AddressFieldNumber = 1;
    private string address_ = "";
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public string Address {
      get { return address_; }
      set {
        address_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    /// <summary>Field number for the "success" field.</summary>
    public const int SuccessFieldNumber = 2;
    private bool success_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public bool Success {
      get { return success_; }
      set {
        success_ = value;
      }
    }

    /// <summary>Field number for the "payload" field.</summary>
    public const int PayloadFieldNumber = 3;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public global::Labust.NanomodemPayload Payload {
      get { return msgCase_ == MsgOneofCase.Payload ? (global::Labust.NanomodemPayload) msg_ : null; }
      set {
        msg_ = value;
        msgCase_ = value == null ? MsgOneofCase.None : MsgOneofCase.Payload;
      }
    }

    /// <summary>Field number for the "range" field.</summary>
    public const int RangeFieldNumber = 4;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public global::Labust.NanomodemRange Range {
      get { return msgCase_ == MsgOneofCase.Range ? (global::Labust.NanomodemRange) msg_ : null; }
      set {
        msg_ = value;
        msgCase_ = value == null ? MsgOneofCase.None : MsgOneofCase.Range;
      }
    }

    private object msg_;
    /// <summary>Enum of possible cases for the "msg" oneof.</summary>
    public enum MsgOneofCase {
      None = 0,
      Payload = 3,
      Range = 4,
    }
    private MsgOneofCase msgCase_ = MsgOneofCase.None;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public MsgOneofCase MsgCase {
      get { return msgCase_; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void ClearMsg() {
      msgCase_ = MsgOneofCase.None;
      msg_ = null;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override bool Equals(object other) {
      return Equals(other as AcousticResponse);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public bool Equals(AcousticResponse other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (Address != other.Address) return false;
      if (Success != other.Success) return false;
      if (!object.Equals(Payload, other.Payload)) return false;
      if (!object.Equals(Range, other.Range)) return false;
      if (MsgCase != other.MsgCase) return false;
      return Equals(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override int GetHashCode() {
      int hash = 1;
      if (Address.Length != 0) hash ^= Address.GetHashCode();
      if (Success != false) hash ^= Success.GetHashCode();
      if (msgCase_ == MsgOneofCase.Payload) hash ^= Payload.GetHashCode();
      if (msgCase_ == MsgOneofCase.Range) hash ^= Range.GetHashCode();
      hash ^= (int) msgCase_;
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
      if (Address.Length != 0) {
        output.WriteRawTag(10);
        output.WriteString(Address);
      }
      if (Success != false) {
        output.WriteRawTag(16);
        output.WriteBool(Success);
      }
      if (msgCase_ == MsgOneofCase.Payload) {
        output.WriteRawTag(26);
        output.WriteMessage(Payload);
      }
      if (msgCase_ == MsgOneofCase.Range) {
        output.WriteRawTag(34);
        output.WriteMessage(Range);
      }
      if (_unknownFields != null) {
        _unknownFields.WriteTo(output);
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public int CalculateSize() {
      int size = 0;
      if (Address.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(Address);
      }
      if (Success != false) {
        size += 1 + 1;
      }
      if (msgCase_ == MsgOneofCase.Payload) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Payload);
      }
      if (msgCase_ == MsgOneofCase.Range) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Range);
      }
      if (_unknownFields != null) {
        size += _unknownFields.CalculateSize();
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(AcousticResponse other) {
      if (other == null) {
        return;
      }
      if (other.Address.Length != 0) {
        Address = other.Address;
      }
      if (other.Success != false) {
        Success = other.Success;
      }
      switch (other.MsgCase) {
        case MsgOneofCase.Payload:
          if (Payload == null) {
            Payload = new global::Labust.NanomodemPayload();
          }
          Payload.MergeFrom(other.Payload);
          break;
        case MsgOneofCase.Range:
          if (Range == null) {
            Range = new global::Labust.NanomodemRange();
          }
          Range.MergeFrom(other.Range);
          break;
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
          case 10: {
            Address = input.ReadString();
            break;
          }
          case 16: {
            Success = input.ReadBool();
            break;
          }
          case 26: {
            global::Labust.NanomodemPayload subBuilder = new global::Labust.NanomodemPayload();
            if (msgCase_ == MsgOneofCase.Payload) {
              subBuilder.MergeFrom(Payload);
            }
            input.ReadMessage(subBuilder);
            Payload = subBuilder;
            break;
          }
          case 34: {
            global::Labust.NanomodemRange subBuilder = new global::Labust.NanomodemRange();
            if (msgCase_ == MsgOneofCase.Range) {
              subBuilder.MergeFrom(Range);
            }
            input.ReadMessage(subBuilder);
            Range = subBuilder;
            break;
          }
        }
      }
    }

  }

  public sealed partial class AcousticRequest : pb::IMessage<AcousticRequest> {
    private static readonly pb::MessageParser<AcousticRequest> _parser = new pb::MessageParser<AcousticRequest>(() => new AcousticRequest());
    private pb::UnknownFieldSet _unknownFields;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pb::MessageParser<AcousticRequest> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Acoustictransmission.AcousticTransmissionReflection.Descriptor.MessageTypes[2]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public AcousticRequest() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public AcousticRequest(AcousticRequest other) : this() {
      success_ = other.success_;
      request_ = other.request_ != null ? other.request_.Clone() : null;
      _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public AcousticRequest Clone() {
      return new AcousticRequest(this);
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

    /// <summary>Field number for the "request" field.</summary>
    public const int RequestFieldNumber = 2;
    private global::Labust.NanomodemRequest request_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public global::Labust.NanomodemRequest Request {
      get { return request_; }
      set {
        request_ = value;
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override bool Equals(object other) {
      return Equals(other as AcousticRequest);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public bool Equals(AcousticRequest other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (Success != other.Success) return false;
      if (!object.Equals(Request, other.Request)) return false;
      return Equals(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override int GetHashCode() {
      int hash = 1;
      if (Success != false) hash ^= Success.GetHashCode();
      if (request_ != null) hash ^= Request.GetHashCode();
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
      if (request_ != null) {
        output.WriteRawTag(18);
        output.WriteMessage(Request);
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
      if (request_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Request);
      }
      if (_unknownFields != null) {
        size += _unknownFields.CalculateSize();
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(AcousticRequest other) {
      if (other == null) {
        return;
      }
      if (other.Success != false) {
        Success = other.Success;
      }
      if (other.request_ != null) {
        if (request_ == null) {
          request_ = new global::Labust.NanomodemRequest();
        }
        Request.MergeFrom(other.Request);
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
          case 18: {
            if (request_ == null) {
              request_ = new global::Labust.NanomodemRequest();
            }
            input.ReadMessage(request_);
            break;
          }
        }
      }
    }

  }

  #endregion

}

#endregion Designer generated code
