#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>
//���õ������㷨merge 
//�����������������У��������������е�˳��һ�� ������������ǽ���
void myprint(int val)
{
	cout << val << " ";
}
void test1()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	vector<int>vtarger;
	vtarger.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarger.begin());
	for_each(vtarger.begin(), vtarger.end(), myprint);
	cout << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
