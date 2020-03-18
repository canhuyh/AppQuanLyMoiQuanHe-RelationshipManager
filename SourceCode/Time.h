#pragma once
#include<iostream>
#include<ctime>
#include<string>
#include"Kmin.hpp"
using namespace std;
using namespace km;

#define _INPUT_X 7
#define INPUT_Y 11

class Time
{
private:
	Console console;
	int day;
	int month;
	int year;
	int hours;
	int minute;
	int seconds;
public:
	Time();
	Time(int d, int m, int y);
	~Time();
	void Input();
	void Output();
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	void SetHours(int hours);
	void SetMinute(int minute);
	void SetSeconds(int seconds);
	int GetDay();
	int GetMonth();
	int GetYear();
	int GetHours();
	int GetMinute();
	int GetSeconds();
	long long CalculateTheDate(int day, int month, int year);
	long long CalculateTheWeeks(int day, int month, int year);
	long long CalculateTheMonth(int day, int month, int year);
	long long CalculateTheYear(int day, int month, int year);
	long long CalculateTheHours(int day, int month, int year);
	long long CalculateTheMinute(int day, int month, int year);
	long long CalculateTheSeconds(int day, int month, int year);
	bool CheckLeapYear(int year);
	long long CaculatorSttDayInYear(int day, int month, int year);
	long long CaculatorSttDayFrom_1_1_1(int day, int month, int year);
};

