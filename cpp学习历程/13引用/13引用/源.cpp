//#include<iostream>
//using namespace std;
//
//void myswap(int &a, int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	//引用的基本语法
//	//数据类型 &别名=原名
//	//int a = 10;
//	//int& b = a;
//	//cout << a << endl;
//	//cout << b << endl;
//	//b = 100; //修改别名的同时，原名称会发生改变
//	//cout << a << endl;
//	//cout << b << endl;
//
//	//int a = 10;
//	////int& b;//错误，引用必须初始化
//	//int a1 = 20;
//	//int& b = a;//引用初始化为a，初始化以后就不能改变了
//	//b = a1;//这是赋值操作，不能更改引用 这里改变b的值，a的值也会发生改变
//	//cout << a << endl;
//	//cout << b << endl;
//
//
//	//利用引用修饰实参
//	int  a = 10;
//	int b = 20;
//	myswap(a, b);
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int& test()
//{
//	int a = 10; //局部变量
//	return a;
//}
////返回静态变量引用
//int& test2()
//{
//	static int a = 20;
//	return a;
//}
//int main()
//{
//	//不能返回局部变量的引用
//	int& ref = test();
//	cout << "ref=" << ref << endl;//这里a能正常输出，因为编译器做了一次数据保留
//	cout << "ref=" << ref << endl; //这里是乱码，因为a通过test()函数后，就被销毁了
//
//	int& ref2 = test2();
//	cout << "ref=" << ref2 << endl;
//	cout << "ref=" << ref2 << endl;
//
//	test2() = 1000;  //函数调用作为左值存在，这里其实就是令a=1000
//
//	cout << "ref=" << ref2 << endl;
//	cout << "ref=" << ref2 << endl;
//
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;
void func(int& ref)
{
	ref = 100;//这里实际上是ref解引用，转换为*ref=100,这一步编译器帮忙做了	
}
//引用的本质实际上是指针




void show(const int& a)
{
	//a += 10; 这里修改形参a的值，实参也会发生改变，但是形参加入const修饰以后这里的a的就不能修改了
	cout << a << endl;
}
int main()
{
	int a = 10;
	//自动转换为 int* const  ref=&a;指针常量是指针指向，不可以更改
	int& ref1 = a;
	ref1 = 20;//这里内部是ref解引用，编译器自动转换为*ref=20;

	//int& ref = 10;这样写代码不正确，引用必须引一块合法的内存空间
	const int& ref = 10;//这样写正确，加上const之后，编译器将代码为 int temp=10;const int &ref=temp
	//ref = 100;//这句代码报错，因为加入const修饰以后 值就不可以修改了
	cout << ref << endl;


	//函数调用中利用常量引用防止无操作修改实参
	int a1 = 10;
	show(a1);
	system("pause");
	return 0;
}