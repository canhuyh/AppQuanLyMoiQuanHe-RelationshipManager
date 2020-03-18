#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<ctime>
#include<string>
#include"Time.h"
#include"Kmin.hpp"
#include"Human.h"
using namespace km;

class FuturePlan
{
private:
    Console console;
    string planName;
    string where;
    string address;
    string id;
    string describe;
    Time* orderCalendar;
public:
    FuturePlan();
    ~FuturePlan();
    void Input();
    void Output();
    void SetNamePlan(string namePlan);
    void SetID(string id);
    void SetWhere(string where);
    void SetAddress(string address);
    void SetDescribe(string des);
    string GetID();
    string GetNamePlan();
    string GetWhere();
    string GetAddress();
    string GetDescribe();
    Time* GetOrderCalendar();
    bool Remind();
};

