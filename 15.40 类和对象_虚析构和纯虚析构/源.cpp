#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//��̬ʹ��ʱ���������е�����������Ϊ���������ߴ�������

//�������ʹ����������ԣ�
//���Խ������ָ���ͷ�����Ķ���
//����Ҫ�о���ĺ���ʵ��
//�������ʹ�����������
//����Ǵ����������������ڳ����࣬�޷�ʾ��������
//�����������������ʵ��������

class animal
{
public:
	animal()
	{
		cout << "animal()�Ĺ��캯���ĵ���" << endl;
	}
	//virtual ~animal()//�������������Խ������ָ���ͷ��������ʱ���ɾ�������
	//{
	//	cout << "animal()�����������ĵ���" << endl;
	//}

	//��������
	virtual ~animal() = 0;   //������������������������һ������

	//�鹹����
	virtual void speak() = 0;
};
animal:: ~animal() 
{
	cout << "animal()�Ĵ����������ĵ���" << endl;
};
class cat :public animal
{
public://���������ӣ�animal* animal = new cat("tom")�ᱨ����ʾcat��private�У��޷�����
	cat(string name)
	{
		cout << "cat()�Ĺ��캯���ĵ���" << endl;
		m_name=new string(name);//new string(name)���ص���һ��stringָ��
	}
	 virtual void speak()
	{
		cout <<*m_name<< "Сè��˵��" << endl;
		//cout <<  "3Сè��˵��" << endl;
	}
	 ~cat()
	 {
		 if (m_name != NULL)
		 {
			 cout << "cat()�����������ĵ���" << endl;
			 delete m_name;
			 m_name = NULL;
		 }
	 }
	string *m_name;
};
void test1()
{
	animal* animal = new cat("tom");//����ָ��ָ������Ķ���  �ڶ�������һ������
	animal->speak();
	//����ָ��������ʱ�� �����������������������������������ж������ԣ������ڴ�й©
	//~animal()ǰ�����virtual�ͻ��ֹ��������
	delete animal;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
//�ܽ�:
//1.�������������������������ͨ������ָ���ͷ��������
//2.���������û�ж������ݣ����Բ�дΪ��������������
//3.ӵ�д���������������Ҳ���ڳ�����