#include <iostream>
using namespace std;
#include<functional>  //ע�����ͷ�ļ�
/*
	template<class T> T plus<T> //�ӷ��º���
	template<class T> T minus<T> //�����º���
	template<class T> T multiplies<T> //�˷��º���
	template<class T> T divides<T> //�����º���
	template<class T> T modulus<T> //ȡģ�º���
	template<class T> T negate<T> //ȡ���º���     һԪ
*/
void test()
{
	negate<int>n;
	int ret=n(50);
	cout << ret << endl;
}

void test2()
{
	plus<int>p1;
	cout << p1(10,20) << endl;

	minus<int>p2;
	cout << p2(10, 20) << endl;

	multiplies<int>p3;
	cout << p3(10, 20) << endl;

	divides<int>p4;
	cout << p4(10, 20) << endl;

	modulus<int>p5;
	cout << p5(10, 20) << endl;
	
}
int main()
{
	test2();
	system("pause");
	return 0;
}