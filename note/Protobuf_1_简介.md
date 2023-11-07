# Protobuf 简介

* 👋 Hi, I’m bliu2-10
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...





## 术语

| 简称/术语/定义 | 全称/描述                                                    | 备注 |
| :------------- | :----------------------------------------------------------- | :--- |
| 结构化数据     | 结构化数据是指按照一定的规则和格式进行组织和存储的数据。它具有明确的数据类型和关系，可以通过预定义的模式或模型进行描述和解释。 |      |
| RPC            | RPC（Remote Procedure Call）远程过程调用，它是利用网络从远程计算机上请求服务，可以理解为把程序的一部分放在其他远程计算机上执行。通过网络通信将调用请求发送至远程计算机后，利用远程计算机的系统资源执行这部分程序，最终返回远程计算机上的执行结果。 |      |
| 序列化         | 把一个对象变成二进制内容。                                   |      |
| 反序列化       | 把一个二进制内容变回对象。                                   |      |
|                |                                                              |      |





## 简介

Protocol Buffers的简称Protobuf，它由Google公司开发，并于2008年对外开源。它是一种数据描述语言，是一种轻便高效结构化数据存储格式，以 K-V 的方式来存储数据，可以用于结构化数据串行化，或者说序列化。protobuf是跨语言的，并且自带一个编译器(protoc)，只需要用protoc进行编译，就可以编译成Java、Python、C++、C#、Go等多种语言的代码，然后可以直接使用相关接口，不需要再写解析代码或其它代码。由于语言无关、平台无关、可扩展的特性，它的设计非常适合作为通讯协议数据格式，数据存储格式，RPC数据交换格式。



Google的Protobuf，相比于它的前辈xml、json，它的体量更小，解析速度更快。



protobuf的核心内容包括：

- 定义消息：消息的结构体，以message标识。
- 定义接口：接口路径和参数，以service标识。

通过protobuf提供的机制，服务端与服务端之间只需要关注接口方法名（service）和参数（message）即可通信，而不需关注繁琐的链路协议和字段解析，极大降低了服务端的设计开发成本。



### Protobuf特点

- 语言无关、平台无关：即Protobuf支持java、C++、Python等多种语言。
- 高效：即比XML更小、更快、更简单。
- 扩展性、兼容性好：可以更新数据结构，而不影响和破坏原有的旧程序。
- 使用特定：Protobuf是需要依赖通过编译生成的头文件和源文件来使用。

### protobuf的优劣势

#### 1、优势：

1. 序列化后体积相比Json和XML很小，适合网络传输
2. 序列化反序列化速度很快，快于Json的处理速度
3. 消息格式升级和兼容性还不错
4. 支持跨平台多语言

#### 2、劣势：

1. 应用不够广(相比xml和json)
2. 二进制格式导致可读性差
3. 缺乏自描述





## 安装

```bash
sudo apt  install protobuf-compiler  //安装
protoc --version    //查看版本
```



### 简单的例子

Protobuf中最基本的数据单元是message，是类似Go语言中结构体的存在。在message中可以嵌套message或其它的基础数据类型的成员。

protobuf协议文件名后缀名为.proto

```protobuf
syntax = "proto3";
package protobuf.addressbook;

enum PhoneType
{
    MOBILE = 0;
    HOME = 1;
    WORK = 2;
}

message Person   //定义数据结构
{
    optional string name = 1;
    optional uint32 age = 2;
    optional string email = 3; 
    message PhoneNumber
    {
      optional string number = 1;
      optional PhoneType type = 2;
    }
  
    repeated PhoneNumber phone = 4;
}
message AddressBook          
{ 
    repeated Person person = 1;
}


```

### 标识符 

- syntax：文件第一行的syntax字段标识使用的protobuf是哪个版本，示例表示指定使用proto3。如果省略,protocol buffer编译器默认使用proto2语法。他必须是文件中非空非注释行的第一行。

- package：标识生成目标文件的包名。在C++中表示的是命名空间。示例表示生成的类和函数在protobuf命名空间的addressbook命令空间下。

- enum：表示一个枚举类型。会在目标.h文件中自动生成一个枚举类型。
- message：标识一条消息。会在目标文件中自动生成一个类。









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

