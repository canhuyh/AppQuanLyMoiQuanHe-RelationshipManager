#include "Relationship.h"

Relationship::Relationship()
{
	human1 = new Human;
	human2 = new Human;
	nameOfRelationship = " ";
	startTime = new Time;
	//
	time_t today = time(0);
	tm* ltm = localtime(&today);
	this->idLinkPlan = to_string(ltm->tm_mday) + to_string(1 + ltm->tm_mon) +
		to_string(1900 + ltm->tm_year) + to_string(ltm->tm_hour) +
		to_string(1 + ltm->tm_min) + to_string(1 + ltm->tm_sec);
}

Relationship::~Relationship()
{
}

void Relationship::Input()
{
	int dem = 0;
	//Di chuyển vị trí con trỏ nhập tại tọa độ cho trước
	human1->OutPut(_INPUT_HUNAM_X, INPUT_HUMAN_Y);
	human2->InPut(_INPUT_HUNAM_X + 30, INPUT_HUMAN_Y);
	cin.ignore();
	this->console.gotoXY(_INPUT_HUNAM_X + 25, INPUT_HUMAN_Y + 3);
	getline(cin, this->nameOfRelationship);
	//Input day, month, year;
	char import;
	do
	{
		this->console.gotoXY(_INPUT_HUNAM_X, INPUT_HUMAN_Y + 4);
		cin >> import;
		if (import != '1' && import != '0')
		{
			this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
			cout << "* Error" << ": Khong hop le, vui long chon lai!!!\n";
		}
	} while (import != '1' && import != '0');
	this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
	cout << "                                                                  \n";//
	if (import == '1')
	{
		string day, month, year;
		//Day
		do
		{
			dem = 0;
			this->console.gotoXY(_INPUT_HUNAM_X + 22, INPUT_HUMAN_Y + 4);
			cin >> day;
			for (int i = 0; i < day.length(); i++)
			{
				if (day[i] <= 48 || day[i] >= 58)
				{
					this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
					cout << "Nhap khong hop le, vui long nhap lai";
					break;
				}
				else
					dem++;
				if (dem == day.length())
				{
					if (atoi(day.c_str()) <= 0 || atoi(day.c_str()) > 31)
					{
						this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
						cout << "Nhap khong hop le, vui long nhap lai";
					}
					else
						this->startTime->SetDay(atoi(day.c_str()));
				}
			}
		} while (dem < day.length() || atoi(day.c_str()) <= 0 || atoi(day.c_str()) > 31);
		this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
		cout << "                                              ";//
		if (this->startTime->GetDay() < 10)
		{
			this->console.gotoXY(_INPUT_HUNAM_X + 22, INPUT_HUMAN_Y + 4);
			cout << "0" << this->startTime->GetDay();
		}

		//Month
		do
		{
			dem = 0;
			this->console.gotoXY(_INPUT_HUNAM_X + 26, INPUT_HUMAN_Y + 4);
			cin >> month;
			for (int i = 0; i < month.length(); i++)
			{
				if (month[i] <= 48 || month[i] >= 58)
				{
					this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
					cout << "Nhap khong hop le, vui long nhap lai";
					break;
				}
				else
					dem++;
				if (dem == month.length())
				{
					if (atoi(month.c_str()) <= 0 || atoi(month.c_str()) > 12)
					{
						this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
						cout << "Nhap khong hop le, vui long nhap lai";
					}
					else
						this->startTime->SetMonth(atoi(month.c_str()));
				}
			}
		} while (dem < month.length() || atoi(month.c_str()) <= 0 || atoi(month.c_str()) > 12);
		this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
		cout << "                                              ";//
		if (this->startTime->GetMonth() < 10)
		{
			this->console.gotoXY(_INPUT_HUNAM_X + 26, INPUT_HUMAN_Y + 4);
			cout << "0" << this->startTime->GetMonth();
		}

		//Year
		do
		{
			dem = 0;
			this->console.gotoXY(_INPUT_HUNAM_X + 30, INPUT_HUMAN_Y + 4);
			cin >> year;
			for (int i = 0; i < year.length(); i++)
			{
				if (year[i] < 48 || year[i] >= 58)
				{
					this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
					cout << "Nhap khong hop le, vui long nhap lai";
					break;
				}
				else
					dem++;
				if (dem == year.length())
				{
					if (atoi(year.c_str()) <= 0)
					{
						this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
						cout << "Nhap khong hop le, vui long nhap lai";
					}
					else
						this->startTime->SetYear(atoi(year.c_str()));
				}
			}
		} while (dem < year.length() || atoi(year.c_str()) <= 0);
		this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
		cout << "                                              ";//
	}
	else if (import == '0')
	{
		time_t today = time(0);
		tm* ltm = localtime(&today);
		this->startTime->SetDay(ltm->tm_mday);
		this->startTime->SetMonth(1 + ltm->tm_mon);
		this->startTime->SetYear(1900 + ltm->tm_year);
		this->console.gotoXY(_INPUT_HUNAM_X + 22, INPUT_HUMAN_Y + 4);
		if (this->startTime->GetDay() < 10)
		{
			cout << "0" << this->startTime->GetDay();
		}
		else
			cout << this->startTime->GetDay();
		this->console.gotoXY(_INPUT_HUNAM_X + 26, INPUT_HUMAN_Y + 4);
		if (this->startTime->GetMonth() < 10)
		{
			/*this->console.gotoXY(x + 11, y + 1);*/
			cout << "0" << this->startTime->GetMonth();
		}
		else
			cout << this->startTime->GetMonth();
		this->console.gotoXY(_INPUT_HUNAM_X + 30, INPUT_HUMAN_Y + 4);
		if (this->startTime->GetYear() < 10)
		{
			/*this->console.gotoXY(x + 11, y + 1);*/
			cout << "0" << this->startTime->GetYear();
		}
		else
			cout << this->startTime->GetYear();
	}
	//Input hours, minutes
	do
	{
		this->console.gotoXY(_INPUT_HUNAM_X, INPUT_HUMAN_Y + 5);
		cin >> import;
		if (import != '1' && import != '0')
		{
			this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
			cout << "* Error" << ": Khong hop le, vui long chon lai!!!\n";
		}
	} while (import != '1' && import != '0');
	this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
	cout << "                                                                  \n";//
	if (import == '1')
	{
		string hours, minutes;
		//Hours
		do
		{
			dem = 0;
			this->console.gotoXY(_INPUT_HUNAM_X + 25, INPUT_HUMAN_Y + 5);
			cin >> hours;
			for (int i = 0; i < hours.length(); i++)
			{
				if (hours[i] < 48 || hours[i] >= 58)
				{
					this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
					cout << "Nhap khong hop le, vui long nhap lai";
					break;
				}
				else
					dem++;
				if (dem == hours.length())
				{
					if (atoi(hours.c_str()) < 0 || atoi(hours.c_str()) > 24)
					{
						this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
						cout << "Nhap khong hop le, vui long nhap lai";
					}
					else
						this->startTime->SetHours(atoi(hours.c_str()));
				}
			}
		} while (dem < hours.length() || atoi(hours.c_str()) < 0 || atoi(hours.c_str()) > 24);
		this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
		cout << "                                              ";//
		this->console.gotoXY(_INPUT_HUNAM_X + 25, INPUT_HUMAN_Y + 5);
		if (this->startTime->GetHours() < 10)
		{
			cout << "0" << this->startTime->GetHours();
		}

		//Minutes
		do
		{
			dem = 0;
			this->console.gotoXY(_INPUT_HUNAM_X + 28, INPUT_HUMAN_Y + 5);
			cin >> minutes;
			for (int i = 0; i < minutes.length(); i++)
			{
				if (minutes[i] < 48 || minutes[i] >= 58)
				{
					this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
					cout << "Nhap khong hop le, vui long nhap lai";
					break;
				}
				else
					dem++;
				if (dem == minutes.length())
				{
					if (atoi(minutes.c_str()) < 0 || atoi(minutes.c_str()) > 59)
					{
						this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
						cout << "Nhap khong hop le, vui long nhap lai";
					}
					else
						this->startTime->SetMinute(atoi(minutes.c_str()));
				}
			}
		} while (dem < minutes.length() || atoi(minutes.c_str()) < 0 || atoi(minutes.c_str()) > 59);
		this->console.gotoXY(_INPUT_HUNAM_X - 10, INPUT_HUMAN_Y + 8);
		cout << "                                              ";//
		this->console.gotoXY(_INPUT_HUNAM_X + 28, INPUT_HUMAN_Y + 5);
		if (this->startTime->GetMinute() < 10)
		{
			cout << "0" << this->startTime->GetMinute();
		}
	}
	else if (import == '0')
	{
		this->startTime->SetHours(0);
		this->startTime->SetMinute(0);
		//
		this->console.gotoXY(_INPUT_HUNAM_X + 25, INPUT_HUMAN_Y + 5);
		if (this->startTime->GetHours() < 10)
		{
			cout << "0" << this->startTime->GetHours();
		}
		else
			cout << this->startTime->GetHours();
		//
		this->console.gotoXY(_INPUT_HUNAM_X + 28, INPUT_HUMAN_Y + 5);
		if (this->startTime->GetMinute() < 10)
		{
			cout << "0" << this->startTime->GetMinute();
		}
		else
			cout << this->startTime->GetMinute();
	}
}

