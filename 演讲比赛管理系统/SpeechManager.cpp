#include "SpeechManager.h"

//构造函数
SpeechManager::SpeechManager()
{
	//初始化属性
	this->Init_Speech();
	this->createSpeaker();
	this->loadRecord();
	this->clearRecord();
}

//菜单功能
void SpeechManager::show_Menu()
{
	cout << "**************************************************" << endl;
	cout << "****************** 欢迎参加演讲比赛 **************" << endl;
	cout << "******************  1.开始演讲比赛  **************" << endl;
	cout << "******************  2.查看往届记录  **************" << endl;
	cout << "******************  3.清空比赛记录  **************" << endl;
	cout << "******************  0.退出比赛程序  **************" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}
void SpeechManager::Exit_Menu()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//创建12名选手
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0;i < nameSeed.size();i++)
	{
		string name = "选手";
		name += nameSeed[i];

		//创建具体选手
		Speaker sp;
		sp.m_name = name;
		for (int j = 0;j < 2;j++)
		{
			sp.m_score[j] = 0;
		}
		//创建选手的编号并放到v1容器中
		this->v1.push_back(i + 10001);
		//选手编号以及选手放入到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::Init_Speech()
{
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_Speaker.clear();
	//比赛轮数
	this->m_index = 1;

	//将记录的容器也清空
	//+this->m_Record.clear();
	
}
//开始比赛  整个流程的控制函数
void SpeechManager::startSpeech()
{
	//第一轮开始比赛

	//抽签
	this->speechDraw();
	//比赛
	this->speechContest();
	//显示晋级
	this->showScore();

	//第二轮开始比赛
	this->m_index++;
	//抽签
	this->speechDraw();
	//比赛
	this->speechContest();
	//显示最终结果
	this->showScore();
	//保存结果到文件中
	this->saveRecord();

	//重置比赛
	this->Init_Speech();
	this->createSpeaker();
	this->loadRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
	
}

//抽签
void SpeechManager::speechDraw()
{
	cout << "第<<" << this->m_index << ">> 轮比赛选手正在抽签" << endl;
	cout << "---------------------------------" << endl;
	cout << "抽签后演讲结果如下" << endl;
	if (this->m_index==1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(),v1.end());
		for (vector<int>::iterator it = v1.begin();it != v1.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//第二轮比赛
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
//比赛
void SpeechManager::speechContest()
{
	cout << "--------------第" <<this->m_index<<"轮比赛正式开始----------------" <<endl;

	//准备临时容器  存放小组成绩
	multimap<double, int, greater<double>>groupScore;
	int num = 0;

	vector<int>v_Src;//比赛选手容器  看一下是哪些选手在比赛
	if (this->m_index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin();it != v_Src.end();it++)
	{
		num++;
		//评委打分
		deque<double>d;
		for (int i = 0;i < 10;i++)
		{
			double score = (double)(rand() % 401 + 600) / 10.f;//600~1000
		//	cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(),greater<double>());//排序   内建函数对象 需要引入头文件 functional
		                         //greater是降序  默认是 less 升序
		d.pop_back();//去掉最低分
		d.pop_front();//去掉最高分
		double sum = accumulate(d.begin(),d.end(),0.0f);//accumulate 累加求和函数  调用需要头文件 numeric
		double avg = sum / (double)d.size();

		//打印平均分
	    //cout << "编号：" << *it << " 姓名： " << this->m_Speaker[*it].m_name << " 获取平均分： " << avg << endl;

		//将平均分放入map容器中
		this->m_Speaker[*it].m_score[this->m_index - 1] = avg;/*这一语句：this->m_Speaker为map型容器，通过中括号
		的方式将编号放入容器中并可通过编号访问到value值，value值中成员属性有m_Score，轮数为this->m_Index-1轮  */
	
		//将打分数据 放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it));//key是得分，value是具体选手编号
		//每6人取出前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();it != groupScore.end();it++)
			{
				cout << "编号：" << it->second<<" 姓名： " << this->m_Speaker[it->second].m_name<<" 成绩 "
					<<this->m_Speaker[it->second].m_score[this->m_index-1] <<endl;
			}

			//取走前三名
			int count = 0;//便于输出前3名
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

			groupScore.clear();//小组容器清空
			cout << endl;
		}
	}
	cout <<" -------------第" <<this->m_index<<"轮比赛完毕----------------" <<endl;
}

//显示得分
void SpeechManager:: showScore()
{
	cout << " -------------第" << this->m_index << "轮晋级选手信息如下：----------------" << endl;

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
		cout << "选手编号：" << *it << " 姓名： " << this->m_Speaker[*it].m_name << " 得分："
			<< this->m_Speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();

}

//保存得分
void SpeechManager::saveRecord()
{
	ofstream ofs;//利用ofs去操作文件
	ofs.open("speech.csv",ios::out|ios::app);//out写文件 app 是用追加的方式写

	//将每个选手的数据写入到文件中
	for (vector<int>::iterator it = victory.begin();it != victory.end();it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ","  ;
	}
	ofs << endl;  
	ofs.close();
	cout << " 文件保存完成！ " << endl;

	//更改文件不为空的状态
	this->fileIsEmpty = false;

}

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv",ios::in);//读文件
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//文件清空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
	//	cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch);//将上面读取的单个字符 放回来
	string data;
	int index = 0;
	while (ifs>>data)
	{
		//cout << data << endl;
		//10010,	86,	10004,	82,	10007,	81,

		vector<string>v;//存放6个字符串的信息
		

		int pos = -1;//查找“，”的位置
		int start = 0;
		
		while (true)
		{
			pos = data.find(",", start);//从start（0）位置开始查找“，”
			if (pos == -1)
			{
				//没有找到的情况
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);//把截出来的数据放在容器中
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index,v));
		index++;
	}
	ifs.close();
	/*for (map<int, vector<string>>::iterator it = m_Record.begin();it != m_Record.end();it++)
	{
		cout<<it->first << "冠军编号：" << it->second[0] << " 分数： " << it->second[1] << endl;
	}*/
}
//显示往届记录
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空或者文件不存在！" << endl;
	}
	else
	{
		for (int i = 0;i < this->m_Record.size();i++)
		{
			cout << "第" << i + 1 << "届" <<
				"冠军编号： " << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " " <<
				"亚军编号： " << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " " <<
				"季军编号： " << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

////显示往届分数的函数实现
//void  SpeechManager::showRecord() {
//	for (int i = 0;i < this->m_Record.size();i++) {
//		cout << "第<<" << i + 1 << ">>届" <<
//			" 冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << "  " <<
//			" 亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << "  " <<
//			" 季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
//	}
//	system("pause");
//	system("cls");
//}


void SpeechManager::clearRecord()
{
	cout << "是否清空文件？" << endl;
	cout << "1、是" << endl;
	cout << "2、否" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//确认请空
		ofstream ofs("speech.scv",ios::trunc);
		ofs.close();
		this->Init_Speech();
		this->createSpeaker();
		this->loadRecord();
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

//析构函数
SpeechManager::~SpeechManager()
{

}