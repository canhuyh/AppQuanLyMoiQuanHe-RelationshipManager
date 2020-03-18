#pragma once
#include<iostream>
#include<ctime>
#include<string>
#include<stdlib.h>
#include"Kmin.hpp"
using namespace std;
using namespace km;


class Human
{
protected:
	Console console;
	string name;
	int dayOfBirth;
	int monthOfBirth;
	int yearOfBirth;
	int sex;
public:
	Human();
	~Human();
	virtual void InPut(int x, int y);
	virtual void OutPut(int x, int y);
	virtual void SetName(string name);
	virtual void SetDayOfBirth(int dayOfBirth);
	virtual void SetMonthOfBirth(int monthOfBirth);
	virtual void SetYearOfBirth(int yearOfBirth);
	virtual void SetSex(int sex);
	virtual string GetName();
	virtual int GetDayOfBirth();
	virtual int GetMonthOfBirth();
	virtual int GetYearOfBirth();
	virtual int GetSex();
};

