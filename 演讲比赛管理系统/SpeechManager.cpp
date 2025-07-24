#include "SpeechManager.h"

//���캯��
SpeechManager::SpeechManager()
{
	//��ʼ������
	this->Init_Speech();
	this->createSpeaker();
	this->loadRecord();
	this->clearRecord();
}

//�˵�����
void SpeechManager::show_Menu()
{
	cout << "**************************************************" << endl;
	cout << "****************** ��ӭ�μ��ݽ����� **************" << endl;
	cout << "******************  1.��ʼ�ݽ�����  **************" << endl;
	cout << "******************  2.�鿴�����¼  **************" << endl;
	cout << "******************  3.��ձ�����¼  **************" << endl;
	cout << "******************  0.�˳���������  **************" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}
void SpeechManager::Exit_Menu()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//����12��ѡ��
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0;i < nameSeed.size();i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		//��������ѡ��
		Speaker sp;
		sp.m_name = name;
		for (int j = 0;j < 2;j++)
		{
			sp.m_score[j] = 0;
		}
		//����ѡ�ֵı�Ų��ŵ�v1������
		this->v1.push_back(i + 10001);
		//ѡ�ֱ���Լ�ѡ�ַ��뵽map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::Init_Speech()
{
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_Speaker.clear();
	//��������
	this->m_index = 1;

	//����¼������Ҳ���
	//+this->m_Record.clear();
	
}
//��ʼ����  �������̵Ŀ��ƺ���
void SpeechManager::startSpeech()
{
	//��һ�ֿ�ʼ����

	//��ǩ
	this->speechDraw();
	//����
	this->speechContest();
	//��ʾ����
	this->showScore();

	//�ڶ��ֿ�ʼ����
	this->m_index++;
	//��ǩ
	this->speechDraw();
	//����
	this->speechContest();
	//��ʾ���ս��
	this->showScore();
	//���������ļ���
	this->saveRecord();

	//���ñ���
	this->Init_Speech();
	this->createSpeaker();
	this->loadRecord();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
	
}

//��ǩ
void SpeechManager::speechDraw()
{
	cout << "��<<" << this->m_index << ">> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "---------------------------------" << endl;
	cout << "��ǩ���ݽ��������" << endl;
	if (this->m_index==1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(),v1.end());
		for (vector<int>::iterator it = v1.begin();it != v1.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//�ڶ��ֱ���
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin();it != v2.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------------------" << endl;
	system("pause");
	cout << endl;
}
//����
void SpeechManager::speechContest()
{
	cout << "--------------��" <<this->m_index<<"�ֱ�����ʽ��ʼ----------------" <<endl;

	//׼����ʱ����  ���С��ɼ�
	multimap<double, int, greater<double>>groupScore;
	int num = 0;

	vector<int>v_Src;//����ѡ������  ��һ������Щѡ���ڱ���
	if (this->m_index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin();it != v_Src.end();it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0;i < 10;i++)
		{
			double score = (double)(rand() % 401 + 600) / 10.f;//600~1000
		//	cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(),greater<double>());//����   �ڽ��������� ��Ҫ����ͷ�ļ� functional
		                         //greater�ǽ���  Ĭ���� less ����
		d.pop_back();//ȥ����ͷ�
		d.pop_front();//ȥ����߷�
		double sum = accumulate(d.begin(),d.end(),0.0f);//accumulate �ۼ���ͺ���  ������Ҫͷ�ļ� numeric
		double avg = sum / (double)d.size();

		//��ӡƽ����
	    //cout << "��ţ�" << *it << " ������ " << this->m_Speaker[*it].m_name << " ��ȡƽ���֣� " << avg << endl;

		//��ƽ���ַ���map������
		this->m_Speaker[*it].m_score[this->m_index - 1] = avg;/*��һ��䣺this->m_SpeakerΪmap��������ͨ��������
		�ķ�ʽ����ŷ��������в���ͨ����ŷ��ʵ�valueֵ��valueֵ�г�Ա������m_Score������Ϊthis->m_Index-1��  */
	
		//��������� ���뵽��ʱС��������
		groupScore.insert(make_pair(avg, *it));//key�ǵ÷֣�value�Ǿ���ѡ�ֱ��
		//ÿ6��ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();it != groupScore.end();it++)
			{
				cout << "��ţ�" << it->second<<" ������ " << this->m_Speaker[it->second].m_name<<" �ɼ� "
					<<this->m_Speaker[it->second].m_score[this->m_index-1] <<endl;
			}

			//ȡ��ǰ����
			int count = 0;//�������ǰ3��
			for (multimap<double,int,greater<double>>::iterator it = groupScore.begin();it != groupScore.end()&&count<3;it++, count++)
			{
				if (this->m_index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					victory.push_back((*it).second);
				}
			}

			groupScore.clear();//С���������
			cout << endl;
		}
	}
	cout <<" -------------��" <<this->m_index<<"�ֱ������----------------" <<endl;
}

