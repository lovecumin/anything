#include <iostream>
using namespace std;
#include<list>
#include<string>

void printlist(const list<int>l)
{
	for (list<int>::const_iterator it = l.begin();it != l.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_front(100);
	l1.push_front(200);
	l1.push_front(300);
	printlist(l1);

	l1.pop_back();
	printlist(l1);
	l1.pop_front();
	printlist(l1);

	//insert����
	list<int>::iterator it = l1.begin();
	l1.insert(++it, 5000);
	printlist(l1);

	//eraseɾ��
	it = l1.begin();
	//l1.erase(it);
	//printlist(l1);
	l1.erase(++it);
	printlist(l1);
	l1.push_back(258741);
	l1.push_back(258741);
	l1.push_back(258741);
	printlist(l1);
	l1.remove(258741);//remove��elem��ɾ��������������elemֵ��ͬ��Ԫ��
	printlist(l1);

	l1.clear();
	printlist(l1);//����ո�
		
}
int main()
{
	test();
	system("pause");
	return 0;
}