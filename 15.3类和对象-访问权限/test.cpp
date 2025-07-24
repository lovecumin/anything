//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
////访问权限
////公共权限 public    成员 类内可以访问 类外可以访问
////保护权限 protected 成员 类内可以访问 类外不可以访问 儿子可以访问父亲中的保护内容
////私有权限 private   成员 类内可以访问 类外不可以访问 儿子不可以访问父亲中的隐私内容
//class person
//{
//public:
//	//公共权限
//	string name;
//protected:
//	//保护权限
//	string m_car;
//		//私有权限
//private:
//	int n_password;
//
//public:
//	void func() 
//	{
//		name = "张三";
//		m_car = "tesila";
//		n_password = 1256321;
//	}
//};
////类内就是上面区域（大括号）以内，类外就是指大括号以外区域
//int main()
//{
//	person p1;
//	p1.name = "Lisi";
//	//p1.m_car="benci"; protected下的内容，在类外访问不到
//	//p1.n_password="1345616"; private下的内容，在类外访问不到
//	p1.func();//类内的func上面的函数若没有public，则不可以访问func()
//	system("pause");
//	return 0;
//}







#include<iostream>
#include<string>
using namespace std;

//struct 默认权限为公共
//class  默认权限为私有

class C1
{
	int m_A;//默认是私有权限
};
struct C2
{
	int m_B;//默认是公共权限
};
int main()
{

	//struct和class的区别
	//struct 默认权限是 公共 public
	//class 默认权限是 私有 private
	C1 c1;
	//c1.m_A = 100;// 在class里的默认权限  私有 因此类外不可以访问
	C2 c2;
	c2.m_B = 100;  //在strcut默认的权限为公共  因此可以访问
	system("pause");
	return 0;
}


//#include<iostream>
//#include<string>
//using namespace std;
//
//
//class person
//{
//public:
//	//公共权限
//	string name;
//protected:
//	//保护权限
//	string m_car;
//	//私有权限
//private:
//	int n_password;
//
//public:
//	void func()
//	{
//		name = "张三";
//		m_car = "tesila";
//		n_password = 1256321;
//	}
//};
////类内就是上面区域（大括号）以内，类外就是指大括号以外区域
//int main()
//{
//	person p1;
//	p1.name = "Lisi";
//	//p1.m_car="benci"; protected下的内容，在类外访问不到
//	//p1.n_password="1345616"; private下的内容，在类外访问不到
//	p1.func();//类内的func上面的函数若没有public，则不可以访问func()
//	system("pause");
//	return 0;
//}