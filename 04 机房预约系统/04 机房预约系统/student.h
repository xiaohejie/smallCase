#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "Identity.h"
#include "computerRoom.h"
#include"globalFile.h"
#include "orderFile.h"

class Student :public Identity{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void openMenu();

	//��ȡ������Ϣ
	void getComputerRoom();
	//����ԤԼ
	void applayOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	int m_Id;		//ѧ��ѧ��
	//��������
	vector<ComputerRoom> vCom;
};
