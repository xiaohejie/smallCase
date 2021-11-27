#include "workreManager.h"

WorkerManager::WorkerManager() {
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//���ļ�
	if (!ifs.is_open())
	{
		//cout << "�ļ������ڣ�" << endl;
		//��ʼ������
		this->m_EmpNum = 0;			//��ʼ������Ϊ��
		this->m_EmpArray = NULL;	//��ʼ������ָ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2���ļ����ڣ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ�գ�" << endl;
		//��ʼ������
		this->m_EmpNum = 0;			//��ʼ������Ϊ��
		this->m_EmpArray = NULL;	//��ʼ������ָ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3���ļ����ڣ����Ҽ�¼������
	int num = this->get_EmpNum();
	//cout << "ְ��������" << num << endl;
	this->m_EmpNum = num;
	
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ浽������
	this->init_Emp();

	////���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id << "  "
	//		<< "ְ��������" << this->m_EmpArray[i]->m_Name << "  "
	//		<< "���ű�ţ�" << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

//չʾ�˵�
void WorkerManager::Show_Menu() {
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager::exitSystem() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void WorkerManager::Add_Emp() {
	cout << "���������ְ����������" << endl;
	//�����û�����������
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//�������
		//��������¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum;//�¿ռ��С = ԭ����¼���� + ��������
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];
		//��ԭ���ռ������ݿ������¿ռ�
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			newSpace[i] = this->m_EmpArray[i];
		}
		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;			//ְ�����
			string name;	//ְ������
			int dSelect;	//����ѡ��

			cout << "�������" << i + 1 << "��ְ���ı��" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id , name , 1);
				break;
			case 2:
				worker = new Manager(id , name , 2);
				break;
			case 3:
				worker = new Boss(id , name, 3);
				break;
			default:
				break;
			}
			//������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum + i] = worker;
 		}
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ��
		this->m_FileIsEmpty = false;

		//�ɹ���Ӻ󣬽���Ϣ���浽�ļ���
		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
		//���������ļ�
		this->save();
	}
	else {
		cout << "������������" << endl;
	}
	
}

//�����ļ�����
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "  "
			<< this->m_EmpArray[i]->m_Name << "  "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

//ͳ���ļ��е�����
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	int id;
	string name;
	int dId;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//ͳ����������
		num++;
	}
	return num;
}

//��ʼ��Ա��
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs>>id && ifs>>name && ifs>>dId )
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else if(dId == 3){
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	//�ر��ļ�
	ifs.close();
}

//չʾְ���б�
void WorkerManager::show_Emp() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	////�������������
	//system("pause");
	//system("cls");
}

//�ж�ְ���Ƿ�����б���
int WorkerManager::IsExit(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;

}

//ɾ��ְ��
void WorkerManager::del_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ�գ�" << endl;
	}
	else {
		//����ְ����Ž���ɾ��
		cout<< "��������Ҫɾ����ְ����ţ�" << endl;
		int id;
		cin >> id;
		int index = IsExit(id);
		if (index == -1)
		{
			cout << "��ְ����Ų����ڣ�" << endl;
		}
		else
		{
			cout << "ȷ���Ƿ�ɾ����Y / N��" << endl;
			char res;
			cin >> res;
			if (res == 'Y')
			{
				for (int i = index; i < this->m_EmpNum - 1; i++)
				{
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				this->m_EmpNum--;
				cout << "ɾ���ɹ���" << endl;
				//������ͬ�����µ��ļ���
				this->save();
			}
			else {
				return;
			}
		}
	}
}

//�޸�ְ��
void WorkerManager::mod_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ�գ�" << endl;
	}
	else {
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;
		int index = IsExit(id);
		if (index == -1)
		{
			cout << "��ְ����Ų����ڣ�" << endl;
		}
		else
		{
			//�Ƚ���Ϣ�����ͷ�
			delete this->m_EmpArray[index];
			int newId = 0;
			string newName = "";
			int newDId = 0;
			cout << "�鵽��" << id << "��ְ������������ְ����" << endl;
			cin >> newId;

			cout << "�������µ�������" << endl;
			cin >> newName;

			cout << "�������µĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> newDId;

			Worker* worker = NULL;
			switch (newDId)
			{
			case 1:
				worker = new Employee(newId, newName, newDId);
				break;
			case 2:
				worker = new Manager(newId, newName, newDId);
				break;
			case 3:
				worker = new Boss(newId, newName, newDId);
				break;
			default:
				break;
			}
			//�������ݵ�������
			this->m_EmpArray[index] = worker;
			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();

		}
	}
}

//����ְ��
void WorkerManager::find_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ(1����ţ�2������)��" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "���������ְ���ı�ţ�" << endl;
			cin >> id;
			int ret = IsExit(id);
			if (ret == -1)
			{
				cout << "��ְ����Ų�����" << endl;
			}
			else
			{
				cout << "�ҵ���ְ����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
		}
		else if (select == 2) {
			string name;
			cout << "��������Ҫ���ҵ�Ա��������" << endl;
			cin >> name;
			//�����Ƿ��ҵ���Ϣ�ı�־
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_Name) {
					cout << "�ҵ���ְ����ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "δ�ҵ���Ա���� " << endl;
			}
		}
		else
		{
			cout << "�������" << endl;
		}
	}
}

//����ְ��(�õ���ѡ������)
void WorkerManager::sort_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��ѡ������ʽ(1������2������)��" << endl;
		int select = 0;
		cin >> select;

		for (int  i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}

				}
				else
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
			}
			//�ж�һ��ʼ�϶�����Сֵ�������ֵ�ǲ��Ǽ������������С�����ǵĻ����н���
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ���" << endl;
		this->save();
	}
}

//����ļ���Ϣ
void WorkerManager::clean_File() {
	cout << "��ȷ���Ƿ�����ļ���Ϣ��Y / N����" << endl;
	char select;
	cin >> select;
	if (select == 'Y')
	{
		//ɾ���ļ��������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		//�ͷŶ����е�����
		if (this->m_EmpNum != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;

	}
	else
	{
		return;
	}
}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}