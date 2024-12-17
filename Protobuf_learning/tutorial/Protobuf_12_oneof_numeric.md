* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...

# oneof numeric



## oneof 数值字段

```protobuf
oneof example_name {
    int32 foo = 1;
    ...
}

```

编译器将生成以下访问器方法：

- bool has_foo（）const（仅限proto2）：

  如果其中一个大小写是kFoo，则返回true。

- int32 foo（）const：

  如果其中一个case是kFoo，则返回字段的当前值。否则，返回默认值。

- void set_foo（int32值）：

  如果设置了同一个字段中的任何其他字段，则调用clear_example_name（）。

  设置此字段的值，并将大小写之一设置为kFoo。

  has_foo（）（仅限proto2）将返回true，foo（）将返回value，example_name_case（）将回归kFoo。

- void clear_foo（）：

  如果其中一个案例不是kFoo，则不会有任何变化。

  如果其中一个case是kFoo，则清除字段的值和其中一个case。has_foo（）（仅限proto2）将返回false，foo（）将返回默认值，example_name_case（）则返回example_name_NOT_SET。

  



## 消息定义

```protobuf
syntax="proto3"; //消息类型命名规范：使⽤驼峰命名法，⾸字⺟⼤写。
package myprotobuf;

message MyMessage{
    oneof test_oneof { 
        int32  mynumber1 = 1;
        int32  mynumber2 = 2;
    }
}

```



## 使用测试

```c++
//！ ********************************************************************
//！ file fields_repeated_int.cpp
//！ author：liubo
//！ date：2024.01.08
//！ describe：
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

    myprotobuf::MyMessage testoneof;

    //！ ********************************************************************
    //！ 默认值测试
    //！ 测试函数 mynumber1()
    //！ ********************************************************************
    cout << "\n----------------默认值测试------------------" << endl;
    cout << "testoneof mynumber1: " << testoneof.mynumber1() << endl;
    cout << "testoneof mynumber2: " << testoneof.mynumber2() << endl;

    //！ ********************************************************************
    //！ 默认值测试
    //！ 测试函数 set_mynumber1()
    //！ ********************************************************************
    cout << "\n----------------存储值测试------------------" << endl;
    testoneof.set_mynumber1(11);

    cout << "testoneof mynumber1: " << testoneof.mynumber1() << endl;
    cout << "testoneof mynumber2: " << testoneof.mynumber2() << endl;

    testoneof.set_mynumber2(33);

    cout << "testoneof mynumber1: " << testoneof.mynumber1() << endl;
    cout << "testoneof mynumber2: " << testoneof.mynumber2() << endl;


    //！ ********************************************************************
    //！ 默认值测试
    //！ 测试函数 clear_mynumber1()
    //！ ********************************************************************
    cout << "\n----------------清除值测试------------------" << endl;
    cout <<   "----------------清除之前--------------------" << endl;

    cout << "testoneof mynumber1: " << testoneof.mynumber1() << endl;
    cout << "testoneof mynumber2: " << testoneof.mynumber2() << endl;

    testoneof.clear_mynumber1();
    testoneof.clear_mynumber2();
    
    cout << "----------------清除之后--------------------" << endl;
    cout << "testoneof mynumber1: " << testoneof.mynumber1() << endl;
    cout << "testoneof mynumber2: " << testoneof.mynumber2() << endl;

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













  