# API

* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...





## 定义proto

```protobuf
syntax = "proto3";

//声明是为了防止不同项目之间的命名冲突,编译生成的类将被放置在一个与package名相同的命名空间中。
package tutorial;

message Student {
	uint64 id = 1;
	string name = 2;
	string email = 3;
	
	enum PhoneType {
		MOBILE 	= 0;
		HOME 	= 1;
	}
	
	message PhoneNumber { 
		string number 	= 1;
	    PhoneType type = 2;
	}

	repeated PhoneNumber phone = 4;

}
```



## Protobuf API

Protobuf编译器为每个字段生成配套函数

### 生成文件

```c++
 // optional uint64 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::uint64 id() const;
  void set_id(::google::protobuf::uint64 value);

  // optional string name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional string email = 3;
  void clear_email();
  static const int kEmailFieldNumber = 3;
  const ::std::string& email() const;
  void set_email(const ::std::string& value);
  void set_email(const char* value);
  void set_email(const char* value, size_t size);
  ::std::string* mutable_email();
  ::std::string* release_email();
  void set_allocated_email(::std::string* email);

  // repeated .tutorial.Student.PhoneNumber phone = 4;
  int phone_size() const;
  void clear_phone();
  static const int kPhoneFieldNumber = 4;
  const ::tutorial::Student_PhoneNumber& phone(int index) const;
  ::tutorial::Student_PhoneNumber* mutable_phone(int index);
  ::tutorial::Student_PhoneNumber* add_phone();
  ::google::protobuf::RepeatedPtrField< ::tutorial::Student_PhoneNumber >*
      mutable_phone();
  const ::google::protobuf::RepeatedPtrField< ::tutorial::Student_PhoneNumber >&
      phone() const;
```

### 基本函数：

数值类型的字段只有基本读写函数,比如字段id

- set_XXX函数：设置字段值
- clear_XXX函数：用来将字段重置到空状态



### 额外函数

string类型的name和email有额外的函数：

- mutable_XXX函数：数返回string的直接指针


重复的字段也有一些特殊的函数——如果你看一下重复字段phone的那些函数，就会发现你可以：

- 得到重复字段的 _size（Person 关联了多少个电话号码）。
- 通过索引（index）来获取一个指定的电话号码。
- mutable_phone函数：通过指定的索引（index）来更新一个已经存在的电话号码。
- add_phone函数：向消息（message）中添加另一个电话号码



### 标准消息函数

```c++
void CopyFrom(const Student& from);
void MergeFrom(const Student& from);
void Clear();
bool IsInitialized() const;
```

### 序列化和反序列化

```C++
bool SerializeToString(string* output) const; 
//将消息序列化并储存在指定的string中。注意里面的内容是二进制的，而不是文本；我们只是使用string作为一个很方便的容器。
bool ParseFromString(const string& data); //从给定的string解析消息。
bool SerializeToArray(void * data, int size) const	//将消息序列化至数组
bool ParseFromArray(const void * data, int size)	//从数组解析消息
bool SerializeToOstream(ostream* output) const; //将消息写入到给定的C++ ostream中。
bool ParseFromIstream(istream* input); //从给定的C++ istream解析消息。
```


































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











