#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
class Person
{
public:
	Person(string name, int score)
	{
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	int m_score;
};
void creatPerson(vector<Person>& v)//一定要用引用的方式引入
{
	string nameseed = "ABCDE";
	for (int i = 0;i < 5;i++)
	{
		string name = "选手";
		name += nameseed[i];

		int score = 0;
		Person p(name, score);
		v.push_back(p);//创建的每个选手放入到容器中
		
	}
}

void setscore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数 放入到deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 40 + 61; // 60 ~ 100
			d.push_back(score);
		}

		////测试
		//cout << "选手： " << it->m_name << " 打分： " << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		// cout << *dit << " ";
		//}
		//cout << endl;
		 
		//排序
		sort(d.begin(), d.end());
		//去除最高和最低分
		d.pop_back();
		d.pop_front();
		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit; //累加每个评委的分数
		}
		float avg = sum / d.size();//这里的d.size()=8
		//将平均分 赋值给选手身上
		it->m_score = avg;
	}
}

void showscore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "姓名：" << it->m_name << " 平均分：" << (float)it->m_score << endl;
	}
}

int main()
{
	//添加随机数种子
	srand((unsigned int)time(NULL));
	vector<Person>v;
	creatPerson(v);
	////测试
	//for (vector<Person>::iterator it=v.begin();it!=v.end();it++)
	//{
	//	cout << "姓名：" << (*it).m_name << " 分数：" << (*it).m_score << endl;
	//}
	//2.给5名选手打分
	setscore(v);
	//3.求5名选手的平均分
	showscore(v);
	system("pause");
	return 0;
}
