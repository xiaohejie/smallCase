#include "manager.h"

//构造函数
Manager::Manager(int id, string name, int dId) {
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}
//显示个人信息
void Manager::showInfo() {
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务，督促员工完成任务！" << endl;
}
//获取岗位名称
string Manager::getDeptName() {
	return string("经理");
}