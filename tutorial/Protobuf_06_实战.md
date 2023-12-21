# Protobuf 实战

* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...







## 编译配置

编写shell文件，自动进行protobuf编译



```shell
#!/bin/sh

# file name:complile.sh
# data:2023.12.21


echo "---protoc begain compile---"

PROTOBUF_PATH=protoc所在路径

# 在build目录下执行，这里的路径以build为当前路径
# 源文件路径 ./proto
# 目标文件路径 ./build/proto
$PROTOBUF_PATH/protoc  -Iproto  --cpp_out=proto   people_info.proto

```



Cmake中调用complile.sh 

```cmake
execute_process(COMMAND   complile.sh)
```

























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
