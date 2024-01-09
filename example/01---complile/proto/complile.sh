#!/bin/sh

# file name:complile.sh
# data:2023.12.21

echo "---------------protoc begain compile---------------"

mkdir -p ../build/proto

# 定义变量
PROTOBUF_PATH=~/00-liubo/project_my/Protobuf_tutorial/protobuf/bin
option=--experimental_allow_proto3_optional


# 在build目录下执行，这里的路径以build为当前路径
# 源文件路径   ../proto
# 目标文件路径 ../build/proto
$PROTOBUF_PATH/protoc  -I../proto  --cpp_out=../build/proto ../proto/*.proto
