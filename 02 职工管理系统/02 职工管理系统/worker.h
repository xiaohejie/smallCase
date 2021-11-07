#pragma once
#include <iostream>
using namespace std;

//职工抽象类
class Worker {
public:
	//行为
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	//属性
	int m_Id;
	string m_Name;
	int m_DeptId;

};