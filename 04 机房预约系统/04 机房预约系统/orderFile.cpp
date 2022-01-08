#include "orderFile.h"

//���캯��
OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;      //����
	string interval;  //ʱ���
	string stuId;     //ѧ�����
	string stuName;   //ѧ������
	string roomId;    //�������
	string status;    //ԤԼ״̬

	this->m_Size = 0;	//��¼����
	while (ifs >> data && ifs >> interval && ifs >> stuId 
		&& ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		/*cout << data << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;
		cout << endl;*/

		//���ڣ�1
		string key;
		string value;
		map<string, string>m;

		int pos = data.find(":");
		if (pos != -1) {
			key = data.substr(0, pos);
			value = data.substr(pos + 1, data.size() - pos - 1);

			//cout << key << " " << value << endl;
			m.insert(make_pair(key, value));
		}
		
		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);

			m.insert(make_pair(key, value));
		}
		//��С��map�������뵽���map������(make_pair�ö������ʽ���в���)
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();
	//���Դ���
	/*for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end();it++)
	{
		cout << "key = " << it->first << " value = " << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{
			cout << "key = " << mit->first << " value = " << mit->second << " ";
		}
		cout << endl;
	}*/
}

//����ԤԼ��¼
void OrderFile::updateOrder() {
	if (this->m_Size == 0) {
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (size_t i = 0; i < this->m_Size; i++)
	{
		ofs << "����:" << this->m_orderData[i]["����"] << " ";
		ofs << "ʱ���:" << this->m_orderData[i]["ʱ���"] << " ";
		ofs << "ѧ��:" << this->m_orderData[i]["ѧ��"] << " ";
		ofs << "����:" << this->m_orderData[i]["����"] << " ";
		ofs << "����:" << this->m_orderData[i]["����"] << " ";
		ofs << "״̬:" << this->m_orderData[i]["״̬"] << endl;
	}
	ofs.close();
}