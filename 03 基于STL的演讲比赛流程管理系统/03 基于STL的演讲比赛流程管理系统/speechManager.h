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

//�ݽ�����������
class SpeechManager {
public:
	SpeechManager();

	//չʾ�˵�
	void showMenu();

	//�˳�ϵͳ
	void exitSyetem();

	//����12��ѡ��
	void createSpeaker();

	//��ʼ�����������������̿��ƺ���
	void startSpeech();
	//��ǩ
	void speechDraw();
	//��ʼ����
	void speechContest();
	//��ʾ�������
	void showScore();
	//�����¼
	void saveRecord();
	~SpeechManager();

	//��ȡ��¼
	void loadRecord();
	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	//��������¼������
	map<int, vector<string>>m_Record;

	//��ʾ�����¼
	void showRecord();

	//����ļ�
	void clearRecord();

	//��ʼ������������
	void initSpeech();
	//��Ա����
	//�����һ�ֱ���ѡ�ֱ������
	vector<int>v1;

	//��һ�ֽ���ѡ�ֱ������
	vector<int>v2;

	//ʤ��ǰ����ѡ�ֱ������
	vector<int>vVictory;

	//��ű���Լ���Ӧ����ѡ������
	map<int, Speaker>m_Speaker;

	//��ű�������
	int m_Index;

};