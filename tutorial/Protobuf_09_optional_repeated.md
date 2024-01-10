* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...



# optional repeated.md



### repeated 数值字段

```protobuf
repeated int32 foo = 1;
```

编译器将生成以下访问器方法：

- int foo_size（）const：

  返回当前字段中的元素数。要检查空集，请考虑在基础RepeatedField中使用empty（）方法，而不是此方法。

- int32 foo（int index）const：

  返回给定的从零开始的索引处的元素。使用[0，foo_size（）之外的索引调用此方法会产生未定义的行为。

- void set_foo（int index，int32 value）：

  在给定的从零开始的索引处设置元素的值。

- void add_foo（int32 value）：

  在具有给定值的字段末尾添加一个新元素。

- void clear_foo（）：

  从字段中删除所有元素。调用此函数后，foo_size（）将返回零。

- const RepeatedField＜int32＞&foo（）const：

  返回存储字段元素的基础RepeatedField。这个容器类提供了类似STL的迭代器和其他方法。

- RepeatedField＜int32＞*mutable_foo（）：

  返回一个指向存储字段元素的基础可变RepeatedField的指针。这个容器类提供了类似STL的迭代器和其他方法。



对于其他数值字段类型（包括bool），根据标量值类型表，将int32替换为相应的C++类型。







## 消息定义

```protobuf
syntax="proto3"; //消息类型命名规范：使⽤驼峰命名法，⾸字⺟⼤写。
package myprotobuf;

message MyRepeated{
    repeated int32  repnumber = 1;
}
```





## 使用测试

```c++
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
    //! 验证我们链接的库版本是否与我们编译的头文件版本兼容。
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
    //! 测试函数 add_repnumber() set_repnumber()
    //! set_repnumber(index)在add_repnumber使用index之前无法使用
    //! ********************************************************************
    cout << "\n----------------存储值测试------------------" << endl;
    //testrep.set_repnumber(0,20); // 段错误 (核心已转储) 在add_repnumber使用index之前无法使用
    //testrep.set_repnumber(1,21);

    testrep.add_repnumber(10);
    testrep.add_repnumber(11);
    cout << "repnumber(0): " << testrep.repnumber(0) << endl;
    cout << "repnumber(1): " << testrep.repnumber(1) << endl;
    
    testrep.set_repnumber(0,20);
    testrep.set_repnumber(1,21);
    cout << "repnumber(0): " << testrep.repnumber(0) << endl;
    cout << "repnumber(1): " << testrep.repnumber(1) << endl;

    //! ********************************************************************
    //! 清除值测试
    //! 测试函数 clear_repnumber() repnumber_size() repnumber().empty()
    //! ********************************************************************
    cout << "\n----------------清除值测试------------------" << endl;
    cout <<   "----------------清除之前--------------------" << endl;
    cout << "repnumber(0): " << testrep.repnumber(0) << endl;
    cout << "repnumber(1): " << testrep.repnumber(1) << endl;
    cout << "repnumber size: " << testrep.repnumber_size() << endl; // 2
    cout << "repnumber empty: " << testrep.repnumber().empty() << endl; // 0

    testrep.clear_repnumber();

    cout << "----------------清除之后--------------------" << endl;
    cout << "repnumber(0): " << testrep.repnumber(0) << endl; // 仍然有值
    cout << "repnumber(1): " << testrep.repnumber(1) << endl; // 仍然有值
    cout << "repnumber size: " << testrep.repnumber_size() << endl; // 0
    cout << "repnumber empty: " << testrep.repnumber().empty() << endl; // 1
    cout << "----------------重新add--------------------" << endl;
    testrep.add_repnumber(30);
    testrep.add_repnumber(31);
    cout << "repnumber(0): " << testrep.repnumber(0) << endl; // 从index0开始
    cout << "repnumber(1): " << testrep.repnumber(1) << endl;

    //! ********************************************************************
    //! 存储值测试
    //! testrep.repnumber() 返回 repnumber_
    //! ********************************************************************
    cout << "\n----------------repnumber_测试------------------" << endl;
    cout << "repnumber().Get(0): " << testrep.repnumber().Get(0) << endl;
    cout << "repnumber().Get(1): " << testrep.repnumber().Get(1) << endl;

    //! ********************************************************************
    //! 存储值测试
    //! testrep.mutable_repnumber() 返回 &repnumber_
    //! ********************************************************************
    cout << "\n----------------&repnumber_指针测试------------------" << endl;
    cout << "mutable_repnumber()->Get(0): " << testrep.mutable_repnumber()->Get(0) << endl;
    cout << "mutable_repnumber()->Get(1): " << testrep.mutable_repnumber()->Get(1) << endl;

    //! ********************************************************************
    //! 迭代器测试
    //! testrep.repnumber().begin() end() 返回 &repnumber_[index]
    //! ********************************************************************
    cout << "\n----------------迭代器测试------------------" << endl;

    testrep.clear_repnumber();
    testrep.add_repnumber(0);
    testrep.add_repnumber(1);
    testrep.add_repnumber(2);
    testrep.add_repnumber(3);
    testrep.add_repnumber(4);
    for(auto iter = testrep.repnumber().begin(); iter != testrep.repnumber().end(); iter++) {
        cout << "mutable_repnumber iter: " << *iter << endl;
    }

    //! ********************************************************************
    //! CopyFrom测试
    //! 
    //! ********************************************************************
    myprotobuf::MyRepeated testrep_copy;
    myprotobuf::MyRepeated testrep1;

    testrep_copy = testrep;
    for(auto iter = testrep_copy.repnumber().begin(); iter != testrep_copy.repnumber().end(); iter++) {
        cout << "testrep_copy iter: " << *iter << endl;
    }

    testrep1.clear_repnumber();
    testrep1.add_repnumber(10);
    testrep1.add_repnumber(11);
    testrep1.add_repnumber(12);
    testrep1.add_repnumber(13);
    testrep1.add_repnumber(14);

    testrep_copy.CopyFrom(testrep1);
    for(auto iter = testrep_copy.repnumber().begin(); iter != testrep_copy.repnumber().end(); iter++) {
        cout << "testrep_copy iter: " << *iter << endl;
    }


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













  