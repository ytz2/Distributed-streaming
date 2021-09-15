//
// Created by Yanhua Liu on 9/14/21.
//

#ifndef DISTRIBUTED_STREAMING_CODEC_H
#define DISTRIBUTED_STREAMING_CODEC_H
#include "interface/message.h"
#include <unordered_map>
#include <memory>

namespace lib {
namespace kafka {

enum KAFKA_CODEC_TYPE {
  FLAT,    // STRING BODY , eg. for json, text etc
  STREAM,  // protocol id | msg id| msg body
  NONE
};

class MessageCodec {
 public:
  explicit MessageCodec(const std::string &protocol) : protocol_(protocol) {}
  virtual ~MessageCodec() = default;
  virtual interface::IMessagePtr deserialize(const std::string &string) = 0;
  virtual bool serialize(interface::IMessagePtr, std::string &buffer) = 0;
 protected:
  std::string protocol_;
};

typedef std::shared_ptr<MessageCodec> MessageCodecPtr;

class FlatMessageCodec : public MessageCodec {
 public:
  explicit FlatMessageCodec(const std::string &protocol)
      : MessageCodec(protocol) {
  }
  virtual ~FlatMessageCodec() = default;
  virtual interface::IMessagePtr deserialize(const std::string &string) override;
  virtual bool serialize(interface::IMessagePtr, std::string &buffer) override;
};

class CodecFactory {
 public:
  static MessageCodecPtr createCodec(const std::string &protocol) {
    if (protocol == "CommonJson")
      return std::make_shared<FlatMessageCodec>(protocol); // only support json now
    return nullptr;
  }
};
}
}

#endif //DISTRIBUTED_STREAMING_CODEC_H