#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	
	float a = 10.3f;
	double b = 10.3;
	cout << a << endl;
	cout << b << endl;
	float f2 = 3e2;
	float f3 = 3e-2;
	cout << f2 << endl;
	cout <<f3 << endl; 

	//�ַ� ע���ǵ�����
	char ch = 'a';//a-97  A-65
	cout << "char�ַ���ռ�������ڴ���" << sizeof(char) << endl;
	cout << "�ַ�������Ӧ��ASCII������" << (int)ch << endl;//�ַ�ǰ���ǿת��int�����ܵõ�ASCII��ֵ
	
	// \tˮƽ�Ʊ����ռ��8���ֽ�  \t����ʹ���������е� hello2024���������
	cout << "aaaa\thello 2024!" << endl;
	cout << "aa\thello 2024!" << endl;
	cout << "aaaaaa\thello 2024!" << endl;
	system("pause");
	return 0;
}

	//��������
	//��ʶ�������ǹؼ���
	//��ʶ��ֻ������ĸ�����֡��»�����ɣ����������ֿ�ͷ
	//��ʶ�������ִ�Сд

//sizeof(��������/����)

//������   float �����Ⱥ��������ͨ�����һ����ĸ f    ռ4�ֽ�
//˫���� double  ռ8�ֽ�
//Ĭ������£����һ��С��������ʾ6λ��Ч����