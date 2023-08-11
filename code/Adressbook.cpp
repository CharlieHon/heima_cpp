#include <iostream>
#include <string>
#define MAX_SIZE 1000

using namespace std;

// 设计联系人结构体
struct Person {
	string Name;
	int Gender;
	int Age;
	string Phone;
	string Address;
};

// 通讯员结构体
struct Addressbook {
	// 通讯录中保存的联系人数组
	struct Person people[MAX_SIZE];
	// 当前记录的认数
	int curr_Size;
};

// 1.添加联系人
void addPerson(Addressbook *abs) {
	if (abs->curr_Size == MAX_SIZE) {
		cout << "通讯录已满，无法添加(上限1000人)" << endl;
		return;
	}
	string name, phone, address;	// 联系人信息
	int age, gender;
	
	cout << "请输入姓名：" << endl;
	cin >> name;
	abs->people[abs->curr_Size].Name = name;
	
	cout << "请输入性别(0：女，1：男)：" << endl;
	while (true) {
		cin >> gender;
		if (gender == 0 || gender == 1) {
			abs->people[abs->curr_Size].Gender = gender;
			break;
		}
		cout << "请根据提示输入联系人性别！" << endl;
	}
	
	cout << "请输入年龄：" << endl;
	cin >> age;
	abs->people[abs->curr_Size].Age = age;

	cout << "请输入电话：" << endl;
	cin >> phone;
	abs->people[abs->curr_Size].Phone = phone;
	
	cout << "请输入地址：" << endl;
	cin >> address;
	abs->people[abs->curr_Size].Address = address;

	// 更新通讯录中人数
	++abs->curr_Size;

	cout << "添加成功！" << endl;
	// system("pause");	// 请按任意键继续
	// system("cls");	// 清屏操作
}

void printPerson(Person *p) {
	cout << "姓名：" << p->Name << "\t";
	cout << "性别：" << (p->Gender == 0 ? "女" : "男") << "\t";
	cout << "年龄：" << p->Age << "\t";
	cout << "电话：" << p->Phone << "\t";
	cout << "地址：" << p->Address << endl;
}

// 2.显示所有联系人
void showPeople(Addressbook* abs) {
	if (abs->curr_Size == 0)
		cout << "当前记录为空！" << endl;
	else {
		for (int i = 0; i < abs->curr_Size; ++i) {
			/*
			cout << "姓名：" << abs->people[i].Name << "\t";
			cout << "性别：" << (abs->people[i].Gender == 0 ? "女" : "男") << "\t";
			cout << "年龄：" << abs->people[i].Age << "\t";
			cout << "电话：" << abs->people[i].Phone << "\t";
			cout << "地址：" << abs->people[i].Address << endl;
			*/
			printPerson(&abs->people[i]);
		}
	}
	// system("pause");
	// system("cls");
}

// 检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
int isExit(Addressbook *abs, const string &s) {
	for (int i = 0; i < abs->curr_Size; ++i) {
		if (abs->people[i].Name == s)
			return i;
	}
	return -1;
}


// 3.删除联系人
void deletePerson(Addressbook* abs) {
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1)
		cout << "查无此人！" << endl;
	else {
		for (int i = ret; i < abs->curr_Size-1; ++i) {
			abs->people[i] = abs->people[i + 1];	// 数据前移
		}
		abs->curr_Size--;	// 更新通讯录中的人员数
		cout << "删除成功！" << endl;
	}
	// system("pause");
	// system("cls");
}

// 4.查找联系人
void findPerson(Addressbook* abs) {
	cout << "请输入要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1)
		cout << "查无此人！" << endl;
	else {
		printPerson(&abs->people[ret]);
	}
	// system("pause");
	// system("cls");
}

// 5.修改联系人
void chagePerson(Addressbook* abs) {
	cout << "请输入要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1)
		cout << "查无此人！" << endl;
	else {
		string phone, address, gender;	// 联系人信息
		int age;
		cout << "请输入姓名：";
		cin >> name;
		cout << "请输入性别：";
		while(true){
			cin >> gender;
			if(gender == "男" || gender == "女"){
				break;
			}else{
				cout << "输入有误，请重新输入！" << endl;
			}
		}
		cout << "请输入年龄：";
		cin >> age;
		cout << "请输入电话：";
		cin >> phone;
		cout << "请输入地址：";
		cin >> address;
		abs->people[ret].Name = name;
		abs->people[ret].Gender = (gender == "女" ? 0 : 1);
		abs->people[ret].Age = age;
		abs->people[ret].Phone = phone;
		abs->people[ret].Address = address;
		cout << "修改成功" << endl;
	}
	// system("pause");
	// system("cls");
}

// 6.清空通讯录
void clearPeople(Addressbook *abs){
	cout << "请确认是否清空通讯录：(0:放弃,1:清空)" << endl;
	int res;
	cin >> res;
	if(res){
		abs->curr_Size = 0;
		cout << "通讯录已清空！" << endl;
	}else{
		cout << "已放弃！" << endl;
	}
}

// 菜单界面
void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1. 添加联系人 *****" << endl;
	cout << "***** 2. 显示联系人 *****" << endl;
	cout << "***** 3. 删除联系人 *****" << endl;
	cout << "***** 4. 查找联系人 *****" << endl;
	cout << "***** 5. 修改联系人 *****" << endl;
	cout << "***** 6. 清空通讯录 *****" << endl;
	cout << "***** 0. 退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

int main()
{

	// 创建通讯录结构体变量
	Addressbook abs;
	// 初始化通讯录中当前人数个数
	abs.curr_Size = 0;

	int select = 0;	// 创建用户选择输入变量

	showMenu();	// 菜单调用
	while (true) {
		cin >> select;

		switch (select) {
		case 1:	// 添加联系人
			addPerson(&abs);	// 传地址
			break;
		case 2:	// 2. 显示联系人
			showPeople(&abs);
			break;
		case 3:	// 3. 删除联系人
			deletePerson(&abs);
			break;
		case 4:	// 4. 查找联系人
			findPerson(&abs);
			break;
		case 5:	// 5. 修改联系人
			chagePerson(&abs);
			break;
		case 6:
			clearPeople(&abs);
			break;
		case 0:	// 0. 退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}