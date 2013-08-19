// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: simulations.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "simulations.pb.h"

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

namespace Simulations {

namespace {

const ::google::protobuf::Descriptor* Task_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Task_reflection_ = NULL;
const ::google::protobuf::Descriptor* Core_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Core_reflection_ = NULL;
const ::google::protobuf::Descriptor* Simulation_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Simulation_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_simulations_2eproto() {
  protobuf_AddDesc_simulations_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "simulations.proto");
  GOOGLE_CHECK(file != NULL);
  Task_descriptor_ = file->message_type(0);
  static const int Task_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Task, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Task, period_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Task, deadline_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Task, wcet_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Task, core_),
  };
  Task_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Task_descriptor_,
      Task::default_instance_,
      Task_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Task, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Task, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Task));
  Core_descriptor_ = file->message_type(1);
  static const int Core_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Core, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Core, u_),
  };
  Core_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Core_descriptor_,
      Core::default_instance_,
      Core_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Core, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Core, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Core));
  Simulation_descriptor_ = file->message_type(2);
  static const int Simulation_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Simulation, tasks_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Simulation, cores_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Simulation, feasible_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Simulation, csa_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Simulation, tsa_),
  };
  Simulation_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Simulation_descriptor_,
      Simulation::default_instance_,
      Simulation_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Simulation, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Simulation, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Simulation));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_simulations_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Task_descriptor_, &Task::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Core_descriptor_, &Core::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Simulation_descriptor_, &Simulation::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_simulations_2eproto() {
  delete Task::default_instance_;
  delete Task_reflection_;
  delete Core::default_instance_;
  delete Core_reflection_;
  delete Simulation::default_instance_;
  delete Simulation_reflection_;
}

void protobuf_AddDesc_simulations_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021simulations.proto\022\013Simulations\"P\n\004Task"
    "\022\n\n\002id\030\001 \002(\005\022\016\n\006period\030\002 \002(\005\022\020\n\010deadline"
    "\030\003 \002(\005\022\014\n\004wcet\030\004 \002(\005\022\014\n\004core\030\005 \002(\005\"\035\n\004Co"
    "re\022\n\n\002id\030\001 \002(\005\022\t\n\001u\030\002 \002(\002\"|\n\nSimulation\022"
    " \n\005tasks\030\001 \003(\0132\021.Simulations.Task\022 \n\005cor"
    "es\030\002 \003(\0132\021.Simulations.Core\022\020\n\010feasible\030"
    "\003 \002(\010\022\013\n\003csa\030\004 \002(\005\022\013\n\003tsa\030\005 \002(\005", 271);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "simulations.proto", &protobuf_RegisterTypes);
  Task::default_instance_ = new Task();
  Core::default_instance_ = new Core();
  Simulation::default_instance_ = new Simulation();
  Task::default_instance_->InitAsDefaultInstance();
  Core::default_instance_->InitAsDefaultInstance();
  Simulation::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_simulations_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_simulations_2eproto {
  StaticDescriptorInitializer_simulations_2eproto() {
    protobuf_AddDesc_simulations_2eproto();
  }
} static_descriptor_initializer_simulations_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Task::kIdFieldNumber;
const int Task::kPeriodFieldNumber;
const int Task::kDeadlineFieldNumber;
const int Task::kWcetFieldNumber;
const int Task::kCoreFieldNumber;
#endif  // !_MSC_VER

Task::Task()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Task::InitAsDefaultInstance() {
}

Task::Task(const Task& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Task::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0;
  period_ = 0;
  deadline_ = 0;
  wcet_ = 0;
  core_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Task::~Task() {
  SharedDtor();
}

void Task::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Task::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Task::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Task_descriptor_;
}

const Task& Task::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_simulations_2eproto();
  return *default_instance_;
}

Task* Task::default_instance_ = NULL;

Task* Task::New() const {
  return new Task;
}

