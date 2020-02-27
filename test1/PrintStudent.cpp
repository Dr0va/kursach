#include "PrintStudent.h"
#include "func_menu.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "choose_menu.h"
#include "choose_login.h"
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
#include "Students.h"
PrintStudent::PrintStudent()
{
}
PrintStudent::~PrintStudent()
{
}
ostream& operator<<(ostream& out, const Students& stud) {
	out << stud.No << "\t|" << setw(17) << left << stud.F << left << "\t|" << setw(20) << stud.I << "\t|" << setw(22) << stud.O << "|" << setw(23) << stud.NoStud << "|" << setw(14) << stud.NoGroup << " |";
	if (stud.Stepend == 1)
		out << setw(12) << "�������" << "|";
	else if (stud.Stepend == 2) {
		out << setw(12) << "����������" << "|";
	}
	else out << setw(12) << "���" << "|";
	if (stud.Otchislenie == 1)
		out << setw(12) << "��������";
	out << "\n";
	return out;
}
void PrintStudent::PrintStud()
{
	vector<Students> studenti;
	int GoTo = 1;
	ifstream tmp;
	tmp.open("temp.bin");
	tmp >> group_;
	tmp.close();
	CreateVec(studenti);
	sort(studenti.begin(), studenti.end(), [](const Students& p1, const Students& p2) {
		return p1.Group < p2.Group;
		});
	PrintList(studenti, GoTo);
}
void PrintStudent::PrintList(vector<Students>& studenti, int GoTo)
{
	int j, i;
	for (i = 0, j = 1; i < studenti.size(); i++, j++)
		studenti[i].No = j;
	cout << "�" << "\t|" << setw(17) << left << "�������" << left << "\t|" << setw(20) << "���" << "\t|" << setw(22) << "��������" << "|" << setw(23) << "����� �������������" << "|" << setw(14) << "����� ������" << " |" << setw(12) << "���������" << "|" << endl;
	cout << "=============================================================================================================================================" << endl;
	for (auto stud : studenti)
		cout << stud;
	system("pause");
	if (GoTo == 1)
		PrintMenu(studenti, GoTo);
	else if (GoTo == 2)
		Serch(studenti, GoTo);
	else ListMenu(studenti, GoTo);
}
void PrintStudent::PrintMenu(vector<Students>& studenti, int GoTo)
{
	int choose;
	cout << "\n\n1) ����� �������� � ������;\n2) ����� � ���� �������;\n3) ����� � ���� ������ ������������;\n4) ����� �� ���������;\n\n";
	cin >> choose;
	choose--;
	switch (choose)
	{
	case 0:
	{
		Serch(studenti, GoTo);
	}
	case 1:
	{
		system("cls");
		func_menu* Menu = new func_menu;
		Menu->FuncMenu();
	}
	case 2:
	{
		system("cls");
		choose_menu();
	}
	case 3:
	{
		remove("temp.bin");
		exit(0);
	}
	default:
		cout << "������!\n";
		system("pause");
		system("cls");
		PrintList(studenti, GoTo);
	}
}

void PrintStudent::CreateVec(vector<Students>& studenti)
{
	ifstream FileStudents;
	Students Temp;
	FileStudents.open("Students.dll", ios::in || ios::app);
	if (!FileStudents.is_open())
	{
		cout << "������ ������! ���������� � ��������������!\n";
		func_menu* Menu = new func_menu();
		Menu->FuncMenu();
	}
	while (!FileStudents.eof())
	{
		FileStudents >> Temp.No >> Temp.F >> Temp.I >> Temp.O >> Temp.NoStud >> Temp.NoGroup >> Temp.Group >> Temp.Stepend >> Temp.Otchislenie;
		studenti.push_back(Temp);
	}
	FileStudents.close();
}

void PrintStudent::Serch(vector<Students>& studenti, int GoTo)
{
	GoTo = 2;
	string key;
	int count = 0;
	cout << "\n������� ���/�������/��������/����� ������������� ������:\n";
	cin >> key;
	cout << "\n";
	vector<Students> tempV;
	for (int i = 0; i < studenti.size(); i++)
	{
		if ((studenti[i].F == key) || (studenti[i].I == key) || (studenti[i].O == key) || (studenti[i].NoStud == key) || (studenti[i].NoGroup == key)) {
			tempV.push_back(studenti[i]);
			count++;
		}
	}
	if (count == 0)
	{
		cout << "�� ������� ��������� ��������� �� �������!\n";
		system("pause");
		system("cls");
		PrintStud();
	}
	system("cls");
	GoTo = 3;
	PrintList(tempV, GoTo);
}
void PrintStudent::ListMenu(vector<Students>& studenti, int GoTo)
{
	if (group_ != 0)
	{
		cout << "\n�������� �������:\n1) �������� ����������;\n2) ��������� ��������;\n3) ��������� ���������;\n4) �������� ������;\n\n";
		int choose, otchsl = 0;
		cin >> choose;
		choose--;
		if (choose == 1) {
			choose = 0;
			otchsl = 1;
		}
		switch (choose)
		{
		case 0:
		{
			cout << "������� ���������� ����� ��������:\n\n";
			int choose_;
			cin >> choose_;
			choose_--;
			studenti[choose_].Otchislenie = otchsl;
			studenti[0] = studenti[choose_];
			Otchisl(studenti);
			cout << "�������� ������.\n\n";
			system("pause");
			system("cls");
			PrintStud();
		}
		case 2:
		{
			cout << "������� ���������� ����� ��������:\n";
			int choose_, choose;
			cin >> choose_;
			cout << "\n�������� �������� ���������:\n1) ��� ���������;\n2) �������;\n3) ����������;\n";
			cin >> choose;
			choose--;
			choose_--;
			studenti[choose_].Stepend = choose;
			studenti[0] = studenti[choose_];
			cout << "�������� ���������� �������� ���������.\n";
			system("pause");
			system("cls");
			Otchisl(studenti);
			PrintStud();
		}
		case 3:
		{
				system("cls");
				PrintStud();
		}
		default:
		{
			cout << "������!";
			system("pause");
			system("cls");
			Serch(studenti, GoTo);
		}
		system("cls");
		PrintMenu(studenti, GoTo);
		}
	}
}
void PrintStudent::Otchisl(vector<Students>& studenti)
{
	vector<Students> full;
	CreateVec(full);
	ofstream FileStudents;
	FileStudents.open("Students.dll", ios::out);
	for (int i = 0, j = 1; i < full.size(); i++, j++)
	{
		if (full[i].NoStud == studenti[0].NoStud)
			full[i] = studenti[0];
		if (j == full.size())
		{
			FileStudents << full[i].No << " " << full[i].F << " " << full[i].I << " " << full[i].O << " " << full[i].NoStud << " " << full[i].NoGroup << " " << full[i].Group << " " << full[i].Stepend << " " << full[i].Otchislenie;
		}
		else {
			FileStudents << full[i].No << " " << full[i].F << " " << full[i].I << " " << full[i].O << " " << full[i].NoStud << " " << full[i].NoGroup << " " << full[i].Group << " " << full[i].Stepend << " " << full[i].Otchislenie << "\n";
		}
	}
	FileStudents.close();
}