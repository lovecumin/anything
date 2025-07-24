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

	//�˵�����
	void show_Menu();

	//�˳�����
	void Exit_Menu();

	~SpeechManager();

	//��ʼ�����Ժ�����
	void Init_Speech();

	//����12��ѡ��
	void createSpeaker();

	//��ʼ����  �������̵Ŀ��ƺ���
	void startSpeech();
	
	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�÷�
	void showScore();

	//�����ļ�
	void saveRecord();

	//��ȡ�÷�
	void loadRecord();

	//��ȡ��¼
	void showRecord();

	//�������
	void clearRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	map<int,vector<string>>m_Record;

	//��Ա����
	//��һ��ѡ�ֱ������
	vector<int>v1;

	//�ڶ���ѡ�ֱ������
	vector<int>v2;

	//ʤ��ǰ�����ı������
	vector<int>victory;

	//��ű�ź�ѡ�ֵ�����
	map<int, Speaker>m_Speaker;

	//��¼��ǰ��������
	int m_index;
};