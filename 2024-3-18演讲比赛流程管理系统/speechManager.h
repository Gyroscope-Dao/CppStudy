#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<deque>
#include"speaker.h"
#include <algorithm>
#include<numeric>
#include<functional>
#include<fstream>


//设计演讲管理类
class SpeechManager {
public:
	//构造函数
	SpeechManager();

	//展示菜单
	void show_Menu();

	//退出系统
	void exitSystem();

	//析构函数
	~SpeechManager();

	//初始化属性
	void initSpeech();

	//初始化创建12名选手
	void createSpeaker();

	//开始比赛 - 比赛流程控制
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示比赛结果
	void showScore();

	//保存记录
	void saveRecord();

	//查看记录
	void loadRecord();

	//文件为空标志
	bool fileIsEmpty;

	//往届记录
	map<int, vector<string>>m_Record;//第几届  数据

	//查看往届得分
	void showRecord();

	//清空记录
	void clearRecord();

	//成员属性
	vector<int>v1;//比赛选手编号 12
	vector<int>v2;//第一轮晋级编号 6
	vector<int>vVictory;//获胜前三名编号  3
	map<int, Speaker>m_Speaker;
	int m_Index;



	
};