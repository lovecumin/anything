#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
// ��ָ��ָ���Ա����
//
class MyClass
{
public:

	void showname()
	{
		cout << "this is MyClass  class" << endl;
	}

	void showage()
	{

		if (this == NULL)
		{
			return;
		}
		cout << "age= " << m_age << endl;
		//�����m_ageǰ����ʵĬ�ϼ���һ�� "this-> "
		//������ñ����ԭ����Ϊ������ǿ�ָ��NULL������취�������ж����
	}

	int m_age;
};

void test1()
{
	MyClass* p = NULL;
	p->showname();
	p->showage();//(û���ж����Ļ�)����ᱨ��
}


int main()
{
	test1();

	system("pause");
	return 0;
}
