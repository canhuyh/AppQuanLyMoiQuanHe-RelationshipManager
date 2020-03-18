#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<string>
#include<vector>
#include"Human.h"
#include"Time.h"
#include"FuturePlan.h"
#include"Account.h"
#include"Kmin.hpp"

#define _INPUT_HUNAM_X 71
#define INPUT_HUMAN_Y 11

using namespace std;
using namespace km;

class Relationship
{
private:
	Console console;
	Human* human1;
	Human* human2;
	string nameOfRelationship;
	Time* startTime;
	string idLinkAccount;
	string idLinkPlan;
public:
	Relationship();
	~Relationship();
	void Input();
	void Output(int x, int y);
	void SetNameOfRelationship(string nameOfRelationship);
	void SetHuman1(string name, int dayOfBirth, int monthOfBirth,
		int yearOfBirth, int sex);
	void SetIDLinkAccount(string id);
	void SetIDLinkPlan(string id);
	Human* GetHuman1();
	Human* GetHuman2();
	string GetNameOfRelationship();
	string GetIDLinkAccount();
	string GetIDLinkPlan();
	void SetStartTime(long long day, long long month, long long year);
	Time* GetStartTime();
};