void Task::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0;
    period_ = 0;
    deadline_ = 0;
    wcet_ = 0;
    core_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Task::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_period;
        break;
      }

      // required int32 period = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_period:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &period_)));
          set_has_period();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_deadline;
        break;
      }

      // required int32 deadline = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_deadline:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &deadline_)));
          set_has_deadline();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_wcet;
        break;
      }

      // required int32 wcet = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_wcet:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &wcet_)));
          set_has_wcet();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_core;
        break;
      }

      // required int32 core = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_core:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &core_)));
          set_has_core();
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

void Task::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // required int32 period = 2;
  if (has_period()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->period(), output);
  }

  // required int32 deadline = 3;
  if (has_deadline()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->deadline(), output);
  }

  // required int32 wcet = 4;
  if (has_wcet()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->wcet(), output);
  }

  // required int32 core = 5;
  if (has_core()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->core(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Task::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // required int32 period = 2;
  if (has_period()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->period(), target);
  }

  // required int32 deadline = 3;
  if (has_deadline()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->deadline(), target);
  }

  // required int32 wcet = 4;
  if (has_wcet()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->wcet(), target);
  }

  // required int32 core = 5;
  if (has_core()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->core(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Task::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // required int32 period = 2;
    if (has_period()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->period());
    }

    // required int32 deadline = 3;
    if (has_deadline()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->deadline());
    }

    // required int32 wcet = 4;
    if (has_wcet()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->wcet());
    }

    // required int32 core = 5;
    if (has_core()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->core());
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

void Task::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Task* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Task*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Task::MergeFrom(const Task& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_period()) {
      set_period(from.period());
    }
    if (from.has_deadline()) {
      set_deadline(from.deadline());
    }
    if (from.has_wcet()) {
      set_wcet(from.wcet());
    }
    if (from.has_core()) {
      set_core(from.core());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Task::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Task::CopyFrom(const Task& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Task::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001f) != 0x0000001f) return false;

  return true;
}

void Task::Swap(Task* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(period_, other->period_);
    std::swap(deadline_, other->deadline_);
    std::swap(wcet_, other->wcet_);
    std::swap(core_, other->core_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Task::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Task_descriptor_;
  metadata.reflection = Task_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Core::kIdFieldNumber;
const int Core::kUFieldNumber;
#endif  // !_MSC_VER

Core::Core()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Core::InitAsDefaultInstance() {
}

Core::Core(const Core& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Core::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0;
  u_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Core::~Core() {
  SharedDtor();
}

void Core::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Core::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Core::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Core_descriptor_;
}

const Core& Core::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_simulations_2eproto();
  return *default_instance_;
}

Core* Core::default_instance_ = NULL;

Core* Core::New() const {
  return new Core;
}

void Core::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0;
    u_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Core::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(21)) goto parse_u;
        break;
      }

      // required float u = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_u:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
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

