#pragma once
#include <iostream>
using namespace std;
/*
	������ݵĻ���
*/
class Identity {
public:
	//���麯���������˵�
	virtual void openMenu() = 0;

	string m_Name;		//�û���
	string m_Pwd;		//�û�����
};
