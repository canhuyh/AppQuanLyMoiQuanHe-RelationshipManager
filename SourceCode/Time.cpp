#include "Time.h"


Time::Time()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
	this->hours = 9;
	this->minute = 0;
	this->seconds = 0;
}

Time::Time(int d, int m, int y)
{
	this->day = d;
	this->month = m;
	this->year = y;
}

Time::~Time()
{
}

void Time::Input()
{
	int dem = 0;
	string day, month, year, hours, minutes;
	//Day
	do
	{
		dem = 0;
		this->console.gotoXY(_INPUT_X + 118, INPUT_Y);
		cin >> day;
		for (int i = 0; i < day.length(); i++)
		{
			if (day[i] < 48 || day[i] >= 58)
			{
				this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
				cout << "Nhap khong hop le, vui long nhap lai";
				break;
			}
			else
				dem++;
			if (dem == day.length())
			{
				if (atoi(day.c_str()) <= 0 || atoi(day.c_str()) > 31)
				{
					this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
					cout << "Nhap khong hop le, vui long nhap lai";
				}
				else
					this->day = atoi(day.c_str());
			}
		}
	} while (dem < day.length() || atoi(day.c_str()) <= 0 || atoi(day.c_str()) > 31);
	this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
	cout << "                                              ";//
	if (this->day < 10)
	{
		this->console.gotoXY(_INPUT_X + 118, INPUT_Y);
		cout << "0" << this->day;
	}

	//Month
	do
	{
		dem = 0;
		this->console.gotoXY(_INPUT_X + 121, INPUT_Y);
		cin >> month;
		for (int i = 0; i < month.length(); i++)
		{
			if (month[i] < 48 || month[i] >= 58)
			{
				this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
				cout << "Nhap khong hop le, vui long nhap lai";
				break;
			}
			else
				dem++;
			if (dem == month.length())
			{
				if (atoi(month.c_str()) <= 0 || atoi(month.c_str()) > 12)
				{
					this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
					cout << "Nhap khong hop le, vui long nhap lai";
				}
				else
					this->month = atoi(month.c_str());
			}
		}
	} while (dem < month.length() || atoi(month.c_str()) <= 0 || atoi(month.c_str()) > 12);
	this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
	cout << "                                              ";//
	if (this->month < 10)
	{
		this->console.gotoXY(_INPUT_X + 121, INPUT_Y);
		cout << "0" << this->month;
	}

	//Year
	do
	{
		dem = 0;
		this->console.gotoXY(_INPUT_X + 125, INPUT_Y);
		cin >> year;
		for (int i = 0; i < year.length(); i++)
		{
			if (year[i] < 48 || year[i] >= 58)
			{
				this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
				cout << "Nhap khong hop le, vui long nhap lai";
				break;
			}
			else
				dem++;
			if (dem == year.length())
			{
				if (atoi(year.c_str()) <= 0)
				{
					this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
					cout << "Nhap khong hop le, vui long nhap lai";
				}
				else
					this->year = atoi(year.c_str());
			}
		}
	} while (dem < year.length() || atoi(year.c_str()) <= 0);
	this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
	cout << "                                              ";//

	//Hours
	do
	{
		dem = 0;
		this->console.gotoXY(_INPUT_X + 137, INPUT_Y);
		cin >> hours;
		for (int i = 0; i < hours.length(); i++)
		{
			if (hours[i] < 48 || hours[i] >= 58)
			{
				this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
				cout << "Nhap khong hop le, vui long nhap lai";
				break;
			}
			else
				dem++;
			if (dem == hours.length())
			{
				if (atoi(hours.c_str()) < 0 || atoi(hours.c_str()) > 24)
				{
					this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
					cout << "Nhap khong hop le, vui long nhap lai";
				}
				else
					this->hours = atoi(hours.c_str());
			}
		}
	} while (dem < hours.length() || atoi(hours.c_str()) < 0 || atoi(hours.c_str()) > 24);
	this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
	cout << "                                              ";//
	if (this->hours < 10)
	{
		this->console.gotoXY(_INPUT_X + 137, INPUT_Y);
		cout << "0" << this->hours;
	}

	//Minutes
	do
	{
		dem = 0;
		this->console.gotoXY(_INPUT_X + 140, INPUT_Y);
		cin >> minutes;
		for (int i = 0; i < minutes.length(); i++)
		{
			if (minutes[i] < 48 || minutes[i] >= 58)
			{
				this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
				cout << "Nhap khong hop le, vui long nhap lai";
				break;
			}
			else
				dem++;
			if (dem == minutes.length())
			{
				if (atoi(minutes.c_str()) < 0 || atoi(minutes.c_str()) > 59)
				{
					this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
					cout << "Nhap khong hop le, vui long nhap lai";
				}
				else
					this->minute = atoi(minutes.c_str());
			}
		}
	} while (dem < minutes.length() || atoi(minutes.c_str()) < 0 || atoi(minutes.c_str()) > 59);
	this->console.gotoXY(_INPUT_X + 50, INPUT_Y + 4);
	cout << "                                              ";//
	if (this->minute < 10)
	{
		this->console.gotoXY(_INPUT_X + 140, INPUT_Y);
		cout << "0" << this->minute;
	}

}

