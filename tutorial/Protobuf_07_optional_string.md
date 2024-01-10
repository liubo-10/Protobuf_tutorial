* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...



# optional string





## optional 字符串字段(proto2 and proto3)

```protobuf
optional string foo = 1;
```

编译器将生成以下访问器方法：

- bool has_foo（）const：

  如果设置了字段，则返回true。

- const string& foo（）const：

  返回字段的当前值。如果未设置该字段，则返回默认值。

- void set_foo(const string& value)：

  设置字段的值。调用此函数后，has_foo（）将返回true，而foo（）则返回value的副本。

- void set_foo(string&& value)（C++11及以上版本）：

  从传递的字符串开始设置字段的值。调用此函数后，has_foo（）将返回true，而foo()则返回value的副本。

  && 是右值引用,rvalue 译为 “read value”，指的是那些可以提供数据值的数据（不一定可以寻址，例如存储于寄存器中的数据）。

- void set_foo（const char* value）：

  使用C样式的以null结尾的字符串设置字段的值。调用此函数后，has_foo()将返回true，而foo()则返回value的副本。

- void set_foo（const char* value，int size）：

  与上面一样，但字符串大小是显式给定的，而不是通过查找null终止符字节来确定的。

- string* mutable_foo（）：

  返回一个指针，指向存储字段值的可变字符串对象。如果在调用之前没有设置字段，则返回的字符串将为空（不是默认值）。调用此函数后，has_foo（）将返回true，而foo（）则返回写入给定字符串的任何值。

- void clear_foo（）：

  清除字段的值。调用此函数后，has_foo（）将返回false，foo（）则返回默认值。

- void set_allocated_foo（string* value）：

  将字符串对象设置为字段，并释放前一个字段值（如果存在）。如果字符串指针不为NULL，则消息将获得已分配字符串对象的所有权，并且has_foo（）将返回true。消息可以随时自由删除分配的字符串对象，因此对该对象的引用可能会无效。否则，如果值为NULL，则行为与调用clear_foo（）相同。

- string* release_foo（）：

  释放字段的所有权并返回字符串对象的指针。调用此函数后，调用者将获得已分配字符串对象的所有权，has_foo（）将返回false，foo（）则返回默认值。



## 隐式字符串字段 (proto3)

```protobuf
string foo = 1;
```

编译器将生成以下访问器方法：

- const string& foo（）const：

- void set_foo(const string& value)：

- void set_foo(string&& value)（C++11及以上版本）：

- void set_foo（const char* value）：

- void set_foo（const char* value，int size）：

- string* mutable_foo（）：

- void clear_foo（）：

- void set_allocated_foo（string* value）：

- string* release_foo（）：

缺少has_foo()，其他和optional string一样的



## 消息定义

```protobuf
syntax="proto3"; //消息类型命名规范：使⽤驼峰命名法，⾸字⺟⼤写。
package myprotobuf;


//定义联系人消息
message MyMessage{
    optional string  optstring = 1;  // optional
             string  impstring = 2;  // implicit
}

```





## 使用测试

