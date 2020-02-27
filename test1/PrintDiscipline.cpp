#include "PrintDiscipline.h"
#include "func_menu.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include "choose_menu.h"
#include "choose_login.h"
#include <algorithm>
PrintDiscipline::PrintDiscipline()
{
}
PrintDiscipline::~PrintDiscipline()
{
}
ostream& operator<<(ostream& out, const Disciplline& discpl) {
	out << discpl.No << "\t|" << setw(25) << left << discpl.name << left << "|" << discpl.kurs << " ����" << "\t|";
	if (discpl.priznak == 0)
		out << setw(25) << "�����" << "|";
	else out << setw(25) << "�������" << "|";
	out << "\n";
	return out;
}
void PrintDiscipline::PrintDiscipl()
{
	vector<Disciplline> disciplini;
	ifstream tmp;
	int i = 0;
	addVector(disciplini);
	PrintListDiscipline(disciplini);
}
void PrintDiscipline::PrintListDiscipline(vector<Disciplline>& disciplini)
{
	int i, j;
	for (i = 0, j = 1; i < disciplini.size(); i++, j++)
		disciplini[i].No = j;
	cout << "�" << "\t|" << left << setw(25) << "�������� ����������" << "|" << setw(13) << "����" << "|" << setw(25) << "������� ������/��������" << "|" << endl;
	cout << "===========================================================================" << endl;
	for (auto disc : disciplini)
		cout << disc;
	system("pause");
	PrintListMenu(disciplini);
}

void PrintDiscipline::PrintListMenu(vector<Disciplline>& disciplini)
{
	int choose;
	cout << "\n\n1) ����� ��������� �� ���������� �����;\n2) ����� � ���� �������;\n3) ����� � ���� ������ ������������;\n4) ����� �� ���������;\n\n";
	cin >> choose;
	choose--;
	switch (choose)
	{
	case 0:
	{
		cout << "������� ����� �����:\n";
		int _choose, count = 0;
		cin >> _choose;
		system("cls");
		vector<Disciplline> tempV;
		for (int i = 0; i < disciplini.size(); i++)
		{
			if (disciplini[i].kurs == _choose)
				tempV.push_back(disciplini[i]);
			count++;
		}
		if (count == 0)
		{
		cout << "��������� ���������� ����� ���!\n";
		system("pause");
		system("cls");
		PrintDiscipl();
		}
		system("cls");
		PrintListDiscipline(tempV);
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
		PrintDiscipl();
	}
}

void PrintDiscipline::addVector(vector<Disciplline>& disciplini)
{
	ifstream FileDiscipline;
	Disciplline Temp;
	FileDiscipline.open("Discipline.dll", ios::in || ios::app);
	if (!FileDiscipline.is_open())
	{
		cout << "������ ������! ���������� � ��������������!\n";
		func_menu* Menu = new func_menu();
		Menu->FuncMenu();
	}
	while (!FileDiscipline.eof())
	{
		FileDiscipline >> Temp.name >> Temp.kurs >> Temp.priznak;
		disciplini.push_back(Temp);
	}
	FileDiscipline.close();
}
