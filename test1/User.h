#pragma once
#include <string>
#include <iostream>
using namespace std;

struct User
{
	string login;
	string pass;
	int group;
	User(string _login, string _pass, int _group) : login(_login), pass(_pass), group(_group) {
	}
	User();
	~User();
};

