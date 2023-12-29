#include <iostream>
#include <string>
#include "../build/proto/mybytes.pb.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    mybytes::MyBytes test_string;

    // ===================================================================
    // 默认值测试
    // 测试函数 XXX_string()
    // ===================================================================
    cout << "----------------默认值测试------------------" << endl;
    cout << "opt_string: " << test_string.opt_string() << endl;
    cout << "imp_string: " << test_string.imp_string() << endl;

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

    test_string.set_opt_string(left_string_opt);
    test_string.set_imp_string(left_string_imp);

    cout << "opt_string: " << test_string.opt_string() << endl;
    cout << "imp_string: " << test_string.imp_string() << endl;

    cout << "----------------左值引用 2------------------" << endl;
    test_string.set_opt_string("Hello World! left_string_opt2");
    test_string.set_imp_string("Hello World! left_string_imp2");

    cout << "opt_string: " << test_string.opt_string() << endl;
    cout << "imp_string: " << test_string.imp_string() << endl;

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

    test_string.set_opt_string(right_string_opt);
    test_string.set_imp_string(right_string_imp);

    cout << "opt_string: " << test_string.opt_string() << endl;
    cout << "imp_string: " << test_string.imp_string() << endl;

    // ===================================================================
    // 存储值测试 
    // 测试函数 set_XXX_string(const char* value)
    // 测试函数 set_XXX_string(const char* value, size_t size)
    // ===================================================================
    cout << "----------------C类型字符串 1------------------" << endl;
    const char* char_opt = "Hello World! char_opt";
    const char* char_imp = "Hello World! char_imp";

    test_string.set_opt_string(char_opt);
    test_string.set_imp_string(char_imp);

    cout << "opt_string: " << test_string.opt_string() << endl;
    cout << "imp_string: " << test_string.imp_string() << endl;

    cout << "----------------C类型字符串 2------------------" << endl;
    char_opt = "o23456789";
    char_imp = "i23456789";

    test_string.set_opt_string(char_opt,5);
    test_string.set_imp_string(char_imp,5);

    cout << "opt_string: " << test_string.opt_string() << endl;
    cout << "imp_string: " << test_string.imp_string() << endl;

    // ===================================================================
    // 获取指针测试 
    // 测试函数 std::string* mutable_XXX_string()
    // ===================================================================
    cout << "\n----------------获取指针测试------------------" << endl;
    string* opt_sting_pt = test_string.mutable_opt_string();
    string* imp_sting_pt = test_string.mutable_imp_string();

    cout << "opt_sting_pt: " << *opt_sting_pt << endl;
    cout << "imp_sting_pt: " << *imp_sting_pt << endl;

    // ===================================================================
    // 释放指针测试 
    // 测试函数 void release_XXX_string()
    // opt_sting_pt_mu imp_sting_pt_mu 之前保存的指针不会被释放
    // 执行release_XXX_string后XXX_sting_pt_mu XXX_sting_pt_rl与test_string.XXX_string()不再指向同一地址
    // ===================================================================
    cout << "\n----------------释放指针测试------------------" << endl;
    cout <<   "----------------释放指针------------------" << endl;

    string* opt_sting_pt_mu = test_string.mutable_opt_string();
    string* imp_sting_pt_mu = test_string.mutable_imp_string();

    test_string.set_opt_string("Hello World!");
    test_string.set_imp_string("Hello World!");

    string* opt_sting_pt_rl = test_string.release_opt_string();
    string* imp_sting_pt_rl = test_string.release_imp_string();

    cout << "opt_sting_pt_mu: " << *opt_sting_pt_mu << endl; // Hello World!
    cout << "imp_sting_pt_mu: " << *imp_sting_pt_mu << endl; // Hello World!
    cout << "opt_sting_pt_rl: " << *opt_sting_pt_rl << endl; // Hello World!
    cout << "imp_sting_pt_rl: " << *imp_sting_pt_rl << endl; // Hello World!
    cout << "opt_string: " << test_string.opt_string() << endl; // 为空
    cout << "imp_string: " << test_string.imp_string() << endl; // 为空
    cout << "has_opt_string: " << test_string.has_opt_string() << endl; // 值为0

    cout << "----------------重新赋值------------------" << endl;
    test_string.set_opt_string("Hello World! another");
    test_string.set_imp_string("Hello World! another");

    cout << "opt_sting_pt_mu: " << *opt_sting_pt_mu << endl; // Hello World!
    cout << "imp_sting_pt_mu: " << *imp_sting_pt_mu << endl; // Hello World!
    cout << "opt_sting_pt_rl: " << *opt_sting_pt_rl << endl; // Hello World!
    cout << "imp_sting_pt_rl: " << *imp_sting_pt_rl << endl; // Hello World!
    cout << "opt_string: " << test_string.opt_string() << endl; // Hello World! another
    cout << "imp_string: " << test_string.imp_string() << endl; // Hello World! another
    cout << "has_opt_string: " << test_string.has_opt_string() << endl; // 值为1

    // ===================================================================
    // 清除值测试 
    // 测试函数 void clear_XXX_string()
    // ===================================================================
    cout << "\n----------------清除值------------------" << endl;
    test_string.clear_opt_string();
    test_string.clear_imp_string();

    cout << "opt_sting_pt_mu: " << *opt_sting_pt_mu << endl; // Hello World!
    cout << "imp_sting_pt_mu: " << *imp_sting_pt_mu << endl; // Hello World!
    cout << "opt_sting_pt_rl: " << *opt_sting_pt_rl << endl; // Hello World!
    cout << "imp_sting_pt_rl: " << *imp_sting_pt_rl << endl; // Hello World!
    cout << "opt_string: " << test_string.opt_string() << endl; // 为空
    cout << "imp_string: " << test_string.imp_string() << endl; // 为空
    cout << "has_opt_string: " << test_string.has_opt_string() << endl; // 值为0

    // ===================================================================
    // 判断值测试 参见以上测试
    // 测试函数 void has_opt_string()
    // has_imp_string() 隐式存在没有此函数
    // ===================================================================

    return 0;
}

