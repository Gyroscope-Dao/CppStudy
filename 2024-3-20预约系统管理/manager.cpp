#include"manager.h"

Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Manager::openMenu() {
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t------------------------------------------------------------\n";
	cout << "\t------------------------|1.添加账号|------------------------\n";
	cout << "\t------------------------------------------------------------\n";
	cout << "\t------------------------|2.查看账号|------------------------\n";
	cout << "\t------------------------------------------------------------\n";
	cout << "\t------------------------|3.查看机房|------------------------\n";
	cout << "\t------------------------------------------------------------\n";
	cout << "\t------------------------|4.清空预约|------------------------\n";
	cout << "\t------------------------------------------------------------\n";
	cout << "\t------------------------|0.注销登录|------------------------\n";
	cout << "\t------------------------------------------------------------\n";
	cout << "请输入您的选择：";
}

//添加账号
void Manager::addPerson() {
	cout << "请输入添加账号的类型：" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加教师" << endl;
	 
	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入教师编号：";
	}
	ofs.open(fileName, ios::out | ios::app);
	
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	ofs.close();

	system("pause");
	system("cls");
}

//查看账号
void Manager::showPerson() {

}

//查看机房信息
void Manager::showComputer() {

}

//清空预约记录
void Manager::cleanFile() {

}