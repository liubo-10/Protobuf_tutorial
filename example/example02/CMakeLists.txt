cmake_minimum_required (VERSION 2.8)

project (demo)

execute_process(COMMAND echo -e "------project:${PROJECT_NAME} complie begain------\n")
message("------project:${PROJECT_NAME} complie begain------\n")



set(PROTOBUF_PATH    ${PROJECT_SOURCE_DIR}/../../protobuf)






# 添加库
find_library(PROTOBUF_LIB protobuf HINTS ${PROJECT_SOURCE_DIR}/../lib)


# 编译protobuf
execute_process(COMMAND ${PROJECT_SOURCE_DIR}/proto/complile.sh)

# include
include_directories(${PROJECT_SOURCE_DIR}/proto
                    ${PROJECT_SOURCE_DIR}/src
                    ${PROJECT_SOURCE_DIR}/../include
                   )

# src
aux_source_directory(${PROJECT_SOURCE_DIR}/proto   PROTO_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/src     SRC_LIST)


# output 路径
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 生成可执行文件
add_executable(main ${SRC_LIST}  ${PROTO_LIST})


target_link_libraries (main ${PROTOBUF_LIB})

