#pragma once
#include <iostream>
using namespace std;
/*
	创建身份的基类
*/
class Identity {
public:
	//纯虚函数：操作菜单
	virtual void openMenu() = 0;

	string m_Name;		//用户名
	string m_Pwd;		//用户密码
};
