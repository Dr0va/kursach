#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include "func_menu.h"
using namespace std;
class PrintStudent
{
	struct Students
	{
		string No = "";
		string F;
		string I;
		string O;
		string NoStud;
		string NoGroup;
		int Group;
		int Stepend;
		int Otchislenie;
		int temp;
		struct Mark
		{
			string Philosophy;
			string Informatics;;
			string TIPERO;
			string ElTeh;
			string OS;
			string IngenerGraphics;
		};
		Students* next, * prev;
	};
public:
	int temp_ = 0;
	PrintStudent();
	~PrintStudent();
	void PrintStud();
	void add_Node(Students* head, int temp_);
	void sort(Students* head);
	void Serch(Students* head, int group_, Students* k);
	void PrintMenu(Students* head, int group_, Students* k);
};

