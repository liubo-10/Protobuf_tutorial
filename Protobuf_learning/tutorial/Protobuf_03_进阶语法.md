* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...



# 数据描述语法





## 复杂字段修饰词

### 枚举

枚举类型名使用驼峰拼写法(CamelCase )，值名使用大写字母加下划线(CAPITALS_WITH_UNDERSCORES)

protobuf中枚举类型构建规则如下：

- 必须有一个零值，以便我们可以使用0作为数字默认值。
- 零值必须是第一个元素，以便与proto2语义兼容，其中第一个枚举值始终是默认值。
- 不要使用负数作为枚举值，编码效率低。
- 每个枚举值应以分号结束，而不是逗号。



```protobuf
enum Foo {
  FIRST_VALUE = 0;
  SECOND_VALUE = 1;
}

message SearchRequest {
  string query = 1;
  int32 page_number = 2;
  int32 result_per_page = 3;
  enum Corpus {
    UNIVERSAL = 0;
    WEB = 1;
    IMAGES = 2;
    LOCAL = 3;
    NEWS = 4;
    PRODUCTS = 5;
    VIDEO = 6;
  }
  Corpus corpus = 4;
}
```



可以通过为不同的枚举常量分配相同的值来定义别名。为此，需要将allow_alias选项设置为true，否则协议编译器会在找到别名时生成错误消息。

```protobuf
enum EnumAllowingAlias {
  option allow_alias = true;
  UNKNOWN = 0;
  STARTED = 1;
  RUNNING = 1;
}
enum EnumNotAllowingAlias {
  UNKNOWN = 0;
  STARTED = 1;
  // RUNNING = 1;  // Uncommenting this line will cause a compile error inside Google and a warning message outside.
}
```

如果你在版本开发的过程中移除了某个枚举，但是在老的协议中还会使用，可以使用reserved关键字标识。 请注意，不能在同一保留语句中混合字段名和数值。

```protobuf
enum Foo {
  reserved 2, 15, 9 to 11, 40 to max;
  reserved "FOO", "BAR";
}
```



### 消息类型

可以使用其他消息类型作为字段类型

```protobuf
message Result {
  string url = 1;
  string title = 2;
  repeated string snippets = 3;
}
message SearchResponse {
  repeated Result results = 1;
}
```

## 消息嵌套

可以在其他消息类型中定义和使用消息类型，如下例：

```protobuf
message SearchResponse {
  message Result {
    string url = 1;
    string title = 2;
    repeated string snippets = 3;
  }
  repeated Result results = 1;
}
```

如果想在其父消息类型之外重用此消息类型，则需要先指定它的父类型，如下所示:

```protobuf
message SomeOtherMessage {
  SearchResponse.Result result = 1;
}
```

可以多重嵌套

```protobuf
message Outer {                  // Level 0
  message MiddleAA {  // Level 1
    message Inner {   // Level 2
      int64 ival = 1;
      bool  booly = 2;
    }
  }
  message MiddleBB {  // Level 1
    message Inner {   // Level 2
      int32 ival = 1;
      bool  booly = 2;
    }
  }
}
```





## 添加注释

proto 添加注释,使用 C/C++风格的 // 或者 /* … */ 语法.





## 服务

如果要在RPC（Remote Procedure Call，远程过程调用）系统中使用消息类型，可以在.proto文件中定义RPC服务接口，协议缓冲区编译器将根据所选语言生成服务接口代码和存根。

```protobuf
service FooService {
  rpc GetSomething(FooRequest) returns (FooResponse);
}
```



更新消息类型

如果现有的消息类型不满足你的所有需求——例如，你希望消息格式有一个额外的字段——但是你仍然希望使用用旧格式创建的代码，别担心！在不破坏任何现有代码的情况下更新消息类型非常简单。请记住以下规则:

- 不要更改任何现有字段的字段编号。
- 如果您添加新字段，则使用“旧”消息格式的代码序列化的任何消息仍然可以由新生成的代码解析。您应该记住这些元素的默认值，以便新代码可以正确地与旧代码生成的消息交互。类似地，新代码创建的消息可以由旧代码解析：旧二进制文件在解析时会忽略新字段。有关详细信息，请参阅未知字段部分。
- 只要在更新的消息类型中不再使用字段编号，就可以删除字段。您可能想要重命名该字段，可能添加前缀“OBSOLETE_”，或将字段编号设为保留，以便您的未来用户.proto不会意外重用该编号。
- int32、uint32、int64、uint64和bool都是兼容的——这意味着您可以将字段从其中一种类型更改为另一种类型，而不会破坏向前或向后兼容性。如果从不适合相应类型的线路中解析出一个数字，您将获得与在 C++ 中将该数字强制转换为该类型相同的效果（例如，如果将 64 位数字读取为int32，它将被截断为 32 位）。
- sint32并且sint64彼此兼容，但与其他整数类型不兼容。
- 只要字节是有效的UTF - 8，string和bytes就兼容
- fixed32与sfixed32兼容， fixed64与sfixed64兼容。
- …





## Maps



语法：

```protobuf
map<key_type, value_type> map_field = N;
```

- 其中key_type可以是任何整数或字符串类型（因此，除浮点类型和之外的任何标量类型）。请注意， enum 不是有效的key_type.
- value_type可以是除了map以外的任何类型



















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







