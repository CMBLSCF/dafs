//������
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
//������
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
//��������
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
			cout << "�˳��ɹ�" << endl;
			system("pause");
			return 0;
			break;
		default:
				break;
		}

	}
	
	return 0;
}
//��װ����
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
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
	cout << "*******************�ٳɳ�Ʒ" << endl;
}
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		string Name;
		cout << "����������:" << endl;
		cin >> Name;
		abs->personArray[abs->m_Size].name = Name;
		cout << "�������Ա�(1������  2����Ů)�� " << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].sex = sex;
				break;
			}
			cout << "���Ĳ�����������������" << endl;
		}
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].age = age;
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].phone = phone;
		cout << "�������ͥסַ��" << endl;
		string adderss;
		cin >> adderss;
		abs->personArray[abs->m_Size].addr = adderss;
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].name << "\t\t";
			if (abs->personArray[i].sex == 1)cout << "�Ա���" << "\t\t";
			else if (abs->personArray[i].sex == 2) cout << "�Ա�Ů" << "\t\t";
			cout << "���䣺" << abs->personArray[i].age << "\t\t";
			cout << "�绰��" << abs->personArray[i].phone << "\t\t";
			cout << "סַ��" << abs->personArray[i].addr << endl;
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
			cout << "������" << abs->personArray[i].name << "\t\t";
			if (abs->personArray[i].sex == 1)cout << "�Ա���" << "\t\t";
			else if (abs->personArray[i].sex == 2) cout << "�Ա�Ů" << "\t\t";
			cout << "���䣺" << abs->personArray[i].age << "\t\t";
			cout << "�绰��" << abs->personArray[i].phone << "\t\t";
			cout << "סַ��" << abs->personArray[i].addr << endl;
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
			cout << "�޸������밴1���޸��Ա��밴2���޸������밴3���޸ĵ绰�밴4���޸�סַ�밴5:" << endl;
			cin >> j;
			if (j == 1)
			{
				cout << "������"; cin >> abs->personArray[i].name;
		    }
			else if (j == 2)
			{
				cout << "sex:"; cin >> abs->personArray[i].sex;
			}
			else if (j == 3)
			{
				cout << "���䣺"; cin >> abs->personArray[i].age;
			}
			else if (j==4)
			{
				cout << "�绰��"; cin >> abs->personArray[i].phone;
			}
			else if (j==5)
			{
				cout << "סַ��"; cin >> abs->personArray[i].addr;
			}
			cout << "�޸ĳɹ�" << endl;
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
	cout << "��ϵ�������" << endl;
	system("pause");
	system("cls");
}