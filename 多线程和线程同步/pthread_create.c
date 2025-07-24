#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>  // Windows API ͷ�ļ�
#include <process.h>  // Windows �߳�ͷ�ļ�

#define MAX 50
// ȫ�ֱ���
int number;

// �̴߳�����
unsigned __stdcall funcA_num(void* arg)
{
    for (int i = 0; i < MAX; ++i)
    {
        int cur = number;
        cur++;
        Sleep(10); // ʹ�� Sleep ���� usleep
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
        Sleep(5); // ʹ�� Sleep ���� usleep
    }

    return 0;
}

int main(int argc, const char* argv[])
{
    HANDLE p1, p2;

    // �����������߳�
    p1 = (HANDLE)_beginthreadex(NULL, 0, funcA_num, NULL, 0, NULL);
    p2 = (HANDLE)_beginthreadex(NULL, 0, funcB_num, NULL, 0, NULL);

    // �ȴ��߳̽���
    WaitForSingleObject(p1, INFINITE);
    WaitForSingleObject(p2, INFINITE);

    // �ر��߳̾��
    CloseHandle(p1);
    CloseHandle(p2);

    return 0;
}

