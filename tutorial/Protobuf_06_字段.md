# 字段

* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...























协议缓冲区编译器还为.proto文件中消息中定义的每个字段生成一组访问器方法。这些方法采用小写字母蛇形命名法，例如has_foo（）和clear_foo（）。



除了访问器方法外，编译器还为每个包含其字段号的字段生成一个整数常量。常量名称是字母k加转换为大小写的字段名再后加FieldNumber。例如，给定可选字段int32 foo_bar=5；，编译器将生成常量静态常量int kFooBarFieldNumber=5；。



对于返回常量引用的字段访问器，当对消息进行下一次修改访问时，该引用可能会无效。这包括调用任何字段的任何非常量访问器，调用从Message继承的任何非常数方法，或通过其他方式修改消息（例如，将消息用作Swap（）的参数）。相应地，只有在没有对消息进行修改访问的情况下，才能保证返回引用的地址在访问器的不同调用中是相同的。



对于返回指针的字段访问器，当对消息进行下一次修改或非修改访问时，该指针可能无效。这包括，无论常量如何，调用任何字段的任何访问器，调用从Message继承的任何方法，或通过其他方式访问消息（例如，使用复制构造函数复制消息）。相应地，返回指针的值在访问器的两个不同调用中永远不能保证相同。











### Optional 数值字段 (proto2 and proto3)









```protobuf
optional int32 foo = 1;
required int32 foo = 1;
```



编译器将生成如下访问器方法







bool has_foo（）const：如果设置了字段，则返回true。

int32 foo（）const：返回字段的当前值。如果未设置该字段，则返回默认值。

void set_foo（int32 value）：设置字段的值。

  调用此函数后，has_foo（）将返回true，而foo（）则返回value。

void clear_foo（）：清除字段的值。

  调用后，has_foo（）将返回false，而foo（）则返回默认值。



对于其他数值字段类型（包括bool），根据标量值类型表，将int32替换为相应的C++类型。











































​    






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