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
		worker.m_name = "Ա��";
		worker.m_name += nameseed[i];

		worker.m_salary = rand() % 10000 + 10000;//10000-19999
		v.push_back(worker);
	}
}
void setgroud(vector<Worker>&vwork, multimap<int, Worker>&mwork)
{
	for (vector<Worker>::iterator it = vwork.begin();it != vwork.end();it++)
	{
		//������ɲ��ŵı��
		int DI = rand() % 3;
		//keyΪ���ű��  valueΪ����Ա��
		mwork.insert(make_pair(DI, *it));
	}
}
void showWorker(multimap<int,Worker>&mwork)
{
	cout << "��������" << endl;
	multimap<int, Worker>::iterator pos =mwork.find(meishu);
	int count=mwork.count(meishu);
	int index = 0;
	for (pos;pos!=mwork.end()&&index<count;pos++,index++)
	{
		cout << "name= " << pos->second.m_name << " salary= " << pos->second.m_salary << endl;
	}
	cout << endl;
	cout << "----------------------------" << endl;
	cout << "�߻�����" << endl;
	pos = mwork.find(cehua);
	count = mwork.count(cehua);
	index = 0;
	for (pos;pos != mwork.end() && index < count;pos++, index++)
	{
		cout << "name= " << pos->second.m_name << " salary= " << pos->second.m_salary << endl;
	}
	cout << endl;
	cout << "----------------------------" << endl;
	cout << "��粿��" << endl;
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
	//����Ա��
	vector<Worker>vwork;
	creatworker(vwork);
	/*for (vector<Worker>::iterator it = vwork.begin();it != vwork.end();it++)
	{
		cout <<"������ " << it->m_name <<" ���� "<<it->m_salary<< endl;
	}*/
	//Ա������
	multimap<int, Worker>mwork;
	setgroud(vwork,mwork);
	//��ʾԱ��
	showWorker(mwork);

	system("pause");
	return 0;
}