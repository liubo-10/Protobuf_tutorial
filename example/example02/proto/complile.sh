#!/bin/sh

# complile.sh

# 源文件路径 ./proto
# 目标文件路径 ./build/proto、

# 注意路径
# mkdir -p proto
# protoc  --proto_path=./proto  --cpp_out=./build/proto   ./proto/*.proto

# 注意路径
echo "---proto---"


PROTOBUF_PATH=~/00-liubo/project_my/Protobuf_tutorial/protobuf/bin


$PROTOBUF_PATH/protoc --experimental_allow_proto3_optional --proto_path=../proto  --cpp_out=../proto   ../proto/addressbook.proto


