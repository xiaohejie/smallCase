#pragma once
#include "Identity.h"
#include "orderFile.h"
#include "globalFile.h"
#include <iostream>
using namespace std;

class Teacher :public Identity {
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι��� (ְ����ţ�����������)
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void openMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int m_EmpId; //��ʦ���
};