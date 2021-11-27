#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<algorithm>
#include<numeric>
#include <fstream>
#include "speaker.h"
using namespace std;

//演讲比赛管理类
class SpeechManager {
public:
	SpeechManager();

	//展示菜单
	void showMenu();

	//退出系统
	void exitSyetem();

	//创建12名选手
	void createSpeaker();

	//开始比赛，比赛整个流程控制函数
	void startSpeech();
	//抽签
	void speechDraw();
	//开始比赛
	void speechContest();
	//显示比赛结果
	void showScore();
	//保存记录
	void saveRecord();
	~SpeechManager();

	//读取记录
	void loadRecord();
	//判断文件是否为空
	bool fileIsEmpty;
	//存放往届记录的容器
	map<int, vector<string>>m_Record;

	//显示往届记录
	void showRecord();

	//清空文件
	void clearRecord();

	//初始化容器和属性
	void initSpeech();
	//成员属性
	//保存第一轮比赛选手编号容器
	vector<int>v1;

	//第一轮晋级选手编号容器
	vector<int>v2;

	//胜出前三名选手编号容器
	vector<int>vVictory;

	//存放编号以及对应具体选手容器
	map<int, Speaker>m_Speaker;

	//存放比赛轮数
	int m_Index;

};