#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
//�º�������������bool�������ͣ���Ϊν��
//operator()����������������ô������Ԫν��
class mycompare
{
public:
	bool operator()(int v1,int v2)  //bool��ν��  v1 v2 �Ƕ�Ԫ
	{
		return v1 > v2;
	}
};
void test()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(25);
	v.push_back(52);
	v.push_back(30);
	v.push_back(30);
	//�Ӵ�С
	sort(v.begin(), v.end());
	// ��С��������
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//
	sort(v.begin(),v.end(),mycompare());
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}