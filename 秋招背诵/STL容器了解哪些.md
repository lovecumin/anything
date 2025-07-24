STL容器了解哪些
#### 简要回答
C++ STL 中主要有三类容器：

**顺序容器**（Sequence Containers）：如 vector, list, deque, array, forward_list

**关联容器**（Associative Containers）：如 set, map, multiset, multimap

**无序容器**（Unordered Containers）哈希容器：如 unordered_map, unordered_set, unordered_multimap, unordered_multiset

此外，STL 还包括配套的**迭代器、算法、仿函数、适配器**等组件。
#### 详细回答

STL容器可分为三大类：

**序列容器：维护元素的线性序列**

vector：动态数组，支持快速随机访问

deque：双端队列，两端高效插入/删除

list：双向链表，任意位置高效插入/删除

forward_list：单向链表，更节省空间

array：固定大小数组，更安全的原生数组替代

**关联容器：基于键值对的有序存储**

set/multiset：有序唯一/非唯一键集合

map/multimap：有序键值对集合，键唯一/非唯一

**无序关联容器：基于哈希表的存储**

unordered_set/unordered_multiset

unordered_map/unordered_multimap

每种容器在时间复杂度、内存布局和适用场景上有所不同。

STL的容器的特点如下

- 顺序容器

| 容器           | 特点                             |
| -------------- | -------------------------------- |
| `vector`       | 动态数组，随机访问快，尾部插入快 |
| `list`         | 双向链表，任意位置插入/删除快    |
| `deque`        | 双端队列，头尾都能快速插入/删除  |
| `array`        | 固定大小数组（C++11）            |
| `forward_list` | 单向链表（C++11）                |
- 关联容器（有序，基于红黑树）

| 容器       | 特点             |
| ---------- | ---------------- |
| `set`      | 唯一元素自动排序 |
| `multiset` | 元素允许重复     |
| `map`      | 键值对，键唯一   |
| `multimap` | 键值对，键可重复 |

- 无序容器（基于哈希表，C++11）

| 容器                 | 特点             |
| -------------------- | ---------------- |
| `unordered_set`      | 无序唯一集合     |
| `unordered_map`      | 无序键值对       |
| `unordered_multiset` | 无序可重复集合   |
| `unordered_multimap` | 无序可重复键值对 |

#### 代码示例

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3};
    vec.push_back(4);  // 动态数组

    list<int> lst = {10, 20, 30};
    lst.push_front(5); // 双向链表

    set<int> s = {5, 2, 3, 2}; // 自动去重排序
    map<string, int> m = {{"Tom", 90}, {"Jerry", 85}}; // 字典

    unordered_map<string, int> um;
    um["apple"] = 3;
    um["banana"] = 5; // 哈希表

    return 0;
}

```
#### 知识拓展
![image](https://file1.kamacoder.com/i/bagu/1.png)


- 知识图解

- 拓展

STL容器的底层结构：

vector, deque → 动态数组

list, forward_list → 链表

set, map → 红黑树

unordered_* → 哈希表

性能差异（插入、删除、查找）：

vector 随机访问快，但插入慢（中间插入需移动元素）

list 插入删除快，但不支持随机访问

map/set 查找、插入都是 O(logN)，但有序

unordered_map 查找、插入是 O(1) 平均复杂度


- 使用场景

vector：需要随机访问、动态扩容的情况（如图像处理、线性缓存）

list：频繁插入删除数据的场景（如编辑器撤回栈）

map/unordered_map：查找、计数、字典、配置解析（如记录访问次数）

set：需要去重、唯一性判断（如用户 ID 集合）

deque：实现滑动窗口算法、双端队列缓存（如 LRU）