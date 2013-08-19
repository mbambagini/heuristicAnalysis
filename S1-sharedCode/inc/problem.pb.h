// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: problem.proto

#ifndef PROTOBUF_problem_2eproto__INCLUDED
#define PROTOBUF_problem_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace Problem {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_problem_2eproto();
void protobuf_AssignDesc_problem_2eproto();
void protobuf_ShutdownFile_problem_2eproto();

class Task;
class Software;
class Coefficients;
class ConsAtSpeed;
class Hardware;

// ===================================================================

class Task : public ::google::protobuf::Message {
 public:
  Task();
  virtual ~Task();

  Task(const Task& from);

  inline Task& operator=(const Task& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Task& default_instance();

  void Swap(Task* other);

  // implements Message ----------------------------------------------

  Task* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Task& from);
  void MergeFrom(const Task& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::int32 id() const;
  inline void set_id(::google::protobuf::int32 value);

  // required int32 wcet = 2;
  inline bool has_wcet() const;
  inline void clear_wcet();
  static const int kWcetFieldNumber = 2;
  inline ::google::protobuf::int32 wcet() const;
  inline void set_wcet(::google::protobuf::int32 value);

  // repeated int32 wcets = 3;
  inline int wcets_size() const;
  inline void clear_wcets();
  static const int kWcetsFieldNumber = 3;
  inline ::google::protobuf::int32 wcets(int index) const;
  inline void set_wcets(int index, ::google::protobuf::int32 value);
  inline void add_wcets(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      wcets() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_wcets();

  // required int32 period = 4;
  inline bool has_period() const;
  inline void clear_period();
  static const int kPeriodFieldNumber = 4;
  inline ::google::protobuf::int32 period() const;
  inline void set_period(::google::protobuf::int32 value);

  // required int32 deadline = 5;
  inline bool has_deadline() const;
  inline void clear_deadline();
  static const int kDeadlineFieldNumber = 5;
  inline ::google::protobuf::int32 deadline() const;
  inline void set_deadline(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Problem.Task)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_wcet();
  inline void clear_has_wcet();
  inline void set_has_period();
  inline void clear_has_period();
  inline void set_has_deadline();
  inline void clear_has_deadline();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 id_;
  ::google::protobuf::int32 wcet_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > wcets_;
  ::google::protobuf::int32 period_;
  ::google::protobuf::int32 deadline_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_problem_2eproto();
  friend void protobuf_AssignDesc_problem_2eproto();
  friend void protobuf_ShutdownFile_problem_2eproto();

  void InitAsDefaultInstance();
  static Task* default_instance_;
};
// -------------------------------------------------------------------

class Software : public ::google::protobuf::Message {
 public:
  Software();
  virtual ~Software();

  Software(const Software& from);

  inline Software& operator=(const Software& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Software& default_instance();

  void Swap(Software* other);

  // implements Message ----------------------------------------------

  Software* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Software& from);
  void MergeFrom(const Software& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .Problem.Task tasks = 1;
  inline int tasks_size() const;
  inline void clear_tasks();
  static const int kTasksFieldNumber = 1;
  inline const ::Problem::Task& tasks(int index) const;
  inline ::Problem::Task* mutable_tasks(int index);
  inline ::Problem::Task* add_tasks();
  inline const ::google::protobuf::RepeatedPtrField< ::Problem::Task >&
      tasks() const;
  inline ::google::protobuf::RepeatedPtrField< ::Problem::Task >*
      mutable_tasks();

  // required double U = 2;
  inline bool has_u() const;
  inline void clear_u();
  static const int kUFieldNumber = 2;
  inline double u() const;
  inline void set_u(double value);

  // required double real_U = 3;
  inline bool has_real_u() const;
  inline void clear_real_u();
  static const int kRealUFieldNumber = 3;
  inline double real_u() const;
  inline void set_real_u(double value);

  // required int32 nOfResources = 4;
  inline bool has_nofresources() const;
  inline void clear_nofresources();
  static const int kNOfResourcesFieldNumber = 4;
  inline ::google::protobuf::int32 nofresources() const;
  inline void set_nofresources(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Problem.Software)
 private:
  inline void set_has_u();
  inline void clear_has_u();
  inline void set_has_real_u();
  inline void clear_has_real_u();
  inline void set_has_nofresources();
  inline void clear_has_nofresources();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::Problem::Task > tasks_;
  double u_;
  double real_u_;
  ::google::protobuf::int32 nofresources_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_problem_2eproto();
  friend void protobuf_AssignDesc_problem_2eproto();
  friend void protobuf_ShutdownFile_problem_2eproto();

  void InitAsDefaultInstance();
  static Software* default_instance_;
};
// -------------------------------------------------------------------

class Coefficients : public ::google::protobuf::Message {
 public:
  Coefficients();
  virtual ~Coefficients();

  Coefficients(const Coefficients& from);

  inline Coefficients& operator=(const Coefficients& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Coefficients& default_instance();

  void Swap(Coefficients* other);

  // implements Message ----------------------------------------------

  Coefficients* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Coefficients& from);
  void MergeFrom(const Coefficients& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required double k0 = 1;
  inline bool has_k0() const;
  inline void clear_k0();
  static const int kK0FieldNumber = 1;
  inline double k0() const;
  inline void set_k0(double value);

  // required double k1 = 2;
  inline bool has_k1() const;
  inline void clear_k1();
  static const int kK1FieldNumber = 2;
  inline double k1() const;
  inline void set_k1(double value);

  // required double k2 = 3;
  inline bool has_k2() const;
  inline void clear_k2();
  static const int kK2FieldNumber = 3;
  inline double k2() const;
  inline void set_k2(double value);

  // required double k3 = 4;
  inline bool has_k3() const;
  inline void clear_k3();
  static const int kK3FieldNumber = 4;
  inline double k3() const;
  inline void set_k3(double value);

  // @@protoc_insertion_point(class_scope:Problem.Coefficients)
 private:
  inline void set_has_k0();
  inline void clear_has_k0();
  inline void set_has_k1();
  inline void clear_has_k1();
  inline void set_has_k2();
  inline void clear_has_k2();
  inline void set_has_k3();
  inline void clear_has_k3();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  double k0_;
  double k1_;
  double k2_;
  double k3_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_problem_2eproto();
  friend void protobuf_AssignDesc_problem_2eproto();
  friend void protobuf_ShutdownFile_problem_2eproto();

  void InitAsDefaultInstance();
  static Coefficients* default_instance_;
};
// -------------------------------------------------------------------

class ConsAtSpeed : public ::google::protobuf::Message {
 public:
  ConsAtSpeed();
  virtual ~ConsAtSpeed();

  ConsAtSpeed(const ConsAtSpeed& from);

  inline ConsAtSpeed& operator=(const ConsAtSpeed& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ConsAtSpeed& default_instance();

  void Swap(ConsAtSpeed* other);

  // implements Message ----------------------------------------------

  ConsAtSpeed* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ConsAtSpeed& from);
  void MergeFrom(const ConsAtSpeed& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required double speed = 1;
  inline bool has_speed() const;
  inline void clear_speed();
  static const int kSpeedFieldNumber = 1;
  inline double speed() const;
  inline void set_speed(double value);

  // required .Problem.Coefficients coeffs = 2;
  inline bool has_coeffs() const;
  inline void clear_coeffs();
  static const int kCoeffsFieldNumber = 2;
  inline const ::Problem::Coefficients& coeffs() const;
  inline ::Problem::Coefficients* mutable_coeffs();
  inline ::Problem::Coefficients* release_coeffs();
  inline void set_allocated_coeffs(::Problem::Coefficients* coeffs);

  // @@protoc_insertion_point(class_scope:Problem.ConsAtSpeed)
 private:
  inline void set_has_speed();
  inline void clear_has_speed();
  inline void set_has_coeffs();
  inline void clear_has_coeffs();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  double speed_;
  ::Problem::Coefficients* coeffs_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_problem_2eproto();
  friend void protobuf_AssignDesc_problem_2eproto();
  friend void protobuf_ShutdownFile_problem_2eproto();

  void InitAsDefaultInstance();
  static ConsAtSpeed* default_instance_;
};
// -------------------------------------------------------------------

class Hardware : public ::google::protobuf::Message {
 public:
  Hardware();
  virtual ~Hardware();

  Hardware(const Hardware& from);

  inline Hardware& operator=(const Hardware& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Hardware& default_instance();

  void Swap(Hardware* other);

  // implements Message ----------------------------------------------

  Hardware* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Hardware& from);
  void MergeFrom(const Hardware& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 nOfClusters = 1;
  inline bool has_nofclusters() const;
  inline void clear_nofclusters();
  static const int kNOfClustersFieldNumber = 1;
  inline ::google::protobuf::int32 nofclusters() const;
  inline void set_nofclusters(::google::protobuf::int32 value);

  // required int32 CpC = 2;
  inline bool has_cpc() const;
  inline void clear_cpc();
  static const int kCpCFieldNumber = 2;
  inline ::google::protobuf::int32 cpc() const;
  inline void set_cpc(::google::protobuf::int32 value);

  // repeated .Problem.ConsAtSpeed cons = 3;
  inline int cons_size() const;
  inline void clear_cons();
  static const int kConsFieldNumber = 3;
  inline const ::Problem::ConsAtSpeed& cons(int index) const;
  inline ::Problem::ConsAtSpeed* mutable_cons(int index);
  inline ::Problem::ConsAtSpeed* add_cons();
  inline const ::google::protobuf::RepeatedPtrField< ::Problem::ConsAtSpeed >&
      cons() const;
  inline ::google::protobuf::RepeatedPtrField< ::Problem::ConsAtSpeed >*
      mutable_cons();

  // required int32 nOfResources = 4;
  inline bool has_nofresources() const;
  inline void clear_nofresources();
  static const int kNOfResourcesFieldNumber = 4;
  inline ::google::protobuf::int32 nofresources() const;
  inline void set_nofresources(::google::protobuf::int32 value);

  // repeated int32 resources = 5;
  inline int resources_size() const;
  inline void clear_resources();
  static const int kResourcesFieldNumber = 5;
  inline ::google::protobuf::int32 resources(int index) const;
  inline void set_resources(int index, ::google::protobuf::int32 value);
  inline void add_resources(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      resources() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_resources();

  // @@protoc_insertion_point(class_scope:Problem.Hardware)
 private:
  inline void set_has_nofclusters();
  inline void clear_has_nofclusters();
  inline void set_has_cpc();
  inline void clear_has_cpc();
  inline void set_has_nofresources();
  inline void clear_has_nofresources();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 nofclusters_;
  ::google::protobuf::int32 cpc_;
  ::google::protobuf::RepeatedPtrField< ::Problem::ConsAtSpeed > cons_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > resources_;
  ::google::protobuf::int32 nofresources_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_problem_2eproto();
  friend void protobuf_AssignDesc_problem_2eproto();
  friend void protobuf_ShutdownFile_problem_2eproto();

  void InitAsDefaultInstance();
  static Hardware* default_instance_;
};
// ===================================================================


// ===================================================================

// Task

// required int32 id = 1;
inline bool Task::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Task::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Task::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Task::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 Task::id() const {
  return id_;
}
inline void Task::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
}

// required int32 wcet = 2;
inline bool Task::has_wcet() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Task::set_has_wcet() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Task::clear_has_wcet() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Task::clear_wcet() {
  wcet_ = 0;
  clear_has_wcet();
}
inline ::google::protobuf::int32 Task::wcet() const {
  return wcet_;
}
inline void Task::set_wcet(::google::protobuf::int32 value) {
  set_has_wcet();
  wcet_ = value;
}

// repeated int32 wcets = 3;
inline int Task::wcets_size() const {
  return wcets_.size();
}
inline void Task::clear_wcets() {
  wcets_.Clear();
}
inline ::google::protobuf::int32 Task::wcets(int index) const {
  return wcets_.Get(index);
}
inline void Task::set_wcets(int index, ::google::protobuf::int32 value) {
  wcets_.Set(index, value);
}
inline void Task::add_wcets(::google::protobuf::int32 value) {
  wcets_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
Task::wcets() const {
  return wcets_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
Task::mutable_wcets() {
  return &wcets_;
}

// required int32 period = 4;
inline bool Task::has_period() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Task::set_has_period() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Task::clear_has_period() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Task::clear_period() {
  period_ = 0;
  clear_has_period();
}
inline ::google::protobuf::int32 Task::period() const {
  return period_;
}
inline void Task::set_period(::google::protobuf::int32 value) {
  set_has_period();
  period_ = value;
}

// required int32 deadline = 5;
inline bool Task::has_deadline() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Task::set_has_deadline() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Task::clear_has_deadline() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Task::clear_deadline() {
  deadline_ = 0;
  clear_has_deadline();
}
inline ::google::protobuf::int32 Task::deadline() const {
  return deadline_;
}
inline void Task::set_deadline(::google::protobuf::int32 value) {
  set_has_deadline();
  deadline_ = value;
}

// -------------------------------------------------------------------

// Software

// repeated .Problem.Task tasks = 1;
inline int Software::tasks_size() const {
  return tasks_.size();
}
inline void Software::clear_tasks() {
  tasks_.Clear();
}
inline const ::Problem::Task& Software::tasks(int index) const {
  return tasks_.Get(index);
}
inline ::Problem::Task* Software::mutable_tasks(int index) {
  return tasks_.Mutable(index);
}
inline ::Problem::Task* Software::add_tasks() {
  return tasks_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Problem::Task >&
Software::tasks() const {
  return tasks_;
}
inline ::google::protobuf::RepeatedPtrField< ::Problem::Task >*
Software::mutable_tasks() {
  return &tasks_;
}

// required double U = 2;
inline bool Software::has_u() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Software::set_has_u() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Software::clear_has_u() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Software::clear_u() {
  u_ = 0;
  clear_has_u();
}
inline double Software::u() const {
  return u_;
}
inline void Software::set_u(double value) {
  set_has_u();
  u_ = value;
}

// required double real_U = 3;
inline bool Software::has_real_u() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Software::set_has_real_u() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Software::clear_has_real_u() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Software::clear_real_u() {
  real_u_ = 0;
  clear_has_real_u();
}
inline double Software::real_u() const {
  return real_u_;
}
inline void Software::set_real_u(double value) {
  set_has_real_u();
  real_u_ = value;
}

// required int32 nOfResources = 4;
inline bool Software::has_nofresources() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Software::set_has_nofresources() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Software::clear_has_nofresources() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Software::clear_nofresources() {
  nofresources_ = 0;
  clear_has_nofresources();
}
inline ::google::protobuf::int32 Software::nofresources() const {
  return nofresources_;
}
inline void Software::set_nofresources(::google::protobuf::int32 value) {
  set_has_nofresources();
  nofresources_ = value;
}

// -------------------------------------------------------------------

// Coefficients

// required double k0 = 1;
inline bool Coefficients::has_k0() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Coefficients::set_has_k0() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Coefficients::clear_has_k0() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Coefficients::clear_k0() {
  k0_ = 0;
  clear_has_k0();
}
inline double Coefficients::k0() const {
  return k0_;
}
inline void Coefficients::set_k0(double value) {
  set_has_k0();
  k0_ = value;
}

// required double k1 = 2;
inline bool Coefficients::has_k1() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Coefficients::set_has_k1() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Coefficients::clear_has_k1() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Coefficients::clear_k1() {
  k1_ = 0;
  clear_has_k1();
}
inline double Coefficients::k1() const {
  return k1_;
}
inline void Coefficients::set_k1(double value) {
  set_has_k1();
  k1_ = value;
}

// required double k2 = 3;
inline bool Coefficients::has_k2() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Coefficients::set_has_k2() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Coefficients::clear_has_k2() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Coefficients::clear_k2() {
  k2_ = 0;
  clear_has_k2();
}
inline double Coefficients::k2() const {
  return k2_;
}
inline void Coefficients::set_k2(double value) {
  set_has_k2();
  k2_ = value;
}

// required double k3 = 4;
inline bool Coefficients::has_k3() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Coefficients::set_has_k3() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Coefficients::clear_has_k3() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Coefficients::clear_k3() {
  k3_ = 0;
  clear_has_k3();
}
inline double Coefficients::k3() const {
  return k3_;
}
inline void Coefficients::set_k3(double value) {
  set_has_k3();
  k3_ = value;
}

// -------------------------------------------------------------------

// ConsAtSpeed

// required double speed = 1;
inline bool ConsAtSpeed::has_speed() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ConsAtSpeed::set_has_speed() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ConsAtSpeed::clear_has_speed() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ConsAtSpeed::clear_speed() {
  speed_ = 0;
  clear_has_speed();
}
inline double ConsAtSpeed::speed() const {
  return speed_;
}
inline void ConsAtSpeed::set_speed(double value) {
  set_has_speed();
  speed_ = value;
}

// required .Problem.Coefficients coeffs = 2;
inline bool ConsAtSpeed::has_coeffs() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ConsAtSpeed::set_has_coeffs() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ConsAtSpeed::clear_has_coeffs() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ConsAtSpeed::clear_coeffs() {
  if (coeffs_ != NULL) coeffs_->::Problem::Coefficients::Clear();
  clear_has_coeffs();
}
inline const ::Problem::Coefficients& ConsAtSpeed::coeffs() const {
  return coeffs_ != NULL ? *coeffs_ : *default_instance_->coeffs_;
}
inline ::Problem::Coefficients* ConsAtSpeed::mutable_coeffs() {
  set_has_coeffs();
  if (coeffs_ == NULL) coeffs_ = new ::Problem::Coefficients;
  return coeffs_;
}
inline ::Problem::Coefficients* ConsAtSpeed::release_coeffs() {
  clear_has_coeffs();
  ::Problem::Coefficients* temp = coeffs_;
  coeffs_ = NULL;
  return temp;
}
inline void ConsAtSpeed::set_allocated_coeffs(::Problem::Coefficients* coeffs) {
  delete coeffs_;
  coeffs_ = coeffs;
  if (coeffs) {
    set_has_coeffs();
  } else {
    clear_has_coeffs();
  }
}

// -------------------------------------------------------------------

// Hardware

// required int32 nOfClusters = 1;
inline bool Hardware::has_nofclusters() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Hardware::set_has_nofclusters() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Hardware::clear_has_nofclusters() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Hardware::clear_nofclusters() {
  nofclusters_ = 0;
  clear_has_nofclusters();
}
inline ::google::protobuf::int32 Hardware::nofclusters() const {
  return nofclusters_;
}
inline void Hardware::set_nofclusters(::google::protobuf::int32 value) {
  set_has_nofclusters();
  nofclusters_ = value;
}

// required int32 CpC = 2;
inline bool Hardware::has_cpc() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Hardware::set_has_cpc() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Hardware::clear_has_cpc() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Hardware::clear_cpc() {
  cpc_ = 0;
  clear_has_cpc();
}
inline ::google::protobuf::int32 Hardware::cpc() const {
  return cpc_;
}
inline void Hardware::set_cpc(::google::protobuf::int32 value) {
  set_has_cpc();
  cpc_ = value;
}

// repeated .Problem.ConsAtSpeed cons = 3;
inline int Hardware::cons_size() const {
  return cons_.size();
}
inline void Hardware::clear_cons() {
  cons_.Clear();
}
inline const ::Problem::ConsAtSpeed& Hardware::cons(int index) const {
  return cons_.Get(index);
}
inline ::Problem::ConsAtSpeed* Hardware::mutable_cons(int index) {
  return cons_.Mutable(index);
}
inline ::Problem::ConsAtSpeed* Hardware::add_cons() {
  return cons_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Problem::ConsAtSpeed >&
Hardware::cons() const {
  return cons_;
}
inline ::google::protobuf::RepeatedPtrField< ::Problem::ConsAtSpeed >*
Hardware::mutable_cons() {
  return &cons_;
}

// required int32 nOfResources = 4;
inline bool Hardware::has_nofresources() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Hardware::set_has_nofresources() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Hardware::clear_has_nofresources() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Hardware::clear_nofresources() {
  nofresources_ = 0;
  clear_has_nofresources();
}
inline ::google::protobuf::int32 Hardware::nofresources() const {
  return nofresources_;
}
inline void Hardware::set_nofresources(::google::protobuf::int32 value) {
  set_has_nofresources();
  nofresources_ = value;
}

// repeated int32 resources = 5;
inline int Hardware::resources_size() const {
  return resources_.size();
}
inline void Hardware::clear_resources() {
  resources_.Clear();
}
inline ::google::protobuf::int32 Hardware::resources(int index) const {
  return resources_.Get(index);
}
inline void Hardware::set_resources(int index, ::google::protobuf::int32 value) {
  resources_.Set(index, value);
}
inline void Hardware::add_resources(::google::protobuf::int32 value) {
  resources_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
Hardware::resources() const {
  return resources_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
Hardware::mutable_resources() {
  return &resources_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Problem

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_problem_2eproto__INCLUDED