#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

class myInteger
{
	friend ostream & operator<<(ostream& cout, myInteger myint);
public:
	myInteger()
	{
		m_num = 0;
	}
	//重载前置++运算符
	myInteger &operator++()
	{
		m_num++;
		return *this;//this指向自身，对自身解引用，找到自身运算符
					 //前置递增要返回引用
	}

	//重载后置++运算符       //返回值不可以作为重载条件
	myInteger  operator++(int)// 这里的int是一个占位参数，可以用于区分前置和后置递增
	{
		//先  记录结果
		myInteger temp = *this;
		//后  递增
		m_num++;
		//最后将记录的结果做返回
		return temp; //后置递增要返回值。返回的是局部对象，局部对象在当前操作执行完就会被释放了，再返回引用就会报错
	}
private:
	int m_num;
};

ostream & operator<<(ostream& cout, myInteger myint)//注意示 ostream而非 iostream 
{
	cout << myint.m_num;//需要用friend对其进行声明
	return cout;
}

void test1()
{
	myInteger myint;
	cout << ++myint << endl;//会报错，因为这里是自定义对象，这里需要重载左移运算符,重载后就不报错了
	//cout << ++(++myint) << endl;
	cout << myint<< endl; // 上面 myInteger &operator++() 这里要带上& 这样输出的结果才跟上面一行36行保持一致,
						  //可以实现一直对一个数据进行递增
						  //否则在返回的时候会返回一个新的 myint
}

void test2()
{
	myInteger myint;
	cout <<myint++ << endl;//会报错，因为这里是自定义对象，这里需要重载左移运算符,重载后就不报错了
	cout << myint++ << endl;
	cout << myint << endl;
	
}



//内置加一运算符
void test3()
{
	int a = 10;
	cout << ++a << endl;//11
	cout << a << endl;//11
	int b = 20;
	cout << b++ << endl;//20
	cout << b << endl;//21

}
int main()
{
	test2();
	test1();
	system("pause");
	return 0;
}
