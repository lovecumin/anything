#include <iostream>
using namespace std;
#include<string>
//����Ĵ���
void test()
{
	pair<string, int>p1(string("tom"), 15);
	cout << "������" << p1.first << " ����" << p1.second << endl;

	pair<string, int>p2 = make_pair("bob", 16);
	cout << "������ " << p2.first << " ���� " << p2.second << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}