#include <iostream>
using namespace std;
#include<list>
#include<algorithm>
void printlist(const list<int>l)
{
	for (list<int>::const_iterator it = l.begin();it != l.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int v1,int v2)
{
	//���� ���õ�һ����>�ڶ�����
	return v1 > v2;
}
void test()
{
	list<int>l;
	l.push_back(10);
	l.push_back(40);
	l.push_back(30);
	l.push_back(20);
	l.push_front(0);
	printlist(l);
	
	//sort(l.begin(),l.end());//����ᱨ�����в�֧��������ʵ��������������������ñ�׼�㷨
	                          //��֧��������ʵ��������������ڲ����ṩһЩ�㷨
	l.sort();//Ĭ������������������С�Ҵ�
	//l.reverse();//��������
	l.sort(myCompare);//��������
	printlist(l);

	//��ת

	l.reverse();
	
	printlist(l);
	cout << "��һ��Ԫ��Ϊ��" << l.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << l.back() << endl;

}
int main()
{
	test();
	system("pause");
	return 0;
}