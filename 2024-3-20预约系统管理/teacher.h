#pragma once
#include"Identity.h"
#include<fstream>
#include"globalFile.h"


//教师类
class Teacher :public Identity {
public:
	Teacher();

	Teacher(int empId, string name, string pwd);

	virtual void openMenu();//菜单

	void showAllOrder();//查看所有预约

	void validOrder();//审核预约

	int m_EmpId;//教师编号
};