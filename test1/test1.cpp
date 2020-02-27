#include <iostream>
#include "choose_menu.h"
#include <windows.h> 
#include <clocale>
#include <list>
#include <locale>
#include <fstream>
#include "User.h"
#include <fstream>
using namespace std;

int main()
{
	//ofstream Fileregistration;
	//Fileregistration.open("Authorization.bin", ios::app | ios::binary | ios::out);
	//struct usr
	//{
	//	string login = "Admin";
	//	string pass = "Admin";
	//	int group = 2;
	//};
	//usr useirl;
	//Fileregistration.write((char*)&useirl, sizeof(User));
	//Fileregistration.close();
	setlocale(LC_ALL, "Russian");
	COORD coord;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);
	choose_menu();
}
