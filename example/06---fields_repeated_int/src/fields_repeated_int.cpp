//！ ********************************************************************
//！ file fields_repeated_int.cpp
//！ author：liubo
//！ date：2024.01.06
//！ describe：
//！ ********************************************************************
#include <iostream>
#include <string>
#include "../build/proto/myrepeated.pb.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "----------------begain------------------" << endl;
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    myprotobuf::MyRepeated testrep;

    //! ********************************************************************
    //! 默认值测试
    //! 测试testrep.repnumber的默认值
    //! ********************************************************************

    //cout << "\n----------------默认值测试------------------" << endl;
    //cout << "repnumber: " << testrep.repnumber(0) << endl; // 段错误 (核心已转储)


    //! ********************************************************************
    //! 存储值测试
    //! 测试函数 set_XXX()
    //! set_repnumber(index)在add_repnumber使用index之前无法使用
    //! ********************************************************************
    cout << "\n----------------存储值测试------------------" << endl;
    testrep.add_repnumber(10);
    testrep.add_repnumber(11);

    cout << "repnumber(0): " << testrep.repnumber(0) << endl;
    cout << "repnumber(1): " << testrep.repnumber(1) << endl;
    cout << "repnumber().Get(0): " << testrep.repnumber().Get(0) << endl;
    cout << "repnumber().Get(1): " << testrep.repnumber().Get(1) << endl;
    
    testrep.set_repnumber(0,20);
    testrep.set_repnumber(1,21);
    cout << "repnumber(0): " << testrep.repnumber(0) << endl;
    cout << "repnumber(1): " << testrep.repnumber(1) << endl;

    //! ********************************************************************
    //! 清除值测试
    //! 测试函数 clear_XXX()
    //! ********************************************************************
    cout << "\n----------------清除值测试------------------" << endl;
    cout <<   "----------------清除之前--------------------" << endl;
    cout << "repnumber(0): " << testrep.repnumber(0) << endl;
    cout << "repnumber(1): " << testrep.repnumber(1) << endl;
    cout << "repnumber size: " << testrep.repnumber_size() << endl;
    cout << "repnumber empty: " << testrep.repnumber().empty() << endl;

    testrep.clear_repnumber();

    cout << "----------------清除之后--------------------" << endl;
    cout << "repnumber(0): " << testrep.repnumber(0) << endl; // 仍然有值
    cout << "repnumber(1): " << testrep.repnumber(1) << endl; // 仍然有值
    cout << "repnumber size: " << testrep.repnumber_size() << endl;
    cout << "repnumber empty: " << testrep.repnumber().empty() << endl;









    //! ********************************************************************
    //! 数目测试
    //! 测试testrep.repnumber的数目
    //! ********************************************************************
    cout << "\n----------------数目测试------------------" << endl;






    return 0;
}

