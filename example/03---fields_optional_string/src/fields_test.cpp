#include <iostream>
#include <string>
#include "../build/proto/mystring.pb.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    mystring::MyString test_string;

    // 获取 XXX_number()
    cout << "----------------默认值------------------" << endl;
    cout << "opt_string: " << test_string.opt_string() << endl;
    cout << "imp_string: " << test_string.imp_string() << endl;


    // 左值引用
    // int num = 10;
    // int &b = num;     // 正确
    // int &c = 10;      // 错误
 
    // int num = 10;
    // const int &b = num;   // 正确
    // const int &c = 10;    // 正确

    // 储存 void set_XXX_string(const std::string& value);
    cout << "\n----------------储存值 左值引用 1------------------" << endl;
    string left_string_value1 = "Hello World! &1";
    string left_string_value2 = "Hello World! &2";

    test_string.set_opt_string(left_string_value1); //const std::string& value = string_value1
    test_string.set_imp_string(left_string_value2);

    cout << "opt_string: " << test_string.opt_string() << endl;
    cout << "imp_string: " << test_string.imp_string() << endl;

    cout << "\n----------------储存值 左值引用 2------------------" << endl;
    test_string.set_opt_string("Hello World! c1"); //const std::string& value = "Hello World! c1"
    test_string.set_imp_string("Hello World! c2");

    cout << "opt_string: " << test_string.opt_string() << endl;
    cout << "imp_string: " << test_string.imp_string() << endl;


    // 右值引用
    // int num = 10;
    // int && a = num;    // 错误，右值引用不能初始化为左值
    // int && a = 10;       // 正确

    // 储存 void set_XXX_string(std::string&& value);
    cout << "\n----------------储存值 右值引用------------------" << endl;
    string&& right_string_value1 = "Hello World! &&1";
    string&& right_string_value2 = "Hello World! &&2";

    test_string.set_opt_string(right_string_value1); //std::string&& value = right_string_value1
    test_string.set_imp_string(right_string_value2);

    cout << "opt_string: " << test_string.opt_string() << endl;
    cout << "imp_string: " << test_string.imp_string() << endl;


    // void set_XXX_string(const char* value);
    cout << "\n----------------储存值 C类型字符串 1------------------" << endl;
    const char* char_value1 = "Hello World! char 1";
    const char* char_value2 = "Hello World! char 2";

    test_string.set_opt_string(char_value1);
    test_string.set_imp_string(char_value2);

    cout << "opt_string: " << test_string.opt_string() << endl;
    cout << "imp_string: " << test_string.imp_string() << endl;

    // void set_XXX_string(const char* value, size_t size);
    cout << "\n----------------储存值 C类型字符串 2------------------" << endl;

    char_value1 = "o23456789";
    char_value2 = "i23456789";

    test_string.set_opt_string(char_value1,5);
    test_string.set_imp_string(char_value2,5);

    cout << "opt_string: " << test_string.opt_string() << endl;
    cout << "imp_string: " << test_string.imp_string() << endl;


    // std::string* mutable_XXX_string();
    cout << "\n----------------获取指针------------------" << endl;
    string* opt_sting_pt = test_string.mutable_opt_string();
    string* imp_sting_pt = test_string.mutable_imp_string();

    cout << "opt_sting_pt: " << *opt_sting_pt << endl;
    cout << "imp_sting_pt: " << *imp_sting_pt << endl;


    // void release_XXX_string();
    cout << "\n----------------释放指针------------------" << endl;
    string* opt_sting_pt1 = test_string.release_opt_string();
    string* imp_sting_pt1 = test_string.release_imp_string();

    cout << "opt_sting_pt1: " << *opt_sting_pt1 << endl;
    cout << "imp_sting_pt1: " << *imp_sting_pt1 << endl;
    cout << "opt_sting_pt: " << *opt_sting_pt << endl; // 不为空
    cout << "imp_sting_pt: " << *imp_sting_pt << endl; // 不为空
    cout << "opt_string: " << test_string.opt_string() << endl; // 为空
    cout << "imp_string: " << test_string.imp_string() << endl; // 为空
    cout << "has_opt_string: " << test_string.has_opt_string() << endl; //为0

    cout << "\n----------------重新赋值------------------" << endl;
    test_string.set_opt_string("Hello World! c1");
    test_string.set_imp_string("Hello World! c2");
    cout << "opt_sting_pt: " << *opt_sting_pt << endl; //opt_sting_pt: o2345
    cout << "imp_sting_pt: " << *imp_sting_pt << endl; //imp_sting_pt: i2345
    cout << "opt_string: " << test_string.opt_string() << endl; //opt_string: Hello World! c1
    cout << "imp_string: " << test_string.imp_string() << endl; //imp_string: Hello World! c2
    cout << "has_opt_string: " << test_string.has_opt_string() << endl;
    //cout << "has_opt_string: " << test_string.has_imp_string() << endl; //has_imp_number()没有此函数

    // void clear_XXX_string();
    cout << "\n----------------清除值------------------" << endl;
    test_string.clear_opt_string();
    test_string.clear_imp_string();

    cout << "opt_string: " << test_string.opt_string() << endl;
    cout << "imp_string: " << test_string.imp_string() << endl;

    cout << "\n----------------判断值------------------" << endl;
    cout << "has_opt_string: " << test_string.has_opt_string() << endl;
    //cout << "has_opt_number: " << number.has_imp_number() << endl; //has_imp_number()没有此函数

    return 0;
}

