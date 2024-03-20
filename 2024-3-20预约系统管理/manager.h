#pragma once
#include"Identity.h"

class Manager :public Identity {
public:
	Manager();

	Manager(string name, string pwd);

	virtual void openMenu();

	void addPerson();//添加账号

	void showPerson();//查看账号

	void showComputer();//查看机房信息

	void cleanFile();//清空预约记录

};