#!/bin/sh

# file name:complile.sh
# data:2023.12.21

echo "---protoc begain compile---"

PROTOBUF_PATH=~/00-liubo/project_my/Protobuf_tutorial/protobuf/bin

# 在build目录下执行，这里的路径以build为当前路径
# 源文件路径 ./proto
# 目标文件路径 ./proto
$PROTOBUF_PATH/protoc  -I../proto  --cpp_out=../proto   people_info.proto

