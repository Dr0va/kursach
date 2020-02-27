#include "PrintStudent.h"
#include "func_menu.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "choose_menu.h"
#include "Authorization.h"
#include "Registration.h"
#include "choose_login.h"
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include "func_menu.h"
PrintStudent::PrintStudent()
{
}
PrintStudent::~PrintStudent()
{
}
void PrintStudent::PrintStud()
{
	string temp;
	ifstream tmp;
	int count_ = 0;
	tmp.open("temp.bin");
	int i = 0, group_;
	tmp >> group_;
	tmp.close();
	char* str = new char[1024];
	ifstream FileStudents;
	FileStudents.open("Students.bin", ios::binary | ios::in);
	if (!FileStudents.is_open())
	{
		cout << "Ошибка чтения! Обратитесь к администратору!\n";
		func_menu* Menu = new func_menu();
		Menu->FuncMenu();
	}
	while (!FileStudents.eof())
	{
		FileStudents.getline(str, 1024, '\n');
		count_++;
	}
	temp_ = count_;
	Students* k = new Students;
	k->next = NULL;
	add_Node(k, count_);
	sort(k);
	Students* current = new Students;
	current = k;
	FileStudents.close();
	PrintMenu(current, group_, k);
}
void PrintStudent::PrintMenu(Students* current, int group_, Students* k)
{
	int count = 0;
	cout << "№" << "\t|" << setw(17) << left << "Фамилия" << left << "\t|" << setw(20) << "Имя" << "\t|" << setw(22) << "Отчество" << "|" << setw(23) << "Номер студенческого" << "|" << setw(14) << "Номер группы"  << " |" << setw(12) << "Стипендия" << "|" << endl;
	cout << "=============================================================================================================================================" << endl;
	for (int i = 0; i < temp_; i++)
	{
		count++;
		current = current->next;
		cout << current->No << "\t|" << setw(17) << left << current->F << left << "\t|" << setw(20) << current->I << "\t|" << setw(22) << current->O << "|" << setw(23) << current->NoStud << "|" << setw(14) << current->NoGroup << " |";
		if (current->Stepend == 1)
			cout << setw(12) << "Обычная" << "|";
		else if(current->Stepend == 2) {
			cout << setw(12) << "Повышенная" << "|";
		} else cout << setw(12) << "Нет" << "|";
		if (current->Otchislenie == 1)
			cout << setw(12) << "Отчислен";
		cout << "\n";
	}
	current = k;
	system("pause");
	int choose;
	cout << "\n\n1) Найти студента в списке;\n2) Выйти в меню функций;\n3) Выйти в меню выбора пользователя;\n4) Выйти из программы;\n\n";
	cin >> choose;
	choose--;
	switch (choose)
	{
	case 0:
	{
		Serch(current, group_, k);
		system("pause");
	}
	case 1:
	{
		system("cls");
		func_menu* Menu = new func_menu;
		Menu->FuncMenu();
	}
	case 2:
	{
		system("cls");
		choose_menu();
	}
	case 3:
	{
		remove("temp.bin");
		exit(0);
	}
	default:
		cout << "Ошибка!\n";
		system("pause");
		system("cls");
		PrintMenu(current, group_, k);
	}
}

void PrintStudent::add_Node(Students* head, int temp_)
{
	ifstream FileStudents;
	int i = 0;
	FileStudents.open("Students.bin", ios::binary | ios::in);
	for (i; i < temp_; i++) 
	{
		Students* current = head;
		while (current->next != NULL)
			current = current->next;
		Students* new_node = new Students;
		new_node->next = NULL;
		FileStudents >> new_node->No >> new_node->F >> new_node->I >> new_node->O >> new_node->NoStud >> new_node->NoGroup >> new_node->Group >> new_node->Stepend >> new_node->Otchislenie;
		current->next = new_node;
	}
}
void PrintStudent::sort(Students* head) 
{
	Students* left = head->next;                
	Students* right = left->next;        
	while (left->next != NULL)		      
	{									 
		while (right != NULL)						
		{														
			if ((left->Group) < (right->Group))		
			{
				swap(left->F,right->F);
				swap(left->I, right->I);
				swap(left->O, right->O);
				swap(left->NoStud, right->NoStud);
				swap(left->NoGroup, right->NoGroup);
				swap(left->Group, right->Group);
				swap(left->Stepend, right->Stepend);
				swap(left->Otchislenie, right->Otchislenie);
			}
			right = right->next;                  
		}
		left = left->next;                            
		right = left->next;                       
	}
}

