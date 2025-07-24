#include <iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>
#include<ctime>
#define cehua  0
#define bianju 1
#define meishu 2
class Worker
{
public:
	string m_Name;
	int m_Salary;
};
void CreateWorker(vector<Worker>&v)
//上面一行代码加入 & 是为了让函数能够修改传入的vector对象，如果不加&，函数只能读取传入的vector，而不能修改它
//在C++中若想通过一个函数来修改一个对象的内容时，需要传入这个对象的地址。
{
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0;i < 10;i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameseed[i];
		
		worker.m_Salary = rand()% 1000 + 1000;//1000~1999
		v.push_back(worker);
	}
}
void setgroud(vector<Worker>&v, multimap<int, Worker>&m)
{
	
	for (vector<Worker>::iterator it = v.begin();it != v.end();it++)
	{
		//产生部门随机编号
		int depID = rand() % 3;

		//key部门编号  value具体员工
		m.insert(make_pair(depID, *it));
	}
}
void showgroup(multimap<int, Worker>& m)
{
	cout << "策划部门" << endl;
	multimap<int, Worker>::iterator pos = m.find(cehua);
	int count = m.count(cehua);//统计具体的人数
	int index = 0;
	cout << count << endl;
	for (pos;pos != m.end()&&index<count;pos++,index++)
	{
		cout << "name= " << pos->second.m_Name << " slsary= " << pos->second.m_Salary << endl;
	}

	cout <<"-------------------------" << endl;
	cout << "编剧部门" << endl;
	pos = m.find(bianju);
	count = m.count(bianju);//统计具体的人数
	index = 0;
	cout << count << endl;
	for (pos;pos != m.end() && index < count;pos++, index++)
	{
		cout << "name= " << pos->second.m_Name << " slsary= " << pos->second.m_Salary << endl;
	}

	cout << "-------------------------" << endl;
	cout << "美术部门" << endl;
	pos = m.find(meishu);
	count = m.count(meishu);//统计具体的人数
	index = 0;
	cout << count << endl;
	for (pos;pos != m.end() && index < count;pos++, index++)
	{
		cout << "name= " << pos->second.m_Name << " slsary= " << pos->second.m_Salary << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	//1.创建员工
	vector<Worker>vworker;
	CreateWorker(vworker);
	////测试创建员工
	//for (vector<Worker>::iterator it = vworker.begin();it != vworker.end();it++)
	//{
	//	cout << "name= " << it->m_Name << " salary= " << it->m_Salary << endl;
	//}
	//cout << endl;

	//2.员工分组
	multimap<int,Worker>mworker;
	setgroud(vworker,mworker);

	//3.分组显示员工
	showgroup(mworker);

	//test();
	system("pause"); 
	return 0;
}