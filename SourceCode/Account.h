#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include"Kmin.hpp"
#include"Relationship.h"
#include"Human.h"
using namespace std;
using namespace km;

class Account :public Human
{
private:
	string userName;
	string passWord;
	string id;
public:
	Account();
	~Account();
	void InPut(int x, int y);
	void Registration();
	bool Login();
	void SetID(string id);
	void SetUserName(string user);
	void SetPassWord(string pass);
	string GetID();
	string GetUserName();
	string GetPassWord();
};

