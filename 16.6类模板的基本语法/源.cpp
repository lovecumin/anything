#include<iostream>
using namespace std;
#include <string>
#include<string>
//��template�����һ���࣬����ͳ�Ϊ��ģ��
template<class nametype,class agetype>
class person
{
public:
	person(nametype name, agetype age)
	{
		this->name = name;
		this->age = age;
	}
	void show()
	{
		cout << "name: " << this->name << "age: " << this->age << endl;
	}
	nametype name;
	agetype age;
};
void test1()
{
	person<string, int>p1("asdf", 180);
	p1.show();
}


int main()
{
	test1();

	system("pause");
	return 0;
}
