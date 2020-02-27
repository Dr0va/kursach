#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
struct Admin
{
	string login;
	string pass;
	int group;
	Admin(string _login, string _pass, int _group) : login(_login), pass(_pass), group(_group) {
	}
	Admin();
};