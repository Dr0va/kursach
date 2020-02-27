#include <iostream>
#include <stdio.h>
#include <fstream>
#include "choose_menu.h"
#include "Authorization.h"
#include "Registration.h"
#include "choose_login.h"
#include "User.h"
#include "func_menu.h"
#include "Administration.h"
#include <list>
using namespace std;
Authorization::Authorization()
{
}

Authorization::~Authorization()
{
}

void Authorization::WindowAuthorization()
{
	string _login, _pass, tmpL, tmpP;
	list<User> Users;
	int _group, group;
	ifstream temp_;
	temp_.open("temp.bin");
	temp_ >> _group;
	group = _group;
	temp_.close();
	cout << "АВТОРИЗАЦИЯ\nВведите логин: ";
	cin >> _login;
	cout << "Введите пароль: ";
	cin >> _pass;
	User usr(_login, _pass, _group), Temp;
	Users.push_front(usr);
	ifstream FileAuthorization;
	FileAuthorization.open("Authorization.bin", ios::binary | ios::in);
	if (!FileAuthorization.is_open())
	{
		cout << "Ошибка авторизации! Обратитесь к администратору!\n";
		choose_login();
	}
	while (FileAuthorization.read((char*)&Temp, sizeof(User)))
	{
		//FileAuthorization >> tmpL >> tmpP >> _group;
		if (Temp.login == usr.login && Temp.pass == usr.pass && Temp.group == usr.group)
		{
			cout << "\nВы успешно авторизировались!\n\n";
			func_menu* Funcmenu = new func_menu();
			FileAuthorization.close();
			system("pause");
			system("cls");
			if (group == 2)
			{
				Administration* Menu = new Administration();
				Menu->PrintUser();
			}
			Funcmenu->FuncMenu();
		}
	}
	FileAuthorization.close();
	cout << "Неверный логин или пароль!\n";
	system("pause");
	system("cls");
	choose_login();
}

