#include "student.h"
#include<fstream>

//默认构造
Student::Student() {

}

//有参构造
Student::Student(int id, string name, string pwd) {
	//初始化属性
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Student::openMenu(){
	cout << "欢迎学生：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//获取机房信息
void Student::getComputerRoom() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前可预约机房：";
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it!=vCom.end(); it++)
	{
		cout << "机房" << it->m_ComId << "可供位置：" << it->m_MaxNum << endl;
	}
	ifs.close();
}
//申请预约
void Student::applayOrder()
{
	this->getComputerRoom();
	cout << "机房预约时间为周一至周五。" << endl;
	cout << "请输入申请预约的时间：" << endl; 
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	int select = 0;
	int room = 0;		//申请房间
	int interval = 0;	//申请时间段

	while (true)
	{
		cin >> select;
		if (select >= 1 && select <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "申请时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << vCom[0].m_MaxNum << endl;
	cout << "2号机房容量：" << vCom[1].m_MaxNum << endl;
	cout << "3号机房容量：" << vCom[2].m_MaxNum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功！审核中..." << endl;

	//打开订单文件，录入信息，给管理员进行审查
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "星期:" << select << " ";
	ofs << "时间段:" << interval << " ";
	ofs << "学号:" << this->m_Id << " ";
	ofs << "姓名:" << this->m_Name << " ";
	ofs << "机房:" << room << " ";
	ofs << "状态:" << 1 << endl;
	ofs.close();
	
	system("pause");
	system("cls");
}

//查看我的预约
void Student::showMyOrder(){
	OrderFile of;
	//cout << "调试1" << endl;
	//cout << of.m_Size << endl;
	if (of.m_Size == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//cout << "调试2" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		/*cout << of.m_orderData[i]["学号"] << "--------------";
		cout << atoi( of.m_orderData[i]["学号"].c_str()) << endl;*/
		//string 转 int
		//string利用.c_str()转const char*
		//利用atoi(const char*)转成int
		if (this->m_Id == atoi( of.m_orderData[i]["学号"].c_str()))
		{//atoi( of.m_orderData[i]["stuId"].c_str())：将字符串类型的数字转到int类型
			cout << "预约日期：周" << of.m_orderData[i]["星期"] << "  ";
			cout << "时间段：" << (of.m_orderData[i]["时间段"] == "1" ? "上午" : "下午") << "  ";
			cout << "预约机房：机房" << of.m_orderData[i]["机房"] << "  ";
			string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
			if (of.m_orderData[i]["状态"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["状态"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderData[i]["状态"] == "-1")
			{
				status += "审核未通过，预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");

}

//查看所有预约
void Student::showAllOrder()
{
	OrderFile of; 
	if (of.m_Size == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//打印所有信息
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "预约日期：周" << of.m_orderData[i]["星期"] << "  ";
		cout << "时间段：" << (of.m_orderData[i]["时间段"] == "1" ? "上午" : "下午") << "  ";
		cout << "预约机房：机房" << of.m_orderData[i]["机房"] << "  ";
		cout << "学生学号：" << of.m_orderData[i]["学号"] << " ";
		cout << "学生姓名：" << of.m_orderData[i]["姓名"] << " ";
		string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
		if (of.m_orderData[i]["状态"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["状态"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["状态"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	vector<int>v;		//存放在最大容器中的下标编号
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//先判断自身学号
		if (this->m_Id == atoi(of.m_orderData[i]["学号"].c_str()))
		{
			//进行筛选，审核中或预约成功的状态才可以进行取消
			if (of.m_orderData[i]["状态"] == "1" | of.m_orderData[i]["状态"] == "2") {
				v.push_back(i);			//存放编号 
				cout << index++ << "、 ";
				cout << "预约日期： 周" << of.m_orderData[i]["星期"];
				cout << " 时段：" << (of.m_orderData[i]["时间段"] == "1" ? "上午" : "下午");
				cout << " 机房：" << of.m_orderData[i]["机房"];
				string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约  -1 预约失败
				if (of.m_orderData[i]["状态"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["状态"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;		//返回
			}
			else
			{
				of.m_orderData[v[select - 1]]["状态"] = "0";

				of.updateOrder();
				cout << "已取消预约！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}
