C++怎么实现多态
#### 简要回答
C++通过**虚函数(virtual function)和继承**实现多态。基**类中声明虚函数，派生类可以重写(override)这些函数**。

通过**基类指针或引用**调用虚函数时，会根据**实际对象类型**调用相应的函数实现。
#### 详细回答
C++多态分为**编译时多态**和**运行时多态**：

编译时多态：通过**函数重载和模板**实现

运行时多态：通过**虚函数和继承**实现

虚函数表(vtable)：每个**包含虚函数的类**都有一个**虚函数表**，存储**虚函数地址**

虚指针(vptr)：每个**对象**包含一个**指向其类虚函数表的指针**

动态绑定：通过vptr在**运行时**确定**调用哪个函数实现**

总结： C++ 多态 = virtual + 继承 + 基类指针/引用调用 + 重写
#### 代码示意
```cpp
#include <iostream>
using namespace std;

// 基类：动物
class Animal {
public:
    virtual void say() {  // 加virtual才能被重写
        cout << "我是动物" << endl;
    }
    virtual ~Animal() {}  // 记得写虚析构
};

// 派生类：狗
class Dog : public Animal {
public:
    void say() override {  // override明确表示重写
        cout << "汪汪汪" << endl;
    }
};

// 派生类：猫
class Cat : public Animal {
public:
    void say() override {
        cout << "喵喵喵" << endl;
    }
};

int main() {
    Animal* myPets[2];
    myPets[0] = new Dog();  // 狗对象
    myPets[1] = new Cat();  // 猫对象
    
    // 同样的调用，不同表现
    for (int i = 0; i < 2; ++i) {
        myPets[i]->say();
        delete myPets[i];
    }
    
    return 0;
}
```

#### 知识拓展

- 知识图解
![image](https://file1.kamacoder.com/i/bagu/1.png)

多态调用过程示例：

Animal* animal = new Dog();

animal->speak();

(1)通过animal指针找到Dog对象

(2)通过对象的vptr找到Dog类的虚函数表

(3)在虚表中查找speak()的地址

(4)跳转到Dog::speak()执行

- 拓展
抽象类：用 =0 表示必须重写，比如virtual void run()=0，使类成为抽象类

c++11新特性涉及override和final两个，其中**override明确表示要重写**，**final表示禁止子类重写**

性能方面：**虚函数调用**比普通函数**稍慢**一些

- 面试官可能追问

多态的底层是咋实现的？

答： 每个带**virtual的类**，编译器会悄悄搞一张**表**，叫**虚函数表（vtable）**，里面列着**所有虚函数的地址**。

然后**每个对象里，会藏一个指针，指着这张表（这个指针叫 vptr）**。

调用虚函数时，其实是通过 **vptr 去 vtable 里找对应的函数地址，然后跳转执行**,这叫**动态绑定**。