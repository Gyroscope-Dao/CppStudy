#pragma once
#include"Identity.h"
#include<fstream>
#include"globalFile.h"


//学生类
class Student :public Identity {
public:
	Student();//默认构造

	Student(int id, string name, string pwd);

	virtual void openMenu();//菜单

	void applyOrder();//申请预约

	void showMyOrder();//查看我的预约

	void showAllOrder();//查看所有预约

	void cancelOrder();//取消预约

	int m_Id;//学号
};