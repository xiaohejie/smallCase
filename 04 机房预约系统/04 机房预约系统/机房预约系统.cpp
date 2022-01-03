#include <iostream>
using namespace std;
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "manager.h"
#include "teacher.h"
#include <fstream>
//管理员菜单
void managerMenu(Identity*& manager) {
	while (true)
	{
		//请选择：
		manager->openMenu();
		//将Identity强制转化为Manager类型
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1://添加账号
			man->addPerson();
			break;
		case 2://查看账号
			man->showPerson();
			break;
		case 3://查看机房
			man->showComputer();
			break;
		case 4://清空预约
			man->cleanFile();
			break;
		case 0://注销登录
			delete manager;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误！" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}
//登录功能
void LoginIn(string fileName, int type) {
	//父类指针，用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	//准备接受用户的信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1) {
		//学生
		cout << "请输入你的学号：";
		cin >> id;
	}
	else if (type == 2) {
		//教师
		cout << "请输入你的职工号：";
		cin >> id;
	}
	else if (type == 3) {
		//管理员
		cout << "请输入管理员账号：";
		cin >> id;
	}
	cout << "请输入用户名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;


	//对输入的信息进行验证
	if (type == 1)
	{
		//学生登录验证
		int fId;		//从文件中读取的id
		string fName;	//从文件中读取的姓名
		string fPwd;	//从文件中读取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "学生验证登陆成功" << endl;
				system("pause");
				system("cls");

				person = new Student(id, name, pwd);
				//进入到学生身份的子菜单


				return;
			}
			/*cout << "学号：" << fId << "  姓名：" << fName << "   密码：" << fPwd << endl;*/
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int fId;		//从文件中读取的id
		string fName;	//从文件中读取的姓名
		string fPwd;	//从文件中读取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "教师验证登陆成功" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);  
				//进入到教师身份的子菜单

				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功!" << endl;
				//登录成功后，按任意键进入管理员界面
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	//以上信息验证均不成功，则验证失败
	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
	return;
}

int main() {
	while (true)
	{
		int select = -1;		//输入你的身份

		cout << "======================  欢迎来到小阿捷机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select;
		switch (select)
		{
		case 1:		//学生
			//学生进行登录
			LoginIn(STUDENT_FILE, 1); 
			break;
		case 2:		//老师
			//老师进行登录
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:		//管理员
			//管理员进行登录
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:		//退出系统
			cout << "欢迎下一次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:	//输入错误
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}