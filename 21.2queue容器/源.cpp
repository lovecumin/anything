#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <queue>
#include<string>

//只有队头队尾能被访问，因此不允许有遍历行为 入队push 出队pop 没有top()
class person
{
public:
	person(string name, int age)
	{
		this->mage = age;
		this->mname = name;
	}
	int mage;
	string mname;
};
void test()
{
	//创建队列
	queue<person>q;
	//准备数据
	person p1("bob",14);
	person p2("pob", 15);
	person p3("mob", 16);
	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);


	while (!q.empty())
	{
		cout << "出队前队列的元素大小" << q.size() << endl;
		cout << "队头元素--姓名：" << q.front().mname << "队头元素--年龄：" << q.front().mage<<endl;
		cout << "队尾元素--姓名：" << q.back().mname << "队头元素--年龄：" << q.back().mage << endl;
		q.pop();
		cout << "出队后队列的元素大小" << q.size() << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}