# Protocol编译

* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...



protobuf编译是通过编译工具protoc进行的，通过这个编译工具，我们可以把.proto文件生成go, Java, Python, C++, Ruby或者C#代码。



## protoc安装

### 命令行方式

linux版本

```shell
sudo apt update
sudo apt upgrade
sudo apt install libprotobuf-dev protobuf-compiler  
```



### 安装包方式

下载地址： https://github.com/protocolbuffers/ProtoBuf/releases

下载界面



![protobuf下载界面](/home/liubo/00-liubo/project_my/Protobuf_tutorial/picture/protobuf下载界面.png)



linux版本

protoc-25.0-linux-x86_64.zip

windows版本

protoc-25.0-win64.zip



不需要编译，只需将下载得到的可执行文件protoc所在的bin目录加到电脑本地环境变量中。

```shell
protoc --version          //查看版本，判断是否安装成功
libprotoc 3.12.4
```



## 编译工具使用

### 编译命令

使用以下命令来编译.proto文件

```shell
protoc  --cpp_out=./  --cpp_opt=paths=source_relative  *.proto
```

命令将当前目录中的所有.proto文件进行编译并生成C++代码。

编译器会为每个.proto文件创建一个源文件。

输出的文件名是把protobuf文件的扩展名.proto替换为.pb.c或.pb.h。

使用*.proto，必须标明完整路径。



### --proto_path 参数

--proto_path=IMPORT_PATH

- IMPORT_PATH是.proto文件所在的路径，如果省略则默认当前目录。
- 如果有多个目录则可以多次调用--proto_path，它们将会顺序的被访问并执行导入。

### --cpp_out 参数

--cpp_out=OUT_PATH

- 编译工具protoc会将生成的C++代码输出到参数指定的位置即OUT_PATH中。
- OUT_PATH必须存在
- 



## 参数使用示例

```shell
protoc --proto_path=src --cpp_out=out  foo.proto bar.proto
```

假设src文件夹中存有文件foo.prot和bar.proto。编译工具将从src目录中读取输入文件foo.prot和bar.proto，并将输出文件foo.pb.c、foo.pb.h、bar.pb.c、bar.pb.h写入out目录。如果需要，编译器会自动创建嵌套的输出子目录，但不会创建输出目录本身。



















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