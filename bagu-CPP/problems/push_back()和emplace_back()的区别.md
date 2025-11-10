# push_back()和emplace_back()的区别

## 简要回答

push_back() 在容器尾部添加元素时，会先构造一个**临时对象**，然后通过**拷贝或移动构造函**数将其**添加到容器**中。

emplace_back() **直接在容器尾部构造元素**，避免了临时对象的创建，**通常更高效**。

就是说push_back()在容器外面做东西，做好后在放进容器中；emplace_back()直接在容器里面做，省去放入这个动作，因此更高效。

## 详细回答

1. 构造方式：

push_back()：接受一个**已构造的对象**（左值或右值），通过**拷贝或移动**操作将其添加到容器

emplace_back()：**接受构造参数**，直接**在容器内存中构造对象**

2. 效率：

push_back() 可能涉及临时对象构造和拷贝/移动操作

**emplace_back()** 通常**只需一次构造**，避免了**不必要的拷贝/移动**

3. 参数传递：

push_back() **只能接受单一对象参数**

emplace_back() **可以接受多个参数**，直接转发给构造函数

4. 异常安全：

**emplace_back()** 在某些情况下可能**提供更强的异常安全保证**


## 适用场景

| 场景                     | 推荐函数         | 原因                                 |
| ------------------------ | ---------------- | ------------------------------------ |
| 需要传入现有对象         | `push_back()`    | 你已经有了一个对象，直接推入即可     |
| 构造临时对象时           | `emplace_back()` | 直接构造，无需中间变量               |
| 追求性能、避免拷贝开销   | `emplace_back()` | 节省资源，构造效率更高               |
| 容器中元素构造参数较复杂 | `emplace_back()` | 支持多参数构造，避免不必要的中间对象 |


## 代码示例
```cpp
#include <vector>
#include <string>

class Person {
public:
    Person(std::string name, int age) : name_(std::move(name)), age_(age) {
        std::cout << "构造 Person: " << name_ << "\n";
    }
    
    Person(const Person& other) : name_(other.name_), age_(other.age_) {
        std::cout << "拷贝 Person: " << name_ << "\n";
    }
    
    Person(Person&& other) noexcept : name_(std::move(other.name_)), age_(other.age_) {
        std::cout << "移动 Person: " << name_ << "\n";
    }
    
private:
    std::string name_;
    int age_;
};

int main() {
    std::vector<Person> people;
    
    // push_back 示例
    Person p1("Alice", 30);
    people.push_back(p1);  // 拷贝构造
    people.push_back(Person("Bob", 25));  // 构造临时对象 + 移动构造
    
    // emplace_back 示例
    people.emplace_back("Charlie", 40);  // 直接构造
    people.emplace_back(std::string("David"), 35);  // 直接构造
    
    return 0;
}
```

## 知识拓展

- 知识图解
![image](https://file1.kamacoder.com/i/bagu/20250801.png)
- 面试官可能追问

1. 在什么情况下 push_back() 可能比 emplace_back() 更高效？

当对象移动操作比构造更高效时

当已有现成对象且构造代价高于移动时

2. 为什么 emplace_back() 有时会导致代码更难理解？

因为它可以接受构造参数，可能需要查看类定义才能知道实际构造的对象类型

3. 如何决定使用哪种方法？

遵循"有现成用 push，需要构造用 emplace"原则

考虑性能关键路径和代码可读性的平衡

 4. emplace_back() 是否总是避免拷贝/移动？

不总是，如果vector需要扩容，元素仍然需要移动