#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class cube
{
public:
	//行为  一般设置为公共部分

	//设置与获取长宽高
	void set_l(int l)
	{
		m_l = l;
	}
	int get_l()
	{
		return m_l;
	}
	void set_w(int w)
	{
		m_w = w;
	}
	int get_w()
	{
		return m_w;
	}
	void set_h(int h)
	{
		m_h = h;
	}
	int get_h()
	{
		return m_h;
	}
	//获取面积
	int mianji()
	{
		return 2*((m_l * m_h)+(m_h * m_w)+(m_w*m_l));
	}
	//获取体积
	int tiji()
	{
		return (m_l * m_h * m_w);
	}


	bool issamebyclass(cube &cube2)//这里传入一个参数就可以，外面传入的这个跟本身所具有的进行对比
	{
		if (m_l == cube2.get_l() && m_h == cube2.get_h() && m_w == cube2.get_w())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	//属性    属性一般设置为私有
	int m_l;
	int m_h;
	int m_w;
};

bool issame(cube &cube1,cube &cube2)//这里要传入两个参数  传入&cube1可以避免为形参开辟新的空间，节省内存
{
	if (cube1.get_l() == cube2.get_l() &&cube1.get_h() == cube2.get_h() && cube1.get_w()== cube2.get_w())
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{

	//1.求立方体的体积与周长
	cube cube1;
	cube1.set_h(10);
	cube1.set_l(10);
	cube1.set_w(10);
	//cube1.mianji();
	//cube1.tiji();
	cout << "面积： " << cube1.mianji() << endl;
	cout << "体积： " << cube1.tiji() << endl;

	//2.分别利用成员函数和全局函数判断两个立方体是否相等
	//2.1成员函数
	cube cube2;
	cube2.set_h(10);
	cube2.set_w(10);
	cube2.set_l(10);
	int ret1 = cube1.issamebyclass(cube2);
	
	if (ret1)
	{
		cout << "利用成员函数判断两个立方体相等" << endl;
	}
	else
	{
		cout << "利用成员函数判读两个立方体不相等" << endl;
	}
	//2.2全局函数
	int ret2 = issame(cube1,cube2);
	if (ret2)
	{
		cout << "利用全局函数判断两个立方体相等" << endl;
	}
	else
	{
		cout << "利用全局函数判读两个立方体不相等" << endl;
	}
	system("pause");
	return 0;
}