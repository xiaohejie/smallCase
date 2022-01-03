#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "Identity.h"
#include "student.h"
#include "teacher.h"

class Manager :public Identity {
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���  ����Ա����������
	Manager(string name, string pwd);

	//ѡ��˵�
	virtual void openMenu();

	//����˺�  
	void addPerson();
	//����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)
	bool checkRepeat(int id, int type);

	//������Ҫ��ӡ���˺�
	void searchID(int id, int type);
	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVetor();

	//ѧ������
	vector<Student>vStu;

	//��ʦ����
	vector<Teacher>vTea;

};