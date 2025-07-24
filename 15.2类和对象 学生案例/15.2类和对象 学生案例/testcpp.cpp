#include<iostream>
using namespace std;
#include<string.h>
class student  //设计类 类名
{
	//访问权限
public: //公共权限

	/*类中的属性和行为  我们统一称为成员
	属性    成员属性  成员变量
	行为    成员函数  成员方法
	*/



	//属性

	string  names;  //名字
	int nums;
	//行为  用一些函数
	void  showstudent()//显示姓名和学号
	{
		cout << "姓名： " << names << "  学号： " <<nums<< endl;
	}
	void setname(string name)
	{
		names = name;
	}
	void setnum(int num)
	{
		nums = num;
	}
};

int main()
{
	//创建一个具体学生  实例化对象
	student s1;
	//给s1对象  进行属性赋值操作
	
	//s1.names = "战三";
	s1.setname("张三");
	s1.nums = 1;
	//s1.setnum(2);   s1.setnum(2) 与s1.nums都可以给nums赋值
	//显示学生信息
	s1.showstudent();

	student s2;
	s2.setname("李四");
	s2.nums = 2;
	s2.showstudent();
	system("pause");
	return 0;
}