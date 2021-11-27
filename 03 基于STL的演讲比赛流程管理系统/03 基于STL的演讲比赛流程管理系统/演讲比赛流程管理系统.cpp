#include "speechManager.h"
int main() {
	//创建管理类的对象
	SpeechManager sm;

	////测试12名选手的创建
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "选手编号：" << it->first << "  选手姓名：" << it->second.m_Name << endl;
	//}
	srand((unsigned)time(NULL));
	int choice = 0;
	while (true)
	{
		sm.showMenu();
		cout << "请输入您的选项：";
		cin >> choice;
		
		switch (choice)
		{
		case 1://开始比赛
			//cout << "开始比赛" << endl;
			sm.startSpeech();
			break;
		case 2://查看记录
			//cout << "查看记录" << endl;
			sm.showRecord();
			break;
		case 3://清空记录
			//cout << "清空记录" << endl;
			sm.clearRecord(); 
			break;
		case 0://退出系统
			//cout << "退出系统" << endl;
			sm.exitSyetem();
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			//system("cls");
			//break;
		}
	}

	system("pause");
	return 0;
}