#include <iostream>
using namespace std;
#include "workreManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {
	////���Դ���
	//Worker* worker = NULL;
	//worker = new Employee(1 , "����" , 1);
	//worker->showInfo();

	//worker = new Manager(2 , "����" , 2);
	//worker->showInfo();

	//worker = new Boss(3, "����", 3);
	//worker->showInfo();

	//ʵ���������߶���
	WorkerManager wm;
	
	while (true)
	{
		//����չʾ�˵��ĳ�Ա����
		wm.Show_Menu();
		char choice = '0';
		cout << "���������ѡ��";
		cin >> choice;

		switch (choice)
		{
		case '0': //�˳�ϵͳ
			wm.exitSystem();
			break;
		case '1': //���ְ��
			wm.Add_Emp();
			break;
		case '2': //��ʾְ��
			wm.show_Emp();
			break;
		case '3': //ɾ��ְ��
			break;
		case '4': //�޸�ְ��
			break;
		case '5': //����ְ��
			break;
		case '6': //����ְ��
			break;
		case '7': //����ļ�
			break;
		default:
			system("cls");
			break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}