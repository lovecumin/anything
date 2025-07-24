#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"Speaker.h"
#include<algorithm>
#include<deque>
#include<string>
#include<functional>
#include<numeric>
#include<fstream>

class SpeechManager
{
public:
	SpeechManager();

	//菜单功能
	void show_Menu();

	//退出功能
	void Exit_Menu();

	~SpeechManager();

	//初始化属性和容器
	void Init_Speech();

	//创建12名选手
	void createSpeaker();

	//开始比赛  整个流程的控制函数
	void startSpeech();
	
	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示得分
	void showScore();

	//保存文件
	void saveRecord();

	//读取得分
	void loadRecord();

	//读取记录
	void showRecord();

	//清空数据
	void clearRecord();

	//判断文件是否为空
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int,vector<string>>m_Record;

	//成员属性
	//第一轮选手编号容器
	vector<int>v1;

	//第二轮选手编号容器
	vector<int>v2;

	//胜出前三名的编号容器
	vector<int>victory;

	//存放编号和选手的容器
	map<int, Speaker>m_Speaker;

	//记录当前比赛轮数
	int m_index;
};