#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>

//�º���
class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

//ν�� _pred
class greater40
{
public:
	bool operator()(int val)
	{
		return val > 40;
	}
};
void test1()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);


	for_each(v.begin(), v.end(), myprint());
	cout << endl;

	//���ڵ�40�Ļ���400
	replace_if(v.begin(), v.end(), greater40(), 400);//��ν�ʵ�ʱ�����С����
	for_each(v.begin(), v.end(), myprint());
	cout << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
