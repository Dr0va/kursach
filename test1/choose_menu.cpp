#include "choose_menu.h"
#include "Registration.h"
#include "Authorization.h"
#include "User.h"
#include <fstream>
#include "choose_login.h"

choose_menu::choose_menu()
{
	WindowChoose_menu();
}

choose_menu::~choose_menu()
{
}

void choose_menu::WindowChoose_menu()
{
	int group_;
	cout << "Выберите пользователя: \n1) Студент;\n2) Диспетчер;\n3) Админ;\n4) Выйти из программы;\n\n";
	cin >> group_;
	group_--;
	if (group_ > 3 || group_ < 0)
	{
		cout << "Ошибка!\n\n";
		system("pause");
		system("cls");
		choose_menu();
	}
	if (group_ == 3) {
		system("cls");
		exit(0);
	}
	system("cls");
	ofstream temp;
	temp.open("temp.bin", ofstream::binary);
	temp << group_;
	temp.close();
	choose_login();
}