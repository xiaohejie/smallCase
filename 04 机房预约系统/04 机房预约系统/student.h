#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "Identity.h"
#include "computerRoom.h"
#include"globalFile.h"
#include "orderFile.h"

class Student :public Identity{
public:
	//默认构造
	Student();
	//有参构造
	Student(int id, string name, string pwd);

	//菜单界面
	virtual void openMenu();

	//获取机房信息
	void getComputerRoom();
	//申请预约
	void applayOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	int m_Id;		//学生学号
	//机房容器
	vector<ComputerRoom> vCom;
};
