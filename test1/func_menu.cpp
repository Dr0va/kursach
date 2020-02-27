#include "func_menu.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Authorization.h"
#include "choose_login.h"
#include "User.h"
#include "choose_menu.h"
#include "PrintStudent.h"
#include "Administration.h"
#include "PrintDiscipline.h"
func_menu::func_menu()
{
}

func_menu::~func_menu()
{
}

void func_menu::FuncMenu()
{
	int group_;
	ifstream temp_;
	temp_.open("temp.bin");
	temp_ >> group_;
	temp_.close();
	if (group_ == 0 || group_ == 1)
		group_ = 0;
	switch (group_)
	{
	case 0:
	{
		StandartMenu();
	}
	default:
		cout << "Ошибка!\n";
		system("pause");
		system("cls");
		choose_menu();
	}
}

void func_menu::StandartMenu()
{
	int choose;
	cout << "Выберите действие: \n1) Вывод списка студентов по группам;\n2) Вывод списка дисциплин;\n3) Выйти в меню выбора пользователя;\n4) Выйти из программы;\n\n";
	cin >> choose;
	choose--;
	switch (choose)
	{
	case 0:
	{
		system("cls");
		PrintStudent* PrintS = new PrintStudent();
		PrintS->PrintStud();
	}
	case 1:
	{
		system("cls");
		PrintDiscipline* PrintD = new PrintDiscipline();
		PrintD->PrintDiscipl();
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
		system("cls");
		cout << "Ошибка ввода!\n";
		system("pause");
		system("cls");
		StandartMenu();
	}
}