void Core::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // required float u = 2;
  if (has_u()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(2, this->u(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Core::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // required float u = 2;
  if (has_u()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(2, this->u(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Core::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // required float u = 2;
    if (has_u()) {
      total_size += 1 + 4;
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

void Core::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Core* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Core*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Core::MergeFrom(const Core& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_u()) {
      set_u(from.u());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Core::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Core::CopyFrom(const Core& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Core::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void Core::Swap(Core* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(u_, other->u_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Core::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Core_descriptor_;
  metadata.reflection = Core_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Simulation::kTasksFieldNumber;
const int Simulation::kCoresFieldNumber;
const int Simulation::kFeasibleFieldNumber;
const int Simulation::kCsaFieldNumber;
const int Simulation::kTsaFieldNumber;
#endif  // !_MSC_VER

Simulation::Simulation()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Simulation::InitAsDefaultInstance() {
}

Simulation::Simulation(const Simulation& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Simulation::SharedCtor() {
  _cached_size_ = 0;
  feasible_ = false;
  csa_ = 0;
  tsa_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Simulation::~Simulation() {
  SharedDtor();
}

void Simulation::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Simulation::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Simulation::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Simulation_descriptor_;
}

const Simulation& Simulation::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_simulations_2eproto();
  return *default_instance_;
}

Simulation* Simulation::default_instance_ = NULL;

Simulation* Simulation::New() const {
  return new Simulation;
}

void Simulation::Clear() {
  if (_has_bits_[2 / 32] & (0xffu << (2 % 32))) {
    feasible_ = false;
    csa_ = 0;
    tsa_ = 0;
  }
  tasks_.Clear();
  cores_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Simulation::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Simulations.Task tasks = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_tasks:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_tasks()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_tasks;
        if (input->ExpectTag(18)) goto parse_cores;
        break;
      }

      // repeated .Simulations.Core cores = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_cores:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_cores()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_cores;
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
        if (input->ExpectTag(32)) goto parse_csa;
        break;
      }

      // required int32 csa = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_csa:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &csa_)));
          set_has_csa();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_tsa;
        break;
      }

      // required int32 tsa = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_tsa:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &tsa_)));
          set_has_tsa();
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

void Simulation::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .Simulations.Task tasks = 1;
  for (int i = 0; i < this->tasks_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->tasks(i), output);
  }

  // repeated .Simulations.Core cores = 2;
  for (int i = 0; i < this->cores_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->cores(i), output);
  }

  // required bool feasible = 3;
  if (has_feasible()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->feasible(), output);
  }

  // required int32 csa = 4;
  if (has_csa()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->csa(), output);
  }

  // required int32 tsa = 5;
  if (has_tsa()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->tsa(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Simulation::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .Simulations.Task tasks = 1;
  for (int i = 0; i < this->tasks_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->tasks(i), target);
  }

  // repeated .Simulations.Core cores = 2;
  for (int i = 0; i < this->cores_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->cores(i), target);
  }

  // required bool feasible = 3;
  if (has_feasible()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->feasible(), target);
  }

  // required int32 csa = 4;
  if (has_csa()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->csa(), target);
  }

  // required int32 tsa = 5;
  if (has_tsa()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->tsa(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Simulation::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[2 / 32] & (0xffu << (2 % 32))) {
    // required bool feasible = 3;
    if (has_feasible()) {
      total_size += 1 + 1;
    }

    // required int32 csa = 4;
    if (has_csa()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->csa());
    }

    // required int32 tsa = 5;
    if (has_tsa()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->tsa());
    }

  }
  // repeated .Simulations.Task tasks = 1;
  total_size += 1 * this->tasks_size();
  for (int i = 0; i < this->tasks_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->tasks(i));
  }

  // repeated .Simulations.Core cores = 2;
  total_size += 1 * this->cores_size();
  for (int i = 0; i < this->cores_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->cores(i));
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

void Simulation::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Simulation* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Simulation*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Simulation::MergeFrom(const Simulation& from) {
  GOOGLE_CHECK_NE(&from, this);
  tasks_.MergeFrom(from.tasks_);
  cores_.MergeFrom(from.cores_);
  if (from._has_bits_[2 / 32] & (0xffu << (2 % 32))) {
    if (from.has_feasible()) {
      set_feasible(from.feasible());
    }
    if (from.has_csa()) {
      set_csa(from.csa());
    }
    if (from.has_tsa()) {
      set_tsa(from.tsa());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Simulation::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Simulation::CopyFrom(const Simulation& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Simulation::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001c) != 0x0000001c) return false;

  for (int i = 0; i < tasks_size(); i++) {
    if (!this->tasks(i).IsInitialized()) return false;
  }
  for (int i = 0; i < cores_size(); i++) {
    if (!this->cores(i).IsInitialized()) return false;
  }
  return true;
}

void Simulation::Swap(Simulation* other) {
  if (other != this) {
    tasks_.Swap(&other->tasks_);
    cores_.Swap(&other->cores_);
    std::swap(feasible_, other->feasible_);
    std::swap(csa_, other->csa_);
    std::swap(tsa_, other->tsa_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Simulation::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Simulation_descriptor_;
  metadata.reflection = Simulation_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Simulations

// @@protoc_insertion_point(global_scope)