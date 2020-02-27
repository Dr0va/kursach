#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
struct Disciplline
{
	string name;
	int kurs;
	int priznak;
	int No;
	Disciplline();
	Disciplline(string _name, int _kurs, int _priznak, int _No) : name(_name), kurs(_kurs), priznak(_priznak), No(_No){}
};

