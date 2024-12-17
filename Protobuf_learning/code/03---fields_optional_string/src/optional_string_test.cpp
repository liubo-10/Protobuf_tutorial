//！ ********************************************************************
//！ file optional_string_test.cpp
//！ author：liubo
//！ date：2024.01.09
//！ describe：测试protobuf类型optional string 
//！           implicit string 类型用法基本与optional string一样只是少了has_XXX函数
//！           bytes类型与string 类型用法一样
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

    myprotobuf::MyMessage teststr;

    //！ ********************************************************************
    //！ 默认值测试
    //！ 测试函数 optstring()
    //！ ********************************************************************
    cout << "\n----------------默认值测试------------------" << endl;
    cout << "optstring: " << teststr.optstring() << endl;

    //！ ********************************************************************
    //！ 存储值测试
    //！ 测试函数 void set_optstring(const std::string& value)
    //！ 
    //！ const std::string& value = left_string_opt             变量当作左值
    //！ const std::string& value = "Hello World! left_value2"  字符串当作左值
    //！ ********************************************************************
    cout << "\n----------------存储值测试------------------" << endl;
    cout <<   "----------------左值引用 1------------------" << endl;
    string left_value = "Hello World! left_value1";
    teststr.set_optstring(left_value);
    cout << "optstring: " << teststr.optstring() << endl;

    cout << "----------------左值引用 2------------------" << endl;
    teststr.set_optstring("Hello World! left_value2");
    cout << "optstring: " << teststr.optstring() << endl;

    //！ ********************************************************************
    //！ 存储值测试
    //！ 测试函数 void set_optstring(std::string&& value)
    //！ 右值引用 C++11及以上版本
    //！ std::string&& value = right_string_opt      变量当作右
    //！ ********************************************************************
    cout << "----------------右值引用--------------------" << endl;
    string&& right_value = "Hello World! right_value";
    teststr.set_optstring(right_value);
    cout << "optstring: " << teststr.optstring() << endl;

    //！ ********************************************************************
    //！ 存储值测试
    //！ 测试函数 set_optstring(const char* value)
    //！ 测试函数 set_optstring(const char* value, size_t size)
    //！ ********************************************************************
    cout << "----------------C类型字符串 1------------------" << endl;
    const char* char1 = "Hello World! char1";
    teststr.set_optstring(char1);
    cout << "optstring: " << teststr.optstring() << endl;

    cout << "----------------C类型字符串 2------------------" << endl;
    char1 = "123456789";
    teststr.set_optstring(char1,5);
    cout << "optstring: " << teststr.optstring() << endl;

    //！ ********************************************************************
    //！ 获取指针测试
    //！ 测试函数 std::string* mutable_optstring()
    //！ sting_pt 与 teststr.optstring()指向同一地址
    //！ ********************************************************************
    cout << "\n----------------获取指针测试------------------" << endl;
    teststr.set_optstring("Hello World!");
    string* sting_pt = teststr.mutable_optstring();
    cout << "sting_pt: " << *sting_pt << endl;

    teststr.set_optstring("Hello World! update");
    cout << "sting_pt: " << *sting_pt << endl;

    //！ ********************************************************************
    //！ 释放指针测试
    //！ 测试函数 void release_XXX_string()
    //！ sting_pt_mu 之前保存的指针不会被释放
    //！ 执行 release_optstring 后 sting_pt_mu sting_pt_rl与teststr.optstring()不再指向同一地址
    //！ ********************************************************************
    cout << "\n----------------释放指针测试------------------" << endl;
    cout <<   "----------------释放指针------------------" << endl;
    
    teststr.set_optstring("Hello World!");
    string* sting_pt_mu = teststr.mutable_optstring();
    string* sting_pt_rl = teststr.release_optstring();

    cout << "sting_pt_mu: " << *sting_pt_mu << endl; // Hello World!
    cout << "sting_pt_rl: " << *sting_pt_rl << endl; // Hello World!
    cout << "optstring: " << teststr.optstring() << endl; // 为空
    cout << "has_optstring: " << teststr.has_optstring() << endl; // 值为0

    cout << "----------------重新赋值------------------" << endl;
    teststr.set_optstring("Hello World! update");
    cout << "opt_sting_pt_mu: " << *sting_pt_mu << endl; // Hello World!
    cout << "opt_sting_pt_rl: " << *sting_pt_rl << endl; // Hello World!
    cout << "optstring: " << teststr.optstring() << endl; // Hello World! update
    cout << "has_optstring: " << teststr.has_optstring() << endl; // 值为1

    //！ ********************************************************************
    //！ 清除值测试
    //！ 测试函数 void clear_optstring()
    //！ ********************************************************************
    cout << "\n----------------清除值------------------" << endl;
    teststr.clear_optstring();

    cout << "sting_pt_mu: " << *sting_pt_mu << endl; // Hello World!
    cout << "sting_pt_rl: " << *sting_pt_rl << endl; // Hello World!
    cout << "optstring: " << teststr.optstring() << endl; // 为空
    cout << "has_optstring: " << teststr.has_optstring() << endl; // 值为0

    // ===================================================================
    // 判断值测试 参见以上测试
    // 测试函数 void has_optstring()
    // has_impstring() 隐式存在没有此函数
    // ===================================================================

    return 0;
}

