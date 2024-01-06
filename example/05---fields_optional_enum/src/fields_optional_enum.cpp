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
    testcase.set_opt_enum(0);
    testcase.set_imp_enum(0);

    cout << "opt_enum: " << testcase.opt_enum() << endl;
    cout << "imp_enum: " << testcase.imp_enum() << endl;

    testcase.set_opt_enum(1);
    testcase.set_imp_enum(1);

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

    // ===================================================================
    // 有无赋值测试 
    // 测试函数 has_opt_enum()
    // has_imp_enum()隐式类型没有此函数
    // set_opt_enum(0),赋值与默认值相同，has_opt_enum()结果为1
    // ===================================================================
    cout << "\n----------------有无赋值测试------------------" << endl;

    testcase.set_opt_enum(1);
    cout << "------------------清除之前--------------------" << endl;
    cout << "has_opt_enum: " << testcase.has_opt_enum() << endl;

    testcase.clear_opt_enum();

    cout << "----------------清除之后--------------------" << endl;
    cout << "has_opt_enum: " << testcase.has_opt_enum() << endl;

    testcase.set_opt_enum(0);

    cout << "----------------设0后判断有无赋值------------------" << endl;
    cout << "has_opt_enum: " << testcase.has_opt_enum() << endl;

    cout << "\n----------------end------------------" << endl;
    return 0;
}

