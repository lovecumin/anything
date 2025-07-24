#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>
#define meishu 0
#define cehua  1
#define bianju 2
#include<ctime>;
class Worker
{
public:
	//Worker worker();
	string m_name;
	int m_salary;
};
void creatworker(vector<Worker>&v)
{
	string nameseed="ABCDEFGHIJ";
	for (int i=0;i<10;i++)
	{
		Worker worker;
		worker.m_name = "员工";
		worker.m_name += nameseed[i];

		worker.m_salary = rand() % 10000 + 10000;//10000-19999
		v.push_back(worker);
	}
}
void setgroud(vector<Worker>&vwork, multimap<int, Worker>&mwork)
{
	for (vector<Worker>::iterator it = vwork.begin();it != vwork.end();it++)
	{
		//随机生成部门的编号
		int DI = rand() % 3;
		//key为部门编号  value为具体员工
		mwork.insert(make_pair(DI, *it));
	}
}
void showWorker(multimap<int,Worker>&mwork)
{
	cout << "美术部门" << endl;
	multimap<int, Worker>::iterator pos =mwork.find(meishu);
	int count=mwork.count(meishu);
	int index = 0;
	for (pos;pos!=mwork.end()&&index<count;pos++,index++)
	{
		cout << "name= " << pos->second.m_name << " salary= " << pos->second.m_salary << endl;
	}
	cout << endl;
	cout << "----------------------------" << endl;
	cout << "策划部门" << endl;
	pos = mwork.find(cehua);
	count = mwork.count(cehua);
	index = 0;
	for (pos;pos != mwork.end() && index < count;pos++, index++)
	{
		cout << "name= " << pos->second.m_name << " salary= " << pos->second.m_salary << endl;
	}
	cout << endl;
	cout << "----------------------------" << endl;
	cout << "编剧部门" << endl;
	pos = mwork.find(bianju);
	count = mwork.count(bianju);
	index = 0;
	for (pos;pos != mwork.end() && index < count;pos++, index++)
	{
		cout << "name= " << pos->second.m_name << " salary= " << pos->second.m_salary << endl;
	}
	cout << endl;
}
int main()
{
	srand((unsigned)time(NULL));
	//创建员工
	vector<Worker>vwork;
	creatworker(vwork);
	/*for (vector<Worker>::iterator it = vwork.begin();it != vwork.end();it++)
	{
		cout <<"姓名； " << it->m_name <<" 工资 "<<it->m_salary<< endl;
	}*/
	//员工分组
	multimap<int, Worker>mwork;
	setgroud(vwork,mwork);
	//显示员工
	showWorker(mwork);

	system("pause");
	return 0;
}