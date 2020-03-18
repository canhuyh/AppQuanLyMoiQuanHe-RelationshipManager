#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<conio.h>
#include<ctime>
#include<vector>
#include<string>
#include"Program.h"
#include"Account.h"
#include"FuturePlan.h"
#include"Relationship.h"
#include"Kmin.hpp"	

using namespace km;

int main()
{
	Program* pr = new Program;
	pr->Run();
	_getch();
	return 0;
}

