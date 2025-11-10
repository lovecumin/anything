#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//继承中的对象模型
class base
{
public:
	int m_A;
	static int m_a;
protected:
	int m_b;
private:
	int m_c;
};
class son :public base
{
	int m_d;

};
void test1()
{
	cout << "size of son= " << sizeof(son) << endl;//16  
												   //父类中所有非静态成员属性都会被子类继承下去
												   //父类中私有成员属性是被编译器给隐藏了，因此是访问不到，但确实是继承了
}


int main()
{
	test1();

	system("pause");
	return 0;
}
