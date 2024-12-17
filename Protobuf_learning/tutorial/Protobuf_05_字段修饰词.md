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









# 字段修饰词

字段修饰词即消息格式里的role,取值如下：

- optional
- singular
- required
- repeated
- reserved
- 如果未应用显式字段标签，则假定为默认字段标签，称为“隐式字段存在”。类似optional













## 保留字段

当不再需要某个字段时，不建议从消息中删除或注释字段定义，reserved保留字段编号，以确保该编号将不能被重复使用。

例如有两个服务，他们各自使用⼀份.proto文件，内容约定好了是⼀模⼀样的。如果不保留字段编号，对.proto文件进行更新时可能会重用已删除字段编号，当两个服务没有同步更新时可能对该字段编号的定义不一致但并不会报错，这可能会导致严重的问题，包括数据损坏、隐私漏洞等。如果该字段编号用reserved标注，这样，当这个字段编号或者字段名字被重新使用的时候，编译器会报错以避免上述问题。



```protobuf
message Message 
{
	// 设置保留项
	reserved 100, 101, 200 to 299;
	reserved "field3", "field4";
	// 注意：不要在⼀⾏ reserved 声明中同时声明字段编号和名称。
	// reserved 102, "field5";
	// 设置保留项之后，下⾯代码会告警
	int32 field1 = 100; //告警：Field 'field1' uses reserved number 100
	int32 field2 = 101; //告警：Field 'field2' uses reserved number 101
	int32 field3 = 102; //告警：Field name 'field3' is reserved
	int32 field4 = 103; //告警：Field name 'field4' is reserved
}

```







## Oneof

如果您有一条包含多个字段的消息，并且最多同时设置一个字段，可以强制执行此行为并使用 oneof 功能节省内存。

一个oneof共享内存中的所有字段，最多可以同时设置一个字段，其他与常规字段一样。设置oneof的任何成员会自动清除所有其他成员。可以使用case()或WhichOneof()方法检查Oneof中的哪个值被设置(如果有的话)，具体取决于选择的语言。


oneof关键字后跟oneof名称，然后大括号里面包含多个字段。

```protobuf
message SampleMessage {
  oneof test_oneof {
    string name = 4;
    SubMessage sub_message = 9;
  }
}
```

注意：

- oneof字段不能被repeated和map修饰
- 设置oneof字段将自动清除oneof的所有其他成员。因此，如果设置了oneof中的多个字段，则只有最后设置的字段仍然有值。

```c++
SampleMessage message;
message.set_name("name");
CHECK(message.has_name());
message.mutable_sub_message(); // Will clear name field.
CHECK(!message.has_name());
```

- 如果使用的是C++，确保代码不会导致内存崩溃。以下示例代码将会崩溃，因为通过调用set_name()方法已经删除了sub_message。

```c++
SampleMessage message;
SubMessage* sub_message = message.mutable_sub_message();
message.set_name("name");      // 将删除 sub_message
sub_message->set_...            // 这里崩溃了
```

还是在C++中，如果你用Swap()两个带有oneof的消息，则每条消息都将拥有对方的值：在下面的示例中，msg1将拥有sub_message，而msg2将拥有name。

```C++
SampleMessage msg1;
msg1.set_name("name");
SampleMessage msg2;
msg2.mutable_sub_message();
msg1.swap(&msg2);
CHECK(msg1.has_sub_message());
CHECK(msg2.has_name());
```






















## 六、总结

以上就是今天要讲的内容，本文仅仅简单介绍了lwIP的官网主页，后续会有更多内容。



## 七、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
一、 htt
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
