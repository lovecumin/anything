#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>
//swap ����   ����������Ҫ��ͬ������
//�Զ������ͽ��� ��Ҫ����operator==
/*
v1.swap(v2); �� swap(v1, v2); ���������ö���������������vector�����ݣ������ǵĵ��÷�ʽ��ͬ��

1.
v1.swap(v2);��
����һ����Ա�������á�
swap��vector���һ����Ա������
����ʱ��v1�ǵ�ǰ����v2��Ҫ��֮�����Ķ���
�������ֱ����v1�ϵ���swap��Ա������������v2��Ϊ������
���ֵ��÷�ʽ����Ҫ��������<algorithm>ͷ�ļ�����Ϊswap��vector���һ���֡�
2.
swap(v1, v2);��
����һ���ǳ�Ա�������á�
swap��һ��ȫ�ֺ�����������<algorithm>ͷ�ļ��С�
����ʱ����Ҫ��������vector������Ϊ������
������ûύ�����������vector�����ݡ�
ʹ�����������Ҫ����<algorithm>ͷ�ļ���
��֮ͬ����

��ͬ�㣺���߶���ʵ������vector�����ݽ�����
��ͬ�㣺
���÷�ʽ��ͬ��һ���ǳ�Ա�������ã���һ���Ƿǳ�Ա�������á�
������ͷ�ļ���ͬ����Ա�������ò���Ҫ�������ͷ�ļ������ǳ�Ա����������Ҫ����<algorithm>ͷ�ļ���
�ɶ��ԣ���ĳЩ����£�ʹ�÷ǳ�Ա����swap���ܸ�������⣬��Ϊ������ر�������������֮��Ľ���������
*/
class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}

};
void test1()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
		v2.push_back(i+100);
	}
	for_each(v1.begin(),v1.end(),myprint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myprint());
	cout << endl;
	cout << "---------------------" << endl;
	//swap(v1, v2);
	v1.swap(v2);// ʵ�ֵĹ�����swap(v1, v2)һ��
	for_each(v1.begin(), v1.end(), myprint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myprint());
	cout << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}