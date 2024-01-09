//！ ********************************************************************
//！ file name： fields_optional_enum.cpp
//！ author：    liubo
//！ date：      2024.01.06
//！ describe：  测试protobuf类型optional enum 
//！             implicit enum 类型用法基本与 optional enum 一样只是少了has_XXX函数
//！ ********************************************************************

#include <iostream>
#include <string>
#include "../build/proto/myprotobuf.pb.h"

using std::cout;
using std::endl;
using std::string;
using myprotobuf::case0;
using myprotobuf::case1;
using myprotobuf::case2;

int main() {
    cout << "----------------begain------------------" << endl;
    //! 验证我们链接的库版本是否与我们编译的头文件版本兼容。
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    myprotobuf::MyCase testcase;

    //！ ********************************************************************
    //！ 默认值测试
    //！ 测试函数 optenum()
    //！ ********************************************************************
    cout << "\n----------------默认值测试------------------" << endl;
    cout << "optenum: " << testcase.optenum() << endl;

    //！ ********************************************************************
    //！ 存储值测试
    //！ 测试函数 set_optenum()
    //！ ********************************************************************
    cout << "\n----------------存储值测试------------------" << endl;

    testcase.set_optenum(case0);
    cout << "optenum: " << testcase.optenum() << endl;

    testcase.set_optenum(case1);
    cout << "optenum: " << testcase.optenum() << endl;


    //！ ********************************************************************
    //！ 清除值测试
    //！ 测试函数 clear_optenum()
    //！ optenum() has_optenum()结果都为0
    //！ ********************************************************************
    cout << "\n----------------清除值测试------------------" << endl;
    cout <<   "----------------清除之前--------------------" << endl;
    cout << "optenum: " << testcase.optenum() << endl;
    cout << "has_optenum: " << testcase.has_optenum() << endl;

    testcase.clear_optenum();

    cout << "----------------清除之后--------------------" << endl;
    cout << "optenum: " << testcase.optenum() << endl;
    cout << "has_optenum: " << testcase.has_optenum() << endl;

    return 0;
}

