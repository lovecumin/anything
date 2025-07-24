#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>  // Windows API 头文件
#include <process.h>  // Windows 线程头文件

#define MAX 50
// 全局变量
int number;

// 线程处理函数
unsigned __stdcall funcA_num(void* arg)
{
    for (int i = 0; i < MAX; ++i)
    {
        int cur = number;
        cur++;
        Sleep(10); // 使用 Sleep 代替 usleep
        number = cur;
        printf("Thread A, id = %lu, number = %d\n", GetCurrentThreadId(), number);
    }

    return 0;
}

unsigned __stdcall funcB_num(void* arg)
{
    for (int i = 0; i < MAX; ++i)
    {
        int cur = number;
        cur++;
        number = cur;
        printf("Thread B, id = %lu, number = %d\n", GetCurrentThreadId(), number);
        Sleep(5); // 使用 Sleep 代替 usleep
    }

    return 0;
}

int main(int argc, const char* argv[])
{
    HANDLE p1, p2;

    // 创建两个子线程
    p1 = (HANDLE)_beginthreadex(NULL, 0, funcA_num, NULL, 0, NULL);
    p2 = (HANDLE)_beginthreadex(NULL, 0, funcB_num, NULL, 0, NULL);

    // 等待线程结束
    WaitForSingleObject(p1, INFINITE);
    WaitForSingleObject(p2, INFINITE);

    // 关闭线程句柄
    CloseHandle(p1);
    CloseHandle(p2);

    return 0;
}

