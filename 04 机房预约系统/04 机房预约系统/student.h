#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"

class Student :public Identity{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void openMenu();

	//����ԤԼ
	void applayOrder();
	//�鿴�ҵ�ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();

	int m_Id;		//ѧ��ѧ��
};
