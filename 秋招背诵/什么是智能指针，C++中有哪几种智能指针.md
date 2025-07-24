字节面试题:什么是智能指针，C++中有哪几种智能指针?
## 简要回答
智能指针 是一种**自动管理动态内存**的工具类，用于**防止内存泄漏**。

c++提供了三种常用的指针 **unique，share，weak**。

unique**独占所有权**，指针指向的对象**只能有这一个**指针。

shared**共享所有权**，指针**可以有多个**，每释放一个指针变量，指针计数减少一个，到零时释放被指对象，常用来计数。

weak指针是一种**弱指针**，**不拥有资源，防止循环引用**，如果对象在指针还在时被释放，也不会报错，不受影响。
## 详细回答
提到智能指针就必须知道RAII的编程思想，RAII是C++语言的一种**管理资源、避免泄漏**的惯用法。

智能指针是用来自动管理动态内存的工具，通过封装原生指针在适当时机释放内存。

unique_ptr：独占智能指针，独占对象所有权，同一时间只能有一个指针指向一个对象，适合独占资源的场景；**禁止拷贝构造和拷贝赋值，支持移动语义**。

share_ptr：一个**共享所有权**的智能指针，**允许对象之间进行复制或者赋值**，展示出来的就是**值语义**。

使用引用**计数的观点**，当对象之间进行复制或者赋值的时候，引用计数会加+1，当最后一个对象销毁的时候，引用计数减为0，此时会回收托管的空间。

weak_ptr：常用于解决share_ptr**循环引用**的问题，weak_ptr类的对象可以指向shared_ptr，并且不会改变shared_ptr的引用计数。一旦最后一个shared_ptr被销毁时，对象就会被释放。

智能指针则深刻的体现了这种思想。在现代 C++ 编程中，标准库包含智能指针，该指针用于**确保**程序**不存在内存和资源泄漏且是异常安全的**。

智能指针本质就是一个类模板，它可以创建任意的类型的指针对象，当智能指针对象使用完后，对象就会自动调用析构函数去释放该指针所指向的空间。

## 代码示例
1. 独占指针
std::unique_ptr<T> 独占指针,不能拷贝，只能移动，一个资源只能被一个unique管理
```cpp
#include <memory>
std::unique_ptr<int> ptr1(new int(10));
// std::unique_ptr<int> ptr2 = ptr1.  错误，不可拷贝
std::unique_ptr<int> ptr2 = std::move(ptr1); //正确
```
2. 共享指针
    std::shared_ptr<T> 共享指针，多个指针可以共享一个资源，使用**计数器**控制资源释放
```cpp
#include <memory>
std::shared_ptr<int> p1 = std::make_shared<int>(10);
std::shared_ptr<int> p2 = p1;  // 引用计数 +1
```
3. 弱指针
    用于观察共享指针的管理资源，不增加引用计数，防止循环引用
```cpp
std::shared_ptr<int> sp = std::make_shared<int>(42);
std::weak_ptr<int> wp = sp;  // 不增加引用计数
```
4. 三个指针同时运用的例子
```cpp
#include <iostream>
#include <memory>
using namespace std;

class Animal {
public:
    Animal(string name) : name_(name) {
        cout << "Animal " << name_ << " created.\n";
    }
    ~Animal() {
        cout << "Animal " << name_ << " destroyed.\n";
    }
    void speak() {
        cout << "Hi, I'm " << name_ << endl;
    }

private:
    string name_;
};

int main() {
    // 1. 使用 unique_ptr 管理一只独占的小狗
    unique_ptr<Animal> dog = make_unique<Animal>("Dog"); 
    dog->speak();

    // 2. 使用 shared_ptr 管理一只共享的猫
    shared_ptr<Animal> cat1 = make_shared<Animal>("Cat");
    {
        shared_ptr<Animal> cat2 = cat1;  // 共享一份资源
        cout << "Cat use_count = " << cat1.use_count() << endl; // 应该是 2
    } // cat2 离开作用域，引用计数 -1
    cout << "Cat use_count = " << cat1.use_count() << endl; // 应该是 1

    // 3. 使用 weak_ptr 观察 shared_ptr 管理的猫
    weak_ptr<Animal> weakCat = cat1;
    if (auto catShared = weakCat.lock()) {
        catShared->speak();  // 还活着，可以访问
    }

    // cat1 离开作用域后，猫对象自动销毁
    return 0;
}
//==================================//
// 输出结果
Animal Dog created.
Hi, I'm Dog
Animal Cat created.
Cat use_count = 2
Cat use_count = 1
Hi, I'm Cat
Animal Dog destroyed.
Animal Cat destroyed.
```

## 知识拓展
  - 智能指针图解
![image](https://file1.kamacoder.com/i/bagu/1.png)
  - 
  - 什么是RAII机制？
RAII 全称： 
    Resource Acquisition Is Initialization（资源获取即初始化）

    即：当你用一个智能指针去**创建**对象时，它立刻就会接管资源（如内存）；
当智能指针生命周期结束（如**离开作用域、函数返回**等），它会**自动调用析构函数**，把**资源安全释放掉**，**不需要你手动 delete**。

  通俗的讲就是，RAII就是“我拿到资源我就负责到底，我走了我就顺手把它销毁”
```cpp
  {
    std::unique_ptr<int> ptr(new int(10)); // 构造：自动接管资源
    // ...用 ptr 做点什么
} // 离开作用域，析构：自动释放内存
```

  - xxxxxxxxxx35 1#include <iostream>2​3// 父类使用 struct 定义，成员默认 public4struct Base {5    void sayHello() {6        std::cout << "Hello from Base" << std::endl;7    }8};9​10// 1. 用 struct 继承 struct：默认 public 继承（可以访问）11struct DerivedStruct : Base {12    void greet() {13        sayHello();  // 正常访问 Base 的成员14    }15};16​17// 2. 用 class 继承 struct：默认 private 继承（访问失败）18class DerivedClass : Base {19public:20    void greet() {21        sayHello();  // 在类内可以访问（Base 是 private 继承，但类内部仍能访问）22    }23};24​25int main() {26    DerivedStruct ds;27    ds.sayHello();   // 可以访问，因为 public 继承28​29    DerivedClass dc;30    // dc.sayHello(); // 编译错误！sayHello 在 DerivedClass 中是 private31​32    dc.greet();      // 可以正常调用，内部访问没问题33    return 0;34}35​cpp
  
    unique 独家专属，不能复制
  
    shared 合作共赢，数清关系
  
    weak 偷偷观察，不管后事
  
    RAII 是关键，内存不手动