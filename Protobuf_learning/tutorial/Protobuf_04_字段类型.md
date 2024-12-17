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




## Maps



语法：

```protobuf
map<key_type, value_type> map_field = N;
```

- 其中key_type可以是任何整数或字符串类型（因此，除浮点类型和之外的任何标量类型）。请注意， enum 不是有效的key_type.
- value_type可以是除了map以外的任何类型









## 六、总结

以上就是今天要讲的内容，本文仅仅简单介绍了lwIP的官网主页，后续会有更多内容。



## 七、参考资料

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
