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
//	//���õĻ����﷨
//	//�������� &����=ԭ��
//	//int a = 10;
//	//int& b = a;
//	//cout << a << endl;
//	//cout << b << endl;
//	//b = 100; //�޸ı�����ͬʱ��ԭ���ƻᷢ���ı�
//	//cout << a << endl;
//	//cout << b << endl;
//
//	//int a = 10;
//	////int& b;//�������ñ����ʼ��
//	//int a1 = 20;
//	//int& b = a;//���ó�ʼ��Ϊa����ʼ���Ժ�Ͳ��ܸı���
//	//b = a1;//���Ǹ�ֵ���������ܸ������� ����ı�b��ֵ��a��ֵҲ�ᷢ���ı�
//	//cout << a << endl;
//	//cout << b << endl;
//
//
//	//������������ʵ��
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
//	int a = 10; //�ֲ�����
//	return a;
//}
////���ؾ�̬��������
//int& test2()
//{
//	static int a = 20;
//	return a;
//}
//int main()
//{
//	//���ܷ��ؾֲ�����������
//	int& ref = test();
//	cout << "ref=" << ref << endl;//����a�������������Ϊ����������һ�����ݱ���
//	cout << "ref=" << ref << endl; //���������룬��Ϊaͨ��test()�����󣬾ͱ�������
//
//	int& ref2 = test2();
//	cout << "ref=" << ref2 << endl;
//	cout << "ref=" << ref2 << endl;
//
//	test2() = 1000;  //����������Ϊ��ֵ���ڣ�������ʵ������a=1000
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
	ref = 100;//����ʵ������ref�����ã�ת��Ϊ*ref=100,��һ����������æ����	
}
//���õı���ʵ������ָ��




void show(const int& a)
{
	//a += 10; �����޸��β�a��ֵ��ʵ��Ҳ�ᷢ���ı䣬�����βμ���const�����Ժ������a�ľͲ����޸���
	cout << a << endl;
}
int main()
{
	int a = 10;
	//�Զ�ת��Ϊ int* const  ref=&a;ָ�볣����ָ��ָ�򣬲����Ը���
	int& ref1 = a;
	ref1 = 20;//�����ڲ���ref�����ã��������Զ�ת��Ϊ*ref=20;

	//int& ref = 10;����д���벻��ȷ�����ñ�����һ��Ϸ����ڴ�ռ�
	const int& ref = 10;//����д��ȷ������const֮�󣬱�����������Ϊ int temp=10;const int &ref=temp
	//ref = 100;//�����뱨����Ϊ����const�����Ժ� ֵ�Ͳ������޸���
	cout << ref << endl;


	//�������������ó������÷�ֹ�޲����޸�ʵ��
	int a1 = 10;
	show(a1);
	system("pause");
	return 0;
}