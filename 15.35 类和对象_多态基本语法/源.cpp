#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//��̬��Ϊ����
// ��̬��̬ : ��������  �� ������������ھ�̬��̬�����ú�������
// ��̬��̬ : ��������麯��ʵ������ʱ��̬
// ��̬��̬�Ͷ�̬��̬����:
//��̬��̬�ĺ�����ַ��� - ����׶�ȷ��������ַ
//��̬��̬�ĺ�����ַ��� - ���н׶�ȷ��������ַ

class  animal
{
public:
	//������ virtual ����д�ϣ�����Ͳ����麯�� ��������дʱ��virtual����ʡ��
	virtual void speak() //�麯�� 
	{
		cout << "������˵��" << endl;
	}
};
class cat :public animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};
class dog :public animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};
//ִ��˵���ĺ���
//��ַ���  �ڱ���׶�ȷ��������ַ
//�����ִ��"Сè��˵��"����ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣��� ��ַ���

//��̬��̬��������
//1.�м̳й�ϵ
//2.������д������麯������д��ʱ��ؼ��� virtual ����ʡ�ԣ�
//������д���� ��������ֵ���� ������ �����б� ��ȫ��ͬ


//��̬��̬��ʹ��
//�����ָ���������  ִ���������
void dospeak(animal &animal)//animal &animal=cat��animal &animal=dog��
							//���������ָ������Ķ��󣬴���Ķ�����ʲô��ָ��ľ���ʲô
{
	animal.speak();	
}
void test1()
{
	cat c;
	dospeak(c);
	dog d;
	dospeak(d);
}
int main()
{
	test1();

	system("pause");
	return 0;
}
