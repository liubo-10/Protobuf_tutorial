#!/bin/sh

# complile.sh

# 源文件路径 ./proto
# 目标文件路径 ./build/proto、

# 注意路径
mkdir -p proto
#protoc  --proto_path=./proto  --cpp_out=./build/proto   ./proto/*.proto

# 注意路径
protoc  --proto_path=../proto  --cpp_out=../build/proto   ../proto/people_info.proto

