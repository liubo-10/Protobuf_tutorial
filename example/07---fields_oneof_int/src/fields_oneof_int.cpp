//！ ********************************************************************
//！ file fields_repeated_int.cpp
//！ author：liubo
//！ date：2024.01.08
//！ describe：
//！ ********************************************************************
#include <iostream>
#include <string>
#include "../build/proto/myprotobuf.pb.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "----------------begain------------------" << endl;
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    myprotobuf::MyMessage testoneof;

    // ===================================================================
    // 默认值测试
    // 测试函数 XXX_number()
    // ===================================================================
    cout << "\n----------------默认值测试------------------" << endl;
    cout << "testoneof mynumber1: " << testoneof.mynumber1() << endl;
    cout << "testoneof mynumber2: " << testoneof.mynumber2() << endl;

    // ===================================================================
    // 存储值测试 
    // 测试函数 set_XXX_number()
    // ===================================================================
    cout << "\n----------------存储值测试------------------" << endl;
    testoneof.set_mynumber1(11);

    cout << "testoneof mynumber1: " << testoneof.mynumber1() << endl;
    cout << "testoneof mynumber2: " << testoneof.mynumber2() << endl;

    testoneof.set_mynumber2(33);

    cout << "testoneof mynumber1: " << testoneof.mynumber1() << endl;
    cout << "testoneof mynumber2: " << testoneof.mynumber2() << endl;

    // ===================================================================
    // 清除值测试 
    // 测试函数 clear_XXX_number()
    // opt_number() imp_number() has_opt_number()结果都为0
    // ===================================================================
    cout << "\n----------------清除值测试------------------" << endl;
    cout <<   "----------------清除之前--------------------" << endl;

    cout << "testoneof mynumber1: " << testoneof.mynumber1() << endl;
    cout << "testoneof mynumber2: " << testoneof.mynumber2() << endl;

    testoneof.clear_mynumber1();
    testoneof.clear_mynumber2();
    
    cout << "----------------清除之后--------------------" << endl;
    cout << "testoneof mynumber1: " << testoneof.mynumber1() << endl;
    cout << "testoneof mynumber2: " << testoneof.mynumber2() << endl;

    return 0;
}
