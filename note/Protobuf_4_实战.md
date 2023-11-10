# Protobuf 实战

* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...



## 安装Protocol编译工具

### 命令行安装

```shell
sudo apt update
sudo apt upgrade
sudo apt install libprotobuf-dev protobuf-compiler  
```



### 安装包安装

下载地址： https://github.com/protocolbuffers/ProtoBuf/releases

下载界面



![protobuf下载界面](/home/liubo/00-liubo/project_my/Protobuf_tutorial/picture/protobuf下载界面.png)



linux版本

protoc-25.0-linux-x86_64.zip

windows版本

protoc-25.0-win64.zip



不需要编译，只需将下载得到的可执行文件protoc所在的bin目录加到我们电脑的环境变量中。



```shell
protoc --version                     //查看版本
```



### .pb.h文件

.pb.h里生成了一个协议数据结构体与操作该结构体的一些接口，有几个message就生成几个类，包括组包与解包（序列化与反序列化）接口，对应的.pb.cc里就是这些接口对应的实现。












protoc [--proto_path=IMPORT_PATH] --cpp_out=DST_DIR path/to/file.proto
protoc 是 Protocol Buffer 提供的命令⾏编译⼯具。

--proto_path 指定 被编译的.proto⽂件所在⽬录，可多次指定。可简写成 -IIMPORT_PATH 。如不指定该参数，则在当前⽬录进⾏搜索。当某个.proto ⽂件 import 其他.proto ⽂件时，或需要编译的 .proto ⽂件不在当前⽬录下，这时就要⽤-I来指定搜索⽬录。

--cpp_out= 指编译后的⽂件为 C++ ⽂件。

DST_DIR 编译后⽣成⽂件的⽬标路径。

path/to/file.proto 要编译的.proto⽂件。





执行命令：protoc --cpp_out=.   ./contacts.proto


protoc   --proto_path=./proto       --cpp_out=./build/proto     ./proto/contacts.proto



编译 .proto 文件

通过定义好的.proto文件来生成Java、Python、C++代码，需要基于.proto文件运行protocol buffer编译器protoc。
编译命令如下：

protoc --proto_path=PATH
	   --cpp_out=DST_DIR
	   --java_out=DST_DIR
	   --python_out=DST_DIR
	   path/xxx.proto

    1
    2
    3
    4
    5
    
    proto_path声明了.proto文件所在目录。如果忽略该值，则使用当前目录。如果有多个目录则可以 对–proto_path 写多次，它们将会顺序的被访问并执行导入。
    DST_DIR声明了cpp_out、java_out、python_out 等对应生成的代码文件路径
    最后的路径是proto文件的具体路径，还可以用*.proto编译对应路径下的所有proto文件

protoc --proto_path=PATH
	   --cpp_out=DST_DIR
	   --java_out=DST_DIR
	   --python_out=DST_DIR
	   path/*.proto

    1
    2
    3
    4
    5

注意

将–proto_path指定为绝对路径时,proto文件不能指定为相对路径。可以删除–proto_path参数(无论如何都默认为当前目录)或者都使用绝对路径


g++ -o contacts ./src/use_contacts.cpp  ./build/proto/contacts.pb.cc -lprotobuf -std=c++11






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
