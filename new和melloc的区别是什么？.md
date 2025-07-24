new和melloc的区别是什么？

#### 简要回答

new和malloc的区别体现在：

new是**c++的运算符**，malloc是**c的库函数**，**new**不仅**分配内存**，还会**调用构造函数**，new**分配失败会抛出异常**，malloc**分配失败返回NULL**，new用**delete释放**，malloc用**free释放**。

#### 详细回答
1. 内存分配：**new无需指定内存块大小**（自动计算）；**malloc需要显式指定所需内存的大小**（手工计算）
2. 内存分配失败：new不会返回NULL，而是会抛出bad_alloc异常；malloc会返回NULL
3. 是否调用构造/析构函数：new/delete会调用类中的构造/析构函数；malloc不会
4. 是否能够重载：new/delete**能够重载**；malloc/free**不能重载**
5. 本质：new/delete是C++运算符；malloc/free是C++**标准库函数**，在使用时需要**加入头文件**
6. 类型安全：**new 安全**；**malloc不安全**
7. 返回类型：new**返回**的是**定义时具体类型的指针**；malloc返回**void *类型**的指针，使用时**需要强制转换**
8. 数组支持：new支持new[],malloc需要手动计算大小


#### 代码示例
```cpp
// 使用 new
MyClass* obj = new MyClass(10);  // 自动构造
delete obj;                      // 自动析构

// 使用 malloc
MyClass* obj = (MyClass*)malloc(sizeof(MyClass)); // 只分配，不构造
obj->MyClass(10); // 错误写法！不能手动调构造
free(obj);        // 不会调用析构函数
```

#### 知识拓展
- 知识图解
![image](https://file1.kamacoder.com/i/bagu/c++7.png)


- 什么时候用？
可以参考这个表格

| 运用场景                     | 推荐选择                 | 为什么                      |
| ---------------------------- | ------------------------ | --------------------------- |
| C++ 中创建对象               | `new`                    | 类型安全，构造+析构         |
| C 代码中或和 C 交互的模块    | `malloc`                 | 没有 `new`，只能用 `malloc` |
| 使用 POD 类型（无构造/析构） | `malloc`                 | 省事、效率高，像 `char*`    |
| 自定义对象生命周期或池化     | `new` 或 `placement new` | 灵活管理构造过程            |
| 分配未初始化的内存块         | `malloc`                 | 快，但要注意初始化风险      |
| STL容器内部或RAII环境        | `new`                    | 和智能指针等现代C++配套     |


- 面试官可能追问

1. new 和 malloc 的底层实现有什么区别？

答：是否直接调用 brk/sbrk，是否用 operator new，构造函数的作用等。malloc 底层可以直接用 brk/sbr，new不会直接调用，而是通过 operator new间接实现。


补充：这里的brk/sbrk是系统调用，用于向操作系统申请或调整用户进程的堆内存边界。
它的调用顺序：所以 new → operator new → malloc → sbrk / mmap（操作系统底层）。现在brk/sbrk 已不推荐使用，替代方案是 mmap/munmap：其更灵活、线程安全、支持匿名页。


2. 能否用 malloc 分配对象后手动调用构造函数？

答： 可以通过placement new 的方法，比如：
```cpp
void* mem = malloc(sizeof(MyClass));
MyClass* obj = new (mem) MyClass(); // placement new
```

3.new[] 和 new 的区别？为什么 delete[] 不能用 delete 替代？

答：new[] 会记录元素个数，用于后续批量调用析构；delete 只析构一个。

- 简记

new 是 C++ 的对象级操作，负责 “分配 + 构造”；
malloc 是 C 的内存级操作，只管 “分配”，不管活不活（构造）。