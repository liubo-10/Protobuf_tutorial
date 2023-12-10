CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(file)

find_package(Protobuf REQUIRED)
include_directories(
    ${Protobuf_INCLUDE_DIRS}
    ${GLOB_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)

# protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS proto/pointpillars_config.proto)
# add_executable(file main.cpp ${PROTO_SRCS} file.cpp)

execute_process(COMMAND ${PROTOBUF_PROTOC_EXECUTABLE} -I=${PROJECT_SOURCE_DIR}/proto/ --cpp_out=${PROJECT_SOURCE_DIR}/  ${PROJECT_SOURCE_DIR}/proto/pointpillars_config.proto)
add_executable(file main.cpp ${PROJECT_SOURCE_DIR}/pointpillars_config.pb.cc file.cpp)

target_link_libraries(file ${Protobuf_LIBRARIES} )
