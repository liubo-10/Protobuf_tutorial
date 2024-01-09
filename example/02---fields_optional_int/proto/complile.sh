#!/bin/sh

# complile.sh

# 源文件路径 ./proto
# 目标文件路径 ./build/proto、

# 注意路径
# mkdir -p proto
# protoc  --proto_path=./proto  --cpp_out=./build/proto   ./proto/*.proto

# 注意路径
echo "------------proto-------------"

mkdir -p ../build/proto

# 定义变量
PROTOBUF_PATH=~/00-liubo/project_my/Protobuf_tutorial/protobuf/bin
option=--experimental_allow_proto3_optional

# 在build目录下执行，这里的路径以build为当前路径
# -I 同义于 --proto_path=
# 源文件路径   ../proto
# 目标文件路径 ../build/proto
$PROTOBUF_PATH/protoc $option -I../proto --cpp_out=../build/proto ../proto/*.proto
