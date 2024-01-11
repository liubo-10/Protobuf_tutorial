//！ ********************************************************************
//！ file optional_int_test.cpp
//！ author：liubo
//！ date：2024.01.09
//！ describe：



// void CopyFrom(const Student& from);
// void MergeFrom(const Student& from);
// void Clear();
// bool IsInitialized() const;


// bool SerializeToString(string* output) const; 
// //将消息序列化并储存在指定的string中。注意里面的内容是二进制的，而不是文本；我们只是使用string作为一个很方便的容器。
// bool ParseFromString(const string& data); //从给定的string解析消息。
// bool SerializeToArray(void * data, int size) const	//将消息序列化至数组
// bool ParseFromArray(const void * data, int size)	//从数组解析消息
// bool SerializeToOstream(ostream* output) const; //将消息写入到给定的C++ ostream中。
// bool ParseFromIstream(istream* input); //从给定的C++ istream解析消息。


//！
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

    // myprotobuf::MyMessage testnumber;

    //！ ********************************************************************
    //！ 默认值测试
    //！ 测试函数 optnumber()
    //！ ********************************************************************
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

