#include "speechManager.h"
int main() {
	//����������Ķ���
	SpeechManager sm;

	////����12��ѡ�ֵĴ���
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "ѡ�ֱ�ţ�" << it->first << "  ѡ��������" << it->second.m_Name << endl;
	//}
	srand((unsigned)time(NULL));
	int choice = 0;
	while (true)
	{
		sm.showMenu();
		cout << "����������ѡ�";
		cin >> choice;
		
		switch (choice)
		{
		case 1://��ʼ����
			//cout << "��ʼ����" << endl;
			sm.startSpeech();
			break;
		case 2://�鿴��¼
			//cout << "�鿴��¼" << endl;
			sm.showRecord();
			break;
		case 3://��ռ�¼
			//cout << "��ռ�¼" << endl;
			sm.clearRecord(); 
			break;
		case 0://�˳�ϵͳ
			//cout << "�˳�ϵͳ" << endl;
			sm.exitSyetem();
			break;
		default:
			cout << "����������������룡" << endl;
			//system("cls");
			//break;
		}
	}

	system("pause");
	return 0;
}