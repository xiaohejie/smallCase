#include "manager.h"
#include "globalFile.h"
#include<fstream>

//默认构造
Manager::Manager()
{
}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器
	this->initVetor();
}

//选择菜单
void Manager::openMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： ";
}

//初始化容器
void Manager::initVetor() {
	vTea.clear();
	vStu.clear();

	//读取学生的信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败！" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//cout << "学生当前数量：" << vStu.size() << endl;
	ifs.close();		//学生初始化

	//读取老师的信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败！" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << "教职工当前数量：" << vTea.size() << endl;
	ifs.close();		//教职工初始化

}


//检测重复
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
//添加账号  
void Manager::addPerson()
{
	cout << "请输入添加账号的类型（1、教职工	2、学生）：";
	int select = 0;
	cin >> select;
	string fileName;
	string tip;
	string errorTip;
	bool isId;

	ofstream ofs;		//文件输出流对象
	if (select == 1){
		//添加教职工账号
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复，请重新输入！";
	}
	else if (select == 2) {
		//添加学生账号
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入！";
	}
	else
	{
		cout << "输入有误！" << endl;
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

		if (ret) //有重复
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;

	//对容器进行初始化
	this->initVetor();

	system("pause");
	system("cls");
	return;
}

//查找想要打印的账号
void Manager::searchID(int id, int type) {
	if (type == 2)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				cout << "学号：" << it->m_Id << " 姓名：" << it->m_Name << " 密码：" << it->m_Pwd << endl;
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
				cout << "学号：" << it->m_EmpId << " 姓名：" << it->m_Name << " 密码：" << it->m_Pwd << endl;
				return ;
			}
		}
	}
	cout << "所查账号不存在！" << endl;
	return;
}
//查看账号
void Manager::showPerson()
{
	cout << "请输入查看账号的类型（1、教职工	2、学生）：";
	int select = 0;
	cin >> select;
	string fileName;
	string tip;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入职工号：";

	}
	else if (select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "请输入该学生学号：";
	}
	else
	{
		cout << "输入有误！" << endl;
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

//查看机房信息
void Manager::showComputer(){

}

//清空预约记录
void Manager::cleanFile()
{
}