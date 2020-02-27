#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include "func_menu.h"
#include "choose_menu.h"
#include <vector>
#include "Admin.h"
using namespace std;
class Administration
{
public:
	Administration();
	~Administration();
	void DeleteUser(vector<Admin>& useri);
	void AddVector(vector<Admin>& useri);
	void PrintUser();
	void PrintListUser(vector<Admin>& useri);
	void PrintMenuUser(vector<Admin>& useri);
	void SaveFile(vector<Admin>& useri);
	void CreateUser(vector<Admin>& useri);
};

