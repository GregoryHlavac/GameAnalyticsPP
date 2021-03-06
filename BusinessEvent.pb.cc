#include "stdafx.h"
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BusinessEvent.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "BusinessEvent.pb.h"

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

namespace ProtocolBuffers {
namespace GameAnalytics {

namespace {

const ::google::protobuf::Descriptor* BusinessEvent_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BusinessEvent_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_BusinessEvent_2eproto() {
  protobuf_AddDesc_BusinessEvent_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "BusinessEvent.proto");
  GOOGLE_CHECK(file != NULL);
  BusinessEvent_descriptor_ = file->message_type(0);
  static const int BusinessEvent_offsets_[1] = {
  };
  BusinessEvent_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BusinessEvent_descriptor_,
      BusinessEvent::default_instance_,
      BusinessEvent_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BusinessEvent, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BusinessEvent, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BusinessEvent));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_BusinessEvent_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BusinessEvent_descriptor_, &BusinessEvent::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_BusinessEvent_2eproto() {
  delete BusinessEvent::default_instance_;
  delete BusinessEvent_reflection_;
}

void protobuf_AddDesc_BusinessEvent_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::ProtocolBuffers::GameAnalytics::protobuf_AddDesc_Event_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023BusinessEvent.proto\022\035ProtocolBuffers.G"
    "ameAnalytics\032\013Event.proto\"\177\n\rBusinessEve"
    "nt27\n\010currency\022$.ProtocolBuffers.GameAna"
    "lytics.Event\030\310\001 \001(\t25\n\006amount\022$.Protocol"
    "Buffers.GameAnalytics.Event\030\311\001 \001(\005", 194);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "BusinessEvent.proto", &protobuf_RegisterTypes);
  BusinessEvent::default_instance_ = new BusinessEvent();
  BusinessEvent::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::ExtensionSet::RegisterExtension(
    &::ProtocolBuffers::GameAnalytics::Event::default_instance(),
    200, 9, false, false);
  ::google::protobuf::internal::ExtensionSet::RegisterExtension(
    &::ProtocolBuffers::GameAnalytics::Event::default_instance(),
    201, 5, false, false);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_BusinessEvent_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_BusinessEvent_2eproto {
  StaticDescriptorInitializer_BusinessEvent_2eproto() {
    protobuf_AddDesc_BusinessEvent_2eproto();
  }
} static_descriptor_initializer_BusinessEvent_2eproto_;

// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

const ::std::string BusinessEvent_currency_default("");
#ifndef _MSC_VER
const int BusinessEvent::kCurrencyFieldNumber;
#endif
::google::protobuf::internal::ExtensionIdentifier< ::ProtocolBuffers::GameAnalytics::Event,
    ::google::protobuf::internal::StringTypeTraits, 9, false >
  BusinessEvent::currency(kCurrencyFieldNumber, BusinessEvent_currency_default);
#ifndef _MSC_VER
const int BusinessEvent::kAmountFieldNumber;
#endif
::google::protobuf::internal::ExtensionIdentifier< ::ProtocolBuffers::GameAnalytics::Event,
    ::google::protobuf::internal::PrimitiveTypeTraits< ::google::protobuf::int32 >, 5, false >
  BusinessEvent::amount(kAmountFieldNumber, 0);
BusinessEvent::BusinessEvent()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void BusinessEvent::InitAsDefaultInstance() {
}

BusinessEvent::BusinessEvent(const BusinessEvent& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void BusinessEvent::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BusinessEvent::~BusinessEvent() {
  SharedDtor();
}

void BusinessEvent::SharedDtor() {
  if (this != default_instance_) {
  }
}

void BusinessEvent::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BusinessEvent::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BusinessEvent_descriptor_;
}

const BusinessEvent& BusinessEvent::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_BusinessEvent_2eproto();
  return *default_instance_;
}

BusinessEvent* BusinessEvent::default_instance_ = NULL;

BusinessEvent* BusinessEvent::New() const {
  return new BusinessEvent;
}

void BusinessEvent::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BusinessEvent::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      return true;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
  return true;
#undef DO_
}

void BusinessEvent::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* BusinessEvent::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int BusinessEvent::ByteSize() const {
  int total_size = 0;

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

void BusinessEvent::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BusinessEvent* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BusinessEvent*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BusinessEvent::MergeFrom(const BusinessEvent& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BusinessEvent::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BusinessEvent::CopyFrom(const BusinessEvent& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BusinessEvent::IsInitialized() const {

  return true;
}

void BusinessEvent::Swap(BusinessEvent* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BusinessEvent::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BusinessEvent_descriptor_;
  metadata.reflection = BusinessEvent_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace GameAnalytics
}  // namespace ProtocolBuffers

// @@protoc_insertion_point(global_scope)
