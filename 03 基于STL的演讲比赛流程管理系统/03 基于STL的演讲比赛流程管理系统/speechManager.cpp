#include "speechManager.h"

SpeechManager::SpeechManager() {
	//初始化属性和容器
	this->initSpeech();
	this->createSpeaker();
	//加载往届记录
	this->loadRecord();
}

void SpeechManager:: showMenu() {
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出系统
void SpeechManager::exitSyetem() {
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

//创建12名选手
void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "姓名";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//创建选手编号，并且放入到v1容器中
		this->v1.push_back(i + 10001);

		//选手编号以及对应选手放入到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//开始比赛，比赛整个流程控制函数
void SpeechManager::startSpeech() {
//第一轮开始比赛
	//1、抽签
	this->speechDraw();
	//2、比赛
	this->speechContest();
	//3、显示晋级结果
	this->showScore();

//第二轮开始比赛
	this->m_Index++;
	//1、抽签
	this->speechDraw();
	//2、比赛
	this->speechContest();
	//3、显示最终结果
	this->showScore(); 
	//4、保存分数到文件中
	this->saveRecord();

	//重置比赛，获取记录
	//初始化属性和容器
	this->initSpeech();
	this->createSpeaker();
	//加载往届记录
	this->loadRecord();

	cout << "比赛结束！" << endl;
	system("pause");
	system("cls");
}
//抽签
void SpeechManager::speechDraw() {
	cout << "第" << this->m_Index << "轮比赛选手正在抽签" << endl;
	cout << "----------------------" << endl;
	cout << "抽签顺序如下：" << endl;

	if (this->m_Index == 1)
	{
		//第一轮
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "----------------------" << endl;
	system("pause");
	cout << endl;
}
//开始比赛
void SpeechManager::speechContest() {
	//准备临时容器存放小组的成绩
	multimap<double, int, greater<double>>groupScore;
	int num = 0;		//记录人员的个数：6人一组

	cout << "第" << this->m_Index << "轮比赛正式开始！" << endl;
	vector<int>v_Src;		//比赛选手容器
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			//十个评委进行打分
			float score = (rand() % 401 + 600) / 10.f; 
			//cout << score << "\t";
			d.push_back(score);
		}
		//cout << endl;

		//从大到小进行排序
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();		//去除最高分
		d.pop_back();		//去除最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f);		//总分
		double avg = sum / (double)d.size();
		//打印平均分
		//cout << "编号：" << *it << "  姓名：" << this->m_Speaker[*it].m_Name << "选手的平均分为：" << avg << endl;

		//将平均分放到map容器中
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
		//将打分数据放入到临时小组容器中：key是得分，value是具体选手编号
		groupScore.insert(make_pair(avg, *it));		
		//每6人去除前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "组选手得分排名" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << " " << this->m_Speaker[it->second].m_Name << "得分：" <<
					it->first << endl;
			}
			//取走前三名
			int count = 0;
			for(multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count < 3; it++ ,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupScore.clear();//小组容器清空
		}
	}
	cout << "第" << this->m_Index << "轮比赛结束！" << endl;
	system("pause");
}

//显示比赛结果
void SpeechManager::showScore() {
	cout << "第" << this->m_Index << "轮晋级选手如下所示：" << endl;

	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号：" << *it << " " << this->m_Speaker[*it].m_Name 
			<< " 分数：" << this->m_Speaker[*it].m_Score[this->m_Index - 1]<< endl;
	}
	cout << endl;
	system("pause");
	system("cls");

	this->showMenu();
}
//保存记录
void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//用追加的方式写文件

	//将每个选手的数据写入到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	this->fileIsEmpty = false; 
	//关闭文件
	ofs.close();
	cout << "记录已经保存！" << endl;
}

//读取记录
void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);	//读文件
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空！" << endl;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch);		//将刚刚读走的字符读回来

	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string>v;		//存放6个string字符串
		//cout << data << endl;
		int pos = -1; //记录，的位置
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
				//没有找到
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

	/*for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		cout << "第" << it->first << "届比赛冠军：" << it->second[0] << " 分数：" << it->second[1] << endl;
	}*/
}

//显示往届记录
void SpeechManager::showRecord() {
	if (this->fileIsEmpty == true)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{

		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届 " <<
				"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
				"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
				"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

//清空文件
void SpeechManager::clearRecord() {
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化属性
		this->initSpeech();

		//创建选手
		this->createSpeaker();

		//获取往届记录
		this->loadRecord();
		//初始化记录容器
		this->m_Record.clear();

		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}


//初始化容器和属性
void SpeechManager::initSpeech() {
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//初始化比赛轮数
	this->m_Index = 1;
	//初始化记录容器
	this->m_Record.clear();
}

SpeechManager::~SpeechManager() {

}