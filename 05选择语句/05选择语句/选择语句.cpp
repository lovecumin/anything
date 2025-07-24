#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	/*int score;
	cout << "输入分数" << endl;
	cin >> score;
	cout << "分数为：" << score << endl;
	if (score > 600)
		if(score>650)
			cout << "C9" << endl;
		else
			cout << "985" << endl;
	else if (score>550)
		cout << "211" << endl;
	else
		cout << "双非" << endl;*/


	//比较abc
	int a=0, b=0, c = 0;
	cout << "请输入a" << endl;
	cin >> a;
	cout << "请输入b" << endl;
	cin >> b;
	cout << "请输入c" << endl;
	cin >> c;
	cout << "数字a:" << a << endl;
	cout << "数字b:" << b << endl;
	cout << "数字c:" << c << endl;
	if (a > b)
	{
		if (a > c)
		{
			cout << "max=" << a << endl;
		}
	}
	else 
		if (b > c)
		{
			cout << "max=" << b << endl;
		}
		else
			cout << "max=" << c << endl;



	system("pause");
	return 0;
}