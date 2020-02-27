#include "Administration.h"
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Admin.h"

Administration::Administration()
{
}

Administration::~Administration()
{
}
void Administration::DeleteUser(vector<Admin>& useri)
{
	cout << "������� ���������� ����� ������������;\n";
	int choose_;
	cin >> choose_;
	choose_--;
	auto iterator = useri.begin() + choose_;
	useri.erase(iterator);
	system("cls");
	SaveFile(useri);
}

void Administration::CreateUser(vector<Admin>& useri)
{
	string temp_login, temp_pass;
	int temp_group;
	Admin Temp;
	//vector<Admin> Temp;
	cout << "������� �����, ������ � ������ ������ ������������, ���:\n'1' - �������;\n'2' - ���������;\n'3' - �������������;\n\n";
	cin >> temp_login >> temp_pass >> temp_group;
	temp_group--;
	Temp.login = temp_login; Temp.pass = temp_pass; Temp.group = temp_group;
	useri.push_back(Temp);
	system("cls");
	SaveFile(useri);
}

void Administration::PrintUser()
{
	vector<Admin> useri;
	AddVector(useri);
}

void Administration::PrintListUser(vector<Admin>& useri)
{
	int j, i = 1;
	cout << "�" << "\t|" << setw(20) << left << "�����" << left << "|" << setw(20) << "������" << "|" << setw(18) << "����" << "|" << endl;
	cout << "======================================================================" << endl;
	for (auto usr : useri)
	{
		cout << left << i << "\t|" << setw(20) << left << usr.login << left << "|" << setw(20) << usr.pass << "|";
		if (usr.group == 0)
			cout << setw(18) << "�������" << "|\n";
		else if (usr.group == 1)
			cout << setw(18) << "���������" << "|\n";
		else cout << setw(18) << "�������������" << "|\n";
		i++;
	}
	system("pause");
	PrintMenuUser(useri);
}

void Administration::PrintMenuUser(vector<Admin>& useri)
{
	int choose, grupa = 1;
	cout << "\n\n�������� ��������: \n1) �������� �������������;\n2) ��������� �����������;\n3) ��������� ���������������;\n4) ������� ������������;\n5) ����� � ���� ������ ������������;\n6) ����� �� ���������;\n\n";
	cin >> choose;
	choose--;
	if (choose == 2)
	{
		choose = 1;
		grupa = 2;
	}
	switch (choose)
	{
	case 0:
	{
		DeleteUser(useri);
	}
	case 1:
	{
		cout << "������� ���������� ����� ������������;\n";
		int choose_;
		cin >> choose_;
		choose_--;
		useri[choose_].group = grupa;
		system("cls");
		SaveFile(useri);
		PrintUser();
	}
	case 3:
	{
		CreateUser(useri);
	}
	case 4:
	{
		system("cls");
		choose_menu();
	}
	case 5:
	{
		remove("temp.bin");
		exit(0);
	}
	default:
		cout << "\n������ �����!\n";
		system("pause");
		system("cls");
		PrintUser();
	}
}

void Administration::SaveFile(vector<Admin>& useri)
{
	Admin Temp;
	ofstream FileStudents;
	FileStudents.open("Authorization.bin", ios::binary | ios::out);
	if (!FileStudents.is_open())
	{
		cout << "������ ������!\n";
		choose_login();
	}
	for (auto stud : useri)
	{
		Temp = stud;
		FileStudents.write(reinterpret_cast<const char*>(&Temp), sizeof(Admin));
	}
	FileStudents.close();
	PrintUser();
}

void Administration::AddVector(vector<Admin>& useri)
{
	Admin Temp;
	ifstream FileStudents;
	FileStudents.open("Authorization.bin", ios::binary | ios::in);
	if (!FileStudents.is_open())
	{
		cout << "������ ������!\n";
		choose_login();
	}
	//while (!FileStudents.eof())
	//{
	//	FileStudents.read(reinterpret_cast<char*>(&useri), sizeof(User));
	//}	
	while (FileStudents.read(reinterpret_cast<char*>(&Temp), sizeof(Admin)))
		useri.push_back(Temp);
	FileStudents.close();
	PrintListUser(useri);
}