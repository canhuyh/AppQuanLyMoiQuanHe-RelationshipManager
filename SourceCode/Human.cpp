#include "Human.h"

Human::Human()
{
	this->dayOfBirth = 1;
	this->monthOfBirth = 1;
	this->yearOfBirth = 1;
}

Human::~Human()
{
}

void Human::InPut(int x, int y)
{
	string day;
	string month;
	string year;
	int dem = 0;
	this->console.gotoXY(x, y);
	cin.ignore();
	getline(cin, this->name);
	//dayofbirth
	do
	{
		dem = 0;
		this->console.gotoXY(x + 7, y + 1);
		cin >> day;
		for (int i = 0; i < day.length(); i++)
		{
			if (day[i] < 48 || day[i] >= 58)
			{
				this->console.gotoXY(x - 40, y + 8);
				cout << "Nhap khong hop le, vui long nhap lai";
				break;
			}
			else
				dem++;
			if (dem == day.length())
			{
				if (atoi(day.c_str()) <= 0 || atoi(day.c_str()) > 31)
				{
					this->console.gotoXY(x - 40, y + 8);
					cout << "Nhap khong hop le, vui long nhap lai";
				}
				else
					this->dayOfBirth = atoi(day.c_str());
			}
		}
	} while (dem < day.length() || atoi(day.c_str()) <= 0 || atoi(day.c_str()) > 31);
	if (this->dayOfBirth < 10)
	{
		this->console.gotoXY(x + 7, y + 1);
		cout << "0" << this->dayOfBirth;
	}
	this->console.gotoXY(x - 40, y + 8);
	cout << "                                              ";//
	//monthofbirth
	do
	{
		dem = 0;
		this->console.gotoXY(x + 11, y + 1);
		cin >> month;
		for (int i = 0; i < month.length(); i++)
		{
			if (month[i] < 48 || month[i] >= 58)
			{
				this->console.gotoXY(x - 40, y + 8);
				cout << "Nhap khong hop le, vui long nhap lai";
				break;
			}
			else
				dem++;
			if (dem == month.length())
			{
				if (atoi(month.c_str()) <= 0 || atoi(month.c_str()) > 12)
				{
					this->console.gotoXY(x - 40, y + 8);
					cout << "Nhap khong hop le, vui long nhap lai";
				}
				else
					this->monthOfBirth = atoi(month.c_str());
			}
		}
	} while (dem < month.length() || atoi(month.c_str()) <= 0 || atoi(month.c_str()) > 12);
	if (this->monthOfBirth < 10)
	{
		this->console.gotoXY(x + 11, y + 1);
		cout << "0" << this->monthOfBirth;
	}
	this->console.gotoXY(x - 40, y + 8);
	cout << "                                              ";//
	//yearofbirth
	do
	{
		dem = 0;
		this->console.gotoXY(x + 15, y + 1);
		cin >> year;
		for (int i = 0; i < year.length(); i++)
		{
			if (year[i] < 48 || year[i] >= 58)
			{
				this->console.gotoXY(x - 40, y + 8);
				cout << "Nhap khong hop le, vui long nhap lai";
				break;
			}
			else
				dem++;
			if (dem == year.length())
			{
				if (atoi(year.c_str()) <= 0)
				{
					this->console.gotoXY(x - 40, y + 8);
					cout << "Nhap khong hop le, vui long nhap lai";
				}
				else
					this->yearOfBirth = atoi(year.c_str());
			}
		}
	} while (dem < year.length() || atoi(year.c_str()) <= 0);
	this->console.gotoXY(x - 40, y + 8);
	cout << "                                              ";//
	//sex
	string sex;
	do
	{
		dem = 0;
		this->console.gotoXY(x + 12, y + 2);
		cin >> sex;
		if (sex != "0" && sex != "1")
		{
			this->console.gotoXY(x - 40, y + 8);
			cout << "Nhap khong hop le, vui long nhap lai";
		}
	} while (sex != "0" && sex != "1");
	if (atoi(sex.c_str()) == 1)
	{
		this->sex = atoi(sex.c_str());
		this->console.gotoXY(x + 11, y + 2);
		cout << "Nam";
	}
	else
	{
		this->sex = atoi(sex.c_str());
		this->console.gotoXY(x + 11, y + 2);
		cout << "Nu";
	}
	this->console.gotoXY(x - 40, y + 8);
	cout << "                                              ";//
}

void Human::OutPut(int x, int y)
{
	this->console.gotoXY(x, y);
	cout << this->name << endl;
	this->console.gotoXY(x + 7, y + 1);
	if (this->dayOfBirth < 10)
		cout << "0" << this->dayOfBirth << endl;
	else
		cout << this->dayOfBirth << endl;
	this->console.gotoXY(x + 11, y + 1);
	if (this->monthOfBirth < 10)
		cout << "0" << this->monthOfBirth << endl;
	else
		cout << this->monthOfBirth << endl;
	this->console.gotoXY(x + 15, y + 1);
	cout << this->yearOfBirth << endl;
	this->console.gotoXY(x + 10, y + 2);
	if (this->sex == 1)
		cout << "Nam" << endl;
	else
		cout << "Nu" << endl;
}

void Human::SetName(string name)
{
	this->name = name;
}

void Human::SetDayOfBirth(int dayOfBirth)
{
	this->dayOfBirth = dayOfBirth;
}

void Human::SetMonthOfBirth(int monthOfBirth)
{
	this->monthOfBirth = monthOfBirth;
}

void Human::SetYearOfBirth(int yearOfBirth)
{
	this->yearOfBirth = yearOfBirth;
}

void Human::SetSex(int sex)
{
	this->sex = sex;
}

string Human::GetName()
{
	return this->name;
}

int Human::GetDayOfBirth()
{
	return this->dayOfBirth;
}

int Human::GetMonthOfBirth()
{
	return this->monthOfBirth;
}

int Human::GetYearOfBirth()
{
	return this->yearOfBirth;
}

int Human::GetSex()
{
	return this->sex;
}
