#include<iostream>
using namespace std;
#include"SpeechManager.h"
#include<string>
#include<ctime>
int main()
{
	srand((unsigned int)time(NULL));
	//创建管理类的对象
	SpeechManager sm;
	
	//测试12名选手创建
	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin();it != sm.m_Speaker.end();it++)
	{
		cout << "选手编号： " << it->first << " 姓名 " << it->second.m_name << " 分数 " << it->second.m_score[0] << endl;
	}*/
	
	int choice = 0;
	while (true)
	{
		sm.show_Menu();
		cout << "请输入你的选择" << endl;
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