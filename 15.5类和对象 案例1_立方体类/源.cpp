#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class cube
{
public:
	//��Ϊ  һ������Ϊ��������

	//�������ȡ�����
	void set_l(int l)
	{
		m_l = l;
	}
	int get_l()
	{
		return m_l;
	}
	void set_w(int w)
	{
		m_w = w;
	}
	int get_w()
	{
		return m_w;
	}
	void set_h(int h)
	{
		m_h = h;
	}
	int get_h()
	{
		return m_h;
	}
	//��ȡ���
	int mianji()
	{
		return 2*((m_l * m_h)+(m_h * m_w)+(m_w*m_l));
	}
	//��ȡ���
	int tiji()
	{
		return (m_l * m_h * m_w);
	}


	bool issamebyclass(cube &cube2)//���ﴫ��һ�������Ϳ��ԣ����洫�����������������еĽ��жԱ�
	{
		if (m_l == cube2.get_l() && m_h == cube2.get_h() && m_w == cube2.get_w())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	//����    ����һ������Ϊ˽��
	int m_l;
	int m_h;
	int m_w;
};

bool issame(cube &cube1,cube &cube2)//����Ҫ������������  ����&cube1���Ա���Ϊ�βο����µĿռ䣬��ʡ�ڴ�
{
	if (cube1.get_l() == cube2.get_l() &&cube1.get_h() == cube2.get_h() && cube1.get_w()== cube2.get_w())
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{

	//1.���������������ܳ�
	cube cube1;
	cube1.set_h(10);
	cube1.set_l(10);
	cube1.set_w(10);
	//cube1.mianji();
	//cube1.tiji();
	cout << "����� " << cube1.mianji() << endl;
	cout << "����� " << cube1.tiji() << endl;

	//2.�ֱ����ó�Ա������ȫ�ֺ����ж������������Ƿ����
	//2.1��Ա����
	cube cube2;
	cube2.set_h(10);
	cube2.set_w(10);
	cube2.set_l(10);
	int ret1 = cube1.issamebyclass(cube2);
	
	if (ret1)
	{
		cout << "���ó�Ա�����ж��������������" << endl;
	}
	else
	{
		cout << "���ó�Ա�����ж����������岻���" << endl;
	}
	//2.2ȫ�ֺ���
	int ret2 = issame(cube1,cube2);
	if (ret2)
	{
		cout << "����ȫ�ֺ����ж��������������" << endl;
	}
	else
	{
		cout << "����ȫ�ֺ����ж����������岻���" << endl;
	}
	system("pause");
	return 0;
}