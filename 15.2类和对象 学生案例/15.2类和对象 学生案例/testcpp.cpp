#include<iostream>
using namespace std;
#include<string.h>
class student  //����� ����
{
	//����Ȩ��
public: //����Ȩ��

	/*���е����Ժ���Ϊ  ����ͳһ��Ϊ��Ա
	����    ��Ա����  ��Ա����
	��Ϊ    ��Ա����  ��Ա����
	*/



	//����

	string  names;  //����
	int nums;
	//��Ϊ  ��һЩ����
	void  showstudent()//��ʾ������ѧ��
	{
		cout << "������ " << names << "  ѧ�ţ� " <<nums<< endl;
	}
	void setname(string name)
	{
		names = name;
	}
	void setnum(int num)
	{
		nums = num;
	}
};

int main()
{
	//����һ������ѧ��  ʵ��������
	student s1;
	//��s1����  �������Ը�ֵ����
	
	//s1.names = "ս��";
	s1.setname("����");
	s1.nums = 1;
	//s1.setnum(2);   s1.setnum(2) ��s1.nums�����Ը�nums��ֵ
	//��ʾѧ����Ϣ
	s1.showstudent();

	student s2;
	s2.setname("����");
	s2.nums = 2;
	s2.showstudent();
	system("pause");
	return 0;
}