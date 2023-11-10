# Protobuf 简介

* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...





## 复杂字段类型

### 枚举

枚举类型名使用CamelCase (带首字母大写)，值名使用CAPITALS_WITH_UNDERSCORES:

- 每个枚举定义必须包含一个映射到零的常量作为第一个元素
- 注意：不要使用负数作为枚举值，编码效率低。
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



**可以通过为不同的枚举常量分配相同的值来定义别名**。为此，您需要将allow_alias选项设置为true，否则协议编译器会在找到别名时生成错误消息。







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





如果你在版本开发的过程中移除了某个枚举，但是在老的协议中还会使用，可以使用reserved 关键字标识。 请注意，不能在同一保留语句中混合字段名和数值。







```protobuf
enum Foo {
  reserved 2, 15, 9 to 11, 40 to max;
  reserved "FOO", "BAR";
}
```





## 添加注释

proto 添加注释,使用 C/C++风格的 // 或者 /* … */ 语法.







## 默认值

当解析 message 时，如果被编码的message里没有包含某些变量，那么根据类型不同，他们会有不同的默认值：

- string：默认是空的字符串
- byte：默认是空的bytes
- bool：默认为false
- numeric：默认为0
- enums：定义在第一位的枚举值，也就是0
- messages：根据生成的不同语言有不同的表现



收到数据反序列化后，对于标准值类型的数据，比如bool，如果它的值是false，那么我们无法判断这个值是对方设置的，还是对方压根就没给这个变量设置值。







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

