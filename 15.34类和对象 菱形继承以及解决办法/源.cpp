#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
class animal
{
public:
	int m_age;
};
//������̳� ������μ̳е�����
//�̳�֮ǰ ���Ϲؼ��� virtual �����̳�
//animal ��Ϊ�����
class sheep:virtual public animal{};
class tuo :virtual public animal{};
class sheeptuo :public sheep, public tuo{};
void test1()
{
	sheeptuo st;
	st.sheep::m_age = 18;
	st.tuo::m_age = 28;

	//�����μ̳У���������ӵ����ͬ�����ݣ���Ҫ��������������
	cout << "m_age= " << st.sheep::m_age << endl;
	cout << "m_age= " << st.tuo::m_age << endl;
	cout << "m_age= " << st.m_age << endl;
	//ͬ��������ӵ��һ�ݾͿɣ����μ̳е������������ݣ�������Դ�˷�
}
int main()
{
	test1();

	system("pause");
	return 0;
}

/*
vbptr v- virtual b- base ptr- pointer
vbtable  v- virtual b- base 
������̳еķ�ʽ�̳еĲ������ݱ�����������ָ�룬����ָ���ͨ��ƫ���������ߵ�ƫ�����ǲ�ͬ�ģ��ҵ�Ψһ������
*/