extern "C"的作用

#### 简要回答

extern "C" 是 C++ 编译器提供的一个**链接规范**（Linkage Specification），其主要作用是指示编译器按照 C 语言的规则来编译和链接其修饰的代码。

这主要体现在函**数名修饰**（Name Mangling）和**调用约定**（Calling Convention）上，目的是为了解决 **C++ 与 C 以及其他语言**在混**合编程时**的链接**兼容性**问题。

简单点说： extern "C" 用于告诉 C++ 编译器，被它修饰的**函数或变量应使用 C 语言的编译和链接规则**，即**不进行**名称修饰（Name Mangling），从而**确保 C++ 代码**可以正确**链接**到**用 C 语言编译的库**或目标代码。

#### 详细回答

核心问题：**名称修饰 **(Name Mangling)

C++ 支持函数重载（Overloading），即**多个函数**可以有**相同的名字**但**不同的参数列表**。

为了在编译后的**二进制代码**中**区分**这些函数，编译器会**对函数名进行复杂的修饰**（Mangling），将参数类型、返回类型等信息**编码到一个新的、唯一的**内部名称中。

举例子，函数 void foo(int) 可能被修饰为 _Z3fooi。

C 语言不支持重载，因此没有名称修饰。

函数 void foo(int) 在**编译后**的符号表中名字**仍然是简单的 foo**。

这是链接时就会出现困境

当一**个 C++ 程序**（main.cpp）试图**调用**一个**由 C 编译器编译的库**（c_lib.a）中的**函数 foo 时**，会发生以下情况：

C++ 编译器在 main.cpp 中看到 foo(...)，会**对其进行名称修饰**（例如，生成`_Z3fooi` ）。

但在**链接阶段**，链接器会**在 C 编译的库**中**寻找符号 `_Z3fooi` **。

**而 C 库中导出的符号名是未修饰的 foo**。

结果：**链接器找不到** _Z3fooi，**报**“undefined reference”**错误**。

extern "C" 的解决方案
通过在 C++ 代码中使用 extern "C" 来声明 C 库中的头文件，明确指示编译器：“**请不要对这里面的函数名进行修饰，直接使用原始的 C 风格名称**。” 

这样，C++ 编译器**生成的目标文件**中寻找的**符号名就是 foo**，**从而能**与 C 库中的 foo 符号**成功链**接。

**调用约定** (Calling Convention)
除了名称修饰，extern "C" 通常也意味着使用 C 语言的调用约定（如 __cdecl），这规定了函数参数如何压栈、栈由谁清理等底层细节，确保了二进制层面的兼容。

#### 代码示例
```cpp
// In my_class.h (C++ header)
class MyClass {
public:
    int doSomethingComplex(int x);
};

// In c_interface.h (C-compatible header)
#ifdef __cplusplus
extern "C" {
#endif
int c_wrapper_do_something(int x);
#ifdef __cplusplus
}
#endif

// In c_interface.cpp
#include "my_class.h"
#include "c_interface.h"

extern "C" int c_wrapper_do_something(int x) {
    MyClass obj; // 在C++内部使用类
    return obj.doSomethingComplex(x); // 调用成员函数
}
```


#### 知识拓展

- 知识图解

![image](https://file1.kamacoder.com/i/bagu/20250820.png)

- 适用场景:

case1:调用 C 语言库：这是最经典的场景，如调用 Linux 的系统 API（glibc）、第三方 C 库（SQLite, Lua, libpng 等）。

case2:C++ 实现被 C 调用：如果你想用 C++ 写一个库，并希望它能被 C 程序调用，也需要在 C++ 的实现文件里用 extern "C" 来导出函数。

case3:与其它语言交互：许多脚本语言（如 Python、Lua）的解释器是用 C 编写的，它们的扩展接口（FFI）通常是 C 风格的。用 C++ 写这些扩展时，必须使用 extern "C" 来导出初始化函数，才能被宿主语言正确识别和加载。