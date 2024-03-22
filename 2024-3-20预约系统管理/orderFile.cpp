#include"orderFile.h"

OrderFile::OrderFile() {
	ifstream ifs(ORDER_FILE, ios::in);

	string date;//周几
	string interval;//上下午
	string stuId;//学生id
	string stuName;//name
	string roomId;//机房编号
	string status;//预约状态

	this->m_Size = 0;//预约记录个数

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) { //每个数据都是 键值对的整体  key:value，以下得去拆分
		string key;
		string value;
		map<string, string>m;

		int pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);//0开始pos个
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);//0开始pos个
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != -1) {
			key = stuId.substr(0, pos);//0开始pos个
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);//0开始pos个
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1) {
			key = roomId.substr(0, pos);//0开始pos个
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);//0开始pos个
			value = status.substr(pos + 1, status.size() - pos -1);
			m.insert(make_pair(key, value));
		}

		this->m_orderData.insert(make_pair(this->m_Size, m));//将小map放入大map中
		this->m_Size++;
	}
	ifs.close();
}

void OrderFile::updateOrder() {//更新预约记录
	if (this->m_Size == 0) {
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out|ios::trunc);//都删了，重新写入
	for (int i = 0; i < this->m_Size; i++) {
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}