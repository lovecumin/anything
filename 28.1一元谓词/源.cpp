#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
//�º�������������bool�������ͣ���Ϊν��
//operator()����һ����������ô����һԪν��

class greatfive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test()
{
	vector<int>v;
	for (int i=0;i<10;i++)
	{
		v.push_back(i);
	}

	//	������������û�д���5������ 
	vector<int>::iterator it=find_if(v.begin(),v.end(),greatfive());
	if (it==v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��˴���5������Ϊ��" << *it << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}