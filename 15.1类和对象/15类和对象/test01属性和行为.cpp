#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define pi 3.14
//const double p = 3.14;  这样以可以实现宏定义，与上一行代码区别在 上面写不占内存，这样写占内存
class circle  //设计类 类名
{
	//访问权限
public: //公共权限

	//属性
	
	int  r;  //半径
	
	//行为  用一些函数
	double cal()//求圆的周长
	{
		return 2 * pi * r;
	}
};

int main()
{
	circle c1;
	c1.r = 10;
	cout << "圆的周长为：" << c1.cal() << endl;//这里的 c1. 表示取行为
	system("pause");
	return 0;
}