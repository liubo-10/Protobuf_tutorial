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

    // ===================================================================
    // 默认值测试
    // 测试函数 XXX_number()
    // ===================================================================
    cout << "\n----------------默认值测试------------------" << endl;
    cout << "opt_number: " << testnumber.opt_number() << endl;
    cout << "imp_number: " << testnumber.imp_number() << endl;

    // ===================================================================
    // 存储值测试 
    // 测试函数 set_XXX_number()
    // ===================================================================
    cout << "\n----------------存储值测试------------------" << endl;
    testnumber.set_opt_number(11);
    testnumber.set_imp_number(22);

    cout << "opt_number: " << testnumber.opt_number() << endl;
    cout << "imp_number: " << testnumber.imp_number() << endl;

    testnumber.set_opt_number(33);
    testnumber.set_imp_number(44);

    cout << "opt_number: " << testnumber.opt_number() << endl;
    cout << "imp_number: " << testnumber.imp_number() << endl;

    // ===================================================================
    // 清除值测试 
    // 测试函数 clear_XXX_number()
    // opt_number() imp_number() has_opt_number()结果都为0
    // ===================================================================
    cout << "\n----------------清除值测试------------------" << endl;
    cout << "------------------清除之前--------------------" << endl;
    cout << "opt_number: " << testnumber.opt_number() << endl;
    cout << "imp_number: " << testnumber.imp_number() << endl;
    cout << "has_opt_number: " << testnumber.has_opt_number() << endl;

    testnumber.clear_opt_number();
    testnumber.clear_imp_number();
    
    cout << "------------------清除之后--------------------" << endl;
    cout << "opt_number: " << testnumber.opt_number() << endl;
    cout << "imp_number: " << testnumber.imp_number() << endl;
    cout << "has_opt_number: " << testnumber.has_opt_number() << endl;

    // ===================================================================
    // 有无赋值测试 
    // 测试函数 has_opt_number()
    // has_imp_number()隐式类型没有此函数
    // set_opt_number(0),赋值与默认值相同，has_opt_number()结果为1
    // ===================================================================
    cout << "\n----------------有无赋值测试------------------" << endl;

    testnumber.set_opt_number(11);
    cout << "------------------清除之前--------------------" << endl;
    cout << "has_opt_number: " << testnumber.has_opt_number() << endl;

    testnumber.clear_opt_number();

    cout << "------------------清除之后--------------------" << endl;
    cout << "has_opt_number: " << testnumber.has_opt_number() << endl;

    testnumber.set_opt_number(0);

    cout << "----------------设0后判断有无赋值------------------" << endl;
    cout << "has_opt_number: " << testnumber.has_opt_number() << endl;

    return 0;
}

