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
void creatPerson(vector<Person>& v)//һ��Ҫ�����õķ�ʽ����
{
	string nameseed = "ABCDE";
	for (int i = 0;i < 5;i++)
	{
		string name = "ѡ��";
		name += nameseed[i];

		int score = 0;
		Person p(name, score);
		v.push_back(p);//������ÿ��ѡ�ַ��뵽������
		
	}
}

void setscore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����ί�ķ��� ���뵽deque������
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 40 + 61; // 60 ~ 100
			d.push_back(score);
		}

		////����
		//cout << "ѡ�֣� " << it->m_name << " ��֣� " << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		// cout << *dit << " ";
		//}
		//cout << endl;
		 
		//����
		sort(d.begin(), d.end());
		//ȥ����ߺ���ͷ�
		d.pop_back();
		d.pop_front();
		//ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit; //�ۼ�ÿ����ί�ķ���
		}
		float avg = sum / d.size();//�����d.size()=8
		//��ƽ���� ��ֵ��ѡ������
		it->m_score = avg;
	}
}

void showscore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "������" << it->m_name << " ƽ���֣�" << (float)it->m_score << endl;
	}
}

int main()
{
	//������������
	srand((unsigned int)time(NULL));
	vector<Person>v;
	creatPerson(v);
	////����
	//for (vector<Person>::iterator it=v.begin();it!=v.end();it++)
	//{
	//	cout << "������" << (*it).m_name << " ������" << (*it).m_score << endl;
	//}
	//2.��5��ѡ�ִ��
	setscore(v);
	//3.��5��ѡ�ֵ�ƽ����
	showscore(v);
	system("pause");
	return 0;
}
