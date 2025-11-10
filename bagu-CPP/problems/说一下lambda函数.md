# lambda函数

## 简要回答

Lambda函数是C++11引入的匿名函数对象，用于**简化单行或短逻辑**代码的就地定义，**无需显式命名和提前声明**

语法为[捕获列表] (参数列表) -> 返回类型 { 函数体 }  

这里返回类型可省略，它就像就是没有名字的“**一次性小函数**”，写代码时直接现场定义用，不用提前声明


## 详细回答

Lambda本质是匿名函数对象（闭包），编译器会为其生成一个未命名的类，并在实例化时捕获外部变量。其核心优势是就地定义、按需使用，避免了传统函数需提前声明或传递的冗余代码。

语法结构：
- 捕获列表：指定如何访问外部变量（**如[=]值捕获、[&]引用捕获**）。
- 参数列表：与普通函数参数一致（可为空）。
- 返回类型：可通过-> 类型显式指定（若仅一行return语句可省略）。
- 函数体：实现具体逻辑。Lambda常与STL算法（如std::sort、std::for_each）或异步编程结合使用。

比如你要比较两个数的大小，直接

auto cmp = [](int a, int b) { return a > b; };

然后就能立刻拿去排序了，省得再单独定义个函数
- 适用场景



1. STL算法：作为谓词（如std::sort的比较函数、std::find_if的条件判断）。
2. 回调函数：事件处理（如GUI点击事件）、异步任务（如线程池任务提交）。
3. 简化代码：短逻辑内联定义（如初始化列表的转换、临时计算）。
4. 闭包特性：捕获外部变量实现状态保持（如循环中绑定当前索引）。
## 代码示例
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 1. 基本Lambda
    auto greet = []() { std::cout << "Hello Lambda!\n"; };
    greet();  // 输出: Hello Lambda!

    // 2. 带参数的Lambda
    auto add = [](int a, int b) { return a + b; };
    std::cout << add(3, 4) << "\n";  // 输出: 7

    // 3. 在STL算法中使用
    std::vector<int> nums{3, 1, 4, 1, 5, 9, 2, 6};
    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;  // 降序排序
    });
    // nums现在是 {9, 6, 5, 4, 3, 2, 1, 1}

    // 4. 捕获局部变量
    int threshold = 5;
    auto count = std::count_if(nums.begin(), nums.end(), 
        [threshold](int x) { return x > threshold; });
    std::cout << count << " numbers > " << threshold << "\n";  // 输出: 2 numbers > 5

    // 5. 可变Lambda (mutable)
    int counter = 0;
    auto incrementer = [counter]() mutable {
        ++counter;
        std::cout << counter << "\n";
    };
    incrementer();  // 输出: 1
    incrementer();  // 输出: 2
    // 注意: 外部的counter仍然是0
}
```


## 知识拓展

- 知识图解

![image](https://file1.kamacoder.com/i/bagu/202508081.png)

![image](https://file1.kamacoder.com/i/bagu/2025080802.png)
- 面试官可能追问

Q1：Lambda 和普通函数指针的区别？

A：
Lambda 可以 捕获外部变量（闭包），函数指针不能。

Lambda 是 对象（编译器生成类），函数指针是纯地址。

Lambda 可内联优化，函数指针间接调用可能有开销。

Q2：[=] 和 [&] 有什么区别？

A：[=] 按值捕获（外部变量的 副本），修改不影响原变量。

[&] 按引用捕获（直接操作原变量），修改会影响外部。

推荐 显式捕获（如 [x, &y]）避免意外修改。

Q3：Lambda 能替代所有函数吗？

A：适合：短小逻辑、局部使用、需要捕获变量的场景。

- 不适合的场景：

复杂函数（可读性差）。

需要复用的逻辑（应定义普通函数）。

递归（需用 std::function 包装）。