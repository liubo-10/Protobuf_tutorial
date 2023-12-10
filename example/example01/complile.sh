#!/bin/sh

# 源文件路径 ./proto
# 目标文件路径 ./build/proto


#protoc  --proto_path=./proto  --cpp_out=./build/proto   ./proto/*.proto
protoc  --proto_path=./proto  --cpp_out=./build/proto   people_info.proto

