#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <queue>
#include<string>

//ֻ�ж�ͷ��β�ܱ����ʣ���˲������б�����Ϊ ���push ����pop û��top()
class person
{
public:
	person(string name, int age)
	{
		this->mage = age;
		this->mname = name;
	}
	int mage;
	string mname;
};
void test()
{
	//��������
	queue<person>q;
	//׼������
	person p1("bob",14);
	person p2("pob", 15);
	person p3("mob", 16);
	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);


	while (!q.empty())
	{
		cout << "����ǰ���е�Ԫ�ش�С" << q.size() << endl;
		cout << "��ͷԪ��--������" << q.front().mname << "��ͷԪ��--���䣺" << q.front().mage<<endl;
		cout << "��βԪ��--������" << q.back().mname << "��ͷԪ��--���䣺" << q.back().mage << endl;
		q.pop();
		cout << "���Ӻ���е�Ԫ�ش�С" << q.size() << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}