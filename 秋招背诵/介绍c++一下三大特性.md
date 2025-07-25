介绍c++一下三大特性

#### 简要回答

C++的三大特性就是：封装、继承、多态。
一句话概括就是：

封装：把**数据和操作**打包在一起，外人不能随便动，通过public，private，protected保护数据

继承：可以“**复制+扩展**”父类的内容，写代码更省力。

子类通过继承使用父类公开的数据，属性和方法，包括实现继承，接口继承和可视继承

多态：用“**同一种方式**”操作不同的对象，扩展性强。

#### 详细回答
##### 1.封装（Encapsulation）

封装是指把**数据**和**操作数据的方法**包装在类里，通过**访问权限（public、private、protected）**来控制对外的暴露。

好处是**提高安全性**，把实现**细节藏起来**，别人只能用你提供的接口，而**不能直接改内部数据**。

##### 2继承（Inheritance）

继承让**一个类（子类）**拥有**另一个类（父类）**的**属性和行为**，可以**在原有功能的基础上做改进和拓展**。

**有了继承，代码可以复用**，比如定义一个Animal类，再派生出Dog、Cat等具体动物类，不用重复写代码。

##### 3多态（Polymorphism）

多态指的是“**同一种接口，不同的行为**”。
主要有两种：

**编译时多态**（函数重载、运算符重载）**运行时多态**（虚函数+继承）

比如写了一个 speak() 接口，猫、狗调用它表现都不一样，这就是多态的威力。

其中编译时多态又叫**静态多态**，指的是**在编译阶段就确定了函数调用的绑定关系**。

典型方式有两个：函数重载和运算符重载

运行时多态又叫**动态多态**，指的是**在程序运行时根据对象的实际类型来决定调用哪个函数**。

原理是通过**重写父类虚函数**，生成**虚函数表和虚函数指针**，通过**父类**引用指向**不同的子类对象**选取**不同的虚函数表**进而实现多态。
#### 代码示例
```cpp
#include <iostream>
using namespace std;

// 封装
class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) {}
    virtual void speak() {  // 多态：虚函数
        cout << name << " is making a sound." << endl;
    }
};

// 继承
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    void speak() override {  // 重写父类方法，实现运行时多态
        cout << name << " says: Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
    void speak() override {
        cout << name << " says: Meow!" << endl;
    }
};

// 多态的体现
void animalSpeak(Animal* a) {
    a->speak();  // 根据对象的真实类型调用不同的方法
}

int main() {
    Dog d("Buddy");
    Cat c("Kitty");

    animalSpeak(&d);  // 输出：Buddy says: Woof!
    animalSpeak(&c);  // 输出：Kitty says: Meow!
    return 0;
}

```
#### 知识拓展

- 知识图解

![image](https://file1.kamacoder.com/i/bagu/202507121.png)

- 面试官可能追问

1. 编译时多态可以代替运行时多态吗？

答： 不完全可以。

编译时多态（如模板、函数重载）是**在编译期确定函数调用**，适用于参数类型、数量已知的情况。

而运行时多态（虚函数+继承）则是**运行时根据对象真实类型做动态绑定**，适用于“需要统一接口处理不同对象”的情况。

当对象的真实类型在编译时就能确定，并且想避免虚函数开销，可以用**模板+策略模式**模拟运行时多态效果。

2. 虚函数调用的底层机制是怎样的？vtable 和 vptr 是怎么工作的？

答：虚函数背后有三样东西：虚函数表，虚指针，动态绑定过程。

虚函数表（vtable）：
**每个含虚函数的类在编译时**都会生成**一个vtable，里面存的是该类的虚函数地址列表**。

虚指针（vptr）：
**每个对象内部都含一个隐藏的指针（vptr），指向它所属类的vtable**。

动态绑定过程：
如：当用Animal* a = new Dog()时：
创建Dog对象时，会设置a->vptr指向Dog类的vtable。

当调用a->speak()，程序会通过vptr找到Dog类的vtable，调用里边的speak()地址。

- 拓展： 

vtable 是**类级别**的（多个对象共享），vptr是**对象级别**的

3. 能不用虚函数实现运行时多态吗？

答：可以，但要用其他技巧，比如函数指针、策略模式、std::function