#include <iostream>
using namespace std;
#include<list>
//��������[] at����ʽ����list�����е�Ԫ��  list������һ�������������������������Կռ�洢����������֧���������
//void printlist(const list<int>l)
//{
//	for (list<int>::const_iterator it = l.begin();it != l.end();it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
void test()
{
	list<int>l;
	l.push_back(10);
	l.push_back(40);
	l.push_back(30);
	l.push_back(20);
	l.push_front(0);
	cout << "��һ��Ԫ��Ϊ��" << l.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << l.back() << endl;
	
	//��֤�������ǲ�֧��������ʵ�
	list<int>::iterator it = l.begin();
	it++;
	it--;//֧��˫���
	//it += 1;//��֧���������
}
int main()
{
	test();
	system("pause");
	return 0;
}