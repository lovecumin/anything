#include<iostream>
using namespace std;
#include <string>
#include <vector>
void test1()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	vector<int>::iterator pos=find(v.begin(), v.end(), 5);//������v�в���5
	if (pos == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << *pos << endl;
	}
}
class person
{
public:
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	//����==  �ײ�find֪����ζԱ�person��������
	bool operator==(const person &p)//const ��ֹ���޸ĵײ����
	{
		if (this->m_age == p.m_age && this->m_name == p.m_name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_name;
	int m_age;
};
void test2()
{
	//����һЩ����
	vector<person>v;
	person p1("pop", 4);
	person p2("bop", 3);
	person p3("rop", 6);
	person p4("top", 1);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p4);
	v.push_back(p3);

	person pp("pop", 7);
	vector<person>::iterator pos = find(v.begin(), v.end(), pp);
	if (pos == v.end())
		cout << "û���ҵ�" << endl;
	else
		cout << "�ҵ���" << endl;
}


int main()
{
	test2();

	system("pause");
	return 0;
}
