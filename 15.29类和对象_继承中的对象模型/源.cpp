#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//�̳��еĶ���ģ��
class base
{
public:
	int m_A;
	static int m_a;
protected:
	int m_b;
private:
	int m_c;
};
class son :public base
{
	int m_d;

};
void test1()
{
	cout << "size of son= " << sizeof(son) << endl;//16  
												   //���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ
												   //������˽�г�Ա�����Ǳ��������������ˣ�����Ƿ��ʲ�������ȷʵ�Ǽ̳���
}


int main()
{
	test1();

	system("pause");
	return 0;
}
