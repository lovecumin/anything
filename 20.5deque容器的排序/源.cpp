#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>//��׼�㷨��ͷ�ļ�

void printdeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin();it != d.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(110);
	d.push_back(120);
	d.push_front(120);
	d.push_front(230);
	d.push_front(210);

	printdeque(d);
	//����  Ĭ���������   ��С����  ����
	//����֧��������ʵĵ���������������������sort�㷨ֱ�Ӷ����������
	//vector����Ҳ�������� sort ��������
	sort(d.begin(), d.end());  //��׼���㷨��ʹ��ǰ��Ҫ����ͷ�ļ� algorithm
	printdeque(d);
}
int main()
{
	test1();
	system("pause");
	return 0;
}