#include <iostream>
using namespace std;
#include<set>

void printset(set<float>s)
{
	for (set<float>::iterator it = s.begin();it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	set<float>s1;
	s1.insert(1.2);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	printset(s1);

	if (s1.empty())
	{
		cout << "set容器为空"<< endl;
	}
	else
	{
		cout << "set容器不为空" << endl;
		cout << "s1的大小为" <<s1.size()<< endl;
	}


	set<float>s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	printset(s2);
	printset(s1);
	s2.swap(s1);
	printset(s2);
	printset(s1);
}
int main()
{
	test();
	system("pause");
	return 0;
}