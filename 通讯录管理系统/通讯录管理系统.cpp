//声明区
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
//定义区
#define MAX 1000
struct Person
{
	string name;
	int sex=0;
	int age=0;
	string phone;
	string addr;
};
struct Addressbooks
{
    Person personArray[MAX];
	int m_Size=0;
};
//主函数；
int main()
{
	system("color 3D");
	int isExist(Addressbooks * abs, string name);
	void showMenu();
	void addPerson(Addressbooks * abs);
	void showPerson(Addressbooks * abs);
	void name_delete(Addressbooks * abs, int i);
	void name_search(Addressbooks * abs, string name);
	void Modify_contact(Addressbooks * abs, string name);
	void Empty_contacts(Addressbooks * abs);
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (1)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
		{
			string name;
			int i;
			cout << "please input a  name :" << endl;
			cin >> name;
			i = isExist(&abs, name);
			if (isExist(&abs, name) == -1)
				cout << "no" << endl;
			else
			{
				name_delete(&abs, i);
			}
		}
			break;
		case 4:
		{
			string name;
			cout << "please input need search name:" << endl;
			cin >> name;
			name_search(&abs, name);
		}	
			break;
		case 5:
		{
			string name;
			cout << "please input a name:" << endl;
			cin >> name;
			Modify_contact(&abs, name);
		}
			break;
		case 6:
		{
			Empty_contacts(&abs);
		}
			break;
		case 0:
			cout << "退出成功" << endl;
			system("pause");
			return 0;
			break;
		default:
				break;
		}

	}
	
	return 0;
}
//封装区；
int isExist(Addressbooks* abs, string name)
{
	int i = 0;
	for (;i<abs->m_Size; i++)
	{
		if (abs->personArray->name == name) return i;
	}
	return -1;
}
void name_delete(Addressbooks* abs, int i)
{
	for (; i < abs->m_Size; i++)
	{
		abs->personArray[i] = abs->personArray[i + 1];
	}
	abs->m_Size--;
cout << "finish task" << endl;
system("pause");
system("cls");
}
void showMenu()
{
	cout << "*****  1，添加联系人  *****" << endl;
	cout << "*****  2，显示联系人  *****" << endl;
	cout << "*****  3，删除联系人  *****" << endl;
	cout << "*****  4，查找联系人  *****" << endl;
	cout << "*****  5，修改联系人  *****" << endl;
	cout << "*****  6，清空联系人  *****" << endl;
	cout << "*****  0，退出通讯录  *****" << endl;
	cout << "**************************" << endl;
	cout << "*******************少成出品" << endl;
}
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		string Name;
		cout << "请输入姓名:" << endl;
		cin >> Name;
		abs->personArray[abs->m_Size].name = Name;
		cout << "请输入性别(1——男  2——女)： " << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].sex = sex;
				break;
			}
			cout << "您的操作有误，请重新输入" << endl;
		}
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].age = age;
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].phone = phone;
		cout << "请输入家庭住址：" << endl;
		string adderss;
		cin >> adderss;
		abs->personArray[abs->m_Size].addr = adderss;
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].name << "\t\t";
			if (abs->personArray[i].sex == 1)cout << "性别：男" << "\t\t";
			else if (abs->personArray[i].sex == 2) cout << "性别：女" << "\t\t";
			cout << "年龄：" << abs->personArray[i].age << "\t\t";
			cout << "电话：" << abs->personArray[i].phone << "\t\t";
			cout << "住址：" << abs->personArray[i].addr << endl;
		}
		system("pause");
		system("cls");
	}
}
void name_search(Addressbooks* abs, string name)
{
	int i = 0;
	for (; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].name == name)
		{
			cout << "姓名：" << abs->personArray[i].name << "\t\t";
			if (abs->personArray[i].sex == 1)cout << "性别：男" << "\t\t";
			else if (abs->personArray[i].sex == 2) cout << "性别：女" << "\t\t";
			cout << "年龄：" << abs->personArray[i].age << "\t\t";
			cout << "电话：" << abs->personArray[i].phone << "\t\t";
			cout << "住址：" << abs->personArray[i].addr << endl;
			break;
		}	 
	}
	if (i==abs->m_Size) cout << "No one was found" << endl;
	system("pause");
	system("cls");
}
void Modify_contact(Addressbooks* abs, string name)
{
	int i = 0,j;
	for (; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].name == name)
		{
			cout << "修改姓名请按1，修改性别请按2，修改年龄请按3，修改电话请按4，修改住址请按5:" << endl;
			cin >> j;
			if (j == 1)
			{
				cout << "姓名："; cin >> abs->personArray[i].name;
		    }
			else if (j == 2)
			{
				cout << "sex:"; cin >> abs->personArray[i].sex;
			}
			else if (j == 3)
			{
				cout << "年龄："; cin >> abs->personArray[i].age;
			}
			else if (j==4)
			{
				cout << "电话："; cin >> abs->personArray[i].phone;
			}
			else if (j==5)
			{
				cout << "住址："; cin >> abs->personArray[i].addr;
			}
			cout << "修改成功" << endl;
			break;
		}
	}
	if (i==abs->m_Size) cout<<"No one was found" << endl;
	system("pause");
	system("cls");
}
void Empty_contacts(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "联系人已清空" << endl;
	system("pause");
	system("cls");
}