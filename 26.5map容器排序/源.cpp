#include <iostream>
using namespace std;
#include<map>
class myCompare
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};

void test()
{
	map<int, int,myCompare>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(4, 10));
	m.insert(make_pair(3, 10));
	m.insert(make_pair(2, 10));
	m.insert(make_pair(5, 10));
	for (map<int,int, myCompare>::iterator it=m.begin();it!=m.end();it++)
	{
		cout << "key= " << it->first << " value= " << it->second << endl;
	}
	cout << endl;
}


int main()
{
	test();
	
	system("pause");
	return 0;
}