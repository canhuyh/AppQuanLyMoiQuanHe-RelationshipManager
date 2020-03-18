#include "Account.h"

Account::Account()
{
	time_t today = time(0);
	tm* ltm = localtime(&today);
	this->id = to_string(ltm->tm_mday) + to_string(1 + ltm->tm_mon) +
		to_string(1900 + ltm->tm_year) + to_string(ltm->tm_hour) +
		to_string(1 + ltm->tm_min) + to_string(1 + ltm->tm_sec);
}

Account::~Account()
{
}

void Account::InPut(int x, int y)
{
	this->console.gotoXY(x, y);
	cout << "========================DANG KY========================\n";
	this->console.gotoXY(x, y + 1);
	cout << "[  UserName        :                                  ]\n";
	this->console.gotoXY(x, y + 2);
	cout << "[  PassWord        :                                  ]\n";
	this->console.gotoXY(x, y + 3);
	cout << "=======================================================\n";
	this->console.gotoXY(x + 22, y + 1);
	cin >> this->userName;
	int key;
	this->console.gotoXY(x + 22, y + 2);
	while (1)
	{
		key = _getch();
		if (key != 13 && key != 8)
		{
			this->passWord.push_back(key);
			cout << "*";
		}
		else if (key == 8)
		{
			if (this->passWord.size() > 0)
			{
				this->passWord.pop_back();
				console.clrscr();
				this->console.gotoXY(x, y);
				cout << "========================DANG KY========================\n";
				this->console.gotoXY(x, y + 1);
				cout << "[  UserName        :                                  ]\n";
				this->console.gotoXY(x, y + 2);
				cout << "[  PassWord        :                                  ]\n";
				this->console.gotoXY(x, y + 3);
				cout << "=======================================================\n";
				this->console.gotoXY(x + 22, y + 1);
				cout << this->userName;
				this->console.gotoXY(x + 22, y + 2);
				for (int i = 0; i < this->passWord.size(); i++)
				{
					cout << "*";
				}
			}
		}
		else if (key == 13)
			break;
	}
}

void Account::Registration()
{
	cin >> this->userName;
	cin >> this->passWord;
}

bool Account::Login()
{
	string tmp_username;
	string tmp_password;
	cin >> tmp_username;
	cin >> tmp_password;
	if (tmp_username == this->userName && tmp_password == this->passWord)
		return true;
	return false;
}

void Account::SetID(string id)
{
	this->id = id;
}

void Account::SetUserName(string user)
{
	this->userName = user;
}

void Account::SetPassWord(string pass)
{
	this->passWord = pass;
}

string Account::GetID()
{
	return this->id;
}

string Account::GetUserName()
{
	return this->userName;
}

string Account::GetPassWord()
{
	return this->passWord;
}
