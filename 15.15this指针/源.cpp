#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;



//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
//thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ�룬������Ҫ���壬ֱ��ʹ��

//thisָ�����;��
//1.���βκͳ�Ա����ͬ��ʱ����Ӧ��thisָ������ 
//2.����ķǾ�̬��Ա�����з��ض��������� return *this
class person
{
public:
	person(int age)
	{
	//	ages = age;
		this->age=age; ////thisָ��ָ�򱻵��õĳ�Ա���������Ķ���,����thisָ��p1
	}
//	int ages;//��Ա����Ҫ��������β���һ������
	int age;
	void personadd(person &p)
	{
		this->age += p.age;//��p1������ӵ�p2����
	}
	person& personadds (person& p) //person&��ʾ����ʱ�Ƿ��صı���
	{
		this->age += p.age;
		return *this;
	}
	person budaixingpersonadds(person& p)
	{
		this->age += p.age;
		return *this;
	}
};
void test1()
{
	person p1(18);
	cout << "P1������" << p1.age << endl;
}
void test2()
{
	person p1(10);

	person p2(10);

	p2.personadd(p1);
	cout << "p2������" << p2.age << endl; //----->  20
	//��Ҫ����׷�ӣ���Ҫ��personadd�����޸�
	p2.personadds(p1).personadds(p1).personadds(p1);
	cout << "p2������" << p2.age << endl; //----->  50  �������&��ÿ�η���ԭ����p2��
									                //ÿ�ε��ö������ϴλ����ϼ�������
	p2.budaixingpersonadds(p1).budaixingpersonadds(p1).budaixingpersonadds(p1);
	cout << "p2������" << p2.age << endl; //-----> 20  �����ִ��Ĭ�Ͽ���������ÿ�η��ض����µ�p2
}

int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}

