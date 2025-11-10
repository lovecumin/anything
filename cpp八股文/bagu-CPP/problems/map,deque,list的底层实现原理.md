# map deque list 的实现原理


#### 简要回答

Map：通常基于**哈希表**或**平衡二叉搜索树**实现，提供**键值对**存储，**哈希表**实现（如HashMap）提供**O(1)平均时间复杂度**，**树**实现（如TreeMap）提供**O(log n**)的**有序**访问。

Deque：**双端**队列，通常基于**动态数组或链表**实现，支持**两端高效插入或删除操作**，**数组**实现（如ArrayDeque）提供**O(1)时间复杂度**，空间利用率高。

List：**有序集合**，ArrayList基于动态数组实现，随机访问高效；LinkedList基于双向链表实现，插入删除高效。

#### 详细回答

- Map 实现原理

1.HashMap：

基于**哈希表**（数组+链表/红黑树）

**初始容量**和**负载因子**决定扩容时机

解决哈希冲突：**链表法**（链表长度>8转红黑树）

**非线程安全**，迭代快速失败(fail-fast)

2.TreeMap：

**基于红黑树**（自平衡二叉搜索树）

**保持键的有序性**（自然顺序或Comparator）

插入、删除、查找均为O(log n)

- Deque 实现原理

通常实现为"数组的数组"（**分段连续存储**）

维护一个中央控制器(map)**管理多个固定大小的块**

**头尾插入**无需移动元素，**只需分配新块**

随机访问需要**两次定位：先找块，再找块内偏移**

- list (双向链表)

双向链表节点**包含前后指针和数据**

插入/删除**只需修改相邻节点的指针**

**不支持随机访问，访问需遍历**

**每个元素额外内存开销大**（两个指针）

#### 适用场景

| 容器      | 适合场景                               | 不适合场景                                        |
| --------- | -------------------------------------- | ------------------------------------------------- |
| **map**   | 需要有序键值查找；频繁插入/查找        | 不要求顺序、追求 O(1) 查找（可用 unordered\_map） |
| **deque** | 两端频繁插入/删除；需要随机访问        | 中间插入删除性能差；对元素地址稳定性有要求        |
| **list**  | 中间频繁插入删除；元素地址稳定性要求高 | 需要快速查找；随机访问                            |



#### 代码示例
```cpp
#include <iostream>
#include <map>
#include <unordered_map>
#include <deque>
#include <list>
#include <vector>

int main() {
    // std::map 示例
    std::map<std::string, int> m;
    m["apple"] = 5;
    m["banana"] = 3;
    for (const auto& pair : m) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
    // 输出自动按key排序
    
    // std::unordered_map 示例
    std::unordered_map<std::string, int> um;
    um["zebra"] = 2;
    um["apple"] = 5;
    std::cout << um["apple"] << "\n";  // 快速查找
    
    // std::deque 示例
    std::deque<int> dq = {2, 3, 4};
    dq.push_front(1);  // 前插高效
    dq.push_back(5);   // 后插高效
    std::cout << dq[2] << "\n";  // 随机访问
    
    // std::list 示例
    std::list<int> lst = {1, 2, 4};
    auto it = lst.begin();
    std::advance(it, 2);
    lst.insert(it, 3);  // 中间插入高效
    
    // std::vector 示例
    std::vector<int> vec = {1, 2, 3};
    vec.push_back(4);  // 尾部插入高效
    std::cout << vec[1] << "\n";  // 随机访问
}
```


#### 知识拓展

- 底层实现对比

## 底层实现细节对比

| 结构       | 底层实现         | 扩容机制              | 线程安全 | 允许null      |
| ---------- | ---------------- | --------------------- | -------- | ------------- |
| HashMap    | 数组+链表/红黑树 | 2倍扩容，负载因子0.75 | 不安全   | Key/Value均可 |
| TreeMap    | 红黑树           | 不扩容                | 不安全   | Key不允许     |
| ArrayDeque | 循环数组         | 2倍扩容               | 不安全   | 不允许        |
| LinkedList | 双向链表         | 不扩容                | 不安全   | 允许          |
| ArrayList  | 动态数组         | 1.5倍扩容             | 不安全   | 允许          |

## 时间复杂度对比

| 操作      | HashMap | TreeMap  | ArrayDeque | LinkedList |
| --------- | ------- | -------- | ---------- | ---------- |
| 插入      | O(1)    | O(log n) | O(1)       | O(1)       |
| 删除      | O(1)    | O(log n) | O(1)       | O(1)       |
| 查找      | O(1)    | O(log n) | O(n)       | O(n)       |
| 随机访问  | 不支持  | 不支持   | O(1)       | O(n)       |
| 头/尾操作 | 不支持  | 不支持   | O(1)       | O(1)       |

- 知识图解

![image1](https://file1.kamacoder.com/i/bagu/202507291.png)

![image2](https://file1.kamacoder.com/i/bagu/202507292.png)

![image3](https://file1.kamacoder.com/i/bagu/202507293.png)
- 面试官可能追问

 为什么deque的中间插入操作比list慢？

 deque：需要移动元素维持连续性，平均需要移动n/2个元素，可能涉及多个内存块的元素移动

而list：只需修改相邻节点的指针，不涉及元素移动，操作时间恒定