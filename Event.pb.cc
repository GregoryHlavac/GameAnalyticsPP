#include "stdafx.h"
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Event.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Event.pb.h"

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

const ::google::protobuf::Descriptor* Event_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Event_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Event_2eproto() {
  protobuf_AddDesc_Event_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Event.proto");
  GOOGLE_CHECK(file != NULL);
  Event_descriptor_ = file->message_type(0);
  static const int Event_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, user_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, session_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, build_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, event_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, area_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, x_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, y_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, z_),
  };
  Event_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Event_descriptor_,
      Event::default_instance_,
      Event_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, _unknown_fields_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, _extensions_),
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Event));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Event_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Event_descriptor_, &Event::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Event_2eproto() {
  delete Event::default_instance_;
  delete Event_reflection_;
}

void protobuf_AddDesc_Event_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013Event.proto\022\035ProtocolBuffers.GameAnaly"
    "tics\"\206\001\n\005Event\022\017\n\007user_id\030\001 \002(\t\022\022\n\nsessi"
    "on_id\030\002 \002(\t\022\r\n\005build\030\003 \002(\t\022\020\n\010event_id\030\004"
    " \001(\t\022\014\n\004area\030\005 \001(\t\022\t\n\001x\030\006 \001(\002\022\t\n\001y\030\007 \001(\002"
    "\022\t\n\001z\030\010 \001(\002*\010\0102\020\200\200\200\200\002", 181);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Event.proto", &protobuf_RegisterTypes);
  Event::default_instance_ = new Event();
  Event::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Event_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Event_2eproto {
  StaticDescriptorInitializer_Event_2eproto() {
    protobuf_AddDesc_Event_2eproto();
  }
} static_descriptor_initializer_Event_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Event::kUserIdFieldNumber;
const int Event::kSessionIdFieldNumber;
const int Event::kBuildFieldNumber;
const int Event::kEventIdFieldNumber;
const int Event::kAreaFieldNumber;
const int Event::kXFieldNumber;
const int Event::kYFieldNumber;
const int Event::kZFieldNumber;
#endif  // !_MSC_VER

Event::Event()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Event::InitAsDefaultInstance() {
}

Event::Event(const Event& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Event::SharedCtor() {
  _cached_size_ = 0;
  user_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  session_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  build_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  event_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  area_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  x_ = 0;
  y_ = 0;
  z_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Event::~Event() {
  SharedDtor();
}

void Event::SharedDtor() {
  if (user_id_ != &::google::protobuf::internal::kEmptyString) {
    delete user_id_;
  }
  if (session_id_ != &::google::protobuf::internal::kEmptyString) {
    delete session_id_;
  }
  if (build_ != &::google::protobuf::internal::kEmptyString) {
    delete build_;
  }
  if (event_id_ != &::google::protobuf::internal::kEmptyString) {
    delete event_id_;
  }
  if (area_ != &::google::protobuf::internal::kEmptyString) {
    delete area_;
  }
  if (this != default_instance_) {
  }
}

void Event::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Event::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Event_descriptor_;
}

const Event& Event::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Event_2eproto();
  return *default_instance_;
}

Event* Event::default_instance_ = NULL;

Event* Event::New() const {
  return new Event;
}

