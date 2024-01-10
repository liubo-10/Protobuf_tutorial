CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

project(contacts)

message("------project:${PROJECT_NAME} complie begain------\n")

# 定义变量
# PROTOBUF_PATH：protobuf目录
set(PROJECT_MAIN_PATH   ${PROJECT_SOURCE_DIR}/..)
set(PROTOBUF_PATH       ${PROJECT_MAIN_PATH}/../../protobuf)

# 添加库
find_library(PROTOBUF_LIB protobuf HINTS  ${PROTOBUF_PATH}/lib)

# 编译protobuf
execute_process(COMMAND ${PROJECT_MAIN_PATH}/proto/complile.sh)

# include
include_directories(${PROJECT_MAIN_PATH}/build/proto
                    ${PROJECT_MAIN_PATH}/src
                    ${PROTOBUF_PATH}/include
                   )

# src源文件
aux_source_directory(${PROJECT_MAIN_PATH}/build/proto   PROTO_LIST)
aux_source_directory(${PROJECT_MAIN_PATH}/src           SRC_LIST)


# output 路径
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_MAIN_PATH}/bin)

# 可执行文件生成
add_executable(main ${SRC_LIST}  ${PROTO_LIST})

# 链接库
target_link_libraries(main ${PROTOBUF_LIB})





