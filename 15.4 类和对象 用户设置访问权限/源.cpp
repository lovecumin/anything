#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//�û��Լ�������˽���ݵĶ�д����
//��֤д���ݵ���Ч��
class person
{
public:
	//�������� ��д
	void setname(string name)
	{
		m_name = name;
	}
	//��ȡ���� �ɶ�
	string getname()
	{
		return m_name;
	}
	//��ȡ���� �ɶ�����д
	int getage()
	{
		return m_age;
	}
	void setage(int age)
	{
		if (age > 0 && age < 150)
		{
			m_age = age;
		}
		else
		{
			cout << "��������,age��0-150֮��" << endl;
			return;
		}

	}
	//��ȡż��  ��д���ɶ�
	void setidlo(string idol)
	{
		m_idol = idol;
	}
private:
	string m_name; //���Զ�����д
	int m_age = 18;//���Զ�ye����д  ������0-150֮��
	string m_idol="zhangsan";//����д�����Զ�
};
int main()
{
	person p;
	//p.name = "zhangsan";�����Է���
	p.setname("����");
	cout << "������ " << p.getname() << endl;

	p.setage (20);
	cout<<"����: "<<p.getage() << endl;

	p.setidlo("С��") ;
	//cout << "ż�� " << p.m_idol << endl;ֻд״̬ ���������
	system("pause");
	return 0;
}