//��ʾ�÷�
void SpeechManager:: showScore()
{
	cout << " -------------��" << this->m_index << "�ֽ���ѡ����Ϣ���£�----------------" << endl;

	vector<int>v;
	if (this->m_index == 1)
	{
		v = v2;
	}
	else
	{
		v = victory;
	}
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << " ������ " << this->m_Speaker[*it].m_name << " �÷֣�"
			<< this->m_Speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();

}

//����÷�
void SpeechManager::saveRecord()
{
	ofstream ofs;//����ofsȥ�����ļ�
	ofs.open("speech.csv",ios::out|ios::app);//outд�ļ� app ����׷�ӵķ�ʽд

	//��ÿ��ѡ�ֵ�����д�뵽�ļ���
	for (vector<int>::iterator it = victory.begin();it != victory.end();it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ","  ;
	}
	ofs << endl;  
	ofs.close();
	cout << " �ļ�������ɣ� " << endl;

	//�����ļ���Ϊ�յ�״̬
	this->fileIsEmpty = false;

}

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv",ios::in);//���ļ�
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//�ļ����
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
	//	cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch);//�������ȡ�ĵ����ַ� �Ż���
	string data;
	int index = 0;
	while (ifs>>data)
	{
		//cout << data << endl;
		//10010,	86,	10004,	82,	10007,	81,

		vector<string>v;//���6���ַ�������Ϣ
		

		int pos = -1;//���ҡ�������λ��
		int start = 0;
		
		while (true)
		{
			pos = data.find(",", start);//��start��0��λ�ÿ�ʼ���ҡ�����
			if (pos == -1)
			{
				//û���ҵ������
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);//�ѽس��������ݷ���������
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index,v));
		index++;
	}
	ifs.close();
	/*for (map<int, vector<string>>::iterator it = m_Record.begin();it != m_Record.end();it++)
	{
		cout<<it->first << "�ھ���ţ�" << it->second[0] << " ������ " << it->second[1] << endl;
	}*/
}
//��ʾ�����¼
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ����ļ������ڣ�" << endl;
	}
	else
	{
		for (int i = 0;i < this->m_Record.size();i++)
		{
			cout << "��" << i + 1 << "��" <<
				"�ھ���ţ� " << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " " <<
				"�Ǿ���ţ� " << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " " <<
				"������ţ� " << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

////��ʾ��������ĺ���ʵ��
//void  SpeechManager::showRecord() {
//	for (int i = 0;i < this->m_Record.size();i++) {
//		cout << "��<<" << i + 1 << ">>��" <<
//			" �ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << "  " <<
//			" �Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << "  " <<
//			" ������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
//	}
//	system("pause");
//	system("cls");
//}


void SpeechManager::clearRecord()
{
	cout << "�Ƿ�����ļ���" << endl;
	cout << "1����" << endl;
	cout << "2����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//ȷ�����
		ofstream ofs("speech.scv",ios::trunc);
		ofs.close();
		this->Init_Speech();
		this->createSpeaker();
		this->loadRecord();
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//��������
SpeechManager::~SpeechManager()
{

}