void PrintStudent::Serch(Students* head, int group_, Students* k)
{
	string key;
	int key_, count = 0;
	cout << "Введите Порядковый номер/Имя/Фамилию/Отчество/Номер студенческого билета:\n";
	cin >> key;
	cout << "\n";
	Students* left = k;
	cout << "№" << "\t|" << setw(17) << "Фамилия" << "\t|" << setw(20) << "Имя" << "\t|" << setw(22) << "Отчество" << "|" << setw(23) << "Номер студенческого" << "|" << setw(14) << "Номер группы " << " |" << setw(12) << "Стипендия" << " |" << endl;
	cout << "==============================================================================================================================================" << endl;
	while (left->next != NULL)
	{
		left = left->next;
		if (key == left->F || key == left->I || key == left->O || key == left->NoStud || key == left->NoGroup || key == left->No)
		{
			count++;
			left->temp = count;
			cout << count << "\t|" << setw(17) << left->F << "\t|" << setw(20) << left->I << "\t|" << setw(22) << left->O << "|" << setw(23) << left->NoStud << "|" << setw(13) << left->NoGroup << "  |";
			if (left->Stepend == 1)
				cout << setw(13) << "Обычная" << "|";
			else if (left->Stepend == 2) {
				cout << setw(13) << "Повышенная" << "|";
			}
			else cout << setw(13) << "Нет" << "|";
			if (left->Otchislenie == 1)
				cout << setw(12) << "Отчислен";
			cout << "\n";
		}
	}
	if (count == 0)
	{
		cout << "По искомым значениям студентов не найдено!\n";
		system("pause");
	}
	cout << "\n";
	system("pause");
	if (group_ != 0 && count != 0)
	{
		cout << "Выберите функцию:\n1) Отчислить студента;\n2) Отменить отчисление;\n3) Назначить стипендию;\n4) Обновить список;\n";
		int choose;
		int temp = 1;
		cin >> choose;
		choose--;
		if (choose == 1)
		{
			choose = 0;
			temp = 0;
		}
		switch (choose)
		{
		case 0:
		{
			cout << "Введите порядковый номер студента:\n";
			int choose_;
			cin >> choose_;
			left = k;
			while (left->next != NULL)
			{
				left = left->next;
				if (choose_ == left->temp)
				{
					left->Otchislenie = temp;
					break;
				}
			}
			if (temp == 1)
				cout << "Студент помечен как «Отчислен».\n";
			else 
				cout << "Студент теперь не отчислен.\n";
			system("pause");
			system("cls");
			ifstream FileStudents;
			ofstream FileStudents_;
			int i = 0;
			FileStudents.open("Students.bin", ios::binary | ios::in);
			FileStudents_.open("Students.bin", ios::binary | ios::out);
			Students* left_ = new Students;
			left_ = k;
			while (left_->next != NULL)
			{
				left_ = left_->next;
				FileStudents >> left_->No >> left_->F >> left_->I >> left_->O >> left_->NoStud >> left_->NoGroup >> left_->Group >> left_->Stepend >> left_->Otchislenie;
				if (left_->NoStud == left->NoStud)
				{
					left_->Otchislenie = temp;
				}
				FileStudents_ << left_->No << " " << left_->F <<" "<< left_->I << " "<< left_->O << " " << left_->NoStud << " " << left_->NoGroup << " " << left_->Group << " " << left_->Stepend << " " << left_->Otchislenie;
				if (left_->next != NULL)
				{
					FileStudents_ << "\n";
				}
			}
			FileStudents.close();
			FileStudents_.close();
			PrintMenu(head, group_, k);
		}
		case 2:
		{
			cout << "Введите порядковый номер студента:\n";
			int choose_, choise;
			cin >> choose_;
			cout << "Выберите значение стипендии:\n1) Без стипендии;\n2) Обычная;\n3) Повышенная;\n";
			cin >> choise;
			choise--;
			left = k;
			while (left->next != NULL)
			{
				left = left->next;
				if (choose_ == left->temp)
				{
					left->Stepend = choise;
					break;
				}
			}
			cout << "Студенту присвоенно значение стипендии.\n";
			system("pause");
			system("cls");
			ifstream FileStudents;
			ofstream FileStudents_;
			int i = 0;
			FileStudents.open("Students.bin", ios::binary | ios::in);
			FileStudents_.open("Students.bin", ios::binary | ios::out);
			Students* left_ = new Students;
			left_ = k;
			while (left_->next != NULL)
			{
				left_ = left_->next;
				FileStudents >> left_->No >> left_->F >> left_->I >> left_->O >> left_->NoStud >> left_->NoGroup >> left_->Group >> left_->Stepend >> left_->Otchislenie;
				if (left_->NoStud == left->NoStud)
				{
					left_->Otchislenie = choise;
				}
				FileStudents_ << left_->No << " " << left_->F << " " << left_->I << " " << left_->O << " " << left_->NoStud << " " << left_->NoGroup << " " << left_->Group << " " << left_->Stepend << " " << left_->Otchislenie;
				if (left_->next != NULL)
				{
					FileStudents_ << "\n";
				}
			}
			FileStudents.close();
			FileStudents_.close();
			PrintMenu(head, group_, k);
		}
		case 3:
		{
			system("cls");
			PrintMenu(head, group_, k);
		}
		default:
			cout << "Ошибка!";
			system("pause");
			system("cls");
			Serch(head, group_, k);
		}
	}
	system("cls");
	PrintMenu(head, group_, k);
}