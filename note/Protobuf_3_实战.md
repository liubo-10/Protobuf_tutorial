# Protobuf 实战

* 👋 Hi, I’m bliu2-10
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...






protoc [--proto_path=IMPORT_PATH] --cpp_out=DST_DIR path/to/file.proto
protoc 是 Protocol Buffer 提供的命令⾏编译⼯具。

--proto_path 指定 被编译的.proto⽂件所在⽬录，可多次指定。可简写成 -IIMPORT_PATH 。如不指定该参数，则在当前⽬录进⾏搜索。当某个.proto ⽂件 import 其他.proto ⽂件时，或需要编译的 .proto ⽂件不在当前⽬录下，这时就要⽤-I来指定搜索⽬录。

--cpp_out= 指编译后的⽂件为 C++ ⽂件。

DST_DIR 编译后⽣成⽂件的⽬标路径。

path/to/file.proto 要编译的.proto⽂件。





执行命令：protoc --cpp_out=.   ./contacts.proto


protoc   --proto_path=./proto       --cpp_out=./build/proto     ./proto/contacts.proto







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
