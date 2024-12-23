#!/bin/sh

# file name:complile.sh
# author:liubo
# data:2023.12.21

echo "---------------protoc begain compile---------------"

mkdir -p ../build/proto

# define parameter
option=--experimental_allow_proto3_optional

# 注意路径，在build目录或proto目录下执行，这里的路径以build为当前路径
# -I 同义于 --proto_path=
# 源文件路径   ../proto
# 目标文件路径 ../build/proto
protoc $option -I../proto --cpp_out=../build/proto ../proto/*.proto
