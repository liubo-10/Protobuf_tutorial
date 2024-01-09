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
    cout << "optnumber: " << testnumber.optnumber() << endl; // 0













    // ===================================================================
    // 默认值测试
    // 测试函数 XXX_string()
    // ===================================================================
    cout << "----------------默认值测试------------------" << endl;
    cout << "optstring: " << teststr.optstring() << endl;
    cout << "imp_string: " << teststr.imp_string() << endl;

    // ===================================================================
    // 存储值测试 
    // 测试函数 void set_XXX_string(const std::string& value)
    //
    // 左值引用
    // int num = 10;
    // int &b = num;     // 正确
    // int &c = 10;      // 错误
    //
    // int num = 10;
    // const int &b = num;   // 正确
    // const int &c = 10;    // 正确
    // 
    // const std::string& value = left_string_opt                  变量当作左值
    // const std::string& value = "Hello World! left_string_opt2"  字符串当作左值
    // ===================================================================
    cout << "\n----------------存储值测试------------------" << endl;
    cout <<   "----------------左值引用 1------------------" << endl;
    string left_string_opt = "Hello World! left_string_opt1";
    string left_string_imp = "Hello World! left_string_imp1";

    teststr.set_optstring(left_string_opt);
    teststr.set_imp_string(left_string_imp);

    cout << "optstring: " << teststr.optstring() << endl;
    cout << "imp_string: " << teststr.imp_string() << endl;

    cout << "----------------左值引用 2------------------" << endl;
    teststr.set_optstring("Hello World! left_string_opt2");
    teststr.set_imp_string("Hello World! left_string_imp2");

    cout << "optstring: " << teststr.optstring() << endl;
    cout << "imp_string: " << teststr.imp_string() << endl;

    // ===================================================================
    // 存储值测试 
    // 测试函数 void set_XXX_string(std::string&& value)
    //
    // 右值引用 C++11及以上版本
    // int num = 10;
    // int && a = num;    // 错误，右值引用不能初始化为左值
    // int && a = 10;     // 正确
    // 
    // std::string&& value = right_string_opt      变量当作右值
    // ===================================================================
    cout << "----------------右值引用--------------------" << endl;
    string&& right_string_opt = "Hello World! right_string_opt";
    string&& right_string_imp = "Hello World! right_string_imp";

    teststr.set_optstring(right_string_opt);
    teststr.set_imp_string(right_string_imp);

    cout << "optstring: " << teststr.optstring() << endl;
    cout << "imp_string: " << teststr.imp_string() << endl;

    // ===================================================================
    // 存储值测试 
    // 测试函数 set_XXX_string(const char* value)
    // 测试函数 set_XXX_string(const char* value, size_t size)
    // ===================================================================
    cout << "----------------C类型字符串 1------------------" << endl;
    const char* char_opt = "Hello World! char_opt";
    const char* char_imp = "Hello World! char_imp";

    teststr.set_optstring(char_opt);
    teststr.set_imp_string(char_imp);

    cout << "optstring: " << teststr.optstring() << endl;
    cout << "imp_string: " << teststr.imp_string() << endl;

    cout << "----------------C类型字符串 2------------------" << endl;
    char_opt = "o23456789";
    char_imp = "i23456789";

    teststr.set_optstring(char_opt,5);
    teststr.set_imp_string(char_imp,5);

    cout << "optstring: " << teststr.optstring() << endl;
    cout << "imp_string: " << teststr.imp_string() << endl;

    // ===================================================================
    // 获取指针测试 
    // 测试函数 std::string* mutable_XXX_string()
    // ===================================================================
    cout << "\n----------------获取指针测试------------------" << endl;
    string* opt_sting_pt = teststr.mutable_optstring();
    string* imp_sting_pt = teststr.mutable_imp_string();

    cout << "opt_sting_pt: " << *opt_sting_pt << endl;
    cout << "imp_sting_pt: " << *imp_sting_pt << endl;

    // ===================================================================
    // 释放指针测试 
    // 测试函数 void release_XXX_string()
    // opt_sting_pt_mu imp_sting_pt_mu 之前保存的指针不会被释放
    // 执行release_XXX_string后XXX_sting_pt_mu XXX_sting_pt_rl与teststr.XXX_string()不再指向同一地址
    // ===================================================================
    cout << "\n----------------释放指针测试------------------" << endl;
    cout <<   "----------------释放指针------------------" << endl;

    string* opt_sting_pt_mu = teststr.mutable_optstring();
    string* imp_sting_pt_mu = teststr.mutable_imp_string();

    teststr.set_optstring("Hello World!");
    teststr.set_imp_string("Hello World!");

    string* opt_sting_pt_rl = teststr.release_optstring();
    string* imp_sting_pt_rl = teststr.release_imp_string();

    cout << "opt_sting_pt_mu: " << *opt_sting_pt_mu << endl; // Hello World!
    cout << "imp_sting_pt_mu: " << *imp_sting_pt_mu << endl; // Hello World!
    cout << "opt_sting_pt_rl: " << *opt_sting_pt_rl << endl; // Hello World!
    cout << "imp_sting_pt_rl: " << *imp_sting_pt_rl << endl; // Hello World!
    cout << "optstring: " << teststr.optstring() << endl; // 为空
    cout << "imp_string: " << teststr.imp_string() << endl; // 为空
    cout << "has_optstring: " << teststr.has_optstring() << endl; // 值为0

    cout << "----------------重新赋值------------------" << endl;
    teststr.set_optstring("Hello World! another");
    teststr.set_imp_string("Hello World! another");

    cout << "opt_sting_pt_mu: " << *opt_sting_pt_mu << endl; // Hello World!
    cout << "imp_sting_pt_mu: " << *imp_sting_pt_mu << endl; // Hello World!
    cout << "opt_sting_pt_rl: " << *opt_sting_pt_rl << endl; // Hello World!
    cout << "imp_sting_pt_rl: " << *imp_sting_pt_rl << endl; // Hello World!
    cout << "optstring: " << teststr.optstring() << endl; // Hello World! another
    cout << "imp_string: " << teststr.imp_string() << endl; // Hello World! another
    cout << "has_optstring: " << teststr.has_optstring() << endl; // 值为1

    // ===================================================================
    // 清除值测试 
    // 测试函数 void clear_XXX_string()
    // ===================================================================
    cout << "\n----------------清除值------------------" << endl;
    teststr.clear_optstring();
    teststr.clear_imp_string();

    cout << "opt_sting_pt_mu: " << *opt_sting_pt_mu << endl; // Hello World!
    cout << "imp_sting_pt_mu: " << *imp_sting_pt_mu << endl; // Hello World!
    cout << "opt_sting_pt_rl: " << *opt_sting_pt_rl << endl; // Hello World!
    cout << "imp_sting_pt_rl: " << *imp_sting_pt_rl << endl; // Hello World!
    cout << "optstring: " << teststr.optstring() << endl; // 为空
    cout << "imp_string: " << teststr.imp_string() << endl; // 为空
    cout << "has_optstring: " << teststr.has_optstring() << endl; // 值为0

    // ===================================================================
    // 判断值测试 参见以上测试
    // 测试函数 void has_optstring()
    // has_imp_string() 隐式存在没有此函数
    // ===================================================================

    return 0;
}