```c++
//！ ********************************************************************
//！ file optional_string_test.cpp
//！ author：liubo
//！ date：2024.01.09
//！ describe：测试protobuf类型optional string 
//！           implicit string 类型用法基本与optional string一样只是少了has_XXX函数
//！           bytes类型与string 类型用法一样
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

    myprotobuf::MyMessage teststr;

    //！ ********************************************************************
    //！ 默认值测试
    //！ 测试函数 optstring()
    //！ ********************************************************************
    cout << "\n----------------默认值测试------------------" << endl;
    cout << "optstring: " << teststr.optstring() << endl;

    //！ ********************************************************************
    //！ 存储值测试
    //！ 测试函数 void set_optstring(const std::string& value)
    //！ 
    //！ const std::string& value = left_string_opt             变量当作左值
    //！ const std::string& value = "Hello World! left_value2"  字符串当作左值
    //！ ********************************************************************
    cout << "\n----------------存储值测试------------------" << endl;
    cout <<   "----------------左值引用 1------------------" << endl;
    string left_value = "Hello World! left_value1";
    teststr.set_optstring(left_value);
    cout << "optstring: " << teststr.optstring() << endl;

    cout << "----------------左值引用 2------------------" << endl;
    teststr.set_optstring("Hello World! left_value2");
    cout << "optstring: " << teststr.optstring() << endl;

    //！ ********************************************************************
    //！ 存储值测试
    //！ 测试函数 void set_optstring(std::string&& value)
    //！ 右值引用 C++11及以上版本
    //！ std::string&& value = right_string_opt      变量当作右
    //！ ********************************************************************
    cout << "----------------右值引用--------------------" << endl;
    string&& right_value = "Hello World! right_value";
    teststr.set_optstring(right_value);
    cout << "optstring: " << teststr.optstring() << endl;

    //！ ********************************************************************
    //！ 存储值测试
    //！ 测试函数 set_optstring(const char* value)
    //！ 测试函数 set_optstring(const char* value, size_t size)
    //！ ********************************************************************
    cout << "----------------C类型字符串 1------------------" << endl;
    const char* char1 = "Hello World! char1";
    teststr.set_optstring(char1);
    cout << "optstring: " << teststr.optstring() << endl;

    cout << "----------------C类型字符串 2------------------" << endl;
    char1 = "123456789";
    teststr.set_optstring(char1,5);
    cout << "optstring: " << teststr.optstring() << endl;

    //！ ********************************************************************
    //！ 获取指针测试
    //！ 测试函数 std::string* mutable_optstring()
    //！ sting_pt 与 teststr.optstring()指向同一地址
    //！ ********************************************************************
    cout << "\n----------------获取指针测试------------------" << endl;
    teststr.set_optstring("Hello World!");
    string* sting_pt = teststr.mutable_optstring();
    cout << "sting_pt: " << *sting_pt << endl;

    teststr.set_optstring("Hello World! update");
    cout << "sting_pt: " << *sting_pt << endl;

    //！ ********************************************************************
    //！ 释放指针测试
    //！ 测试函数 void release_XXX_string()
    //！ sting_pt_mu 之前保存的指针不会被释放
    //！ 执行 release_optstring 后 sting_pt_mu sting_pt_rl与teststr.optstring()不再指向同一地址
    //！ ********************************************************************
    cout << "\n----------------释放指针测试------------------" << endl;
    cout <<   "----------------释放指针------------------" << endl;
    
    teststr.set_optstring("Hello World!");
    string* sting_pt_mu = teststr.mutable_optstring();
    string* sting_pt_rl = teststr.release_optstring();

    cout << "sting_pt_mu: " << *sting_pt_mu << endl; // Hello World!
    cout << "sting_pt_rl: " << *sting_pt_rl << endl; // Hello World!
    cout << "optstring: " << teststr.optstring() << endl; // 为空
    cout << "has_optstring: " << teststr.has_optstring() << endl; // 值为0

    cout << "----------------重新赋值------------------" << endl;
    teststr.set_optstring("Hello World! update");
    cout << "opt_sting_pt_mu: " << *sting_pt_mu << endl; // Hello World!
    cout << "opt_sting_pt_rl: " << *sting_pt_rl << endl; // Hello World!
    cout << "optstring: " << teststr.optstring() << endl; // Hello World! update
    cout << "has_optstring: " << teststr.has_optstring() << endl; // 值为1

    //！ ********************************************************************
    //！ 清除值测试
    //！ 测试函数 void clear_optstring()
    //！ ********************************************************************
    cout << "\n----------------清除值------------------" << endl;
    teststr.clear_optstring();

    cout << "sting_pt_mu: " << *sting_pt_mu << endl; // Hello World!
    cout << "sting_pt_rl: " << *sting_pt_rl << endl; // Hello World!
    cout << "optstring: " << teststr.optstring() << endl; // 为空
    cout << "has_optstring: " << teststr.has_optstring() << endl; // 值为0

    // ===================================================================
    // 判断值测试 参见以上测试
    // 测试函数 void has_optstring()
    // has_impstring() 隐式存在没有此函数
    // ===================================================================

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













  