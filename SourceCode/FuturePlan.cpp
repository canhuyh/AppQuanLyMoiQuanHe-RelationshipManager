#include "FuturePlan.h"

FuturePlan::FuturePlan()
{
	this->planName = " ";
	this->where = " ";
	this->address = " ";
	orderCalendar = new Time;
}

FuturePlan::~FuturePlan()
{
}

void FuturePlan::Input()
{
	this->console.gotoXY(_INPUT_X, INPUT_Y);
	cin.ignore();
	getline(cin, this->planName);
	this->console.gotoXY(_INPUT_X + 25, INPUT_Y);
	getline(cin, this->where);
	this->console.gotoXY(_INPUT_X + 56, INPUT_Y);
	getline(cin, this->address);
	orderCalendar->Input();
}

void FuturePlan::Output()
{
	cout << this->planName << endl;
	cout << this->where << endl;
	cout << this->address << endl;
	orderCalendar->Output();
}

void FuturePlan::SetNamePlan(string namePlan)
{
	this->planName = namePlan;
}

void FuturePlan::SetID(string id)
{
	this->id = id;
}

void FuturePlan::SetWhere(string where)
{
	this->where = where;
}

void FuturePlan::SetAddress(string address)
{
	this->address = address;
}

void FuturePlan::SetDescribe(string des)
{
	this->describe = des;
}

string FuturePlan::GetID()
{
	return this->id;
}

string FuturePlan::GetNamePlan()
{
	return this->planName;
}

string FuturePlan::GetWhere()
{
	return this->where;
}

string FuturePlan::GetAddress()
{
	return this->address;
}

string FuturePlan::GetDescribe()
{
	return this->describe;
}

Time* FuturePlan::GetOrderCalendar()
{
	return this->orderCalendar;
}

bool FuturePlan::Remind()
{
	time_t today = time(0);
	tm* ltm = localtime(&today);
	int day = ltm->tm_mday;
	int month = 1 + ltm->tm_mon;
	int year = 1900 + ltm->tm_year;
	int hours = ltm->tm_hour;
	//
	int dayofplan = this->orderCalendar->GetDay();
	int monthofplan = this->orderCalendar->GetMonth();
	int yearofplan = this->orderCalendar->GetYear();
	//
	int timeofplan = this->orderCalendar->CaculatorSttDayFrom_1_1_1(dayofplan, monthofplan, yearofplan);
	int timetoday = this->orderCalendar->CaculatorSttDayFrom_1_1_1(day, month, year);
	int result = timeofplan - timetoday;
	if (result <= 2 && result > 0)
		return true;
	else if (this->orderCalendar->GetDay() == day && this->orderCalendar->GetMonth() == month
		&& this->orderCalendar->GetYear() == year && this->orderCalendar->GetHours() >= hours)
		return true;
	return false;
}
