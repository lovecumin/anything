#include <iostream>
using namespace std;
#include<map>
void printmap(map<int,int>&m)
{
	for (map<int, int>::iterator it = m.begin();it != m.end();it++)
	{
		cout << "key= " << (*it).first << " second= " << (*it).second << endl;
	}
	cout << endl;
}
void test()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 10));
	m.insert(pair<int, int>(3, 10));
	m.insert(pair<int, int>(4, 10));
	m.insert(make_pair(11, 10));
	m.insert(make_pair(12, 10));
	m[100] = 101;
	//[]��������룬��; ��������key���ʵ�value
	
	printmap(m);
	cout << m[100] << endl;

	m.erase(3);
	printmap(m);
	
	m.erase(m.begin());
	printmap(m);

	m.clear();
	//�ȼ���
	m.erase(m.begin(), m.end());
	printmap(m);
}
int main()
{
	test();
	system("pause");
	return 0;
}