#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//��̬��Ϊ����
// ��̬��̬ : �������غ� ������������ھ�̬��̬�����ú�������
// ��̬��̬ : ��������麯��ʵ������ʱ��̬
// ��̬��̬�Ͷ�̬��̬����:
//��̬��̬�ĺ�����ַ��� - ����׶�ȷ��������ַ
//��̬��̬�ĺ�����ַ��� - ���н׶�ȷ��������ַ

class  animal
{
public:
	virtual void speak() //�麯�� 
	{
		cout << "������˵��" << endl;
	}
};
class cat :public animal
{
public:
	//void speak() //��������д�����麯���������е��麯�����ڲ����滻�������麯����ַ   "&animal::speak"�ᱻ�滻��"&cat::speak" 
	//	//�������ָ���������ָ���������ʱ�򣬷�����̬
	//{
	//	cout << "Сè��˵��" << endl;
	//}
};
class dog :public animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};

void dospeak(animal& animal)//animal &animal=cat��animal &animal=dog��
							//���������ָ������Ķ��󣬴���Ķ�����ʲô��ָ��ľ���ʲô
{
	animal.speak();
}
void test()
{
	cout << "size of animal= " << sizeof(animal)<<endl;//�����д��Ϲؼ��� virtual��sizeof(animal)��ֵ����4  ��������1 
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
	test();

	system("pause");
	return 0;
}
