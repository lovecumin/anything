#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
#include<vector>
/*
	push_back(ele); //β������Ԫ��ele
	pop_back(); //ɾ�����һ��Ԫ��
	insert(const_iterator pos, ele); //������ָ��λ��pos����Ԫ��ele
	insert(const_iterator pos, int count,ele); //������ָ��λ��pos����count��Ԫ��ele
	erase(const_iterator pos); //ɾ��������ָ���Ԫ��
	erase(const_iterator start, const_iterator end); //ɾ����������start��end֮���Ԫ��
	clear(); //ɾ������������Ԫ��
*/

void printvector(vector<int> &v1)
{
	for (vector<int>::iterator it=v1.begin();it!=v1.end();it++)
	{
		cout <<  *it << " ";
	}
	cout << endl;
}
void test1()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	printvector(v1);

	//βɾ
	v1.pop_back();
	printvector(v1);

	//��������
	v1.insert(v1.begin(), 100);
	printvector(v1);
	v1.insert(v1.begin(), 3,300);
	printvector(v1);

	//ɾ������
	v1.erase(v1.begin());
	printvector(v1);

	//�������
	v1.erase(v1.begin(),v1.end());//�ȼ������
	printvector(v1);

	v1.clear();
	printvector(v1);
}


int main()
{
	test1();

	system("pause");
	return 0;
}
