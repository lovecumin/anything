free和delete区别的是什么？

#### 简要回答
free是**C语言的函数**，配套malloc使用，**不使用析构函数**

delete是**c++的操作符**，配套new使用，同时**调用析构函数**

#### 详细回答

free配合**malloc()/calloc()/realloc()**使用，它做的事情很简单，**把之前申请的那块内存还给操作系统**，但是它**不会管那块内存存放的是什么数据**，也不会调用析构函数。

自己写的类没有资源释放的逻辑，free是不会管的 

delete是C++的关键词，配合**new**使用，new创建了一个对象，系统会调用构造函数进行初始化，用delete删除一个对象，系统会**先调用析构函数，在释放内存**

若写了自定义类，**使用new**开辟了别的内存，则**必须用delete释放内存**，不能用free，否则会导致资源没有释放干净

如果需要分配了一个数组，则**用new[]**，那么释放的时候一定要**用delete[]** 不能用delete，否则只会析构第一个元素，对象就会彻底暴露了。

#### 代码示例
- free
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    // 分配内存
    Point* p = (Point*)malloc(sizeof(Point));
    p->x = 10;
    p->y = 20;
    
    // 释放内存（注意：不会调用任何析构函数，因为是 C 风格 struct）
    free(p);

    return 0;
}

```
- delete
```cpp
#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    Point() {
        cout << "构造函数调用" << endl;
    }

    ~Point() {
        cout << "析构函数调用" << endl;
    }
};

int main() {
    // 分配对象（构造函数被调用）
    Point* p = new Point();
    p->x = 10;
    p->y = 20;

    // 释放对象（析构函数会被调用）
    delete p;

    return 0;
}

```

#### 知识拓展

- 图解

  ![image](https://file1.kamacoder.com/i/bagu/c++8.png)


- 面试官可能追问
1. 为什么要分delete和delete[]？

答：这是因为 new[] 会在分配的时候偷偷记录元素数量，而 delete[] 会一个一个调用析构函数。如果你用 delete 去释放数组，系统就只析构了第一个对象，其他全漏了，造成内存泄漏或逻辑错误。
```cpp
#include <iostream>
using namespace std;

class Point {
public:
    Point() {
        cout << "构造" << endl;
    }

    ~Point() {
        cout << "析构" << endl;
    }
};

int main() {
    // 创建对象数组
    Point* arr = new Point[3];  // 会调用3次构造函数

    // 正确释放数组
    delete[] arr;  // 会调用3次析构函数

    return 0;
}
```

2. 如果我 delete 一个 nullptr 会怎么样？

答：**没事**，C++ 标准里规定，对 nullptr 调用 delete 是安全的，不会有异常，也不会报错。所以在释放前判不判断是不是空指针，其实都行。

3.  new 和 free 混着用会怎么样？

答：这个是严重错误，叫“**未定义行为**”。有时候能看到程序崩溃，有时候程序能跑但偷偷泄露了内存。

4. free和delete的底层实现是怎样的？


答：free 的本质是调用 **libc**（标准 C 库）里的一段内存释放逻辑，通常向下面这样：一般通过malloc申请一块内存时，会在该内存前面悄悄加上一段标志位（名为metadata）记录这块内存的大小和状态。

然后在使用free释放时先找到p前面的metadata，进行标记为已释放，然后尝试与相邻空闲块进行合并（防止内存碎片），如果这块太大（如128K）可以直接调用munmap回收给内核，否则加入用户的空闲链表中。

delete这个操作符本质上只做了两件事，**先析构函数，再释放内存**

析构函数释放资源，然后再释放内存，本质上调用的还是free,或者更高级的分配器（如tcmalloc等）