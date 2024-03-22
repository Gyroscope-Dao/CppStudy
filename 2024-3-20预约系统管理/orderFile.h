#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<map>
#include<fstream>

class OrderFile {
public:
	OrderFile();

	void updateOrder();//更新预约记录

	map<int, map<string, string>>m_orderData;//key记录条数   value具体记录的键值对信息（order.txt的键值对信息（一行6个））

	int m_Size;//预约条数


};
