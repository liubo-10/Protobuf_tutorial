# 编译 Protobuf 库

* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...



## 下载 Protobuf 源码

Protobuf 有许多版本，以v3.12.4为例，

下载地址在：

https://link.csdn.net/?target=https%3A%2F%2Fgithub.com%2Fprotocolbuffers%2Fprotobuf%2Freleases%2Ftag%2Fv3.14.4



推荐下载 cpp 版本：protobuf-cpp-3.12.4.zip。





## 编译

```shell
unzip protobuf-cpp-3.12.4.zip
cd protobuf-3.11.4/
./configure --prefix=/home/protobuf/
make -j8
make check
make install
```

--prefix= 指明编译完成之后生成的头文件、库文件、可执行文件的路径，如果没有此参数默认在 /usr/local 目录下。

编译成功之后，就可以在对应目录下看到编译出来的库文件和头文件了，包括动态库和静态库，然后就可以将其放置在工程中使用了。








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