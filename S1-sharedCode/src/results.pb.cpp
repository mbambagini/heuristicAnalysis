// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: results.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "results.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Results {

namespace {

const ::google::protobuf::Descriptor* Consumption_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Consumption_reflection_ = NULL;
const ::google::protobuf::Descriptor* Execution_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Execution_reflection_ = NULL;
const ::google::protobuf::Descriptor* Result_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Result_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_results_2eproto() {
  protobuf_AddDesc_results_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "results.proto");
  GOOGLE_CHECK(file != NULL);
  Consumption_descriptor_ = file->message_type(0);
  static const int Consumption_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Consumption, nactivecores_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Consumption, meanpower_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Consumption, alpha_),
  };
  Consumption_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Consumption_descriptor_,
      Consumption::default_instance_,
      Consumption_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Consumption, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Consumption, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Consumption));
  Execution_descriptor_ = file->message_type(1);
  static const int Execution_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Execution, tsa_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Execution, csa_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Execution, feasible_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Execution, sfa_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Execution, no_sfa_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Execution, partitioningfile_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Execution, n_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Execution, u_),
  };
  Execution_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Execution_descriptor_,
      Execution::default_instance_,
      Execution_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Execution, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Execution, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Execution));
  Result_descriptor_ = file->message_type(2);
  static const int Result_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Result, iterations_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Result, hwfile_),
  };
  Result_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Result_descriptor_,
      Result::default_instance_,
      Result_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Result, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Result, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Result));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_results_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Consumption_descriptor_, &Consumption::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Execution_descriptor_, &Execution::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Result_descriptor_, &Result::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_results_2eproto() {
  delete Consumption::default_instance_;
  delete Consumption_reflection_;
  delete Execution::default_instance_;
  delete Execution_reflection_;
  delete Result::default_instance_;
  delete Result_reflection_;
}

void protobuf_AddDesc_results_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rresults.proto\022\007Results\"E\n\013Consumption\022"
    "\024\n\014nActiveCores\030\001 \002(\005\022\021\n\tmeanPower\030\002 \002(\001"
    "\022\r\n\005alpha\030\003 \002(\001\"\260\001\n\tExecution\022\013\n\003TSA\030\001 \002"
    "(\005\022\013\n\003CSA\030\002 \002(\005\022\020\n\010feasible\030\003 \002(\010\022!\n\003sfa"
    "\030\004 \003(\0132\024.Results.Consumption\022$\n\006no_sfa\030\005"
    " \002(\0132\024.Results.Consumption\022\030\n\020partitioni"
    "ngFile\030\006 \002(\t\022\t\n\001n\030\007 \002(\005\022\t\n\001u\030\010 \002(\001\"@\n\006Re"
    "sult\022&\n\niterations\030\001 \003(\0132\022.Results.Execu"
    "tion\022\016\n\006hwFile\030\002 \002(\t", 340);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "results.proto", &protobuf_RegisterTypes);
  Consumption::default_instance_ = new Consumption();
  Execution::default_instance_ = new Execution();
  Result::default_instance_ = new Result();
  Consumption::default_instance_->InitAsDefaultInstance();
  Execution::default_instance_->InitAsDefaultInstance();
  Result::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_results_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_results_2eproto {
  StaticDescriptorInitializer_results_2eproto() {
    protobuf_AddDesc_results_2eproto();
  }
} static_descriptor_initializer_results_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Consumption::kNActiveCoresFieldNumber;
const int Consumption::kMeanPowerFieldNumber;
const int Consumption::kAlphaFieldNumber;
#endif  // !_MSC_VER

Consumption::Consumption()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Consumption::InitAsDefaultInstance() {
}

Consumption::Consumption(const Consumption& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Consumption::SharedCtor() {
  _cached_size_ = 0;
  nactivecores_ = 0;
  meanpower_ = 0;
  alpha_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Consumption::~Consumption() {
  SharedDtor();
}

void Consumption::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Consumption::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Consumption::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Consumption_descriptor_;
}

const Consumption& Consumption::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_results_2eproto();
  return *default_instance_;
}

