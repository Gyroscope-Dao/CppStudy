#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//登录
void Login(string fileName, int type) {
	Identity* person = NULL;//父类对象， 用于指向子类对象

	ifstream ifs(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;

	if (type == 1) {//学生
		cout << "请输入学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {//教师
		cout << "请输入教师编号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1) {
		//学生身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {//按行读  遇到空格会停
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份菜单

				return;
			}

		}
	}
	else if (type == 2) {
		//教师身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {//按行读  遇到空格会停
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份菜单

				return;
			}

		}
	}
	else if (type == 3) {
		//管理员身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {//按行读  遇到空格会停
			if (fName == name && fPwd == pwd) {
				cout << "验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份菜单

				return;
			}

		}
	}
	
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
}

int main() {
	int select = 0;
	while (true)
	{
		cout << "===========================Welcome To The System===========================" << endl;
		cout << endl << "请选择身份" << endl;
		cout << "\t------------------------------------------------------------\n";
		cout << "\t------------------------------------------------------------\n";
		cout << "\t------------------------|1.学生代表|------------------------\n";
		cout << "\t------------------------------------------------------------\n";
		cout << "\t------------------------|2.老    师|------------------------\n";
		cout << "\t------------------------------------------------------------\n";
		cout << "\t------------------------|3.管 理 员|------------------------\n";
		cout << "\t------------------------------------------------------------\n";
		cout << "\t------------------------|0.退    出|------------------------\n";
		cout << "\t------------------------------------------------------------\n";
		cout << "\t------------------------------------------------------------\n";
		cout << "请输入您的选择：";
		cin >> select;

		switch (select)
		{
		case 1://学生身份
			Login(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			Login(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			Login(ADMIN_FILE, 3);
			break;
		case 0://退出
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}