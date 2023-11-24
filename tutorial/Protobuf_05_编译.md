# protobuf编译

* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...



## 编译器使用

protobuf编译是通过编译器 protoc 进行的，通过这个编译器，我们可以把 .proto 文件生成 go,Java,Python,C++, Ruby或者C# 代码

可以使用以下命令来通过 .proto 文件生成C++代码（以及grpc代码）

```shell
 // 将当前目录中的所有 .proto文件进行编译生成C++代码
 protoc  --cpp_out=./  --go_opt=paths=source_relative  *.proto
```

protobuf 编译器会把 .proto 文件编译成 .pd.h 文件

## --proto_path 参数

--proto_path=IMPORT_PATH

- IMPORT_PATH是.proto文件所在的路径，如果省略则默认当前目录。
- 如果有多个目录则可以多次调用--proto_path，它们将会顺序的被访问并执行导入。

## --cpp_out 参数

作用：指定生成代码为C++，并指定生成的基本路径

- protocol buffer编译器会将生成的C++代码输出到命令行参数--cpp_out指定的位置

- --cpp_out等号后面的参数是编译器编译输出.h文件的目录
- 编译器会为每个.proto 文件创建一个源文件

- 输出的文件名是把protobuf文件的扩展名.proto替换为.pb.h而创建

## --cpp_opt 参数

protobuf编译提供了--cpp_opt参数来为其指定参数，可以设置多个：

- paths=import：生成的文件会按cpp_package路径来生成，当然是在--cpp_out指定的目录

  例如，cpp_out/$cpp_package/pb_filename.pb.go。如果未指定路径标志，这就是默认输出模式

- paths=source_relative：输出文件与输入文件放在相同的目录中

  例如，一个protos/buzz.proto输入文件会产生一个位于protos/的输出文件buzz.pb.h。

- module=$PREFIX：输出文件放在以C++包的导入路径命名的目录中，但是从输出文件名中删除了指定的目录前缀。

  例如，输入文件 pros/buzz.proto，其导入路径为example.com/project/protos/fizz 并指定example.com/project为module前缀，结果会产生一个名为pros/fizz/buzz.pb.h的输出文件。在module路径之外生成任何C++包都会导致错误，此模式对于将生成的文件直接输出到C++模块非常有用。



## 使用示例

```shell
protoc --proto_path=src --cpp_out=out --cpp_opt=paths=source_relative foo.proto bar/baz.proto
```

编译器将从src目录中读取输入文件foo.prot和bar/baz.proto，并将输出文件foo.pb.go和bar/baz.pb.go写入 out目录。如果需要，编译器会自动创建嵌套的输出子目录，但不会创建输出目录本身










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