






// bool SerializeToString(string* output) const; 
// //将消息序列化并储存在指定的string中。注意里面的内容是二进制的，而不是文本；我们只是使用string作为一个很方便的容器。
// bool ParseFromString(const string& data); //从给定的string解析消息。
// bool SerializeToArray(void * data, int size) const	//将消息序列化至数组
// bool ParseFromArray(const void * data, int size)	//从数组解析消息
// bool SerializeToOstream(ostream* output) const; //将消息写入到给定的C++ ostream中。
// bool ParseFromIstream(istream* input); //从给定的C++ istream解析消息。








#include <iostream>
#include <string>
#include "../build/proto/contacts.pb.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    string people_str;
    { 
        // .proto⽂件声明的package，通过protoc编译后，会为编译⽣成的C++代码声明同名的命名空间
        // 其范围是在.proto ⽂件中定义的内容
        contacts::PeopleInfo people;
        people.set_name("张三");
        people.set_age("20");
        // 调⽤序列化⽅法，将序列化后的⼆进制序列存⼊string中
        if (!people.SerializeToString(&people_str))
        {
            cout << "序列化联系⼈失败." << endl;
        }
        // 打印序列化结果
        cout << "序列化后的 people_str: " << people_str << endl;//张三20
    }

    cout << "----------------------------------" << endl;

    {
        contacts::PeopleInfo people;
        // 调⽤反序列化⽅法，读取string中存放的⼆进制序列，并反序列化出对象
        if (!people.ParseFromString(people_str))
        {
            cout << "反序列化出联系⼈失败." << endl;
        }
        // 打印结果
        cout << "反序列化得到的people:" << endl;
        cout << "Parse name: " << people.name() << endl;//张三
        cout << "Parse age: " << people.age() << endl;//20
    }

    return 0;
}

