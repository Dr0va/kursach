#include "User.h"

User::User()
{
	login = "";
	pass = "";
	group = NULL;
}

User::~User()
{
}
ostream& operator<<(ostream& ost, const User& user) {
	ost << user.login << "\t" << user.pass << "\t" << user.group << '\n';
	return ost;
}