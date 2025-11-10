#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
class animal
{
public:
	int m_age;
};
//利用虚继承 解决菱形继承的问题
//继承之前 加上关键字 virtual 变成虚继承
//animal 称为虚基类
class sheep:virtual public animal{};
class tuo :virtual public animal{};
class sheeptuo :public sheep, public tuo{};
void test1()
{
	sheeptuo st;
	st.sheep::m_age = 18;
	st.tuo::m_age = 28;

	//当菱形继承，两个父类拥有相同的数据，需要加以作用域区分
	cout << "m_age= " << st.sheep::m_age << endl;
	cout << "m_age= " << st.tuo::m_age << endl;
	cout << "m_age= " << st.m_age << endl;
	//同样的数据拥有一份就可，菱形继承导致有两份数据，产生资源浪费
}
int main()
{
	test1();

	system("pause");
	return 0;
}

/*
vbptr v- virtual b- base ptr- pointer
vbtable  v- virtual b- base 
利用虚继承的方式继承的不是数据本身，而是两个指针，两个指针会通过偏移量（二者的偏移量是不同的）找到唯一的数据
*/