void Relationship::Output(int x, int y)
{
	this->console.gotoXY(25, 6);
	cout << this->nameOfRelationship << endl;
	human1->OutPut(x, y);
	human2->OutPut(x, y);
}

void Relationship::SetNameOfRelationship(string nameOfRelationship)
{
	this->nameOfRelationship = nameOfRelationship;
}

void Relationship::SetHuman1(string name, int dayOfBirth, int monthOfBirth,
	int yearOfBirth, int sex)
{
	human1->SetName(name);
	human1->SetDayOfBirth(dayOfBirth);
	human1->SetMonthOfBirth(monthOfBirth);
	human1->SetYearOfBirth(yearOfBirth);
	human1->SetSex(sex);
}

void Relationship::SetIDLinkAccount(string id)
{
	this->idLinkAccount = id;
}

void Relationship::SetIDLinkPlan(string id)
{
	this->idLinkPlan = id;
}

Human* Relationship::GetHuman1()
{
	return this->human1;
}

Human* Relationship::GetHuman2()
{
	return this->human2;
}

string Relationship::GetNameOfRelationship()
{
	return this->nameOfRelationship;
}

string Relationship::GetIDLinkAccount()
{
	return this->idLinkAccount;
}

string Relationship::GetIDLinkPlan()
{
	return this->idLinkPlan;
}

void Relationship::SetStartTime(long long day, long long month, long long year)
{
	this->startTime->SetDay(day);
	this->startTime->SetMonth(month);
	this->startTime->SetYear(year);
}

Time* Relationship::GetStartTime()
{
	return this->startTime;
}
