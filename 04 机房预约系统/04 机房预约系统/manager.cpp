#include "manager.h"
#include "globalFile.h"
#include<fstream>

//Ĭ�Ϲ���
Manager::Manager()
{
}

//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������
	this->initVetor();
}

//ѡ��˵�
void Manager::openMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� ";
}

//��ʼ������
void Manager::initVetor() {
	vTea.clear();
	vStu.clear();

	//��ȡѧ������Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//cout << "ѧ����ǰ������" << vStu.size() << endl;
	ifs.close();		//ѧ����ʼ��

	//��ȡ��ʦ����Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << "��ְ����ǰ������" << vTea.size() << endl;
	ifs.close();		//��ְ����ʼ��

}


//����ظ�
bool Manager::checkRepeat(int id, int type) {
	if (type == 2)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
//����˺�  
void Manager::addPerson()
{
	cout << "����������˺ŵ����ͣ�1����ְ��	2��ѧ������";
	int select = 0;
	cin >> select;
	string fileName;
	string tip;
	string errorTip;
	bool isId;

	ofstream ofs;		//�ļ����������
	if (select == 1){
		//��ӽ�ְ���˺�
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ������������룡";
	}
	else if (select == 2) {
		//���ѧ���˺�
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룡";
	}
	else
	{
		cout << "��������" << endl;
		system("pause");
		system("cls");
		return;
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip;

	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);

		if (ret) //���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "������������";
	cin >> name;
	cout << "���������룺";
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;

	//���������г�ʼ��
	this->initVetor();

	system("pause");
	system("cls");
	return;
}

//������Ҫ��ӡ���˺�
void Manager::searchID(int id, int type) {
	if (type == 2)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				cout << "ѧ�ţ�" << it->m_Id << " ������" << it->m_Name << " ���룺" << it->m_Pwd << endl;
				return ;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				cout << "ѧ�ţ�" << it->m_EmpId << " ������" << it->m_Name << " ���룺" << it->m_Pwd << endl;
				return ;
			}
		}
	}
	cout << "�����˺Ų����ڣ�" << endl;
	return;
}
//�鿴�˺�
void Manager::showPerson()
{
	cout << "������鿴�˺ŵ����ͣ�1����ְ��	2��ѧ������";
	int select = 0;
	cin >> select;
	string fileName;
	string tip;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ְ���ţ�";

	}
	else if (select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "�������ѧ��ѧ�ţ�";
	}
	else
	{
		cout << "��������" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << tip;
	int id;
	cin >> id;
	this->searchID(id, select);

	system("pause");
	system("cls");
	return;
}

//�鿴������Ϣ
void Manager::showComputer(){

}

//���ԤԼ��¼
void Manager::cleanFile()
{
}