void Time::Output()
{
	cout << this->day;
	cout << this->month;
	cout << this->year;
	cout << this->hours;
	cout << this->minute;
}

void Time::SetDay(int day)
{
	this->day = day;
}

void Time::SetMonth(int month)
{
	this->month = month;
}

void Time::SetYear(int year)
{
	this->year = year;
}

void Time::SetHours(int hours)
{
	this->hours = hours;
}

void Time::SetMinute(int minute)
{
	this->minute = minute;
}

void Time::SetSeconds(int seconds)
{
	this->seconds = seconds;
}

int Time::GetDay()
{
	return this->day;
}

int Time::GetMonth()
{
	return this->month;
}

int Time::GetYear()
{
	return this->year;
}

int Time::GetHours()
{
	return this->hours;
}

int Time::GetMinute()
{
	return this->minute;
}

int Time::GetSeconds()
{
	return this->seconds;
}

bool Time::CheckLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

long long Time::CaculatorSttDayInYear(int day, int month, int year)
{
	int all_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (CheckLeapYear(year) == true)
		all_month[1] = 29;
	int stt = day;
	for (int i = 0; i < month - 1; i++)
	{
		stt += all_month[i];
	}
	return stt;
}

long long Time::CaculatorSttDayFrom_1_1_1(int day, int month, int year)
{
	int stt = 0;
	for (int i = 1; i < year; i++)
	{
		if (CheckLeapYear(i) == true)
			stt += 366;
		else
			stt += 365;
	}
	return stt + CaculatorSttDayInYear(day, month, year);
}

long long Time::CalculateTheDate(int day, int month, int year)
{
	int sttStartDay = CaculatorSttDayFrom_1_1_1(this->day, this->month, this->year);
	int sttToDay = CaculatorSttDayFrom_1_1_1(day, month, year);
	return sttToDay - sttStartDay;
}

long long Time::CalculateTheWeeks(int day, int month, int year)
{
	return CalculateTheDate(day, month, year) / 7;
}

long long Time::CalculateTheMonth(int day, int month, int year)
{
	return CalculateTheDate(day, month, year) / 30;
}

long long Time::CalculateTheYear(int day, int month, int year)
{
	return CalculateTheDate(day, month, year) / 365;
}

long long Time::CalculateTheHours(int day, int month, int year)
{
	return CalculateTheDate(day, month, year) * 24;
}

long long Time::CalculateTheMinute(int day, int month, int year)
{
	return CalculateTheHours(day, month, year) * 60;
}

long long Time::CalculateTheSeconds(int day, int month, int year)
{
	return CalculateTheMinute(day, month, year) * 60;
}