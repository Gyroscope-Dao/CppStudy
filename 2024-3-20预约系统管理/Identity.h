#pragma once
#include<iostream>
using namespace std;
//抽象类有 头文件就ok，不需要实现（.cpp）
class Identity {
public:
	virtual void openMenu() = 0;

	string m_Name;//用户名
	int m_Pwd;//密码
};
