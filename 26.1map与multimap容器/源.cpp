#include <iostream>
using namespace std;
#include<map>
//map�����Ĺ���͸�ֵ   Ĭ�Ϲ���
//map����������Ԫ�ض��ǳɶԳ��֣���������ʱ��Ҫʹ�ö���
void printmap(map<int, int>&m)
{
	for (map<int,int>::iterator it=m.begin();it!=m.end();it++)
	{
		cout << "key=" << (*it).first << " value= " << it->second << endl;
	}
	cout << endl;
}
void test()
{
	map<int, int>m;//map�����ڵ�Ԫ����pair���ͣ�����������Ҫ����������
	m.insert(pair<int,int>(1,10));//��������
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(2, 20));
	

	printmap(m);///��ӡ���������ݻ����map�����е� keyֵ����
	//��������
	map<int, int>m2(m);
	printmap(m2);
	//��ֵ����
	map<int, int>m3;
	m3 = m;
	printmap(m3);
}
int main()
{
	test();
	system("pause");
	return 0;
}