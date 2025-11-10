说一下select，poll和epoll

#### 简要回答

select、poll和epoll都是Linux系统中用于**I/O多路复用**的机制，允许**单个线程监视多个文件描述符**的就绪状态。

select是**最早**的实现，**有**文件描述符**数量限制**；

poll**改进了select的局限性**，但性能**在大规模连接时仍不理想**；

epoll是**Linux特有的**高性能实现，使用事**件驱动模型**，适合处理**大量并发连接**。
#### 详细回答

- 1.select:

最早出现的**I/O多路复用机制**

使用**位图**(**fd_set**)表示文件描述符集合

默认**限制为1024个文件描述符**(FD_SETSIZE)

**每次调用需要重新设置监控集合**

采用**轮询方式**检查就绪状态，时间复杂度**O(n)**

- 2.poll:

**改进select**的文件描述符**数量限制**

使**用pollfd结构数组**代替**位图**

**没有**最大文件描述符**数量**的硬性**限制**

仍然**需要遍历所有描述符检查就绪状态**

每次**调用需要**复制整个描**述符数组到内核**

- 3.epoll:

Linux特有的**高性能**I/O多路复用机制

使用**事件驱动模型**，**无需轮询**

支持**边缘触发(ET)和水平触发(LT)模式**

使用**红黑树存储**监控的描述符，高效管理大量连接

就绪列表直接返回已就绪的描述符，**时间复杂度O(1)**

使用**mmap加速内核**与用户**空间的数据交换**


#### 代码示例
```cpp
// select 示例

fd_set readfds;
FD_ZERO(&readfds);
FD_SET(sockfd, &readfds);

struct timeval tv;
tv.tv_sec = 5;
tv.tv_usec = 0;

int ret = select(sockfd+1, &readfds, NULL, NULL, &tv);
if (ret > 0) {
    if (FD_ISSET(sockfd, &readfds)) {
        // 处理可读事件
    }
}
// poll 示例

struct pollfd fds[1];
fds[0].fd = sockfd;
fds[0].events = POLLIN;

int ret = poll(fds, 1, 5000);
if (ret > 0) {
    if (fds[0].revents & POLLIN) {
        // 处理可读事件
    }
}

// epoll 示例

int epfd = epoll_create1(0);
struct epoll_event ev, events[10];
ev.events = EPOLLIN;
ev.data.fd = sockfd;

epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &ev);

int nfds = epoll_wait(epfd, events, 10, 5000);
for (int i = 0; i < nfds; i++) {
    if (events[i].data.fd == sockfd) {
        // 处理可读事件
    }
}
```


#### 知识拓展

- 三者性能对比:

连接数少时，三者性能差异不大

连接数**超过1000**时，select/poll性能**线性下降**,epoll性能基本不受连接数影响

- 适用场景:

select/poll: **跨平台程序，连接数少**

epoll: **Linux平台高并发**服务


- 水平触发（LT）和边缘触发(ET)

ET: 只在状态变化时通知一次，必须一次性处理完所有数据

LT: 只要满足条件就持续通知，可以分多次处理

- 知识图解

![image](https://file1.kamacoder.com/i/bagu/20250815.png)

- 面试官可能追问


 Q1.为什么epoll比select/poll更高效？

 epoll使用事件驱动而非轮询，只关注活跃连接

epoll使用红黑树管理描述符，查找效率高

epoll_wait直接返回就绪列表，无需遍历所有连接

内核与用户空间共享内存，减少数据拷贝


Q2.epoll的LT和ET模式有什么区别？如何选择？

LT(水平触发): 只要fd就绪就会不断通知

ET(边缘触发): 只在fd状态变化时通知一次

ET效率更高但编程更复杂，需要一次处理完所有数据

默认使用LT，高性能场景使用ET



Q3.epoll是如何实现高性能的？

使用红黑树存储监控的fd，插入删除效率高

就绪列表直接返回活跃fd，无需遍历

使用mmap共享内存减少内核与用户空间数据拷贝

回调机制避免轮询


Q4.select的1024限制可以修改吗？

可以修改FD_SETSIZE宏并重新编译程序

但不推荐，因为内核可能有自己的限制

需要大文件描述符数量时应改用poll/epoll