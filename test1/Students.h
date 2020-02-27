#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
struct Students
{
	int No;
	string F;
	string I;
	string O;
	string NoStud;
	string NoGroup;
	int Group;
	int Stepend;
	int Otchislenie;
	Students(int _No, string _F, string _I, string _O, string _NoStud, string _NoGroup, int _Group, int _Stepend, int _Otchislenie) : No(_No), F(_F), I(_I), O(_O), NoStud(_NoStud), NoGroup(_NoGroup), Group(_Group), Stepend(_Stepend), Otchislenie(_Otchislenie) {
	}
	Students();
};

