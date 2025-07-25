面试官问，重载和重写，又追着问virtual 和 override的区别，我有亿点点懵

简述一下 C++ 的重载和重写，以及它们的区别和实现方式。
#### 简要回答
重载（Overload）：**函数名相同，参数不同，发生在同一个作用域**（类内）。

即在同一个类里，函数名字一样，但参数不一样，编译器自己能分清。

重写（Override）：派生类中重写父类的虚函数，函数名、参数、返回值完全相同，使用**virtual 和 override 关键字**。

即**子类把父类的虚函数重新写一遍**，运行时决定用哪一个。

#### 详细回答
- 重载（函数重载 Function Overloading）

重载就是**一个函数名可以用好几次**，只要**参数类型或者个数不一样就行**。比如你写个 print 函数，可以传 int、float、string，各自有不同的实现，这就是重载。

它有以下三个特点
1. 发生在同一个类里面
2. 编译器在编译的时候能决定哪个用，叫编译期多态，属于静态绑
3. 和返回值没有关系，不能光靠返回值来区分重载

- 重写（函数重写 Function Overriding）

重写就是**子类**对**父类里的虚函数**重新写一遍，达到“改写原来功能”的目的。

它有以下四个特点
1. 必须有继承关系
2. 父类函数要有virtual类型
3. 子类函数和父类一模一样（名字、参数、返回值都不能改）
4. 最好写上override，避免写错（c++11提倡这么写）

#### 代码示例
- 重载
```cpp
class Printer {
public:
    void show(int x) {
        std::cout << "打印 int: " << x << std::endl;
    }

    void show(double x) {
        std::cout << "打印 double: " << x << std::endl;
    }
};
// 同一个类，函数名一样，参数不一样，这就是重载
```
- 重写
```cpp
class Animal {
public:
    virtual void speak() {
        std::cout << "动物在叫" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "狗在叫：汪汪汪" << std::endl;
    }
};

// 用父类指针调用：
Animal* a = new Dog();
a->speak();  // 输出：狗在叫：汪汪汪
```

#### 知识拓展

- 知识图解
![image](https://file1.kamacoder.com/i/bagu/202507131.jpg)

- 什么是虚函数

答：virtual 是用来支持“**多态**”的关键字。**它告诉编译器，这个函数将来可能会被“子类改写”，所以真正调用哪个版本，要在运行时决定**。

- 面试官可能追问

1. 重载能不能靠返回值来区分？

答： 不行，编译器光看返回值分不清哪个函数，得靠参数。

2. override 有啥用？

答： 防止你写错函数签名，比如你拼错了参数，它能报错。

3. 不加 virtual 会怎样？

答： 那就不是重写，调用的是父类的函数，不是子类的。
4. virtual 和 override 的区别？

答： virtual 是用在父类函数上，告诉编译器：“这个函数以后可能会被重写”；
override 是用在子类函数上，告诉编译器：“我就是要重写你父类的函数”。

5. virtual 和 override 哪个必须？

答： virtual 是前提，父类必须是虚函数；override 是附加保障，算是一种检查机制。