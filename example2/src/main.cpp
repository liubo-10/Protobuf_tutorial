#include <iostream>
#include <string>
#include "config.pb.h"

#include "file.h"

bool SetProtoToASCIIFile(const google::protobuf::Message &message,
                         int file_descriptor) {
  using google::protobuf::TextFormat;
  using google::protobuf::io::FileOutputStream;
  using google::protobuf::io::ZeroCopyOutputStream;
  if (file_descriptor < 0) {
    std::cout << "Invalid file descriptor.";
    return false;
  }
  ZeroCopyOutputStream *output = new FileOutputStream(file_descriptor);
  bool success = TextFormat::Print(message, output);
  delete output;
  close(file_descriptor);
  return success;
}

bool GetProtoFromASCIIFile(const std::string& file_name,
    google::protobuf::Message* message) {
    using google::protobuf::TextFormat;
    using google::protobuf::io::FileInputStream;
    using google::protobuf::io::ZeroCopyInputStream;
    int file_descriptor = open(file_name.c_str(), O_RDONLY);
    if (file_descriptor < 0) {
        std::cout << "Failed to open file " << file_name << " in text mode.";
        // Failed to open;
        return false;
    }

    ZeroCopyInputStream* input = new FileInputStream(file_descriptor);
    bool success = TextFormat::Parse(input, message);
    if (!success) {
        std::cout << "Failed to parse file " << file_name << " as text proto.";
    }
    delete input;
    close(file_descriptor);
    return success;
}

int main(int argc, char *argv[])
{
    // 将此宏放在main函数中(使用 protobuf 库之前的某个位置), 以验证您链接的版本是否与您编译的头文件匹配。 如果检测到版本不匹配，该过程将中止
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    PointPillarsConfig config;
    std::string config_file = "../config/pointpillars.conf";
    GetProtoFromFile(config_file, &config);
    std::cout << config.pfe_file() << std::endl;

    google::protobuf::ShutdownProtobufLibrary();
}
