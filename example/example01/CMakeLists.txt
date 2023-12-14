cmake_minimum_required (VERSION 2.8)

project (demo)


# \e[1 是标准格式，代表颜色输出开始，\e[0m 代表颜色输出结束

# execute_process(COMMAND echo -e "\e[1;35m ------complie begain------\e[0m \n")
execute_process(COMMAND echo -e "------project:${PROJECT_NAME} complie begain------\n")
# 注意路径
execute_process(COMMAND ../complile.sh)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)



# add_executable(main main.c)
