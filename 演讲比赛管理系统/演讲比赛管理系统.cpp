#include<iostream>
using namespace std;
#include"SpeechManager.h"
#include<string>
#include<ctime>
int main()
{
	srand((unsigned int)time(NULL));
	//����������Ķ���
	SpeechManager sm;
	
	//����12��ѡ�ִ���
	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin();it != sm.m_Speaker.end();it++)
	{
		cout << "ѡ�ֱ�ţ� " << it->first << " ���� " << it->second.m_name << " ���� " << it->second.m_score[0] << endl;
	}*/
	
	int choice = 0;
	while (true)
	{
		sm.show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			sm.startSpeech();
			break;
		case 2:
			sm.showRecord();
			break;
		case 3:
			sm.clearRecord();
			break;
		case 0:
			sm.Exit_Menu();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}