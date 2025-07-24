static关键字和const关键字的作用

## 简要回答
- static 

声明**静态变量**，静态变量的**生命周期直到程序结束**。

当在函数内部声明静态变量时，即使函数**执行完了也不会释放**它，下次调用该函数时会**保留上次的状态**。


所有静态成员变量**共享一个内存空间**，即无论实例化多少个对象，其中的静态成员都是共享的,**静态成员函数只能访问静态成员变量**。
- const

声明**变量为常量**，使得**变量不能被修改**，避免误操作。

加在指针前面，const int* p可以使得指针指向的元素不变，int* const p可以使得指针指向的位置不变。

加在函数后面void func() const可以使得函数**不会修改任何变量**。

## 详细解答
1. **static的作用**：
用于**控制**变量和函数的**生命周期、作用域和访问权限**。 
- 1）静态局部变量：在函数体内部使用static关键字修饰的变量
特点：其**生命周期与程序的生命周期相同**，但**只能在定义它的函数内部**进行访问。
- 2）静态成员变量：在类中使用static关键字修饰的成员变量
特点：所有对象**共享同一份数据**；在编译阶段分配内存（程序还没运行前，内存分配在全局区），类内声明，类外初始化。
- 3）静态成员函数：在类内使用static关键字修饰的成员函数
特点：所有对象共享同一个函数；静态成员函数只能访问静态成员变量；**静态成员函数**调用可以不需要通过创建类的实例，而是**直接通过类名调用**。
2. **const的作用**：用于指定变量、指针、引用、成员函数等的性质。
- 1）常量变量：声明变量，使变量的值不能修改（**只读**）；
- 2）指针和引用：声明指向常量的指针（指针常量），表示指针的指向的值是常量，不能通过指针修改，但是指针的值（内存地址）可以修改；

  声明常量引用，表示引用的值是常量，不能通过引用修改；
- 3）成员函数：声明**常量成员函数**，表示该函数**不会修改对象的成员变量**；
- 4）常量对象：声明对象为**常量**，使对象的成员变量**不能被修改**；
- 5）常指针参数：声明函数参数为**指向常量的指针**（指针常量），表示函数**不会通过该指针修改传入的数据**；
- 6）常引用参数：声明函数参数为**常量引用**，表示函**数不会修改传入的数据**。
## 代码示例
1. static
- 静态局部变量
```cpp
#include <iostream>
void counter() {
    static int count = 0;  // 初始化仅一次
    count++;
    std::cout << "Count: " << count << std::endl;
}
int main() {
    for (int i = 0; i < 3; i++) counter();  // 输出：1, 2, 3
    return 0;
}
```
- 静态成员变量（类共享数据）
```cpp
class Car {
public:
    static int totalCars;  // 声明
    Car() { totalCars++; }
};
int Car::totalCars = 0;  // 类外初始化

int main() {
    Car a, b;
    std::cout << "Total cars: " << Car::totalCars;  // 输出：2
    return 0;
}
```
- 静态成员函数
```cpp
class MathUtils {
public:
    static double square(double x) { return x * x; }  // 不依赖对象
};
int main() {
    std::cout << MathUtils::square(5);  // 直接通过类调用
    return 0;
}
```
2. const
- 常量变量
```cpp
const int MAX_SIZE = 100;  // 必须初始化
// MAX_SIZE = 200;  // 编译错误
```
- 常量成员函数（对象状态保护）
```cpp
class Student {
    int score;
public:
    int getScore() const { return score; }  // 承诺不修改成员
};
```
- 常量指针与指针常量
```cpp
int a = 10;
int b = 20;
const int* p1 = &a;  // 指向的内容不可改（*p1 只读），指针可变
int* const p2 = &a;  // 指针不可改，指向的内容可变
const int* const p3 = &a;  // 指针和内容都不可变
```
- **口诀** 看 const 位置，谁在 * 的左边谁只读，谁在右边谁固定
## 知识图解拓展
- const关键字和static关键字的示意图
                                                 ![image](https://file1.kamacoder.com/i/bagu/111.jpg)
                                           ![image](https://file1.kamacoder.com/i/bagu/222.jpg)
- ![image](https://file1.kamacoder.com/i/bagu/333.jpg)