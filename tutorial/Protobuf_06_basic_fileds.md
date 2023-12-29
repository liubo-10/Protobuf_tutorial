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



### optional 数值字段 (proto2 and proto3)

```protobuf
optional int32 foo = 1;
```

编译器将生成如下访问器方法：

- bool has_foo（）const：

  如果设置了字段，则返回true。

- int32 foo（）const：

  返回字段的当前值。如果未设置该字段，则返回默认值。

- void set_foo（int32 value）：

  设置字段的值。调用此函数后，has_foo（）将返回true，而foo（）则返回value。

- void clear_foo（）：

  清除字段的值。调用后，has_foo（）将返回false，而foo（）则返回默认值。



对于其他数值字段类型（包括bool），根据标量值类型表，将int32替换为相应的C++类型。



### 隐式数值字段 (proto3)

```protobuf
int32 foo = 1;  // no field label specified, defaults to implicit presence.
```

编译器将生成以下访问器方法：

- int32 foo（）const：

- void set_foo（int32 value）：

- void clear_foo（）：


缺少has_foo()，其他和optional int32一样的

对于其他数值字段类型（包括bool），根据标量值类型表，将int32替换为相应的C++类型。





### optional 字符串字段(proto2 and proto3)

```protobuf
optional string foo = 1;
```

编译器将生成以下访问器方法：

- bool has_foo（）const：

  如果设置了字段，则返回true。

- const string& foo（）const：

  返回字段的当前值。如果未设置该字段，则返回默认值。

- void set_foo(const string& value)：

  设置字段的值。调用此函数后，has_foo（）将返回true，而foo（）则返回value的副本。

- void set_foo(string&& value)（C++11及以上版本）：

  从传递的字符串开始设置字段的值。调用此函数后，has_foo（）将返回true，而foo()则返回value的副本。

  && 是右值引用,rvalue 译为 “read value”，指的是那些可以提供数据值的数据（不一定可以寻址，例如存储于寄存器中的数据）。

- void set_foo（const char* value）：

  使用C样式的以null结尾的字符串设置字段的值。调用此函数后，has_foo()将返回true，而foo()则返回value的副本。

- void set_foo（const char* value，int size）：

  与上面一样，但字符串大小是显式给定的，而不是通过查找null终止符字节来确定的。

- string* mutable_foo（）：

  返回一个指针，指向存储字段值的可变字符串对象。如果在调用之前没有设置字段，则返回的字符串将为空（不是默认值）。调用此函数后，has_foo（）将返回true，而foo（）则返回写入给定字符串的任何值。

- void clear_foo（）：

  清除字段的值。调用此函数后，has_foo（）将返回false，foo（）则返回默认值。

- void set_allocated_foo（string* value）：

  将字符串对象设置为字段，并释放前一个字段值（如果存在）。如果字符串指针不为NULL，则消息将获得已分配字符串对象的所有权，并且has_foo（）将返回true。消息可以随时自由删除分配的字符串对象，因此对该对象的引用可能会无效。否则，如果值为NULL，则行为与调用clear_foo（）相同。

- string* release_foo（）：

  释放字段的所有权并返回字符串对象的指针。调用此函数后，调用者将获得已分配字符串对象的所有权，has_foo（）将返回false，foo（）则返回默认值。





### 隐式字符字段 (proto3)

```protobuf
string foo = 1;
```

编译器将生成以下访问器方法：

- const string& foo（）const：

- void set_foo(const string& value)：

- void set_foo(string&& value)（C++11及以上版本）：

- void set_foo（const char* value）：

- void set_foo（const char* value，int size）：

- string* mutable_foo（）：

- void clear_foo（）：

- void set_allocated_foo（string* value）：

- string* release_foo（）：

缺少has_foo()，其他和optional string一样的









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