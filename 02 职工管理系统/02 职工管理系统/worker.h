#pragma once
#include <iostream>
using namespace std;

//ְ��������
class Worker {
public:
	//��Ϊ
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	//����
	int m_Id;
	string m_Name;
	int m_DeptId;

};