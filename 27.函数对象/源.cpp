#include <iostream>
using namespace std;

//�������󣨷º�����
/*
1������������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
2���������󳬳���ͨ�����ĸ����������������Լ���״̬
3���������������Ϊ��������
*/

//1������������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
class myadd
{
public:
	int operator()(int v1,int v2)
	{
		return v1 + v2;
	}
};

void test()
{
	myadd add;
	cout << add(10, 20) << endl;
}

//2���������󳬳���ͨ�����ĸ����������������Լ���״̬
class myprint
{
public:
	myprint()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count ++ ;
	}
	int count;
};
void test2()
{
	myprint myprint;
	myprint("hello word!");
	cout << "���ô�����" << myprint.count << endl;
}

//3���������������Ϊ��������
void doprint(myprint& mp,string  test)
{
	mp(test);
}
void test3()
{
	myprint myprint;
	doprint(myprint,"hello c++");
}
int main()
{
	//test();
	//test2();
	test3();
	system("pause");
	return 0;
}