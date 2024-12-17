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


# 走入Protobuf

通过介绍Protobuf概况，走入Protobuf。



## 一、术语

- 结构化数据: 结构化数据是指按照一定的规则和格式进行组织和存储的数据。它具有明确的数据类型和关系，可以通过预定义的模式或模型进行描述和解释。

- RPC: RPC（Remote Procedure Call）远程过程调用，它是利用网络从远程计算机上请求服务，可以理解为把程序的一部分放在其他远程计算机上执行。通过网络通信将调用请求发送至远程计算机后，利用远程计算机的系统资源执行这部分程序，最终返回远程计算机上的执行结果。
- 序列化: 把一个对象变成二进制内容。
- 反序列化: 把一个二进制内容变回对象。



## 二、简介

Protobuf是Protocol Buffers的简称，它由Google公司开发，并于2008年对外开源。它是一种语言无关、平台无关、可扩展的结构化数据构建机制，在一些资料中也称为数据描述语言。作为数据描述语言可以与json类比。



protobu自带一个编译工具(protoc)，当我们构建好数据结构后，用编译工具protoc对Protobuf文件进行编译，可以根据需要得到C++、C#、Dart、Go、Java、Kotlin、Objective-C、Python、PHP和Ruby，等多种语言的代码文件。然后可以直接使用生成的代码文件中的相关接口与变量，轻松地在各种数据流中写入和读取结构化数据，不需要再写解析代码或其它代码。



相比于它的前辈xml、json，它的体量更小，解析速度更快。它的设计非常适合在通讯协议，数据存储，RPC数据交换等场景中使用。



protobuf的核心内容包括：

- 定义消息：消息的结构体，以message标识。
- 定义接口：接口路径和参数，以service标识。

通过protobuf提供的机制，服务端与服务端之间只需要关注接口方法名（service）和参数（message）即可通信，而不需关注繁琐的链路协议和字段解析，极大降低了服务端的设计开发成本。



## 三、Protobuf特点

- 语言无关、平台无关：即Protobuf支持java、C++、Python等多种语言。
- 高效：即比XML更小、更快、更简单。
- 扩展性、兼容性好：可以更新数据结构，而不影响和破坏原有的旧程序。
- 使用特定：Protobuf是需要依赖通过编译生成的头文件和源文件来使用。

### 四、protobuf的优劣

#### 优势：

1. 序列化后体积相比Json和XML很小，适合网络传输
2. 序列化反序列化速度很快，快于Json的处理速度
3. 消息格式升级和兼容性还不错
4. 支持跨平台多语言
5. 减少了二义性
6. 生成的变量和接口更容易在编程中使用

#### 劣势：

1. 应用不够广(相比xml和json)
2. 二进制格式导致可读性差
3. 缺乏自描述

## 五、数据交互格式的比较

protobuf和json或者xml，从一定意义上来说他们的作用是一样的，都是数据交互的一种格式。

1、json: 一般的web项目中，最流行的主要还是json。因为浏览器对于json数据支持非常好，有很多内建的函数支持。

2、xml: 在webservice中应用最为广泛，但是相比于json，它的数据更加冗余，因为需要成对的闭合标签。json使用了键值对的方式，不仅压缩了一定的数据空间，同时也具有可读性。

3、protobuf:是后起之秀，适合高性能，对响应速度有要求的数据传输场景。因为profobuf是二进制数据格式，需要编码和解码。数据本身不具有可读性。因此只能反序列化之后得到真正可读的数据。



## 六、protobuf和gRPC的关系

protobuf可以把结构体序列化为二进制，也可以把对应二进制反序列化回结构体。说白了protobuf单纯就是做编解码。用protobuf可以把程序中的一些对象序列化，然后存为本地文件，过一会儿再读取文件，然后恢复出那些对象。
grpb是网络通信协议，在网络通信时，会发送和接收数据。收发的数据使用protobuf进行编解码（当然它也可以使用其它的编解码方式，比如thrift、JSON，也可以自己造轮子，比如Go的gob）当然grpc作为一个rpc框架，数据的编解码只是其中一小部分，还有很多其它的工作需要处理，参见各种其它框架。



注意：protobuf本身并不是和gRPC绑定的。它也可以被用于非RPC场景，如存储等

## 七、相关资料

官网教程

https://protobuf.dev/

github仓

https://github.com/protocolbuffers/protobuf





## 八、总结

以上就是今天要讲的内容，本文仅仅简单介绍了lwIP的官网主页，后续会有更多内容。



## 九、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
一、 https://blog.csdn.net/Gefangenes/article/details/131319610
二、 ht
三、 Lw







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
