#include <iostream>
#include <stdio.h>
#include <fstream>
#include "choose_menu.h"
#include "Registration.h"
#include "choose_login.h"
#include <list>
#include <iterator>
using namespace std;
Registration::Registration()
{
}

Registration::~Registration()
{
}

void Registration::WindowRegistration()
{
	string _login, _pass, tmpL, tmpP;
	int _group;
	ifstream temp_;
	temp_.open("temp.bin");
	temp_ >> _group;
	temp_.close();
	cout << "�����������:\n������� �����: ";
	cin >> _login;
	cout << "������� ������: ";
	cin >> _pass;
	User usr(_login, _pass, _group), Temp;
	ofstream FileRegistration;
	ifstream FileAuthorization;
	FileAuthorization.open("Authorization.bin", ios::binary | ios::in);
	FileRegistration.open("Authorization.bin", ios::app | ios::binary | ios::out);
	if (!FileAuthorization.is_open())
	{
		cout << "������ �����������! ���������� � ��������������!\n";
		choose_login();
	}
	while (!FileAuthorization.eof())
	{
		FileAuthorization.read((char*)&Temp, sizeof(User));
		if (Temp.login == usr.login)
		{
			cout << "����� ������������ ��� ����������!\n";
			FileAuthorization.close();
			FileRegistration.close();
			system("pause");
			system("cls");
			choose_login();
		}
	}
	FileRegistration.write((char*)&usr, sizeof(User));
	FileRegistration.close();
	FileAuthorization.close();
	cout << "����������� ������ �������!\n";
	system("pause");
	system("cls");
	choose_login();
}