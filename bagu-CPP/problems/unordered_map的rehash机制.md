c++中 unordered_map的负载因子与rehash机制

面试时没有回答好问题是很正常的，被面试官质疑时，要有今天不会明天会的底气，面后做好复盘，不在同一道题目上跌倒第二次，今天就从unordered_map的负载因子与rehash机制背起来

#### 简要回答

unordered_map的**负载因子**是**已存储元素数量**与**桶数组大小**的比值。

当负载因子超过预设的最大负载因子时，容器会自动执行 rehash：**创建一个新的、更大的桶数组**，并将所有现有元素重新哈希到新的数组中，以降低每个桶的平均元素数，从而**保证 O(1) 平均时间复杂度**的操作性能。

#### 详细回答

**负载因子**：

定义：**负载因子是衡量哈希表拥挤程度的指标。**

其计算公式为：**负载因子 = size() / bucket_count()。**

其中 size()是容器中键值对的数量，bucket_count()是底层桶数组的大小。

作用：**负载因子直接影响了哈希表的性能**。

**负载因子越高**，意味着**平均每个桶中存储的元素越多**（即**哈希冲突更严重**）。

这**会导致查找、插入**等操作需要**遍历更长的链表**（或更深的树结构），从而**性能下降**。

**最大负载因子**：

**unordered_map有一个默认的最大负载因子**（通常为 1.0）。

当前**负载因子 > 最大负载因子**时，容器**会自动触发 rehash 操作**，以维持操作的效率。

**Rehash 机制**：

触发条件：有两种，分别为**自动触发和手动触发**。

**自动触发**：在插入新元素后，如果计算出的**新负载因子超过了 max_load_factor()，容器会自动 rehash**。

**手动触发**：程序员可以**主动调用 rehash(n)或 reserve(m)函数**。

rehash(n)：**将桶数量设置为至少为 n**。

如果 **n大于 size() / max_load_factor()，则新的 bucket_count()将 >= n**。

reserve(m)：**预留空间，确保在存入 m个元素前不会 rehash**。

它**内部会计算需要多少桶：rehash(ceil(m / max_load_factor()))**。

过程：

**分配一块新的、更大的内存空间作为新的桶数组**。

**遍历旧桶数组中的所有元素**（包括每个桶链表/树上的所有元素）。

根据**元素键的新哈希值**和**新桶数组**的大小，**重新计算每个元素应该归属的新桶的位置**。

将**元素移动到新的桶**中，**释放旧桶数组的内存**。

特点：

Rehash 是一个**相对耗时**的操作，**时间复杂度为 O(n)，其中 n 是容器中元素的数量**。

它还会使所有迭代器失效（但指向元素本身的引用和指针不会失效）。


#### 代码示例

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> myMap;

    // 1. 查看默认的桶数量、最大负载因子
    std::cout << "初始桶数量: " << myMap.bucket_count() << std::endl;
    std::cout << "最大负载因子: " << myMap.max_load_factor() << std::endl; // 通常为 1.0

    // 2. 插入元素，观察负载因子变化和 rehash
    for (int i = 0; i < 1000; ++i) {
        // 在插入前检查，如果负载因子接近最大值，可能会触发rehash
        if (myMap.load_factor() > 0.8) { // 检查当前负载因子
            std::cout << "即将触发rehash... ";
            std::cout << "Size: " << myMap.size();
            std::cout << ", Buckets: " << myMap.bucket_count();
            std::cout << ", Load Factor: " << myMap.load_factor() << std::endl;
        }
        myMap["key" + std::to_string(i)] = i;
    }

    std::cout << "最终桶数量: " << myMap.bucket_count() << std::endl;
    std::cout << "最终负载因子: " << myMap.load_factor() << std::endl;

    // 3. 手动控制 rehash
    std::cout << "\n--- 手动 rehash ---" << std::endl;
    std::unordered_map<std::string, int> myMap2;

    // 在插入大量数据前，先预留空间，避免多次自动rehash
    myMap2.reserve(1000); // 预留1000个元素的空间，内部会自动计算所需的桶数并rehash
    std::cout << "调用 reserve(1000) 后的桶数量: " << myMap2.bucket_count() << std::endl;

    // 或者直接指定桶的数量
    myMap2.rehash(2048);
    std::cout << "调用 rehash(2048) 后的桶数量: " << myMap2.bucket_count() << std::endl;

    return 0;
}
```


#### 知识拓展

- 知识图解

![image](https://file1.kamacoder.com/i/bagu/2025092502.png)

- 适用场景


**适用 unordered_map**：
对单个元素的存取速度要求极高，不需要元素按键排序。

能够提供良好的哈希函数来分散键的分布。

可以接受 rehash 带来的偶尔性能波动和迭代器失效。

**不适用 unordered_map**：
需要元素按键排序，需要稳定的性能，无法接受 rehash 带来的延迟峰值（如实时系统）。

内存非常紧张，因为 unordered_map通常会有一些空桶以保持低负载因子。

键的类型没有合适的哈希函数或哈希函数质量很差。

- 面试官可能追问


Q1:rehash 的复杂度是多少？为什么？

A1:O(n)，其中 n 是元素数量。因为需要遍历每个元素，重新计算哈希并插入到新桶中。

Q2:reserve和 rehash有什么区别？

A2:reserve(n)是从元素数量的角度出发，保证在存入 n 个元素前不会 rehash。它内部会计算需要的桶数。rehash(n)是直接从桶数量的角度出发，设置桶的数量至少为 n。通常更推荐使用 reserve，因为它的语义（预留 n 个元素的空间）更直观。

Q3:rehash 后，迭代器、引用、指针会失效吗？

A3迭代器会全部失效，因为元素已经被移动到了新的内存地址。但是，元素的引用和指针不会失效。因为 rehash 过程是移动元素（节点），而不是复制或改变元素本身在内存中的地址（在常见的节点式实现中）。


Q3除了负载因子，还有什么情况会触发 rehash？

A3:手动调用 rehash()或 reserve()函数。此外，某些操作如 clear()后，实现可能会选择缩小桶数组（但标准不要求），这也可以看作一种 rehash。