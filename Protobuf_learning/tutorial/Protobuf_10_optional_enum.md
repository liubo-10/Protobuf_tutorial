* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...



# optional enum





## Optional枚举字段 (proto2 and proto3)



```protobuf
enum Bar {
  BAR_UNSPECIFIED = 0;
  BAR_VALUE = 1;
  BAR_OTHER_VALUE = 2;
}

optional Bar foo = 1;
```

编译器将生成以下访问器方法：

- bool has_foo（）const：

  如果设置了字段，则返回true。

- Bar foo（）const：

  返回字段的当前值。如果未设置该字段，则返回默认值。

- void set_foo（条形值）：

  设置字段的值。调用此函数后，has_foo（）将返回true，而foo（）则返回value。在调试模式下（即未定义NDEBUG），如果值与为Bar定义的任何值都不匹配，则此方法将中止该过程。

- void clear_foo（）：

  清除字段的值。调用后，has_foo（）将返回false，而foo（）则返回默认值。



### Implicit 枚举字段 (proto3)

```protobuf
enum Bar {
  BAR_UNSPECIFIED = 0;
  BAR_VALUE = 1;
  BAR_OTHER_VALUE = 2;
}

Bar foo = 1;  // no field label specified, defaults to implicit presence.
```

编译器将生成以下访问器方法：

- Bar foo（）const：

  返回字段的当前值。如果未设置该字段，则返回默认值。

- void set_foo（条形值）：

  设置字段的值。调用此函数后，has_foo（）将返回true，而foo（）则返回value。在调试模式下（即未定义NDEBUG），如果值与为Bar定义的任何值都不匹配，则此方法将中止该过程。

- void clear_foo（）：

  清除字段的值。调用后，has_foo（）将返回false，而foo（）则返回默认值。



## 消息定义

```protobuf
syntax="proto3"; //消息类型命名规范：使⽤驼峰命名法，⾸字⺟⼤写。
package myprotobuf;

enum MyEnum {
    case0 = 0;
    case1 = 1;
    case2 = 2;
}

message MyCase{
    optional MyEnum  optenum = 1;  // optional
             MyEnum  impenum = 2;  // implicit
}

```





## 使用测试

```c++
//！ ********************************************************************
//！ file name： fields_optional_enum.cpp
//！ author：    liubo
//！ date：      2024.01.06
//！ describe：  测试protobuf类型optional enum 
//！             implicit enum 类型用法基本与 optional enum 一样只是少了has_XXX函数
//！ ********************************************************************

#include <iostream>
#include <string>
#include "../build/proto/myprotobuf.pb.h"

using std::cout;
using std::endl;
using std::string;
using myprotobuf::case0;
using myprotobuf::case1;
using myprotobuf::case2;

int main() {
    cout << "----------------begain------------------" << endl;
    //! 验证我们链接的库版本是否与我们编译的头文件版本兼容。
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    myprotobuf::MyCase testcase;

    //！ ********************************************************************
    //！ 默认值测试
    //！ 测试函数 optenum()
    //！ ********************************************************************
    cout << "\n----------------默认值测试------------------" << endl;
    cout << "optenum: " << testcase.optenum() << endl;

    //！ ********************************************************************
    //！ 存储值测试
    //！ 测试函数 set_optenum()
    //！ ********************************************************************
    cout << "\n----------------存储值测试------------------" << endl;

    testcase.set_optenum(case0);
    cout << "optenum: " << testcase.optenum() << endl;

    testcase.set_optenum(case1);
    cout << "optenum: " << testcase.optenum() << endl;


    //！ ********************************************************************
    //！ 清除值测试
    //！ 测试函数 clear_optenum()
    //！ optenum() has_optenum()结果都为0
    //！ ********************************************************************
    cout << "\n----------------清除值测试------------------" << endl;
    cout <<   "----------------清除之前--------------------" << endl;
    cout << "optenum: " << testcase.optenum() << endl;
    cout << "has_optenum: " << testcase.has_optenum() << endl;

    testcase.clear_optenum();

    cout << "----------------清除之后--------------------" << endl;
    cout << "optenum: " << testcase.optenum() << endl;
    cout << "has_optenum: " << testcase.has_optenum() << endl;

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













  