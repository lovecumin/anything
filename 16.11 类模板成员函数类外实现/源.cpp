#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
template<class t1,class t2>
class person
{
public:
	person(t1 name, t2 age);
		/*{
			this->name=name;
			this->age=age;
		}*/
		void showperson();
	/*{
		cout << "name: " <<this->name<< endl;
	}*/
	t1 name;
	t2 age;
};

//���캯��������ʵ��
template<class t1,class t2>
person<t1, t2>::person(t1 name, t2 age)//��<t1,t2>��Ҫд��˫ð��ǰ�� 
{
	this->name = name;
	this->age = age;
}
template<class t1,class t2>
void person<t1,t2>:: showperson()//��<t1,t2>��Ҫд��˫ð��ǰ�� 
{
	cout << "name: " << this->name << " age: " << this->age << endl;
}
void test1()
{
	person<string,int>p("tom",20);
	p.showperson();
}


int main()
{
	test1();

	system("pause");
	return 0;
}


