//！ ********************************************************************
//！ file optional_int_test.cpp
//！ author：liubo
//！ date：2024.01.09
//！ describe：



// 
// void MergeFrom(const Student& from);
// void Clear();
// bool IsInitialized() const;



//！
//！ ********************************************************************
#include <iostream>
#include <string>
#include "../build/proto/myprotobuf.pb.h"

using std::cout;
using std::endl;
using std::string;
// using myprotobuf::MOBILE;
// using myprotobuf::HOME;

int main() {
    cout << "----------------begain------------------" << endl;
    //! 验证我们链接的库版本是否与我们编译的头文件版本兼容。
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    myprotobuf::Student Student1;
    myprotobuf::Student Student2;

    //！ ********************************************************************
    //！ 测试函数 void CopyFrom(const Student& from);
    //！ ********************************************************************
    Student1.set_id(1);
    Student1.set_name("Tom");
    Student1.set_email("qq@123");
    Student1.add_phone()->set_number("12345");
    Student1.mutable_phone(0)->set_type(myprotobuf::Student::MOBILE);

    Student2.CopyFrom(Student1);


    cout << "Student2.id: " << Student2.id() << endl;
    cout << "Student2.name: " << Student2.name() << endl;
    cout << "Student2.email: " << Student2.email() << endl;
    cout << "Student2 number: " << Student2.mutable_phone(0)->number() << endl;
    cout << "Student2 type: " << Student2.mutable_phone(0)->type() << endl;






    // cout << "\n----------------默认值测试------------------" << endl;
    // cout << "optnumber: " << testnumber.optnumber() << endl; // 0

    //！ ********************************************************************
    //！ 存储值测试
    //！ 测试函数 set_optnumber()
    //！ ********************************************************************
    // cout << "\n----------------存储值测试------------------" << endl;
    // testnumber.set_optnumber(11);
    // cout << "optnumber: " << testnumber.optnumber() << endl;

    // testnumber.set_optnumber(22);
    // cout << "optnumber: " << testnumber.optnumber() << endl;

    //！ ********************************************************************
    //！ 清除值测试
    //！ 测试函数 clear_optnumber()
    //！ optnumber() has_optnumber()结果都为0
    //！ ********************************************************************
    // cout << "\n----------------清除值测试------------------" << endl;
    // cout <<   "----------------清除之前--------------------" << endl;
    // cout << "optnumber: " << testnumber.optnumber() << endl;
    // cout << "has_optnumber: " << testnumber.has_optnumber() << endl;

    // testnumber.clear_optnumber();
    
    // cout << "----------------清除之后--------------------" << endl;
    // cout << "optnumber: " << testnumber.optnumber() << endl;
    // cout << "has_optnumber: " << testnumber.has_optnumber() << endl;

    //！ ********************************************************************
    //！ 有无赋值测试
    //！ 测试函数 has_optnumber()
    //！ has_impnumber()隐式类型没有此函数
    //！ set_optnumber(0),赋值与默认值相同，has_optnumber()结果为1
    //！ ********************************************************************
    // cout << "\n----------------有无赋值测试------------------" << endl;
    // testnumber.clear_optnumber();
    // cout << "----------------清除之后--------------------" << endl;
    // cout << "has_optnumber: " << testnumber.has_optnumber() << endl;

    // testnumber.set_optnumber(0);
    // cout << "----------------设0后判断有无赋值------------------" << endl;
    // cout << "has_optnumber: " << testnumber.has_optnumber() << endl;

    // cout << "\n----------------end------------------" << endl;
    return 0;
}

