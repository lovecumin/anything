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
//����һ�д������ & ��Ϊ���ú����ܹ��޸Ĵ����vector�����������&������ֻ�ܶ�ȡ�����vector���������޸���
//��C++������ͨ��һ���������޸�һ�����������ʱ����Ҫ�����������ĵ�ַ��
{
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0;i < 10;i++)
	{
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameseed[i];
		
		worker.m_Salary = rand()% 1000 + 1000;//1000~1999
		v.push_back(worker);
	}
}
void setgroud(vector<Worker>&v, multimap<int, Worker>&m)
{
	
	for (vector<Worker>::iterator it = v.begin();it != v.end();it++)
	{
		//��������������
		int depID = rand() % 3;

		//key���ű��  value����Ա��
		m.insert(make_pair(depID, *it));
	}
}
void showgroup(multimap<int, Worker>& m)
{
	cout << "�߻�����" << endl;
	multimap<int, Worker>::iterator pos = m.find(cehua);
	int count = m.count(cehua);//ͳ�ƾ��������
	int index = 0;
	cout << count << endl;
	for (pos;pos != m.end()&&index<count;pos++,index++)
	{
		cout << "name= " << pos->second.m_Name << " slsary= " << pos->second.m_Salary << endl;
	}

	cout <<"-------------------------" << endl;
	cout << "��粿��" << endl;
	pos = m.find(bianju);
	count = m.count(bianju);//ͳ�ƾ��������
	index = 0;
	cout << count << endl;
	for (pos;pos != m.end() && index < count;pos++, index++)
	{
		cout << "name= " << pos->second.m_Name << " slsary= " << pos->second.m_Salary << endl;
	}

	cout << "-------------------------" << endl;
	cout << "��������" << endl;
	pos = m.find(meishu);
	count = m.count(meishu);//ͳ�ƾ��������
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
	//1.����Ա��
	vector<Worker>vworker;
	CreateWorker(vworker);
	////���Դ���Ա��
	//for (vector<Worker>::iterator it = vworker.begin();it != vworker.end();it++)
	//{
	//	cout << "name= " << it->m_Name << " salary= " << it->m_Salary << endl;
	//}
	//cout << endl;

	//2.Ա������
	multimap<int,Worker>mworker;
	setgroud(vworker,mworker);

	//3.������ʾԱ��
	showgroup(mworker);

	//test();
	system("pause"); 
	return 0;
}