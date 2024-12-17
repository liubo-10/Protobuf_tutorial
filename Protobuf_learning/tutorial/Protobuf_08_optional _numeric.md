* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...
* 📇 sssssdsdsdsdsdsdasd
* 🎃 dsdsdsdsdsddfsgdgasd
* 🍺 jyukyuiyuiyuigkasd
* 🍥 fsdfgdsgsdgdgadsa
* ✨ xcvxcvxcvxcvdasdaasd
* 🍰 dazdsxasxsaxsaasdsa
* 🚨 gdfgdshdfhfhygjtyu



# optional字段

optional，表示该字段可以有两种状态。

- 该字段被设置，包含一个可以清晰准确的从二进制格式解析得到的值，会被序列化。
- 该字段没有被设置，会返回一个默认值，不会被序列化。也可以自定义默认值。如果没有自定义默认值，会用系统默认值。
- 隐式字段(implicit) 用法基本与optional一样只是少了has_XXX函数



## optional 数值字段 (proto2 and proto3)

```protobuf
optional int32 foo = 1;
```

编译器将生成如下访问器方法：

- bool has_foo（）const：

  如果设置了字段，则返回true。

- int32 foo（）const：

  返回字段的当前值。如果未设置该字段，则返回默认值。

- void set_foo（int32 value）：

  设置字段的值。调用此函数后，has_foo（）将返回true，而foo（）则返回value。

- void clear_foo（）：

  清除字段的值。调用后，has_foo（）将返回false，而foo（）则返回默认值。



对于其他数值字段类型（包括bool），根据标量值类型表，将int32替换为相应的C++类型。



## 隐式数值字段 (proto3)

```protobuf
int32 foo = 1;  // no field label specified, defaults to implicit presence.
```

编译器将生成以下访问器方法：

- int32 foo（）const：

- void set_foo（int32 value）：

- void clear_foo（）：


缺少has_foo()，其他函数和optional int32一样的

对于其他数值字段类型（包括bool），根据标量值类型表，将int32替换为相应的C++类型。





## 消息定义

```protobuf
syntax="proto3"; //消息类型命名规范：使⽤驼峰命名法，⾸字⺟⼤写。
package myprotobuf;

//定义联系人消息
message MyMessage{
    optional int32  optnumber=1;  // optional
          int32  impnumber=2;  // implicit
}

```



## 使用测试

```c++
//！ ********************************************************************
//！ file optional_int_test.cpp
//！ author：liubo
//！ date：2024.01.09
//！ describe：测试protobuf类型optional int32 
//！           implicit int32类型用法基本与optional int32一样只是少了has_XXX函数
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

    myprotobuf::MyMessage testnumber;

    //！ ********************************************************************
    //！ 默认值测试
    //！ 测试函数 optnumber()
    //！ ********************************************************************
    cout << "\n----------------默认值测试------------------" << endl;
    cout << "optnumber: " << testnumber.optnumber() << endl; // 0

    //！ ********************************************************************
    //！ 存储值测试
    //！ 测试函数 set_optnumber()
    //！ ********************************************************************
    cout << "\n----------------存储值测试------------------" << endl;
    testnumber.set_optnumber(11);
    cout << "optnumber: " << testnumber.optnumber() << endl;

    testnumber.set_optnumber(22);
    cout << "optnumber: " << testnumber.optnumber() << endl;

    //！ ********************************************************************
    //！ 清除值测试
    //！ 测试函数 clear_optnumber()
    //！ optnumber() has_optnumber()结果都为0
    //！ ********************************************************************
    cout << "\n----------------清除值测试------------------" << endl;
    cout <<   "----------------清除之前--------------------" << endl;
    cout << "optnumber: " << testnumber.optnumber() << endl;
    cout << "has_optnumber: " << testnumber.has_optnumber() << endl;

    testnumber.clear_optnumber();
    
    cout << "----------------清除之后--------------------" << endl;
    cout << "optnumber: " << testnumber.optnumber() << endl;
    cout << "has_optnumber: " << testnumber.has_optnumber() << endl;

    //！ ********************************************************************
    //！ 有无赋值测试
    //！ 测试函数 has_optnumber()
    //！ has_impnumber()隐式类型没有此函数
    //！ set_optnumber(0),赋值与默认值相同，has_optnumber()结果为1
    //！ ********************************************************************
    cout << "\n----------------有无赋值测试------------------" << endl;
    testnumber.clear_optnumber();
    cout << "----------------清除之后--------------------" << endl;
    cout << "has_optnumber: " << testnumber.has_optnumber() << endl;

    testnumber.set_optnumber(0);
    cout << "----------------设0后判断有无赋值------------------" << endl;
    cout << "has_optnumber: " << testnumber.has_optnumber() << endl;

    cout << "\n----------------end------------------" << endl;
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
