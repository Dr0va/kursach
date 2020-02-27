#pragma once
#include <iostream>
#include <string>
#include "func_menu.h"
#include <vector>
#include "Students.h"
using namespace std;
class PrintStudent
{
public:
	int group_ = 0;
	PrintStudent();
	~PrintStudent();
	void PrintStud();
	void CreateVec(vector<Students>& studenti);
	void Serch(vector<Students>& studenti, int GoTo);
	void ListMenu(vector<Students>& studenti, int GoTo);
	void PrintList(vector<Students>& studenti, int GoTo);
	void PrintMenu(vector<Students>& studenti, int GoTo);
	void Otchisl(vector<Students>& studenti);
};

