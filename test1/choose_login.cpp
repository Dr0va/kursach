#include "choose_login.h"
#include "choose_menu.h"
#include "Authorization.h"
#include "Registration.h"
#include <fstream>
#include <stdio.h>
#include <iostream>

choose_login::choose_login()
{
	WindowChoose_login();
}

choose_login::~choose_login()
{
}

void choose_login::WindowChoose_login()
{
	int choose, group_;
	ifstream temp_;
	temp_.open("temp.bin");
	temp_ >> group_;
	temp_.close();
	if (group_ == 2)
		cout << "�������� ��������: \n1) ����;\n2) ����� � ���� ������ ������������;\n3) ����� �� ���������;\n\n";
	else cout << "�������� ��������: \n1) ����;\n2) �����������;\n3) ����� � ���� ������ ������������;\n4) ����� �� ���������;\n\n";
	cin >> choose;
	choose--;
	if (choose == 1 && group_ == 2) {
		choose = 2;
	}
	else if (choose == 2 && group_ == 2) {
		choose = 3;
	}
	if (choose > 3 || choose < 0)
	{
		cout << "������!\n\n";
		system("pause");
		system("cls");
		choose_login();
	}
	system("cls");
	switch (choose)
	{
	case 0:
	{
		Authorization* AuthWindow = new Authorization();
		AuthWindow->WindowAuthorization();
	}
	case 1:
	{
		Registration* RegWindow = new Registration();
		RegWindow->WindowRegistration();
	}
	case 2:
	{
		remove("temp.bin");
		choose_menu* Choose_menu = new choose_menu();
		Choose_menu->WindowChoose_menu();
	}
	case 3:
	{
		remove("temp.bin");
		exit(0);
	}
	default:
		choose_menu* Choose_menu = new choose_menu();
		Choose_menu->WindowChoose_menu();
	}
}
