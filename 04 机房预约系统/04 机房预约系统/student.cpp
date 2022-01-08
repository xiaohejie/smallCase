#include "student.h"
#include<fstream>

//Ĭ�Ϲ���
Student::Student() {

}

//�вι���
Student::Student(int id, string name, string pwd) {
	//��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Student::openMenu(){
	cout << "��ӭѧ����" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//��ȡ������Ϣ
void Student::getComputerRoom() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��ԤԼ������";
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it!=vCom.end(); it++)
	{
		cout << "����" << it->m_ComId << "�ɹ�λ�ã�" << it->m_MaxNum << endl;
	}
	ifs.close();
}
//����ԤԼ
void Student::applayOrder()
{
	this->getComputerRoom();
	cout << "����ԤԼʱ��Ϊ��һ�����塣" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl; 
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int select = 0;
	int room = 0;		//���뷿��
	int interval = 0;	//����ʱ���

	while (true)
	{
		cin >> select;
		if (select >= 1 && select <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "����ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << vCom[0].m_MaxNum << endl;
	cout << "2�Ż���������" << vCom[1].m_MaxNum << endl;
	cout << "3�Ż���������" << vCom[2].m_MaxNum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������..." << endl;

	//�򿪶����ļ���¼����Ϣ��������Ա�������
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "����:" << select << " ";
	ofs << "ʱ���:" << interval << " ";
	ofs << "ѧ��:" << this->m_Id << " ";
	ofs << "����:" << this->m_Name << " ";
	ofs << "����:" << room << " ";
	ofs << "״̬:" << 1 << endl;
	ofs.close();
	
	system("pause");
	system("cls");
}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder(){
	OrderFile of;
	//cout << "����1" << endl;
	//cout << of.m_Size << endl;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	//cout << "����2" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		/*cout << of.m_orderData[i]["ѧ��"] << "--------------";
		cout << atoi( of.m_orderData[i]["ѧ��"].c_str()) << endl;*/
		//string ת int
		//string����.c_str()תconst char*
		//����atoi(const char*)ת��int
		if (this->m_Id == atoi( of.m_orderData[i]["ѧ��"].c_str()))
		{//atoi( of.m_orderData[i]["stuId"].c_str())�����ַ������͵�����ת��int����
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["����"] << "  ";
			cout << "ʱ��Σ�" << (of.m_orderData[i]["ʱ���"] == "1" ? "����" : "����") << "  ";
			cout << "ԤԼ����������" << of.m_orderData[i]["����"] << "  ";
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
			if (of.m_orderData[i]["״̬"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["״̬"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["״̬"] == "-1")
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");

}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	OrderFile of; 
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	//��ӡ������Ϣ
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["����"] << "  ";
		cout << "ʱ��Σ�" << (of.m_orderData[i]["ʱ���"] == "1" ? "����" : "����") << "  ";
		cout << "ԤԼ����������" << of.m_orderData[i]["����"] << "  ";
		cout << "ѧ��ѧ�ţ�" << of.m_orderData[i]["ѧ��"] << " ";
		cout << "ѧ��������" << of.m_orderData[i]["����"] << " ";
		string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
		if (of.m_orderData[i]["״̬"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["״̬"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["״̬"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int>v;		//�������������е��±���
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//���ж�����ѧ��
		if (this->m_Id == atoi(of.m_orderData[i]["ѧ��"].c_str()))
		{
			//����ɸѡ������л�ԤԼ�ɹ���״̬�ſ��Խ���ȡ��
			if (of.m_orderData[i]["״̬"] == "1" | of.m_orderData[i]["״̬"] == "2") {
				v.push_back(i);			//��ű�� 
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["����"];
				cout << " ʱ�Σ�" << (of.m_orderData[i]["ʱ���"] == "1" ? "����" : "����");
				cout << " ������" << of.m_orderData[i]["����"];
				string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
				if (of.m_orderData[i]["״̬"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["״̬"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;		//����
			}
			else
			{
				of.m_orderData[v[select - 1]]["״̬"] = "0";

				of.updateOrder();
				cout << "��ȡ��ԤԼ��" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}
