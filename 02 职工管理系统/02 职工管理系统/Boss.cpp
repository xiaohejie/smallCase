#include "boss.h"

Boss::Boss(int id , string name, int dId) {
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：把任务交给经理完成！" << endl;
}

string Boss::getDeptName() {
	return string("老板");
}