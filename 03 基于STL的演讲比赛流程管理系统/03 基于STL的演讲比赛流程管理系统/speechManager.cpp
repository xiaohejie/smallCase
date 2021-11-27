#include "speechManager.h"

SpeechManager::SpeechManager() {
	//��ʼ�����Ժ�����
	this->initSpeech();
	this->createSpeaker();
	//���������¼
	this->loadRecord();
}

void SpeechManager:: showMenu() {
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void SpeechManager::exitSyetem() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//����12��ѡ��
void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "����";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//����ѡ�ֱ�ţ����ҷ��뵽v1������
		this->v1.push_back(i + 10001);

		//ѡ�ֱ���Լ���Ӧѡ�ַ��뵽map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//��ʼ�����������������̿��ƺ���
void SpeechManager::startSpeech() {
//��һ�ֿ�ʼ����
	//1����ǩ
	this->speechDraw();
	//2������
	this->speechContest();
	//3����ʾ�������
	this->showScore();

//�ڶ��ֿ�ʼ����
	this->m_Index++;
	//1����ǩ
	this->speechDraw();
	//2������
	this->speechContest();
	//3����ʾ���ս��
	this->showScore(); 
	//4������������ļ���
	this->saveRecord();

	//���ñ�������ȡ��¼
	//��ʼ�����Ժ�����
	this->initSpeech();
	this->createSpeaker();
	//���������¼
	this->loadRecord();

	cout << "����������" << endl;
	system("pause");
	system("cls");
}
//��ǩ
void SpeechManager::speechDraw() {
	cout << "��" << this->m_Index << "�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "----------------------" << endl;
	cout << "��ǩ˳�����£�" << endl;

	if (this->m_Index == 1)
	{
		//��һ��
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
//��ʼ����
void SpeechManager::speechContest() {
	//׼����ʱ�������С��ĳɼ�
	multimap<double, int, greater<double>>groupScore;
	int num = 0;		//��¼��Ա�ĸ�����6��һ��

	cout << "��" << this->m_Index << "�ֱ�����ʽ��ʼ��" << endl;
	vector<int>v_Src;		//����ѡ������
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			//ʮ����ί���д��
			float score = (rand() % 401 + 600) / 10.f; 
			//cout << score << "\t";
			d.push_back(score);
		}
		//cout << endl;

		//�Ӵ�С��������
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();		//ȥ����߷�
		d.pop_back();		//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);		//�ܷ�
		double avg = sum / (double)d.size();
		//��ӡƽ����
		//cout << "��ţ�" << *it << "  ������" << this->m_Speaker[*it].m_Name << "ѡ�ֵ�ƽ����Ϊ��" << avg << endl;

		//��ƽ���ַŵ�map������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
		//��������ݷ��뵽��ʱС�������У�key�ǵ÷֣�value�Ǿ���ѡ�ֱ��
		groupScore.insert(make_pair(avg, *it));		
		//ÿ6��ȥ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "��ѡ�ֵ÷�����" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << " " << this->m_Speaker[it->second].m_Name << "�÷֣�" <<
					it->first << endl;
			}
			//ȡ��ǰ����
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

			groupScore.clear();//С���������
		}
	}
	cout << "��" << this->m_Index << "�ֱ���������" << endl;
	system("pause");
}

//��ʾ�������
void SpeechManager::showScore() {
	cout << "��" << this->m_Index << "�ֽ���ѡ��������ʾ��" << endl;

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
		cout << "��ţ�" << *it << " " << this->m_Speaker[*it].m_Name 
			<< " ������" << this->m_Speaker[*it].m_Score[this->m_Index - 1]<< endl;
	}
	cout << endl;
	system("pause");
	system("cls");

	this->showMenu();
}
//�����¼
void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�

	//��ÿ��ѡ�ֵ�����д�뵽�ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	this->fileIsEmpty = false; 
	//�ر��ļ�
	ofs.close();
	cout << "��¼�Ѿ����棡" << endl;
}

//��ȡ��¼
void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);	//���ļ�
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}
	//�ļ�������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch);		//���ոն��ߵ��ַ�������

	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string>v;		//���6��string�ַ���
		//cout << data << endl;
		int pos = -1; //��¼����λ��
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
				//û���ҵ�
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
		cout << "��" << it->first << "������ھ���" << it->second[0] << " ������" << it->second[1] << endl;
	}*/
}

//��ʾ�����¼
void SpeechManager::showRecord() {
	if (this->fileIsEmpty == true)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{

		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "�� " <<
				"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
				"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
				"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ļ�
void SpeechManager::clearRecord() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������
		this->initSpeech();

		//����ѡ��
		this->createSpeaker();

		//��ȡ�����¼
		this->loadRecord();
		//��ʼ����¼����
		this->m_Record.clear();

		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}


//��ʼ������������
void SpeechManager::initSpeech() {
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//��ʼ����������
	this->m_Index = 1;
	//��ʼ����¼����
	this->m_Record.clear();
}

SpeechManager::~SpeechManager() {

}