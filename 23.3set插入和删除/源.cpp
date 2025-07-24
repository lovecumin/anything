#include <iostream>
using namespace std;
#include<set>

void printset(set<int>s)
{
	for (set<int>::iterator it = s.begin();it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	set<int>s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	printset(s1);

	//É¾³ı
	s1.erase(s1.begin());
	printset(s1);

	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printset(s1);
}
int main()
{
	test();
	system("pause");
	return 0;
}