c++中 STL中仿函数与lambda表达式的性能对比

面试时没有回答好问题是很正常的，被面试官质疑时，要有今天不会明天会的底气，面后做好复盘，不在同一道题目上跌倒第二次，就从STL内的仿函数和lambda表达式的性能开始。

#### 简要回答

迭代器失效是指**当容器结构发生变化**时，**之前获取的迭代器指向变得无效**的情况。

主要发生在**插入、删除操作后**，具体失效规则取决于容器类型和操作位置。

**失效后**继续使用这些迭代器**会导致未定义行为**。

#### 详细回答
失效的根本原因：

内存重新分配（vector, string, deque），元素位置移动（插入/删除导致），数据结构重构（关联容器删除时），这些情况会导致迭代器失效

按容器类型分类：

序列容器

**vector/string**：**插入**可能引起重新分配，**删除**使后续迭代器失效

**deque**：首尾插入安全，**中间插入复杂；删除影响多个迭代器**

**list/forward_list**：**插入不失效**，只**有被删除元素的迭代器失**效

关联容器

**set/map**：插入不失效，只有**被删除元素的迭代器失效**

**unordered_**：**插入可能引起rehash，使所有迭代器失效**


#### 代码示例

vector的典型失效场景
```cpp
#include <vector>
#include <iostream>

void vector_invalidation_examples() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // 示例1：插入导致重新分配
    auto it = vec.begin();
    std::cout << "Before: " << *it << std::endl; // 输出1
    
    // 插入大量元素导致重新分配
    for(int i = 0; i < 100; ++i) {
        vec.push_back(i);
    }
    // it已失效！未定义行为
    // std::cout << "After reallocation: " << *it << std::endl; // 危险！
    
    // 示例2：删除元素
    vec = {1, 2, 3, 4, 5};
    auto it1 = vec.begin() + 1; // 指向2
    auto it2 = vec.begin() + 3; // 指向4
    
    vec.erase(vec.begin() + 2); // 删除3
    std::cout << *it1 << std::endl; // 安全，输出2
    // std::cout << *it2 << std::endl; // 危险！it2已失效
}
```
正确使用方式
```cpp
#include <vector>
#include <list>
#include <map>

void correct_usage_examples() {
    // vector删除时的正确做法
    std::vector<int> vec = {1, 2, 3, 4, 3, 5};
    for(auto it = vec.begin(); it != vec.end(); ) {
        if(*it == 3) {
            it = vec.erase(it); // erase返回下一个有效迭代器
        } else {
            ++it;
        }
    }
    
    // list删除更安全
    std::list<int> lst = {1, 2, 3, 4, 5};
    auto lit = lst.begin();
    ++lit; // 指向2
    lst.erase(lst.begin()); // 删除1，lit仍然有效
    std::cout << *lit << std::endl; // 安全，输出2
    
    // map删除
    std::map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};
    auto mit = myMap.find(2);
    if(mit != myMap.end()) {
        myMap.erase(mit); // 只有被删除的迭代器失效
    }
    // 其他迭代器仍然有效
}
```


#### 知识拓展

- 迭代器失效规则总结表

```text
// 不同容器的失效规则总结

容器类型        | 插入操作                 | 删除操作
---------------+-------------------------+-------------------------
vector/string  | 可能全部失效(重新分配)   | 被删元素及之后全部失效
deque          | 可能全部失效             | 被删元素及之后可能失效  
list           | 不会失效                | 只有被删元素失效
map/set        | 不会失效                | 只有被删元素失效
unordered_*    | 可能全部失效(rehash)     | 只有被删元素失效

```

- 知识图解

![image](https://file1.kamacoder.com/i/bagu/2025092601.png)

![image](https://file1.kamacoder.com/i/bagu/2025092602.png)

- 适用场景
```cpp
// 场景1：循环中删除元素
void safe_erase_in_loop() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // 错误做法
    // for(auto it = vec.begin(); it != vec.end(); ++it) {
    //     if(*it % 2 == 0) {
    //         vec.erase(it); // it失效后++it未定义
    //     }
    // }
    
    // 正确做法1：使用返回值
    for(auto it = vec.begin(); it != vec.end(); ) {
        if(*it % 2 == 0) {
            it = vec.erase(it);
        } else {
            ++it;
        }
    }
    
    // 正确做法2：使用算法
    vec.erase(std::remove_if(vec.begin(), vec.end(), 
                            [](int x) { return x % 2 == 0; }), 
              vec.end());
}

// 场景2：多迭代器操作
void multiple_iterators() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it1 = vec.begin() + 1; // 指向2
    auto it2 = vec.begin() + 3; // 指向4
    
    vec.erase(vec.begin() + 2); // 删除3
    // it1仍然有效，it2失效！
    
    // 正确：重新获取迭代器
    it2 = vec.begin() + 2; // 重新指向新位置
}
```

- 面试官可能追问


Q1:"如何在多线程环境中处理迭代器失效？"

A1: 使用互斥锁保护容器操作;避免在迭代过程中修改容器;考虑使用线程安全容器

Q2:"调试迭代器失效问题有哪些技巧？"

A2:使用调试版本的STL,比如#define _GLIBCXX_DEBUG，它会检查迭代器有效性，抛出异常