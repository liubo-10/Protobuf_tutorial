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
    //! 验证我们链接的库版本是否与我们编译的头文件版本兼容。
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    myprotobuf::MyMessage testoneof;

    //！ ********************************************************************
    //！ 默认值测试
    //！ 测试函数 mynumber1()
    //！ ********************************************************************
    cout << "\n----------------默认值测试------------------" << endl;
    cout << "testoneof mynumber1: " << testoneof.mynumber1() << endl;
    cout << "testoneof mynumber2: " << testoneof.mynumber2() << endl;

    //！ ********************************************************************
    //！ 默认值测试
    //！ 测试函数 set_mynumber1()
    //！ ********************************************************************
    cout << "\n----------------存储值测试------------------" << endl;
    testoneof.set_mynumber1(11);

    cout << "testoneof mynumber1: " << testoneof.mynumber1() << endl;
    cout << "testoneof mynumber2: " << testoneof.mynumber2() << endl;

    testoneof.set_mynumber2(33);

    cout << "testoneof mynumber1: " << testoneof.mynumber1() << endl;
    cout << "testoneof mynumber2: " << testoneof.mynumber2() << endl;


    //！ ********************************************************************
    //！ 默认值测试
    //！ 测试函数 clear_mynumber1()
    //！ ********************************************************************
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
