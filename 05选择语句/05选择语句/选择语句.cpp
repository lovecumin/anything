#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	/*int score;
	cout << "�������" << endl;
	cin >> score;
	cout << "����Ϊ��" << score << endl;
	if (score > 600)
		if(score>650)
			cout << "C9" << endl;
		else
			cout << "985" << endl;
	else if (score>550)
		cout << "211" << endl;
	else
		cout << "˫��" << endl;*/


	//�Ƚ�abc
	int a=0, b=0, c = 0;
	cout << "������a" << endl;
	cin >> a;
	cout << "������b" << endl;
	cin >> b;
	cout << "������c" << endl;
	cin >> c;
	cout << "����a:" << a << endl;
	cout << "����b:" << b << endl;
	cout << "����c:" << c << endl;
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