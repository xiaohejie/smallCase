#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "empFile.txt"


class WorkerManager {
public:
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ�ĳ�Ա����
	void exitSystem();

	//���ְ��
	//����
	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker** m_EmpArray;
	void Add_Emp();

	//�����ļ�����
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ��е�����
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//չʾְ���б�
	void show_Emp();

	//�ж�ְ���Ƿ�����б���
	int IsExit(int id);

	//ɾ��ְ��
	void del_Emp();

	//�޸�ְ��
	void mod_Emp();

	//����ְ��
	void find_Emp();

	//����ְ��
	void sort_Emp();

	//����ļ���Ϣ
	void clean_File();

	

	~WorkerManager();
};