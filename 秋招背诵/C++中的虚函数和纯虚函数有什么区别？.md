C++ 中的虚函数和纯虚函数有什么区别？

#### 简要回答
虚函数(virtual function)是在**基类中**用**virtual关键字**声明的**成员函数**，**允许派生类重写实现，实现运行时多态**。

纯虚函数(pure virtual function)是在**虚函数声明后加=0的函数**，**没有默认实现，强制派生类必须重写**，并使所在类**成为抽象类**(不能实例化)。

通俗意义上可以这么理解：
虚函数就像是基类说"**父类有这个功能，子类可以按需修改**"；纯虚函数则是基类说"**我规定必须有这个功能，但具体怎么实现你们子类自己决定**"。
#### 详细回答

**虚函数**是实现C++运行时多态的核心机制，通过**virtual关键字**声明，当通过**基类指针或引用调用虚函数**时，会根据对象的实际类型**动态绑定**到正确的函数实现。

虚函数可以有**默认实现**，**派生类**可以**选择性重写**，包含虚函数的**类可以实例化**。

**纯虚函数**通过在虚函数声明后**加=0定义，没有默认实现，强制派生类必须重写**。

包含纯虚函数的类称为**抽象类，不能实例化**，纯虚函数用于**定义接口规范**，确保所有派生类都有该功能。



#### 代码详解
- 虚函数
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {  // 虚函数，有默认实现
        cout << "Animal sound" << endl;
    }
    virtual ~Animal() {}  // 虚析构函数
};

class Dog : public Animal {
public:
    void speak() override {  // 重写虚函数
        cout << "Woof!" << endl;
    }
};

int main() {
    Animal* animal = new Dog();
    animal->speak();  // 输出: Woof!
    delete animal;
    return 0;
}
```
- 纯虚函数
```cpp
#include <iostream>
using namespace std;

class Shape {  // 抽象基类
public:
    virtual void draw() = 0;  // 纯虚函数，无实现
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {  // 必须实现纯虚函数
        cout << "Drawing a circle" << endl;
    }
};

int main() {
    // Shape shape;  // 错误: 不能实例化抽象类
    Shape* shape = new Circle();
    shape->draw();  // 输出: Drawing a circle
    delete shape;
    return 0;
}
```
#### 知识拓展
- 知识图解
  ![image](https://file1.kamacoder.com/i/bagu/202507151.png)

  



Derived：是C++继承体系中的术语，指通过派生（derivation）从基类（Base class）创建的新类

![image](https://file1.kamacoder.com/i/bagu/202507152.png.png)

- 拓展
**虚函数表(VTable)工作原理**：

每个包含虚函数的类有一个虚函数表，存储虚函数地址

每个对象有一个虚指针(vptr)指向所属类的VTable

调用虚函数时，通过vptr找到VTable，再跳转到正确函数

- 现代C++特性

**override关键字**：显式标记重写虚函数，编译器会检查是否真的重写了基类虚函数，避免拼写错误：
```cpp
class Derived : public Base {
public:
    void show() override;  // 明确表示重写基类虚函数
};
```
**final关键字**：禁止派生类重写虚函数或禁止类被继承：
```cpp
class Base {
public:
    virtual void show() final;  // 派生类不能重写
};
```
**虚函数的特殊用法**
纯虚函数可以在基类中提供实现，派生类可以显式调用：
```cpp
class Interface {
public:
    virtual void api() = 0;
};

// 纯虚函数的实现
void Interface::api() {
    cout << "Default implementation" << endl;
}

class Impl : public Interface {
public:
    void api() override {
        Interface::api();  // 调用基类实现
        // 添加具体实现
    }
};
```

- 面试官追问

1.为什么构造函数不能是虚函数？

构造函数用于初始化对象，虚函数机制依赖vptr，而vptr在构造函数执行期间才被初始化，形成循环依赖。

即：构造函数的工作是"把对象建出来"，而虚函数机制需要"对象已经存在"才能工作，两者顺序矛盾

2. 什么情况下应该使用纯虚函数？

当基类只规定"要做什么"，但不知道"怎么做"时；当想确保所有子类都有某个功能时，这两种情况

3. 虚函数表是如何工作的？

每个有虚函数的类有一个vtable，存储虚函数指针；每个对象有vptr指向vtable；调用时通过vptr找到vtable再跳转函数。