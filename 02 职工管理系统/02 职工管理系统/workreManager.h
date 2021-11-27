#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "empFile.txt"


class WorkerManager {
public:
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出系统的成员函数
	void exitSystem();

	//添加职工
	//属性
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker** m_EmpArray;
	void Add_Emp();

	//保存文件内容
	void save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中的人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//展示职工列表
	void show_Emp();

	//判断职工是否存在列表中
	int IsExit(int id);

	//删除职工
	void del_Emp();

	//修改职工
	void mod_Emp();

	//查找职工
	void find_Emp();

	//排序职工
	void sort_Emp();

	//清空文件信息
	void clean_File();

	

	~WorkerManager();
};