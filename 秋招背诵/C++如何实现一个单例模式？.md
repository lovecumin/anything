C++如何实现一个单例模式？
#### 简要回答

单例模式（Singleton Pattern）确保**某个类在程序运行期间只能有一个实例**，并**提供一个全局访问点**。

常见的 C++ 实现方式：

**饿汉式**：程序启动时立即创建

**懒汉式**：第一次使用时才创建，线程不安全

**双检锁（懒汉式 + 线程安全）**：加锁或使用 std::call_once

**C++11 局部静态变量（Magic Static）**:推荐使用这样，因为这种情景下线程是安全的

#### 详细回答

单例模式通过以下机制确保类的唯一性：

**权限控制**：将构造函数、拷贝构造函数和赋值运算符设为私有或删除，防止外部实例化和拷贝

**静态管家**：类内部维护一个静态成员变量来保存唯一实例

**全局访问点**：提供公共静态方法(通常命名为getInstance)作为获取实例的唯一入口

- 每种单例模式的特点

饿汉式(Eager Initialization)

特点：**程序启动时就创建实例**

优点：实现简单，线程安全

缺点：可能造成资源浪费(实例未被使用时也占用内存)

```cpp
class Singleton {
private:
    static Singleton* instance;
    Singleton() {}
public:
    static Singleton* getInstance() {
        return instance;
    }
};
// 程序启动时初始化
Singleton* Singleton::instance = new Singleton();
```
懒汉式(Lazy Initialization)

特点：**首次请求时才创建实例**

优点：资源利用率高

缺点：基础实现非线程安全
```cpp
class Singleton {
private:
    static Singleton* instance;
    Singleton() {}

public:
    static Singleton* getInstance() {
        if (!instance)
            instance = new Singleton();
        return instance;
    }
};
// 初始化静态成员
Singleton* Singleton::instance = nullptr;
```
双检锁(Double-Checked Locking)

特点：**懒加载+线程安全**

原理：**两次检查**实例是否存在，**中间加锁**
```cpp
class Singleton {
private:
    static Singleton* instance;
    static std::mutex mtx;
    Singleton() {}
public:
    static Singleton* getInstance() {
        if(instance == nullptr) {
            std::lock_guard<std::mutex> lock(mtx);
            if(instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }
};
```

局部静态变量(Magic Static, C++11推荐)

特点：**利用C++11的静态局部变量线程安全特性**

优点：代码简洁，自动线程安全，自动销毁

```cpp
class Singleton {
private:
    Singleton() {}
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
};
```

#### 代码示例
现代C++推荐实现：局部静态变量，这是用的最多的，下面给出一个这种情况下的例子
```cpp
#include <iostream>

class Singleton {
public:
    // 删除拷贝构造和赋值操作
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    // 全局访问点
    static Singleton& getInstance() {
        static Singleton instance; // 线程安全初始化(C++11)
        return instance;
    }
    
    // 示例方法
    void log(const std::string& message) {
        std::cout << "[LOG] " << message << std::endl;
    }

private:
    // 私有构造函数
    Singleton() { std::cout << "Singleton created\n"; }
    ~Singleton() { std::cout << "Singleton destroyed\n"; }
};

int main() {
    Singleton::getInstance().log("Hello World");
    Singleton::getInstance().log("Another message");
    return 0;
}
```


#### 知识拓展
- 单例模式的优缺点

优点：

严格控制实例数量，避免资源浪费,全局访问点简化资源访问

避免频繁创建销毁对象,减少全局变量污染

缺点：

违反单一职责原则（同时管理自身和业务）,且单元测试困难（全局状态难以隔离）

可能隐藏类间依赖关系，多线程环境需要特殊处理

- 知识图解

![image](https://file1.kamacoder.com/i/bagu/1.png)




- 使用场景

比如要实现下列功能时

日志管理器（Logger）

数据库连接池

配置读取器（配置文件只读一次）

驱动设备控制器（如串口、打印机）

游戏中的全局控制器（音效、UI管理）