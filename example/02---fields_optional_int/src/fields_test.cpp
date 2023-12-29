#include <iostream>
#include <string>
#include "../build/proto/mynumber.pb.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    mynumber::MyNumber testnumber;

    // 获取 XXX_number()
    cout << "----------------默认值------------------" << endl;
    cout << "opt_number: " << testnumber.opt_number() << endl;
    cout << "imp_number: " << testnumber.imp_number() << endl;

    // 储存 set_XXX_number()
    testnumber.set_opt_number(20);
    testnumber.set_imp_number(40);

    cout << "----------------储存值------------------" << endl;
    cout << "opt_number: " << testnumber.opt_number() << endl;
    cout << "imp_number: " << testnumber.imp_number() << endl;

    cout << "----------------设值判断------------------" << endl;
    cout << "has_opt_number: " << testnumber.has_opt_number() << endl;
    //cout << "has_opt_number: " << testnumber.has_imp_number() << endl; //has_imp_number()没有此函数

    // 清除 clear_XXX_number()
    testnumber.clear_opt_number();
    testnumber.clear_imp_number();

    cout << "----------------清除值------------------" << endl;
    cout << "opt_number: " << testnumber.opt_number() << endl;
    cout << "imp_number: " << testnumber.imp_number() << endl;

    cout << "----------------设值判断------------------" << endl;
    cout << "has_opt_number: " << testnumber.has_opt_number() << endl;

    // test
    // 设0判断值
    testnumber.set_opt_number(0);
    cout << "----------------设0判断------------------" << endl;
    cout << "has_opt_number: " << testnumber.has_opt_number() << endl; //结果为1




    

    return 0;
}

