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
	//����ǰ��++�����
	myInteger &operator++()
	{
		m_num++;
		return *this;//thisָ����������������ã��ҵ����������
					 //ǰ�õ���Ҫ��������
	}

	//���غ���++�����       //����ֵ��������Ϊ��������
	myInteger  operator++(int)// �����int��һ��ռλ������������������ǰ�úͺ��õ���
	{
		//��  ��¼���
		myInteger temp = *this;
		//��  ����
		m_num++;
		//��󽫼�¼�Ľ��������
		return temp; //���õ���Ҫ����ֵ�����ص��Ǿֲ����󣬾ֲ������ڵ�ǰ����ִ����ͻᱻ�ͷ��ˣ��ٷ������þͻᱨ��
	}
private:
	int m_num;
};

ostream & operator<<(ostream& cout, myInteger myint)//ע��ʾ ostream���� iostream 
{
	cout << myint.m_num;//��Ҫ��friend�����������
	return cout;
}

void test1()
{
	myInteger myint;
	cout << ++myint << endl;//�ᱨ����Ϊ�������Զ������������Ҫ�������������,���غ�Ͳ�������
	//cout << ++(++myint) << endl;
	cout << myint<< endl; // ���� myInteger &operator++() ����Ҫ����& ��������Ľ���Ÿ�����һ��36�б���һ��,
						  //����ʵ��һֱ��һ�����ݽ��е���
						  //�����ڷ��ص�ʱ��᷵��һ���µ� myint
}

void test2()
{
	myInteger myint;
	cout <<myint++ << endl;//�ᱨ����Ϊ�������Զ������������Ҫ�������������,���غ�Ͳ�������
	cout << myint++ << endl;
	cout << myint << endl;
	
}



//���ü�һ�����
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