void Event::Clear() {
  _extensions_.Clear();
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_user_id()) {
      if (user_id_ != &::google::protobuf::internal::kEmptyString) {
        user_id_->clear();
      }
    }
    if (has_session_id()) {
      if (session_id_ != &::google::protobuf::internal::kEmptyString) {
        session_id_->clear();
      }
    }
    if (has_build()) {
      if (build_ != &::google::protobuf::internal::kEmptyString) {
        build_->clear();
      }
    }
    if (has_event_id()) {
      if (event_id_ != &::google::protobuf::internal::kEmptyString) {
        event_id_->clear();
      }
    }
    if (has_area()) {
      if (area_ != &::google::protobuf::internal::kEmptyString) {
        area_->clear();
      }
    }
    x_ = 0;
    y_ = 0;
    z_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Event::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string user_id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_user_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->user_id().data(), this->user_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_session_id;
        break;
      }

      // required string session_id = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_session_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_session_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->session_id().data(), this->session_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_build;
        break;
      }

      // required string build = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_build:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_build()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->build().data(), this->build().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_event_id;
        break;
      }

      // optional string event_id = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_event_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_event_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->event_id().data(), this->event_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_area;
        break;
      }

      // optional string area = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_area:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_area()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->area().data(), this->area().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(53)) goto parse_x;
        break;
      }

      // optional float x = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_x:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &x_)));
          set_has_x();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(61)) goto parse_y;
        break;
      }

      // optional float y = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_y:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &y_)));
          set_has_y();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(69)) goto parse_z;
        break;
      }

      // optional float z = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_z:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &z_)));
          set_has_z();
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
        if ((400u <= tag)) {
          DO_(_extensions_.ParseField(tag, input, default_instance_,
                                      mutable_unknown_fields()));
          continue;
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

void Event::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string user_id = 1;
  if (has_user_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->user_id().data(), this->user_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->user_id(), output);
  }

  // required string session_id = 2;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->session_id().data(), this->session_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->session_id(), output);
  }

  // required string build = 3;
  if (has_build()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->build().data(), this->build().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->build(), output);
  }

  // optional string event_id = 4;
  if (has_event_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->event_id().data(), this->event_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->event_id(), output);
  }

  // optional string area = 5;
  if (has_area()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->area().data(), this->area().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      5, this->area(), output);
  }

  // optional float x = 6;
  if (has_x()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(6, this->x(), output);
  }

  // optional float y = 7;
  if (has_y()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(7, this->y(), output);
  }

  // optional float z = 8;
  if (has_z()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(8, this->z(), output);
  }

  // Extension range [50, 536870912)
  _extensions_.SerializeWithCachedSizes(
      50, 536870912, output);

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Event::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string user_id = 1;
  if (has_user_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->user_id().data(), this->user_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->user_id(), target);
  }

  // required string session_id = 2;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->session_id().data(), this->session_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->session_id(), target);
  }

  // required string build = 3;
  if (has_build()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->build().data(), this->build().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->build(), target);
  }

  // optional string event_id = 4;
  if (has_event_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->event_id().data(), this->event_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->event_id(), target);
  }

  // optional string area = 5;
  if (has_area()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->area().data(), this->area().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->area(), target);
  }

  // optional float x = 6;
  if (has_x()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(6, this->x(), target);
  }

  // optional float y = 7;
  if (has_y()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(7, this->y(), target);
  }

  // optional float z = 8;
  if (has_z()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(8, this->z(), target);
  }

  // Extension range [50, 536870912)
  target = _extensions_.SerializeWithCachedSizesToArray(
      50, 536870912, target);

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Event::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string user_id = 1;
    if (has_user_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->user_id());
    }

    // required string session_id = 2;
    if (has_session_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->session_id());
    }

    // required string build = 3;
    if (has_build()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->build());
    }

    // optional string event_id = 4;
    if (has_event_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->event_id());
    }

    // optional string area = 5;
    if (has_area()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->area());
    }

    // optional float x = 6;
    if (has_x()) {
      total_size += 1 + 4;
    }

    // optional float y = 7;
    if (has_y()) {
      total_size += 1 + 4;
    }

    // optional float z = 8;
    if (has_z()) {
      total_size += 1 + 4;
    }

  }
  total_size += _extensions_.ByteSize();

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

void Event::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Event* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Event*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Event::MergeFrom(const Event& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_user_id()) {
      set_user_id(from.user_id());
    }
    if (from.has_session_id()) {
      set_session_id(from.session_id());
    }
    if (from.has_build()) {
      set_build(from.build());
    }
    if (from.has_event_id()) {
      set_event_id(from.event_id());
    }
    if (from.has_area()) {
      set_area(from.area());
    }
    if (from.has_x()) {
      set_x(from.x());
    }
    if (from.has_y()) {
      set_y(from.y());
    }
    if (from.has_z()) {
      set_z(from.z());
    }
  }
  _extensions_.MergeFrom(from._extensions_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Event::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Event::CopyFrom(const Event& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Event::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;


  if (!_extensions_.IsInitialized()) return false;  return true;
}

void Event::Swap(Event* other) {
  if (other != this) {
    std::swap(user_id_, other->user_id_);
    std::swap(session_id_, other->session_id_);
    std::swap(build_, other->build_);
    std::swap(event_id_, other->event_id_);
    std::swap(area_, other->area_);
    std::swap(x_, other->x_);
    std::swap(y_, other->y_);
    std::swap(z_, other->z_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
    _extensions_.Swap(&other->_extensions_);
  }
}

::google::protobuf::Metadata Event::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Event_descriptor_;
  metadata.reflection = Event_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace GameAnalytics
}  // namespace ProtocolBuffers

// @@protoc_insertion_point(global_scope)
