#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>

/*
�󽻼����������ϱ����������������У�����������Ҫ��һ��ν�ʣ�
Ŀ���������ٿռ���Ҫ������������ȡ��ֵ
set_difference����ֵ���ǽ��������һ��Ԫ�ص�λ��
*/

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
		v2.push_back(i + 5);
	}
	vector<int>vtarget;
	//���������   ��������û�н���   ���ٿռ�   ȡС������size����  
	vtarget.resize(max(v1.size(),v2.size()));
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), itEnd, myprint);
	cout << endl;

}

int main()
{
	test1();

	system("pause");
	return 0;
}
