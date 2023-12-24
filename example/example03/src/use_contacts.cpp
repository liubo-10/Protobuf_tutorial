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
        people.set_age("20");
        people.set_name("张三");
        // 调⽤序列化⽅法，将序列化后的⼆进制序列存⼊string中
        if (!people.SerializeToString(&people_str))
        {
            cout << "序列化联系⼈失败." << endl;
        }
        // 打印序列化结果
        cout << "序列化后的 people_str: " << people_str << endl;
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
        cout << "Parse age: " << people.age() << endl;
        cout << "Parse name: " << people.name() << endl;
    }

    return 0;
}

