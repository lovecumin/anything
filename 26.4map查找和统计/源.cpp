#include <iostream>
using namespace std;
#include<map>

void test()
{
	map<int, int>m;
	//multimap<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 10));
	m.insert(pair<int, int>(3, 10));
	m.insert(make_pair(3, 10));//map��������������ظ���Ԫ�أ��ؼ���key�ظ��Ͳ�����
	//����multimap��count���Դ���1

	//����
	map<int, int>::iterator pos = m.find(4);//find ���ص��ǵ�����
	if (pos != m.end())//
	{
		cout << "�ҵ���" <<(*pos).first <<" value= "<<pos->second<<endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}

	//ͳ��
	int ret=m.count(3);
	cout << "ret= " << ret << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}