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

    mystring::MyString teststring;

    // 获取 opt_number()
    cout << "----------------默认值------------------" << endl;
    cout << "opt_string: " << teststring.opt_string() << endl;
    // cout << "imp_number: " << number.imp_number() << endl;

    // // 储存 set_opt_number()
    // number.set_opt_number(20);
    // number.set_imp_number(40);

    // cout << "----------------储存值------------------" << endl;
    // cout << "opt_number: " << number.opt_number() << endl;
    // cout << "imp_number: " << number.imp_number() << endl;

    // cout << "----------------判断值------------------" << endl;
    // cout << "has_opt_number: " << number.has_opt_number() << endl;
    // //cout << "has_opt_number: " << number.has_imp_number() << endl; //has_imp_number()没有此函数

    // // 清除 set_opt_number()
    // number.clear_opt_number();
    // number.clear_imp_number();

    // cout << "----------------清除值------------------" << endl;
    // cout << "opt_number: " << number.opt_number() << endl;
    // cout << "imp_number: " << number.imp_number() << endl;

    // cout << "----------------判断值------------------" << endl;
    // cout << "has_opt_number: " << number.has_opt_number() << endl;


    // // 储存 set_opt_number()
    // number.set_opt_number(0);
    // cout << "----------------设0判断值------------------" << endl;
    // cout << "has_opt_number: " << number.has_opt_number() << endl; //结果为一



    return 0;
}

