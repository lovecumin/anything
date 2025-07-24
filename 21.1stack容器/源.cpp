#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <stack>
void test()
{
	stack<int>s;
	s.push(1);
	s.push(2);
	s.push(11);
	s.push(12);

	while (!s.empty())
	{
		cout <<"栈顶元素：" << s.top() << endl;

		s.pop();
		cout << "栈的元素大小"<<s.size() << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}