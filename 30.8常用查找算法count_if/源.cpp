#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>
class greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}

};
void test1()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	int num = count_if(v.begin(), v.end(),greater20());
	cout << "大于20的元素个数为" << num << endl;
}

//自定义类型查找  此事要记得重载等等号
class person
{
public:
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	////要重载等等号运算符
	//bool operator==(const person& p)
	//	//上一行代码加上const 是为了保证等号运算符不会修改对象的状态
	//{
	//	if (this->m_age == p.m_age)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}
	string m_name;
	int m_age;
};
class greater_age_30
{
public:
	bool operator()(const person& p)
	{
		return p.m_age > 30;
	}
};

void test2()
{
	vector<person>v;
	person p1("bob", 30);
	person p2("pob", 20);
	person p3("oob", 30);
	person p4("iob", 20);
	person p5("uob", 30);
	person p6("yob", 40 );

	person p7("aa", 30);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);

	int num = count_if(v.begin(), v.end(), greater_age_30());
	cout << num << endl;
}

int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}
