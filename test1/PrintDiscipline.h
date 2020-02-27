#pragma once
#include <iostream>
#include <string>
#include "func_menu.h"
#include <vector>
#include "Disciplline.h"
using namespace std;
class PrintDiscipline
{
public:
	int temp_ = 0;
	PrintDiscipline();
	~PrintDiscipline();
	void PrintDiscipl();
	void addVector(vector<Disciplline>& disciplini);
	void PrintListDiscipline(vector<Disciplline>& disciplini);
	void PrintListMenu(vector<Disciplline>& disciplini);
};

