#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

template<typename T> //typenameҲ���Ի���class
void myswap(T &a,T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test1()
{
	int a = 10;
	int b = 30;
	//1.�Զ������Ƶ�,�����Ƶ���һ�µ���������T�ſ���ʹ��
	myswap(a, b);
	
	//myswap<int>(a, b);
	cout << "a= " <<a<< endl;
	cout << "b= " << b << endl;
}
template<typename T>
void func()
{
	cout << "func1()�����ĵ���"<< endl;
}
void test2()
{
	func<int>();//2.��ʾָ�����ͣ�ģ�����Ҫȷ����T����������(int����flaot���߱�ģ����ǲ�����ΪT)���ſ���ʹ��
}

int main()
{
	test2();

	system("pause");
	return 0;
}
