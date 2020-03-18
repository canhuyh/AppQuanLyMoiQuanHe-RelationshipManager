#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<ctime>
#include<iostream>
#include<fstream>
#include"Relationship.h"
#include"Account.h"
#include"FuturePlan.h"
#include"Kmin.hpp"

#define _FRAME_ADD_RELATIONSHIP_X 30
#define FRAME_ADD_RELATIONSHIP_Y 10
#define _SEARCH_RELATIONSHIP_X 35
#define SEARCH_RELATIONSHIP_Y 5
#define _OUTPUT_SEARCH_RELATIONSHIP_X 65
#define OUTPUT_SEARCH_RELATIONSHIP_Y 6
#define _OUTPUT_DEATAIL_X 5
#define OUTPUT_DEATAIL_Y 17
#define _OUTPUT_TIME_X 124
#define OUTPUT_TIME_Y 2
#define _OUTPUT_LIST_X 5
#define OUTPUT_LIST_Y 2
#define _FRAME_ADD_FUTUREPLAN_X 5
#define FARME_ADD_FUTUREPLAN_Y 12
#define _LOGIN_X 55
#define LOGIN_Y 10
#define _FRAME_START_PR_X 65
#define FRAME_START_PR_Y 10
#define _REGISTRATION_X 55
#define REGISTRATION_Y 10
#define _MORE_INFORMATION_X 52
#define MORE_INFORMATION_Y 17
#define ID_LINK_PLANLIST " "

using namespace std;
using namespace km;

class Program
{
private:
	vector<Account*> account;
	vector<Relationship*> list;
	vector<FuturePlan*> planList;
	vector<FuturePlan*>historys;
	Console console;
public:
	Program();
	~Program();
	int MainMenu();
	void Run();
	void FrameAddRelationship();
	void FrameAddFuturePlan();
	void FrameOutPutList();
	void FrameLogin();
	void MoreInformation();
	int FrameStartPR();
	bool Login();
	bool Registration();
	vector<Relationship*>ListTmp();
	vector<FuturePlan*> PLTmp();
	void OutputList();
	void OutputDetail(int stt);
	void OutputHistory();
	int OutputTime(int stt);
	int MenuFooter(int stt);
	int MenuFooterHistory();
	void SearchRelationship(int stt);
	void SearchHistoryPlan(int stt);
	void AddRelationship();
	void DeleteRelationship(int stt);
	void AddFuturePlan();
	void DeleteFuturePlan(int plan);
	void ReadAccountList();
	void ReadRelatioshipList();
	void ReadPlanList();
	void ReadHistoryPlanList();
	void WriteRelationshipList();
	void WriteAccountList();
	void WritePlanList();
	void WriteHistoryPlanList();
	void DeleteContentFile(string file);
	void AddHistory();
	vector<FuturePlan*> FilterPlan();
	void Remind();
};

