// *********************************************************
// file name：fields_optional_enum.cpp
// author：liubo
// date：2024.01.05
// describe：
// *********************************************************
#include <iostream>
#include <string>
#include "../build/proto/myenum.pb.h"

using std::cout;
using std::endl;
using std::string;
using myenum::case0;
using myenum::case1;
using myenum::case2;

int main() {
    cout << "----------------begain------------------" << endl;
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    myenum::MyCase testcase;

    // ===================================================================
    // 默认值测试
    // 测试函数 XXX_number()
    // ===================================================================
    cout << "\n----------------默认值测试------------------" << endl;
    cout << "opt_enum: " << testcase.opt_enum() << endl;
    cout << "imp_enum: " << testcase.imp_enum() << endl;

    // ===================================================================
    // 存储值测试 
    // 测试函数 set_XXX_number()
    // ===================================================================
    cout << "\n----------------存储值测试------------------" << endl;
    testcase.set_opt_enum(case0);
    testcase.set_imp_enum(case0);

    cout << "opt_enum: " << testcase.opt_enum() << endl;
    cout << "imp_enum: " << testcase.imp_enum() << endl;

    testcase.set_opt_enum(case1);
    testcase.set_imp_enum(case1);

    cout << "opt_enum: " << testcase.opt_enum() << endl;
    cout << "imp_enum: " << testcase.imp_enum() << endl;

    // ===================================================================
    // 清除值测试 
    // 测试函数 clear_XXX_number()
    // opt_enum() imp_enum() has_opt_enum()结果都为0
    // ===================================================================
    cout << "\n----------------清除值测试------------------" << endl;
    cout <<   "----------------清除之前--------------------" << endl;
    cout << "opt_enum: " << testcase.opt_enum() << endl;
    cout << "imp_enum: " << testcase.imp_enum() << endl;
    cout << "has_opt_enum: " << testcase.has_opt_enum() << endl;

    testcase.clear_opt_enum();
    testcase.clear_imp_enum();
    
    cout << "----------------清除之后--------------------" << endl;
    cout << "opt_enum: " << testcase.opt_enum() << endl;
    cout << "imp_enum: " << testcase.imp_enum() << endl;
    cout << "has_opt_enum: " << testcase.has_opt_enum() << endl;

    return 0;
}

