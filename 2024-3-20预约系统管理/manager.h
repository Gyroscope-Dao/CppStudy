#pragma once
#include"Identity.h"
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
#include<algorithm>

class Manager :public Identity {
public:
	Manager();

	Manager(string name, string pwd);

	virtual void openMenu();

	void addPerson();//添加账号

	void showPerson();//查看账号

	void showComputer();//查看机房信息

	void cleanFile();//清空预约记录

	void initVector();//初始化容器

	vector<Student>vStu;//学生容器

	vector<Teacher>vTea;//教师容器

	vector<ComputerRoom>vCom;//机房容器

	bool checkRepeat(int id, int type);//检测重复


};