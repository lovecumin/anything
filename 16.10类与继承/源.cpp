#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
template<class t>
class base
{
public:
	t m;
};
//class son :public base //����̳и��࣬������һ����ģ�� ���󣬱���Ҫ֪�������е�t���ͣ����ܼ̳и�����
class son :public base<int>//����̳и��࣬������һ����ģ�壬�̳�ʱ����ָ����������� 
{


};
void test1()
{
	son s1;
}
//����̳и��࣬Ҫ�����ָ�������е�T���ͣ�����ҲҪ����ģ��
template<class t1,class t2>
class son2 :public base<t2>
{
public:
	t2 obj;
	//son s2;
	son2()
	{
		cout << "t1����������" << typeid(t1).name() << endl;
		cout << "t2����������" << typeid(t2).name() << endl;
	}
};
void test2()
{
	son2<int,char> s2; //�����int���ݸ���t1,�����char���ݸ���t2
	
}

int main()
{
	test2();

	system("pause");
	return 0;
}
