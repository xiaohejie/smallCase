#include <iostream>
using namespace std;
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "manager.h"
#include "teacher.h"
#include <fstream>
//����Ա�˵�
void managerMenu(Identity*& manager) {
	while (true)
	{
		//��ѡ��
		manager->openMenu();
		//��Identityǿ��ת��ΪManager����
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1://����˺�
			man->addPerson();
			break;
		case 2://�鿴�˺�
			man->showPerson();
			break;
		case 3://�鿴����
			man->showComputer();
			break;
		case 4://���ԤԼ
			man->cleanFile();
			break;
		case 0://ע����¼
			delete manager;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "�������" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}
//��¼����
void LoginIn(string fileName, int type) {
	//����ָ�룬����ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//�ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1) {
		//ѧ��
		cout << "���������ѧ�ţ�";
		cin >> id;
	}
	else if (type == 2) {
		//��ʦ
		cout << "���������ְ���ţ�";
		cin >> id;
	}
	else if (type == 3) {
		//����Ա
		cout << "���������Ա�˺ţ�";
		cin >> id;
	}
	cout << "�������û�����";
	cin >> name;
	cout << "���������룺";
	cin >> pwd;


	//���������Ϣ������֤
	if (type == 1)
	{
		//ѧ����¼��֤
		int fId;		//���ļ��ж�ȡ��id
		string fName;	//���ļ��ж�ȡ������
		string fPwd;	//���ļ��ж�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "ѧ����֤��½�ɹ�" << endl;
				system("pause");
				system("cls");

				person = new Student(id, name, pwd);
				//���뵽ѧ����ݵ��Ӳ˵�


				return;
			}
			/*cout << "ѧ�ţ�" << fId << "  ������" << fName << "   ���룺" << fPwd << endl;*/
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fId;		//���ļ��ж�ȡ��id
		string fName;	//���ļ��ж�ȡ������
		string fPwd;	//���ļ��ж�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ʦ��֤��½�ɹ�" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);  
				//���뵽��ʦ��ݵ��Ӳ˵�

				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				//��¼�ɹ��󣬰�������������Ա����
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	//������Ϣ��֤�����ɹ�������֤ʧ��
	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;
}

int main() {
	while (true)
	{
		int select = -1;		//����������

		cout << "======================  ��ӭ����С���ݻ���ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select;
		switch (select)
		{
		case 1:		//ѧ��
			//ѧ�����е�¼
			LoginIn(STUDENT_FILE, 1); 
			break;
		case 2:		//��ʦ
			//��ʦ���е�¼
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:		//����Ա
			//����Ա���е�¼
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:		//�˳�ϵͳ
			cout << "��ӭ��һ��ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:	//�������
			cout << "����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}