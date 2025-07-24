C++构造函数有几种，分别什么作用？

#### 简要回答
C++构造函数主要有以下几种：

**默认构造函数**：**无参或所有参数都有默认值**，用于创建对象时的默认初始化。

**参数化构造函数**：**带参数**，用于创建对象时进行特定初始化。

**拷贝构造函数**：接受**同类型对象的引用**，用于通过已有对象初始化新对象。

**移动构造函数**(C++11)：接受同类型对象的**右值引用**，用于**资源的高效转移**。

**委托构造函数**(C++11)：一个构造函数可以**调用同类中的其他构造函数**。

**继承构造函数**(C++11)：派生类可以**直接使用基类的构造函数**。
#### 详细回答
**默认构造函数**

如果**没有显式定义任何构造函数**，**编译器会自动生成**一个默认构造函数。

如果定义了其他构造函数，编译器不会自动生成默认构造函数，除非显式声明 = default。

**参数化构造函数**

允许**在创建对象时传入参数**，**直接初始化成员变量**。

可以**重载多个版本**以适应不同的初始化需求。

**拷贝构造函数**

形式为**ClassName(const ClassName& other)**，用于**深拷贝或浅拷贝**。

如果**未定义，编译器会生成一个默认的**拷贝构造函数（按成员浅拷贝）。

**移动构造函数**

形式为 ClassName(ClassName&& other)，**用于“窃取”临时对象（右值）的资源**，避免不必要的拷贝。

典型应用场景：STL容器、智能指针等需要高效资源管理的场景。

**委托构造函数**

允许一个构造函数**调用同类中的其他构造函数，避免代码重复**。

示例：ClassName() : ClassName(0, 0) {}。

**继承构造函数**

派生类通过**using Base::Base**直接继承基类的构造函数（C++11特性）。

注意：**继承的构造函数不会初始化派生类新增的成员**。



#### 代码示例
```cpp
#include <iostream>
#include <utility>

class Example {
public:
    int* data;

    // 1. 默认构造函数
    Example() : data(new int(0)) {
        std::cout << "Default constructor\n";
    }

    // 2. 参数化构造函数
    Example(int val) : data(new int(val)) {
        std::cout << "Parameterized constructor\n";
    }

    // 3. 拷贝构造函数
    Example(const Example& other) : data(new int(*other.data)) {
        std::cout << "Copy constructor\n";
    }

    // 4. 移动构造函数
    Example(Example&& other) noexcept : data(other.data) {
        other.data = nullptr; // 防止析构时释放资源
        std::cout << "Move constructor\n";
    }

    // 5. 委托构造函数
    Example(int a, int b) : Example(a + b) {
        std::cout << "Delegating constructor\n";
    }

    ~Example() {
        delete data;
        std::cout << "Destructor\n";
    }
};

// 6. 继承构造函数示例
class Derived : public Example {
public:
    using Example::Example; // 继承基类构造函数
    int derived_member = 42;
};

int main() {
    Example obj1;            // 默认构造
    Example obj2(10);        // 参数化构造
    Example obj3(obj2);      // 拷贝构造
    Example obj4(std::move(obj2)); // 移动构造
    Example obj5(1, 2);      // 委托构造
    Derived d(100);          // 继承构造
    std::cout << *d.data << " " << d.derived_member << "\n";
    return 0;
}
```
#### 知识拓展
- 知识图解
![image](https://file1.kamacoder.com/i/bagu/1.png)


- 面试官可能追问

为什么需要移动构造函数？

答：**避免深拷贝临时对象的资源，提升性能**（如 std::vector 的 push_back 使用移动语义）。

拷贝构造函数参数为什么必须是 const 引用？

答：**避免无限递归调用拷贝构造**，同时支持常量对象的拷贝。

什么情况下编译器不会生成默认构造函数？

答：当用户定义了其他构造函数时，**除非显式声明 = default。**