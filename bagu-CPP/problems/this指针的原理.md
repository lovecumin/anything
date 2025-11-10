在c++中this指针的原理及存储位置 如何禁止一个类被继承


#### 简要回答
this指针是一个**隐含于**每个**非静态成员函数**中的特殊指针，它是一个**常量指针**（ClassName *const this），其值为调用该成员函数的那个对象的地址。

它用于**在成员函数内部访问对象自身**的成员。

#### 详细回答
- 本质与类型：

this是一个**隐含**的参数，由编译器**自动添加**到所有**非静态成员函数的参数列表**的最前面。

其类型为 ClassName *const this，这意味着**this本身是**一个**常量指针**，指向一个非常量的ClassName对象（除非成员函数被const修饰，那么类型就是 const ClassName *const this）。

- 存储位置：

this指针本身是一个**函数形参**，因此，它和其他函数参数一样，**存储在栈区**（对于x86/ARM等常见架构）。

当通过obj.func()调用函数时，**对象obj的地址**会被作为**实参**传递给**func函数的this形参**。

- 生命周期：

**this指针的生命周期**与任何**其他函数参数**的**生命周期相同**，即在函数被调用时创建，在**函数返回时销毁**。

- 用途：

主要用于**解决成员变量与函数参数同名时的歧义**，以及**在成员函数中返回对象自身的引用**（return *this;），这在链式调用中非常常见。


#### 代码示例

```cpp
#include <iostream>

class MyClass {
public:
    MyClass(int value) : value_(value) {} // 构造函数初始化列表

    void PrintValue() {
        // 这里实际上是通过 this->value_ 来访问的，只是"this->"通常可以省略
        std::cout << "Value: " << value_ << std::endl;
        std::cout << "This address: " << this << std::endl;
    }

    void SetValue(int value_) { // 参数名与成员变量名相同，产生歧义
        // value_ = value_; // 错误！这只是在给参数自己赋值
        this->value_ = value_; // 正确！使用this指针明确指示要赋值给成员变量
    }

    // 返回对象自身的引用以支持链式调用
    MyClass& Add(int n) {
        value_ += n;
        return *this; // 解引用this指针，返回对象本身
    }

private:
    int value_;
};

int main() {
    MyClass obj1(10);
    MyClass obj2(20);

    std::cout << "Address of obj1: " << &obj1 << std::endl;
    obj1.PrintValue(); // 输出地址应与 &obj1 相同

    std::cout << "Address of obj2: " << &obj2 << std::endl;
    obj2.PrintValue(); // 输出地址应与 &obj2 相同

    obj1.SetValue(42);
    obj1.PrintValue(); // 输出 Value: 42

    // 链式调用
    obj2.Add(5).Add(10).PrintValue(); // 输出 Value: 35 (20+5+10)
    return 0;
}
```



#### 知识拓展

const成员函数中的this：在一个被const修饰的成员函数（如 void func() const;）中，**this指针的类型变为 const ClassName *const this**。

这意味着**不能通过这个this指针来修改对象的数据成员**（除非成员被mutable修饰）。

静态成员函数：**静态成员函数**（static member functions）不属于任何一个对象实例，因此它们没有this指针，这也是为什么静态函数不能直接访问类的非静态成员。

继承体系中的this：在继承中，**this指针的类型始终是当前正在执行的成员函数所属类的类型**。

例如，在Base类的函数中，this是Base *const；在Derived类的函数中，this是Derived *const。这使得多态成为可能。

与Python/Java的self/this区别：**原理类似**，但**C++的this是指针，需要解引用（*this）才能得到对象本身**，而Java的this是一个引用，Python的self也是一个显式参数，但它们的使用更直接，**不需要解引用**操作。


- 知识图解

![image](https://file1.kamacoder.com/i/bagu/2025092002.png)

- 面试官可能追问

this指针可以为nullptr吗？

答：**可以，但行为是未定义的**(Undefined Behavior)，如果你通过一个空指针调用成员函数，如 nullptr->func();，在func函数内部，this就是nullptr。

只要不访问成员变量（因为需要通过this寻址），程序可能不会立即崩溃，但这绝对是危险且错误的代码，任何对成员的访问都会导致解引用空指针。

this指针和智能指针的关系？

答：this是一个原生裸指针，它**仅仅是一个地址**，它不拥有所指向对象的所有权，也不管理其生命周期，它和std::shared_ptr或std::unique_ptr这些智能指针是截然不同的概念。

有时你需要从一个对象内部获取一个指向自身的shared_ptr，这时可以使用 std::enable_shared_from_this 这个基类。

为什么静态成员函数没有this指针？

答：因为**静态成员函数与类相关联，而不是与类的任何一个特定对象实例相关联**，调用它不需要一个对象（可以通过类名直接调用ClassName::StaticFunc()），所以自然没有对象地址（this）可以传递。

*this是什么？

答：*this是对this指针进行解引用，得到了this所指向的那个对象本身。它的类型是ClassName&（一个引用）。返回*this常用于实现链式调用（如上面的Add函数示例）。