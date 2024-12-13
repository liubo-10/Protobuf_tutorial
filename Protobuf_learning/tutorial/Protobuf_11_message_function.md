* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...



# message function

定义的message本身常用的有三个函数

void CopyFrom(const Student& from);

void MergeFrom(const Student& from);

void Clear();





## 消息定义

```protobuf
syntax="proto3"; 
package myprotobuf;

message Student {  //消息类型命名规范：使⽤驼峰命名法，⾸字⺟⼤写。
    enum PhoneType {
        MOBILE = 0;
        HOME   = 1;
    }
    
    message PhoneNumber { 
        string number  = 1;
        PhoneType type = 2;
    }
    
    uint64 id = 1;
    string name = 2;
    string email = 3;
    repeated PhoneNumber phone = 4;
}
```



## 使用测试

```c++
//！ ********************************************************************
//！ file optional_int_test.cpp
//！ author：liubo
//！ date：2024.01.11
//！ describe：
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
    cout << "\n----------------CopyFrom 测试------------------" << endl;
    Student1.set_id(1);
    Student1.set_name("Tom");
    Student1.set_email("qq@123");
    Student1.add_phone();// 先要添加才能使用
    Student1.mutable_phone(0)->set_number("12345");
    Student1.mutable_phone(0)->set_type(myprotobuf::Student::HOME);

    Student2.CopyFrom(Student1);

    cout << "Student2.id: " << Student2.id() << endl;
    cout << "Student2.name: " << Student2.name() << endl;
    cout << "Student2.email: " << Student2.email() << endl;
    cout << "Student2 number: " << Student2.mutable_phone(0)->number() << endl;
    cout << "Student2 type: " << Student2.mutable_phone(0)->type() << endl;

    //！ ********************************************************************
    //！ 测试函数 void MergeFrom(const Student& from);
    //！ 与 CopyFrom结果一样
    //！ ********************************************************************
    cout << "\n----------------MergeFrom 测试------------------" << endl;
    myprotobuf::Student Student3;
    Student3.set_id(3);

    Student3.MergeFrom(Student1);

    cout << "Student3.id: " << Student3.id() << endl;
    cout << "Student3.name: " << Student3.name() << endl;
    cout << "Student3.email: " << Student3.email() << endl;
    cout << "Student3 number: " << Student3.mutable_phone(0)->number() << endl;
    cout << "Student3 type: " << Student3.mutable_phone(0)->type() << endl;


    //！ ********************************************************************
    //！ 测试函数 void Clear();
    //！ ********************************************************************
    cout << "\n----------------Clear 测试------------------" << endl;

    Student3.Clear();

    cout << "Student3.id: " << Student3.id() << endl;
    cout << "Student3.name: " << Student3.name() << endl;
    cout << "Student3.email: " << Student3.email() << endl;
    //cout << "Student3 number: " << Student3.mutable_phone(0)->number() << endl;//error
    //cout << "Student3 type: " << Student3.mutable_phone(0)->type() << endl;//error


    //！ ********************************************************************
    //！ 测试函数 void IsInitialized();
    //！ bool Student::IsInitialized() const {
    //！   return true;
    //！ }
    //！ ********************************************************************

    return 0;
}
```










---

---

---

---

---

---

---

---

---

---

---

---

---

---

---

---

---

---

---

---













  