Consumption* Consumption::default_instance_ = NULL;

Consumption* Consumption::New() const {
  return new Consumption;
}

void Consumption::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    nactivecores_ = 0;
    meanpower_ = 0;
    alpha_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Consumption::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 nActiveCores = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &nactivecores_)));
          set_has_nactivecores();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(17)) goto parse_meanPower;
        break;
      }

      // required double meanPower = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_meanPower:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &meanpower_)));
          set_has_meanpower();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(25)) goto parse_alpha;
        break;
      }

      // required double alpha = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_alpha:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &alpha_)));
          set_has_alpha();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Consumption::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 nActiveCores = 1;
  if (has_nactivecores()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->nactivecores(), output);
  }

  // required double meanPower = 2;
  if (has_meanpower()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->meanpower(), output);
  }

  // required double alpha = 3;
  if (has_alpha()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(3, this->alpha(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Consumption::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 nActiveCores = 1;
  if (has_nactivecores()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->nactivecores(), target);
  }

  // required double meanPower = 2;
  if (has_meanpower()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->meanpower(), target);
  }

  // required double alpha = 3;
  if (has_alpha()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, this->alpha(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Consumption::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 nActiveCores = 1;
    if (has_nactivecores()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->nactivecores());
    }

    // required double meanPower = 2;
    if (has_meanpower()) {
      total_size += 1 + 8;
    }

    // required double alpha = 3;
    if (has_alpha()) {
      total_size += 1 + 8;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Consumption::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Consumption* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Consumption*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Consumption::MergeFrom(const Consumption& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_nactivecores()) {
      set_nactivecores(from.nactivecores());
    }
    if (from.has_meanpower()) {
      set_meanpower(from.meanpower());
    }
    if (from.has_alpha()) {
      set_alpha(from.alpha());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Consumption::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Consumption::CopyFrom(const Consumption& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Consumption::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void Consumption::Swap(Consumption* other) {
  if (other != this) {
    std::swap(nactivecores_, other->nactivecores_);
    std::swap(meanpower_, other->meanpower_);
    std::swap(alpha_, other->alpha_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Consumption::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Consumption_descriptor_;
  metadata.reflection = Consumption_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Execution::kTSAFieldNumber;
const int Execution::kCSAFieldNumber;
const int Execution::kFeasibleFieldNumber;
const int Execution::kSfaFieldNumber;
const int Execution::kNoSfaFieldNumber;
const int Execution::kPartitioningFileFieldNumber;
const int Execution::kNFieldNumber;
const int Execution::kUFieldNumber;
#endif  // !_MSC_VER

Execution::Execution()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Execution::InitAsDefaultInstance() {
  no_sfa_ = const_cast< ::Results::Consumption*>(&::Results::Consumption::default_instance());
}

Execution::Execution(const Execution& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Execution::SharedCtor() {
  _cached_size_ = 0;
  tsa_ = 0;
  csa_ = 0;
  feasible_ = false;
  no_sfa_ = NULL;
  partitioningfile_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  n_ = 0;
  u_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Execution::~Execution() {
  SharedDtor();
}

void Execution::SharedDtor() {
  if (partitioningfile_ != &::google::protobuf::internal::kEmptyString) {
    delete partitioningfile_;
  }
  if (this != default_instance_) {
    delete no_sfa_;
  }
}

void Execution::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Execution::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Execution_descriptor_;
}

const Execution& Execution::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_results_2eproto();
  return *default_instance_;
}

Execution* Execution::default_instance_ = NULL;

Execution* Execution::New() const {
  return new Execution;
}

void Execution::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    tsa_ = 0;
    csa_ = 0;
    feasible_ = false;
    if (has_no_sfa()) {
      if (no_sfa_ != NULL) no_sfa_->::Results::Consumption::Clear();
    }
    if (has_partitioningfile()) {
      if (partitioningfile_ != &::google::protobuf::internal::kEmptyString) {
        partitioningfile_->clear();
      }
    }
    n_ = 0;
    u_ = 0;
  }
  sfa_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Execution::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 TSA = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &tsa_)));
          set_has_tsa();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_CSA;
        break;
      }

      // required int32 CSA = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_CSA:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &csa_)));
          set_has_csa();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_feasible;
        break;
      }

      // required bool feasible = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_feasible:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &feasible_)));
          set_has_feasible();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_sfa;
        break;
      }

      // repeated .Results.Consumption sfa = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_sfa:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_sfa()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_sfa;
        if (input->ExpectTag(42)) goto parse_no_sfa;
        break;
      }

      // required .Results.Consumption no_sfa = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_no_sfa:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_no_sfa()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(50)) goto parse_partitioningFile;
        break;
      }

      // required string partitioningFile = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_partitioningFile:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_partitioningfile()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->partitioningfile().data(), this->partitioningfile().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_n;
        break;
      }

      // required int32 n = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_n:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &n_)));
          set_has_n();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(65)) goto parse_u;
        break;
      }

      // required double u = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_u:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &u_)));
          set_has_u();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Execution::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 TSA = 1;
  if (has_tsa()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->tsa(), output);
  }

  // required int32 CSA = 2;
  if (has_csa()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->csa(), output);
  }

  // required bool feasible = 3;
  if (has_feasible()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->feasible(), output);
  }

  // repeated .Results.Consumption sfa = 4;
  for (int i = 0; i < this->sfa_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->sfa(i), output);
  }

  // required .Results.Consumption no_sfa = 5;
  if (has_no_sfa()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->no_sfa(), output);
  }

  // required string partitioningFile = 6;
  if (has_partitioningfile()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->partitioningfile().data(), this->partitioningfile().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      6, this->partitioningfile(), output);
  }

  // required int32 n = 7;
  if (has_n()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(7, this->n(), output);
  }

  // required double u = 8;
  if (has_u()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(8, this->u(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Execution::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 TSA = 1;
  if (has_tsa()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->tsa(), target);
  }

  // required int32 CSA = 2;
  if (has_csa()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->csa(), target);
  }

  // required bool feasible = 3;
  if (has_feasible()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->feasible(), target);
  }

  // repeated .Results.Consumption sfa = 4;
  for (int i = 0; i < this->sfa_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->sfa(i), target);
  }

  // required .Results.Consumption no_sfa = 5;
  if (has_no_sfa()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->no_sfa(), target);
  }

  // required string partitioningFile = 6;
  if (has_partitioningfile()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->partitioningfile().data(), this->partitioningfile().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        6, this->partitioningfile(), target);
  }

  // required int32 n = 7;
  if (has_n()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, this->n(), target);
  }

  // required double u = 8;
  if (has_u()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(8, this->u(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Execution::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 TSA = 1;
    if (has_tsa()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->tsa());
    }

    // required int32 CSA = 2;
    if (has_csa()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->csa());
    }

    // required bool feasible = 3;
    if (has_feasible()) {
      total_size += 1 + 1;
    }

    // required .Results.Consumption no_sfa = 5;
    if (has_no_sfa()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->no_sfa());
    }

    // required string partitioningFile = 6;
    if (has_partitioningfile()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->partitioningfile());
    }

    // required int32 n = 7;
    if (has_n()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->n());
    }

    // required double u = 8;
    if (has_u()) {
      total_size += 1 + 8;
    }

  }
  // repeated .Results.Consumption sfa = 4;
  total_size += 1 * this->sfa_size();
  for (int i = 0; i < this->sfa_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->sfa(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Execution::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Execution* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Execution*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Execution::MergeFrom(const Execution& from) {
  GOOGLE_CHECK_NE(&from, this);
  sfa_.MergeFrom(from.sfa_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_tsa()) {
      set_tsa(from.tsa());
    }
    if (from.has_csa()) {
      set_csa(from.csa());
    }
    if (from.has_feasible()) {
      set_feasible(from.feasible());
    }
    if (from.has_no_sfa()) {
      mutable_no_sfa()->::Results::Consumption::MergeFrom(from.no_sfa());
    }
    if (from.has_partitioningfile()) {
      set_partitioningfile(from.partitioningfile());
    }
    if (from.has_n()) {
      set_n(from.n());
    }
    if (from.has_u()) {
      set_u(from.u());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Execution::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Execution::CopyFrom(const Execution& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Execution::IsInitialized() const {
  if ((_has_bits_[0] & 0x000000f7) != 0x000000f7) return false;

  for (int i = 0; i < sfa_size(); i++) {
    if (!this->sfa(i).IsInitialized()) return false;
  }
  if (has_no_sfa()) {
    if (!this->no_sfa().IsInitialized()) return false;
  }
  return true;
}

void Execution::Swap(Execution* other) {
  if (other != this) {
    std::swap(tsa_, other->tsa_);
    std::swap(csa_, other->csa_);
    std::swap(feasible_, other->feasible_);
    sfa_.Swap(&other->sfa_);
    std::swap(no_sfa_, other->no_sfa_);
    std::swap(partitioningfile_, other->partitioningfile_);
    std::swap(n_, other->n_);
    std::swap(u_, other->u_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Execution::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Execution_descriptor_;
  metadata.reflection = Execution_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Result::kIterationsFieldNumber;
const int Result::kHwFileFieldNumber;
#endif  // !_MSC_VER

Result::Result()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Result::InitAsDefaultInstance() {
}

Result::Result(const Result& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Result::SharedCtor() {
  _cached_size_ = 0;
  hwfile_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Result::~Result() {
  SharedDtor();
}

void Result::SharedDtor() {
  if (hwfile_ != &::google::protobuf::internal::kEmptyString) {
    delete hwfile_;
  }
  if (this != default_instance_) {
  }
}

void Result::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Result::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Result_descriptor_;
}

const Result& Result::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_results_2eproto();
  return *default_instance_;
}

Result* Result::default_instance_ = NULL;

Result* Result::New() const {
  return new Result;
}

void Result::Clear() {
  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (has_hwfile()) {
      if (hwfile_ != &::google::protobuf::internal::kEmptyString) {
        hwfile_->clear();
      }
    }
  }
  iterations_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Result::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Results.Execution iterations = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_iterations:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_iterations()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_iterations;
        if (input->ExpectTag(18)) goto parse_hwFile;
        break;
      }

      // required string hwFile = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_hwFile:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_hwfile()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->hwfile().data(), this->hwfile().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Result::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .Results.Execution iterations = 1;
  for (int i = 0; i < this->iterations_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->iterations(i), output);
  }

  // required string hwFile = 2;
  if (has_hwfile()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->hwfile().data(), this->hwfile().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->hwfile(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Result::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .Results.Execution iterations = 1;
  for (int i = 0; i < this->iterations_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->iterations(i), target);
  }

  // required string hwFile = 2;
  if (has_hwfile()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->hwfile().data(), this->hwfile().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->hwfile(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Result::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // required string hwFile = 2;
    if (has_hwfile()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->hwfile());
    }

  }
  // repeated .Results.Execution iterations = 1;
  total_size += 1 * this->iterations_size();
  for (int i = 0; i < this->iterations_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->iterations(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Result::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Result* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Result*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Result::MergeFrom(const Result& from) {
  GOOGLE_CHECK_NE(&from, this);
  iterations_.MergeFrom(from.iterations_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_hwfile()) {
      set_hwfile(from.hwfile());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Result::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Result::CopyFrom(const Result& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Result::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;

  for (int i = 0; i < iterations_size(); i++) {
    if (!this->iterations(i).IsInitialized()) return false;
  }
  return true;
}

void Result::Swap(Result* other) {
  if (other != this) {
    iterations_.Swap(&other->iterations_);
    std::swap(hwfile_, other->hwfile_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Result::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Result_descriptor_;
  metadata.reflection = Result_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Results

// @@protoc_insertion_point(global_scope)
