#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/* 构造函数的分类与调用
*  分类
*  按照参数分类  无参构造（又称作为默认构造） 和有参构造
*  按照类型分类  普通构造   拷贝构造
*/
class MyClass
{
public:
	
	MyClass()
	{
		cout << "MyClass的无参构造函数调用" << endl;
	}
	MyClass(int a)
	{
		age = a;//不能忘！！！
		cout << "MyClass的有参构造函数调用" << endl;
	}
	//拷贝构造函数
	MyClass(const MyClass &a)//注意写法，传进来和自身一致的东西，用引用的方法，用const修饰防止修改本体
	{
		age = a.age;
		cout << "MyClass的拷贝构造函数调用" << endl;
	}
	~MyClass()
	{
		cout << "MyClass的析构构造函数调用" << endl;
	}
	int age ;
};

//调动
void test()
{
	//1.括号法
	MyClass a1;//调用默认构造函数时候，不要加()，即Myclass a1()，否则编译器会认为是函数的声明
	MyClass a2(10);
	MyClass a3(a2);
	cout << "a2的年龄为： " << a2.age << endl;
	cout << "a3的年龄为： " << a3.age << endl;

	//2.显示法
	MyClass a1;
	MyClass a2 = MyClass(10);//有参构造
	MyClass a3 = MyClass(a2);//拷贝构造
	//               ↑
	//            匿名对象    特点：当前执行结束后，系统会立即回收掉匿名对象

	//注意：不要利用拷贝构造函数初始化匿名对象  编译器会认为是对象声明
	//eg: Myclass(a3) 等价为 Myclass a3

	//3.隐式转换法
	MyClass a4 = 10;//等价于 MyClass a4 = MyClass（10）；
	MyClass a5 = a4;
}
int main()
{
	test();
	system("pause");
	return 0;
}