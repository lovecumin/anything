#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>

//copy�㷨 copy�㷨�����ڲ�ͬ������֮����и��� ����<list>��<vector>
//transform �����ڿ�����ͬʱ�����ݲ���
void myprint(int val)
{
	cout << val << " ";
}
void test1()
{
	vector<int>v1;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(),v2.end(),myprint);
	cout << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
