#include "Program.h"

string idAc = "0";
string idPlan = "0";
//More Information
string name;
int dayOfBirth;
int monthOfBirth;
int yearOfBirth;
int sex;

Program::Program()
{
}

Program::~Program()
{
}

void Program::Run()
{
	ReadAccountList();
	ReadRelatioshipList();
	ReadPlanList();
	ReadHistoryPlanList();
	while (1)
	{
		bool check_id = false;
		do
		{
			this->console.clrscr();
			switch (FrameStartPR())
			{
			case '1':
			{
				this->console.clrscr();
				check_id = Login();
				if (check_id == false)
				{
					this->console.gotoXY(_LOGIN_X, LOGIN_Y + 5);
					cout << "Tai khoan hoac mat khau khong dung!!\n";
					Sleep(1500);
				}
				else
				{
					this->console.gotoXY(_LOGIN_X + 15, LOGIN_Y + 5);
					cout << "Dang nhap thanh cong!!!\n";
					Sleep(1500);
				}
			}
			break;
			case '2':
			{
				this->console.clrscr();
				bool check_ac = Registration();
				if (check_ac == false)
				{
					this->console.gotoXY(_REGISTRATION_X, REGISTRATION_Y + 5);
					cout << "Tai khoan da ton tai, moi ban dang ky lai!!!\n";
					Sleep(1500);
				}
				else
				{
					this->console.gotoXY(_MORE_INFORMATION_X + 21, MORE_INFORMATION_Y + 8);
					cout << "Dang ky thanh cong!\n";
					Sleep(1500);
				}
			}
			break;
			default:
				cout << "Khong co lua chon nay!\n";
				break;
			}
		} while (check_id == false);
		//
		while (1)
		{
			this->console.clrscr();
			this->console.cursorType();
			int mainMenu = MainMenu();
			switch (mainMenu)
			{
			case 1:
			{
				int continues1 = 1;
				do
				{
					this->console.clrscr();
					FrameAddRelationship();
					AddRelationship();
					cout << "\n\n\n* Ban co muon tiep tuc hay ko: ";
					cin >> continues1;
				} while (continues1 == 1);
			}
			break;
			case 2:
			{
				this->console.clrscr();
				FrameOutPutList();
				while (1)
				{
					this->console.noCursorType();
					OutputList();
					if (_kbhit())
					{
						int key = _getch();
						if (key == 8)
						{
							break;
						}
					}
					this->console.gotoXY(0, (ListTmp().size() * 2) + 3);
					cout << "* Nhan phim Back de thoat!!!\n";

				}
			}
			break;
			case 3:
			{
				this->console.clrscr();
				int stt;
				this->console.gotoXY(60, 12);
				while (1)
				{
					cout << "Vui long nhap so thu tu cua moi quan he: ";
					cin >> stt;
					if (ListTmp().size() == 0 || stt < 0 || stt > ListTmp().size() - 1)
					{
						this->console.gotoXY(60, 14);
						cout << "Khong co moi quan he nay trong danh sach!!!\n";
						while (1)
						{
							if (_kbhit())
							{
								int key = _getch();
								if (key == 8)
								{
									break;
								}
							}
							this->console.gotoXY(60, 16);
							cout << "\n\n\n* Nhan phim Back de thoat!!!\n";
						}
						break;
					}
					else
					{
						while (1)
						{
							this->console.clrscr();
							this->console.cursorType();
							SearchRelationship(stt);
							AddHistory();
							OutputTime(stt);
							OutputDetail(stt);
							int menuFooter = MenuFooter(stt);
							switch (menuFooter)
							{
							case 1:
							{
								this->console.clrscr();
								char choose;
								this->console.cursorType();
								cout << "Ban co chac chan muon xoa moi quan he nay? (Y/N): ";
								do
								{
									cin >> choose;
									if (choose != 'Y' && choose != 'y' && choose != 'N' && choose != 'n')
										cout << "* Nhap khong hop le, moi nhap lai (Y/N): ";
								} while (choose != 'Y' && choose != 'y' && choose != 'N' && choose != 'n');
								if (choose == 'Y' || choose == 'y')
								{
									DeleteRelationship(stt);
									menuFooter = 5;
								}
								else
									break;
							}
							break;
							case 2:
							{
								this->console.clrscr();
								this->console.cursorType();
								FrameAddFuturePlan();
								for (int i = 0; i < this->list.size(); i++)
								{
									if (i == stt)
									{
										AddFuturePlan();
									}
								}
							}
							break;
							case 3:
							{
								int sttplan;
								char choose;
								this->console.clrscr();
								this->console.cursorType();
								cout << "Nhap so thu tu cua ke hoach muon xoa: ";
								cin >> sttplan;
								if (PLTmp().size() == 0 || sttplan < 0 || sttplan > PLTmp().size() - 1)
								{
									this->console.clrscr();
									cout << "Khong co ke hoach nay trong danh sach!!!\n";
									while (1)
									{
										if (_kbhit())
										{
											int key = _getch();
											if (key == 8)
											{
												break;
											}
										}
										this->console.gotoXY(60, 16);
										cout << "\n\n\n* Nhan phim Back de thoat!!!\n";
									}
									break;
								}
								else
								{
									this->console.clrscr();
									cout << "Ban co chac chan muon xoa ke hoach co so thu tu la " << sttplan << " khong? (Y/N): ";
									do
									{
										cin >> choose;
										if (choose != 'Y' && choose != 'y' && choose != 'N' && choose != 'n')
											cout << "* Nhap khong hop le, moi nhap lai (Y/N): ";
									} while (choose != 'Y' && choose != 'y' && choose != 'N' && choose != 'n');
									if (choose == 'Y' || choose == 'y')
										DeleteFuturePlan(sttplan);
									else
										break;
									break;
								}
							}
							break;
							case 4:
							{
								while (1)
								{
									console.clrscr();
									int stt;
									OutputHistory();
									int menuFooterHistory = MenuFooterHistory();
									switch (menuFooterHistory)
									{
									case 1:
									{
										this->console.clrscr();
										cout << "Nhap so thu tu cua su kien muon xem chi tiet: ";
										cin >> stt;
										if (stt < 0 || stt >= FilterPlan().size())
										{
											cout << "Khong ton tai su kien nay!!!";
											while (1)
											{
												this->console.noCursorType();
												if (_kbhit())
												{
													int key = _getch();
													if (key == 8)
													{
														break;
													}
												}
												this->console.gotoXY(60, 4);
												cout << "\n\n\n* Nhan phim Back de thoat!!!\n";
											}
										}
										else
										{
											SearchHistoryPlan(stt);
											while (1)
											{
												this->console.noCursorType();
												if (_kbhit())
												{
													int key = _getch();
													if (key == 8)
													{
														break;
													}
												}
												this->console.gotoXY(60, 16);
												cout << "\n\n\n* Nhan phim Back de thoat!!!\n";
											}
										}
									}
									break;
									case 2:
									{
										break;
									}
									break;
									default:
										break;
									}
									if (menuFooterHistory == 2)
										break;
								}
							}
							break;
							case 5:
								break;
							default:
								cout << "Khong co lua chon nay!!!\n";
								break;
							}
							if (menuFooter == 5)
							{
								break;
							}
						}
						break;
					}
					break;
				}
			}
			break;
			case 4:
				break;
			default:
				cout << "Khong co chuc nang nay!\n";
				break;
			}
			if (mainMenu == 4)
			{
				ListTmp().clear();
				PLTmp().clear();
				break;
			}
		}
	}
}

int Program::MainMenu()
{
	this->console.gotoXY(50, 4);
	cout << "XIN CHAO " << name << "!!! Chuc ban ngay moi tot lanh :))";
	Remind();
	int choose;
	this->console.gotoXY(45, 6);
	cout << "============================= MAIN MENU =============================\n";
	this->console.gotoXY(45, 7);
	cout << "[                                                                   ]\n";
	this->console.gotoXY(45, 8);
	cout << "[    1. TAO MOI QUAN HE MOI                     : Nhan phim so 1    ]\n";
	this->console.gotoXY(45, 9);
	cout << "[                                                                   ]\n";
	this->console.gotoXY(45, 10);
	cout << "[    2. XEM DANH SACH CAC MOI QUAN HE           : Nhan phim so 2    ]\n";
	this->console.gotoXY(45, 11);
	cout << "[                                                                   ]\n";
	this->console.gotoXY(45, 12);
	cout << "[    3. XEM THONG TIN CHI TIET CUA MOI QUAN HE  : Nhan phim so 3    ]\n";
	this->console.gotoXY(45, 13);
	cout << "[                                                                   ]\n";
	this->console.gotoXY(45, 14);
	cout << "[    4. DANG XUAT                               : Nhan phim so 4    ]\n";
	this->console.gotoXY(45, 15);
	cout << "[                                                                   ]\n";
	this->console.gotoXY(45, 16);
	cout << "=====================================================================\n";
	this->console.gotoXY(45, 18);
	cout << "* Hay nhap lua chon cua ban: ";
	cin >> choose;
	return choose;
}

void Program::FrameAddRelationship()
{
	int x = 30;
	this->console.gotoXY(_FRAME_ADD_RELATIONSHIP_X, FRAME_ADD_RELATIONSHIP_Y);
	cout << "=====================================================BAN============VA=======DOI PHUONG=========\n";
	this->console.gotoXY(_FRAME_ADD_RELATIONSHIP_X, FRAME_ADD_RELATIONSHIP_Y + 1);
	cout << "HO TEN HOAC NICKNAME                  |                             |                          ]\n";
	this->console.gotoXY(_FRAME_ADD_RELATIONSHIP_X, FRAME_ADD_RELATIONSHIP_Y + 2);
	cout << "NGAY, THANG, NAM SINH                 |            /   /            |            /   /         ]\n";
	this->console.gotoXY(_FRAME_ADD_RELATIONSHIP_X, FRAME_ADD_RELATIONSHIP_Y + 3);
	cout << "GIOI TINH (1: NAM, 0: NU)             |                             |                          ]\n";
	this->console.gotoXY(_FRAME_ADD_RELATIONSHIP_X, FRAME_ADD_RELATIONSHIP_Y + 4);
	cout << "MOI QUAN HE MUON THIEP LAP            |                                                        ]\n";
	this->console.gotoXY(_FRAME_ADD_RELATIONSHIP_X, FRAME_ADD_RELATIONSHIP_Y + 5);
	cout << "NGAY BAT DAU(1: NHAP, 0: BO QUA)      |                           /   /                        ]\n";
	this->console.gotoXY(_FRAME_ADD_RELATIONSHIP_X, FRAME_ADD_RELATIONSHIP_Y + 6);
	cout << "THOI GIAN BAT DAU(1: NHAP, 0: BO QUA) |                             :                          ]\n";
	this->console.gotoXY(_FRAME_ADD_RELATIONSHIP_X, FRAME_ADD_RELATIONSHIP_Y + 7);
	cout << "================================================================================================\n";
}

void Program::FrameAddFuturePlan()
{
	this->console.gotoXY(_FRAME_ADD_FUTUREPLAN_X, FRAME_ADD_RELATIONSHIP_Y);
	cout << "========KE HOACH==================DIA DIEM===========================DIA CHI CU THE=======================================THOI GIAN===============\n";
	this->console.gotoXY(_FRAME_ADD_FUTUREPLAN_X, FRAME_ADD_RELATIONSHIP_Y + 1);
	cout << "[                       |                              |                                                        | NGAY:   /   /       GIO:   :   ]\n";
	this->console.gotoXY(_FRAME_ADD_FUTUREPLAN_X, FRAME_ADD_RELATIONSHIP_Y + 2);
	cout << "==================================================================================================================================================\n";
}

void Program::FrameOutPutList()
{
	int size = 2;
	if (ListTmp().size() != 0)
		size = (ListTmp().size() * 2) + 2;
	for (int i = 0; i <= size; i++)
	{
		if (i == 0)
		{
			/*this->console.gotoXY(x, y);*/
			cout << "=====STT=======MOI QUAN HE===============NGUOI THU 1===============PHAI===============NGUOI THU 2===============PHAI===============THOI GIAN DA TROI QUA=====\n";
		}
		else if (i == size)
		{
			/*this->console.gotoXY(x, i + y);*/
			cout << "=============================================================================================================================================================\n";
		}
		else
		{
			/*this->console.gotoXY(20, i + y);*/
			cout << "[          |                     |                         |                  |                         |                  |                                ]\n";
		}
	}
}

void Program::FrameLogin()
{
	this->console.gotoXY(_LOGIN_X, LOGIN_Y);
	cout << "========================DANG NHAP========================\n";
	this->console.gotoXY(_LOGIN_X, LOGIN_Y + 1);
	cout << "[  UserName        :                                    ]\n";
	this->console.gotoXY(_LOGIN_X, LOGIN_Y + 2);
	cout << "[  PassWord        :                                    ]\n";
	this->console.gotoXY(_LOGIN_X, LOGIN_Y + 3);
	cout << "=========================================================\n";
}

void Program::MoreInformation()
{
	this->console.gotoXY(_MORE_INFORMATION_X - 5, MORE_INFORMATION_Y);
	cout << "HAY NHAP THEM THONG TIN CUA BAN DE CHUNG TOI QUAN LY DE DANG HON NHE !\n";
	this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 2);
	cout << "============================================================\n";
	this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 3);
	cout << "[ HO TEN HOAC NICKNAME       :                             ]\n";
	this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 4);
	cout << "[ NGAY, THANG, NAM SINH      :            /   /            ]\n";
	this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 5);
	cout << "[ GIOI TINH (1: NAM, 0 NU)   :                             ]\n";
	this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 6);
	cout << "============================================================\n";
	this->console.gotoXY(_MORE_INFORMATION_X + 31, MORE_INFORMATION_Y + 3);
	cin.ignore();
	getline(cin, name);
	int dem = 0;
	string day, month, year, sexx;
	//daypfbirth
	do
	{
		dem = 0;
		this->console.gotoXY(_MORE_INFORMATION_X + 39, MORE_INFORMATION_Y + 4);
		cin >> day;
		for (int i = 0; i < day.length(); i++)
		{
			if (day[i] < 48 || day[i] >= 58)
			{
				this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 8);
				cout << "Nhap khong hop le, vui long nhap lai";
				break;
			}
			else
				dem++;
			if (dem == day.length())
			{
				if (atoi(day.c_str()) <= 0 || atoi(day.c_str()) > 31)
				{
					this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 8);
					cout << "Nhap khong hop le, vui long nhap lai";
				}
				else
					dayOfBirth = atoi(day.c_str());
			}
		}
	} while (dem < day.length() || atoi(day.c_str()) <= 0 || atoi(day.c_str()) > 31);
	this->console.gotoXY(_MORE_INFORMATION_X + 39, MORE_INFORMATION_Y + 4);
	if (dayOfBirth < 10)
		cout << "0" << dayOfBirth;
	this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 8);
	cout << "                                              ";//
	//monthofbirth
	do
	{
		dem = 0;
		this->console.gotoXY(_MORE_INFORMATION_X + 43, MORE_INFORMATION_Y + 4);
		cin >> month;
		for (int i = 0; i < month.length(); i++)
		{
			if (month[i] < 48 || month[i] >= 58)
			{
				this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 8);
				cout << "Nhap khong hop le, vui long nhap lai";
				break;
			}
			else
				dem++;
			if (dem == month.length())
			{
				if (atoi(month.c_str()) <= 0 || atoi(month.c_str()) > 12)
				{
					this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 8);
					cout << "Nhap khong hop le, vui long nhap lai";
				}
				else
					monthOfBirth = atoi(month.c_str());
			}
		}
	} while (dem < month.length() || atoi(month.c_str()) <= 0 || atoi(month.c_str()) > 12);
	this->console.gotoXY(_MORE_INFORMATION_X + 43, MORE_INFORMATION_Y + 4);
	if (monthOfBirth < 10)
		cout << "0" << monthOfBirth;
	this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 8);
	cout << "                                              ";//
	//year
	do
	{
		dem = 0;
		this->console.gotoXY(_MORE_INFORMATION_X + 47, MORE_INFORMATION_Y + 4);
		cin >> year;
		for (int i = 0; i < year.length(); i++)
		{
			if (year[i] < 48 || year[i] >= 58)
			{
				this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 8);
				cout << "Nhap khong hop le, vui long nhap lai";
				break;
			}
			else
				dem++;
			if (dem == year.length())
			{
				if (atoi(year.c_str()) <= 0)
				{
					this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 8);
					cout << "Nhap khong hop le, vui long nhap lai";
				}
				else
					yearOfBirth = atoi(year.c_str());
			}
		}
	} while (dem < year.length() || atoi(year.c_str()) <= 0);
	this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 8);
	cout << "                                              ";//
	//sex
	do
	{
		dem = 0;
		this->console.gotoXY(_MORE_INFORMATION_X + 31, MORE_INFORMATION_Y + 5);
		cin >> sexx;
		if (sexx != "0" && sexx != "1")
		{
			this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 8);
			cout << "Nhap khong hop le, vui long nhap lai";
		}
		else
			sex = atoi(sexx.c_str());
	} while (sexx != "0" && sexx != "1");
	this->console.gotoXY(_MORE_INFORMATION_X + 31, MORE_INFORMATION_Y + 5);
	if (sex == 1)
		cout << "Nam";
	else
		cout << "Nu";
	this->console.gotoXY(_MORE_INFORMATION_X, MORE_INFORMATION_Y + 8);
	cout << "                                              ";//
}

int Program::FrameStartPR()
{
	char choose = '1';
	do
	{
		this->console.clrscr();
		this->console.gotoXY(_FRAME_START_PR_X, FRAME_START_PR_Y + 10);
		if (choose != '1' && choose != '2')
		{
			this->console.changeColor(6);
			cout << "Nhap khong hop le, moi nhap lai!\n";
		}
		this->console.changeColor(15);
		this->console.gotoXY(_FRAME_START_PR_X - 15, FRAME_START_PR_Y);
		cout << "CHAO MUNG BAN DA DEN VOI CHUONG TRINH QUAN LY MOI QUAN HE CUA CHUNG TOI\n";
		this->console.gotoXY(_FRAME_START_PR_X, FRAME_START_PR_Y + 1);
		cout << " [vo tay, vo tay *bac, bac, bac*] =))\n";
		this->console.gotoXY(_FRAME_START_PR_X, FRAME_START_PR_Y + 3);
		cout << "=====================================\n";
		this->console.gotoXY(_FRAME_START_PR_X, FRAME_START_PR_Y + 4);
		cout << "[   DANG NHAP    : Nhan phim so 1   ]\n";
		this->console.gotoXY(_FRAME_START_PR_X, FRAME_START_PR_Y + 5);
		cout << "[   DANG KY      : Nhan phim so 2   ]\n";
		this->console.gotoXY(_FRAME_START_PR_X, FRAME_START_PR_Y + 6);
		cout << "=====================================\n";
		this->console.gotoXY(_FRAME_START_PR_X, FRAME_START_PR_Y + 8);
		cout << "* Nhap lua chon: ";
		cin >> choose;
	} while (choose != '1' && choose != '2');
	return choose;
}

bool Program::Login()
{
	string user;
	string pass;
	while (1)
	{
		FrameLogin();
		this->console.gotoXY(_LOGIN_X + 22, LOGIN_Y + 1);
		cin >> user;
		//Input Pass
		int key;
		this->console.gotoXY(_LOGIN_X + 22, LOGIN_Y + 2);
		while (1)
		{
			key = _getch();
			if (key != 13 && key != 8)
			{
				pass.push_back(key);
				cout << "*";
			}
			else if (key == 8)
			{
				if (pass.size() > 0)
				{
					pass.pop_back();
					console.clrscr();
					FrameLogin();
					this->console.gotoXY(_LOGIN_X + 22, LOGIN_Y + 1);
					cout << user;
					this->console.gotoXY(_LOGIN_X + 22, LOGIN_Y + 2);
					for (int i = 0; i < pass.size(); i++)
					{
						cout << "*";
					}
				}
			}
			else if (key == 13)
				break;
		}
		//
		int dem = 0;
		for (int i = 0; i < account.size(); i++)
		{
			if (account[i]->GetUserName() == user && account[i]->GetPassWord() == pass)
			{
				idAc = this->account[i]->GetID();
				name = this->account[i]->GetName();
				dayOfBirth = this->account[i]->GetDayOfBirth();
				monthOfBirth = this->account[i]->GetMonthOfBirth();
				yearOfBirth = this->account[i]->GetYearOfBirth();
				sex = this->account[i]->GetSex();
				return true;
			}
			else
				dem++;
		}
		if (dem == account.size())
			return false;
		break;
	}
}

bool Program::Registration()
{
	Account* ac = new Account;
	int dem = 0;
	while (1)
	{
		this->console.clrscr();
		ac->InPut(_REGISTRATION_X, REGISTRATION_Y);
		for (int i = 0; i < account.size(); i++)
		{
			if (account[i]->GetUserName() == ac->GetUserName())
			{
				return false;
			}
			else
				dem++;
		}
		if (dem == account.size())
		{
			MoreInformation();
			ac->SetName(name);
			ac->SetDayOfBirth(dayOfBirth);
			ac->SetMonthOfBirth(monthOfBirth);
			ac->SetYearOfBirth(yearOfBirth);
			ac->SetSex(sex);
			//
			account.push_back(ac);
			WriteAccountList();
			return true;
		}
	}
}

vector<Relationship*> Program::ListTmp()
{
	vector<Relationship*>tmp;
	for (int i = 0; i < this->list.size(); i++)
	{
		if (this->list[i]->GetIDLinkAccount() == idAc)
		{
			tmp.push_back(this->list[i]);
		}
	}
	return tmp;
}

vector<FuturePlan*> Program::PLTmp()
{
	vector<FuturePlan*>tmp;
	for (int i = 0; i < this->planList.size(); i++)
	{
		if (this->planList[i]->GetID() == idPlan)
			tmp.push_back(this->planList[i]);
	}
	return tmp;
}

void Program::OutputList()
{
	//
	int y = OUTPUT_LIST_Y;
	for (int i = 0; i < ListTmp().size(); i++)
	{
		this->console.gotoXY(_OUTPUT_LIST_X, y);
		cout << i << endl;
		this->console.gotoXY(_OUTPUT_LIST_X + 10, y);
		cout << ListTmp()[i]->GetNameOfRelationship();
		//Human1
		this->console.gotoXY(_OUTPUT_LIST_X + 36, y);
		cout << ListTmp()[i]->GetHuman1()->GetName() << endl;
		this->console.gotoXY(_OUTPUT_LIST_X + 62, y);
		if (ListTmp()[i]->GetHuman1()->GetSex() == 1)
			cout << "Nam";
		else
			cout << "Nu";
		//Human2
		this->console.gotoXY(_OUTPUT_LIST_X + 81, y);
		cout << ListTmp()[i]->GetHuman2()->GetName() << endl;
		this->console.gotoXY(_OUTPUT_LIST_X + 107, y);
		if (ListTmp()[i]->GetHuman2()->GetSex() == 1)
			cout << "Nam";
		else
			cout << "Nu";
		//Day
		time_t today = time(0);
		tm* ltm = localtime(&today);
		int day = ltm->tm_mday;
		int month = 1 + ltm->tm_mon;
		int year = 1900 + ltm->tm_year;
		this->console.gotoXY(_OUTPUT_LIST_X + 130, y);
		cout << ListTmp()[i]->GetStartTime()->CalculateTheDate(day, month, year) << " Ngay";
		y += 2;
	}
}

void Program::SearchRelationship(int stt)
{
	this->console.gotoXY(_SEARCH_RELATIONSHIP_X, SEARCH_RELATIONSHIP_Y);
	cout << "=====================================NGUOI THU 1=====================NGUOI THU 2============\n";
	this->console.gotoXY(_SEARCH_RELATIONSHIP_X, SEARCH_RELATIONSHIP_Y + 1);
	cout << "HO TEN HOAC NICKNAME       |                             |                                 ]\n";
	this->console.gotoXY(_SEARCH_RELATIONSHIP_X, SEARCH_RELATIONSHIP_Y + 2);
	cout << "NGAY, THANG, NAM SINH      |           /   /             |            /   /                ]\n";
	this->console.gotoXY(_SEARCH_RELATIONSHIP_X, SEARCH_RELATIONSHIP_Y + 3);
	cout << "GIOI TINH                  |                             |                                 ]\n";
	this->console.gotoXY(_SEARCH_RELATIONSHIP_X, SEARCH_RELATIONSHIP_Y + 4);
	cout << "MOI QUAN HE                |                                                               ]\n";
	this->console.gotoXY(_SEARCH_RELATIONSHIP_X, SEARCH_RELATIONSHIP_Y + 5);
	cout << "NGAY BAT DAU:              |                           /   /                               ]\n";
	this->console.gotoXY(_SEARCH_RELATIONSHIP_X, SEARCH_RELATIONSHIP_Y + 6);
	cout << "THOI GIAN BAT DAU          |                             :                                 ]\n";
	this->console.gotoXY(_SEARCH_RELATIONSHIP_X, SEARCH_RELATIONSHIP_Y + 7);
	cout << "============================================================================================\n";
	cout << endl;
	for (int i = 0; i < ListTmp().size(); i++)
	{
		if (i == stt)
		{
			idPlan = ListTmp()[i]->GetIDLinkPlan();
			ListTmp()[i]->GetHuman1()->OutPut(_OUTPUT_SEARCH_RELATIONSHIP_X, OUTPUT_SEARCH_RELATIONSHIP_Y);
			ListTmp()[i]->GetHuman2()->OutPut(_OUTPUT_SEARCH_RELATIONSHIP_X + 30, OUTPUT_SEARCH_RELATIONSHIP_Y);
		}

		this->console.gotoXY(_OUTPUT_SEARCH_RELATIONSHIP_X + 24, OUTPUT_SEARCH_RELATIONSHIP_Y + 3);
		cout << ListTmp()[i]->GetNameOfRelationship();
		//Day
		this->console.gotoXY(_OUTPUT_SEARCH_RELATIONSHIP_X + 22, OUTPUT_SEARCH_RELATIONSHIP_Y + 4);
		if (this->ListTmp()[i]->GetStartTime()->GetDay() < 10)
			cout << "0" << ListTmp()[i]->GetStartTime()->GetDay();
		else
			cout << ListTmp()[i]->GetStartTime()->GetDay();
		//Month
		this->console.gotoXY(_OUTPUT_SEARCH_RELATIONSHIP_X + 26, OUTPUT_SEARCH_RELATIONSHIP_Y + 4);
		if (ListTmp()[i]->GetStartTime()->GetMonth() < 10)
			cout << "0" << ListTmp()[i]->GetStartTime()->GetMonth();
		else
			cout << ListTmp()[i]->GetStartTime()->GetMonth();
		//Year
		this->console.gotoXY(_OUTPUT_SEARCH_RELATIONSHIP_X + 30, OUTPUT_SEARCH_RELATIONSHIP_Y + 4);
		cout << ListTmp()[i]->GetStartTime()->GetYear();
		//Hours
		this->console.gotoXY(_OUTPUT_SEARCH_RELATIONSHIP_X + 25, OUTPUT_SEARCH_RELATIONSHIP_Y + 5);
		if (ListTmp()[i]->GetStartTime()->GetHours() < 10)
			cout << "0" << ListTmp()[i]->GetStartTime()->GetHours();
		else
			cout << ListTmp()[i]->GetStartTime()->GetHours();
		//Minute
		this->console.gotoXY(_OUTPUT_SEARCH_RELATIONSHIP_X + 28, OUTPUT_SEARCH_RELATIONSHIP_Y + 5);
		if (ListTmp()[i]->GetStartTime()->GetMinute() < 10)
			cout << "0" << ListTmp()[i]->GetStartTime()->GetMinute();
		else
			cout << ListTmp()[i]->GetStartTime()->GetMinute();
	}
}


void Program::SearchHistoryPlan(int stt)
{
	//
	vector<Relationship*> re = ListTmp();
	string describe;
	for (int i = 0; i < re.size(); i++)
	{
		console.clrscr();
		this->console.cursorType();
		int x = 50;
		int y = 10;
		this->console.gotoXY(x, y);
		cout << FilterPlan()[stt]->GetOrderCalendar()->GetDay();
		cout << "/" << FilterPlan()[stt]->GetOrderCalendar()->GetMonth();
		cout << "/" << FilterPlan()[stt]->GetOrderCalendar()->GetYear();
		cout << "  " << FilterPlan()[stt]->GetOrderCalendar()->GetHours();
		cout << ":" << FilterPlan()[stt]->GetOrderCalendar()->GetMinute() << endl;
		this->console.gotoXY(x, y + 1);
		cout << "Hom nay, qua la mot ngay tuyet voi!!!\n";
		//
		if (FilterPlan()[stt]->GetID() == re[i]->GetIDLinkPlan())
		{
			console.gotoXY(x, y + 3);
			cout << "Ban va " << re[i]->GetHuman2()->GetName();
			cout << " da " << FilterPlan()[stt]->GetNamePlan() << " cung nhau o ";
			cout << FilterPlan()[stt]->GetWhere();
		}
		//
		if (FilterPlan()[stt]->GetDescribe().size() == 0)
		{
			console.gotoXY(x, y + 5);
			cout << "Hay viet vai dong cam nhan o day de chung minh do la mot ngay tuyet voi giua 2 ban nhe: " << endl;
			console.gotoXY(x, y + 6);
			cin.ignore();
			getline(cin, describe);
			FilterPlan()[stt]->GetDescribe().clear();
			FilterPlan()[stt]->SetDescribe(describe);
			WriteHistoryPlanList();
			i = i - 1;
			continue;
		}
		else
		{
			int dem = 0;
			string tmp = FilterPlan()[stt]->GetDescribe();
			console.gotoXY(x, y + 5);
			int yy = y + 6;
			cout << "Dong cam xuc: ";
			for (int i = 0; i < FilterPlan()[stt]->GetDescribe().size(); i++)
			{
				if (tmp[i] == ' ')
					dem++;
				if (dem == 20)
				{
					cout << tmp[i];
					yy++;
					dem = 0;
					x = 50;
				}
				else
				{
					console.gotoXY(x, yy);
					cout << tmp[i];
					x++;
				}
			}
			//
			break;
		}
	}
}

void Program::OutputDetail(int stt)
{
	int size = 2;
	if (PLTmp().size() != 0)
		size = (PLTmp().size() * 2) + 2;
	for (int i = 0; i <= size; i++)
	{
		if (i == 0)
		{
			this->console.gotoXY(0, SEARCH_RELATIONSHIP_Y + 14);
			cout << "=====STT=============KE HOACH==================DIA DIEM===========================DIA CHI CU THE=======================================THOI GIAN===============\n";
		}
		else if (i == size)
		{
			cout << "===============================================================================================================================================================\n";
		}
		else
		{
			cout << "[            |                       |                              |                                                        |                                ]\n";
		}
	}
	int y = OUTPUT_DEATAIL_Y + 4;

	for (int i = 0; i < PLTmp().size(); i++)
	{
		this->console.gotoXY(0, y);
		cout << "[            |                       |                              |                                                        | NGAY:   /  /        GIO:   :   ]\n";
		this->console.gotoXY(_OUTPUT_DEATAIL_X, y);
		cout << i << endl;
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 10, y);
		cout << PLTmp()[i]->GetNamePlan();
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 34, y);
		cout << PLTmp()[i]->GetWhere() << endl;
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 65, y);
		cout << PLTmp()[i]->GetAddress() << endl;
		//Day
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 128, y);
		if (PLTmp()[i]->GetOrderCalendar()->GetDay() < 10)
			cout << "0" << PLTmp()[i]->GetOrderCalendar()->GetDay();
		else
			cout << PLTmp()[i]->GetOrderCalendar()->GetDay() << endl;
		//Month
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 131, y);
		if (PLTmp()[i]->GetOrderCalendar()->GetMonth() < 10)
			cout << "0" << PLTmp()[i]->GetOrderCalendar()->GetMonth() << endl;
		else
			cout << PLTmp()[i]->GetOrderCalendar()->GetMonth() << endl;
		//Year
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 134, y);
		cout << PLTmp()[i]->GetOrderCalendar()->GetYear() << endl;
		//Hours
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 147, y);
		if (PLTmp()[i]->GetOrderCalendar()->GetHours() < 10)
			cout << "0" << PLTmp()[i]->GetOrderCalendar()->GetHours() << endl;
		else
			cout << PLTmp()[i]->GetOrderCalendar()->GetHours() << endl;
		//Minute
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 150, y);
		if (PLTmp()[i]->GetOrderCalendar()->GetMinute() < 10)
			cout << "0" << PLTmp()[i]->GetOrderCalendar()->GetMinute() << endl;
		else
			cout << PLTmp()[i]->GetOrderCalendar()->GetMinute() << endl;
		y += 2;
	}
}

void Program::OutputHistory()
{
	int size = 2;
	if (FilterPlan().size() != 0)
		size = (FilterPlan().size() * 2) + 2;
	this->console.gotoXY(70, SEARCH_RELATIONSHIP_Y - 2);
	cout << "LICH SU CAC SU KIEN DA DIEN RA";
	for (int i = 0; i <= size; i++)
	{
		if (i == 0)
		{
			this->console.gotoXY(0, SEARCH_RELATIONSHIP_Y);
			cout << "=====STT=============KE HOACH==================DIA DIEM===========================DIA CHI CU THE=======================================THOI GIAN===============\n";
		}
		else if (i == size)
		{
			cout << "===============================================================================================================================================================\n";
		}
		else
		{
			cout << "[            |                       |                              |                                                        |                                ]\n";
		}
	}
	int y = OUTPUT_DEATAIL_Y - 10;

	for (int i = 0; i < FilterPlan().size(); i++)
	{
		this->console.gotoXY(0, y);
		cout << "[            |                       |                              |                                                        | NGAY:   /  /        GIO:   :   ]\n";
		this->console.gotoXY(_OUTPUT_DEATAIL_X, y);
		cout << i << endl;
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 10, y);
		cout << FilterPlan()[i]->GetNamePlan();
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 34, y);
		cout << FilterPlan()[i]->GetWhere() << endl;
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 65, y);
		cout << FilterPlan()[i]->GetAddress() << endl;
		//Day
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 128, y);
		if (FilterPlan()[i]->GetOrderCalendar()->GetDay() < 10)
			cout << "0" << FilterPlan()[i]->GetOrderCalendar()->GetDay();
		else
			cout << FilterPlan()[i]->GetOrderCalendar()->GetDay() << endl;
		//Month
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 131, y);
		if (FilterPlan()[i]->GetOrderCalendar()->GetMonth() < 10)
			cout << "0" << FilterPlan()[i]->GetOrderCalendar()->GetMonth() << endl;
		else
			cout << FilterPlan()[i]->GetOrderCalendar()->GetMonth() << endl;
		//Year
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 134, y);
		cout << FilterPlan()[i]->GetOrderCalendar()->GetYear() << endl;
		//Hours
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 147, y);
		if (FilterPlan()[i]->GetOrderCalendar()->GetHours() < 10)
			cout << "0" << FilterPlan()[i]->GetOrderCalendar()->GetHours() << endl;
		else
			cout << FilterPlan()[i]->GetOrderCalendar()->GetHours() << endl;
		//Minute
		this->console.gotoXY(_OUTPUT_DEATAIL_X + 150, y);
		if (FilterPlan()[i]->GetOrderCalendar()->GetMinute() < 10)
			cout << "0" << FilterPlan()[i]->GetOrderCalendar()->GetMinute() << endl;
		else
			cout << FilterPlan()[i]->GetOrderCalendar()->GetMinute() << endl;
		y += 2;
	}
}

int Program::OutputTime(int stt)
{
	int back;
	this->console.noCursorType();
	time_t today = time(0);
	tm* ltm = localtime(&today);
	int day = ltm->tm_mday;
	int month = 1 + ltm->tm_mon;
	int year = 1900 + ltm->tm_year;
	int y = OUTPUT_TIME_Y;
	//
	this->console.gotoXY(_OUTPUT_SEARCH_RELATIONSHIP_X - 4, OUTPUT_SEARCH_RELATIONSHIP_Y + 8);
	cout << "Moi quan he cua ban va " << ListTmp()[stt]->GetHuman2()->GetName() << " da keo dai duoc: \n";
	this->console.gotoXY(_OUTPUT_SEARCH_RELATIONSHIP_X - 29, OUTPUT_SEARCH_RELATIONSHIP_Y + 9);
	cout << ListTmp()[stt]->GetStartTime()->CalculateTheYear(day, month, year) << " Nam";
	cout << " <=> " << ListTmp()[stt]->GetStartTime()->CalculateTheMonth(day, month, year) << " Thang";
	cout << " <=> " << ListTmp()[stt]->GetStartTime()->CalculateTheWeeks(day, month, year) << " Tuan";
	cout << " <=> " << ListTmp()[stt]->GetStartTime()->CalculateTheDate(day, month, year) << " Ngay";
	cout << " <=> " << ListTmp()[stt]->GetStartTime()->CalculateTheHours(day, month, year) << " Gio";
	cout << " <=> " << ListTmp()[stt]->GetStartTime()->CalculateTheMinute(day, month, year) << " Phut";
	cout << " <=> " << ListTmp()[stt]->GetStartTime()->CalculateTheSeconds(day, month, year) << " Giay " << endl;
	this->console.gotoXY(_OUTPUT_SEARCH_RELATIONSHIP_X - 9, OUTPUT_SEARCH_RELATIONSHIP_Y + 10);
	cout << "(Du lieu chung toi se cap nhat hang ngay cho ban!!!)" << endl;
	this->console.gotoXY(_OUTPUT_SEARCH_RELATIONSHIP_X - 9, OUTPUT_SEARCH_RELATIONSHIP_Y + 11);
	cout << "Chung toi xin chuc 2 ban se mai la " << ListTmp()[stt]->GetNameOfRelationship() << " cua nhau nhe!!!" << endl;
	return 0;
}

int Program::MenuFooter(int stt)
{
	int choose;
	int size = 2;
	if (ListTmp().size() != 0)
		size = (ListTmp().size() * 2) + 2;
	int x = 5;
	int y = SEARCH_RELATIONSHIP_Y + size + 17;
	this->console.gotoXY(x, y);
	cout << "=======================================================================================================================================================\n";
	this->console.gotoXY(x, y + 1);
	cout << "[ XOA MOI QUAN HE HAY: Nhan phim 1  | THEM KE HOACH: Nhan phim 2  | XOA KE HOACH: Nhan phim 3  | LICH SU SU KIEN: Nhan phim so 4 | THOAT: Nhan phim 5 ]\n";
	this->console.gotoXY(x, y + 2);
	cout << "=======================================================================================================================================================\n";
	this->console.gotoXY(x, y + 4);
	cout << "* Nhap lua chon: ";
	cin >> choose;
	return choose;
}

int Program::MenuFooterHistory()
{
	int choose;
	int size = 2;
	if (this->historys.size() != 0)
		size = (this->historys.size() * 2) + 2;
	int x = 50;
	int y = SEARCH_RELATIONSHIP_Y + size + 2;
	this->console.gotoXY(x, y);
	cout << "=====================================================\n";
	this->console.gotoXY(x, y + 1);
	cout << "[ XEM CHI TIET: Nhan phim so 1 | THOAT: Nhan phim 2 ]\n";
	this->console.gotoXY(x, y + 2);
	cout << "=====================================================\n";
	this->console.gotoXY(x, y + 4);
	cout << "* Nhap lua chon: ";
	cin >> choose;
	return choose;
}

void Program::AddRelationship()
{
	Relationship* rlts = new Relationship;
	rlts->SetHuman1(name, dayOfBirth, monthOfBirth, yearOfBirth, sex);
	rlts->Input();
	rlts->SetIDLinkAccount(idAc);
	list.push_back(rlts);
	WriteRelationshipList();
}

void Program::DeleteRelationship(int stt)
{
	for (int i = 0; i < this->list.size(); i++)
	{
		if (this->list[i]->GetIDLinkAccount() == idAc && (this->list[i]->GetNameOfRelationship() == ListTmp()[stt]->GetNameOfRelationship()))
			list.erase(list.begin() + i);
	}
	WriteRelationshipList();
}

void Program::AddFuturePlan()
{
	FuturePlan* Fp = new FuturePlan;
	Fp->Input();
	Fp->SetID(idPlan);
	this->planList.push_back(Fp);
	WritePlanList();
}

void Program::DeleteFuturePlan(int stt)
{
	for (int i = 0; i < planList.size(); i++)
	{
		if (planList[i]->GetID() == idPlan && planList[i]->GetNamePlan() == PLTmp()[stt]->GetNamePlan()
			&& planList[i]->GetOrderCalendar() == PLTmp()[stt]->GetOrderCalendar())
			planList.erase(planList.begin() + i);
	}
	WritePlanList();
}

void Program::ReadAccountList()
{
	ifstream infile;
	infile.open("AccountList.txt");
	string data_str;
	infile >> data_str;
	if (data_str == "")
		infile.close();
	else
	{
		infile.close();
		infile.open("AccountList.txt");
		Account* ac_tmp = new Account;
		int dem = 0;
		while (!infile.eof() && getline(infile, data_str))
		{
			dem++;
			if (dem == 1)
			{
				//ID
				ac_tmp->SetID(data_str);
			}
			else if (dem == 2)
			{
				//UserName
				ac_tmp->SetUserName(data_str);
			}
			else if (dem == 3)
			{
				//Pass
				ac_tmp->SetPassWord(data_str);
			}
			else if (dem == 4)
			{
				//Name
				ac_tmp->SetName(data_str);
			}
			else if (dem == 5)
			{
				//DayOfBirth
				ac_tmp->SetDayOfBirth(atoi(data_str.c_str()));
			}
			else if (dem == 6)
			{
				//MonthOfBirth
				ac_tmp->SetMonthOfBirth(atoi(data_str.c_str()));
			}
			else if (dem == 7)
			{
				//YearOfBirth
				ac_tmp->SetYearOfBirth(atoi(data_str.c_str()));
			}
			else if (dem == 8)
			{
				//Sex
				ac_tmp->SetSex(atoi(data_str.c_str()));
				this->account.push_back(ac_tmp);
				dem = 0;
				ac_tmp = new Account;
			}
		}
		infile.close();
	}
}

void Program::ReadRelatioshipList()
{
	ifstream infile;
	infile.open("RelationshipList.txt");
	string data_str;
	int dem = 0;
	infile >> data_str;
	if (data_str == "")
		infile.close();
	else
	{
		infile.close();
		infile.open("RelationshipList.txt");
		Relationship* rlts_tmp = new Relationship;
		while (!infile.eof() && getline(infile, data_str))
		{
			dem++;
			if (dem == 1)
			{
				//ID_Link_Account
				rlts_tmp->SetIDLinkAccount(data_str);
			}
			else if (dem == 2)
			{
				//ID_Link_Plan
				rlts_tmp->SetIDLinkPlan(data_str);
			}
			//Human1
			else if (dem == 3)
			{
				rlts_tmp->GetHuman1()->SetName(data_str);
			}
			else if (dem == 4)
			{
				rlts_tmp->GetHuman1()->SetDayOfBirth(atoi(data_str.c_str()));
			}
			else if (dem == 5)
			{
				rlts_tmp->GetHuman1()->SetMonthOfBirth(atoi(data_str.c_str()));
			}
			else if (dem == 6)
			{
				rlts_tmp->GetHuman1()->SetYearOfBirth(atoi(data_str.c_str()));
			}
			else if (dem == 7)
			{
				rlts_tmp->GetHuman1()->SetSex(atoi(data_str.c_str()));
			}
			//Human2
			else if (dem == 8)
			{
				rlts_tmp->GetHuman2()->SetName(data_str);
			}
			else if (dem == 9)
			{
				rlts_tmp->GetHuman2()->SetDayOfBirth(atoi(data_str.c_str()));
			}
			else if (dem == 10)
			{
				rlts_tmp->GetHuman2()->SetMonthOfBirth(atoi(data_str.c_str()));
			}
			else if (dem == 11)
			{
				rlts_tmp->GetHuman2()->SetYearOfBirth(atoi(data_str.c_str()));
			}
			else if (dem == 12)
			{
				rlts_tmp->GetHuman2()->SetSex(atoi(data_str.c_str()));
			}
			else if (dem == 13)
			{
				//Relatioship
				rlts_tmp->SetNameOfRelationship(data_str);
			}
			//Time
			else if (dem == 14)
			{
				rlts_tmp->GetStartTime()->SetDay(atoi(data_str.c_str()));
			}
			else if (dem == 15)
			{
				rlts_tmp->GetStartTime()->SetMonth(atoi(data_str.c_str()));
			}
			else if (dem == 16)
			{
				rlts_tmp->GetStartTime()->SetYear(atoi(data_str.c_str()));
			}
			else if (dem == 17)
			{
				rlts_tmp->GetStartTime()->SetHours(atoi(data_str.c_str()));
			}
			else if (dem == 18)
			{
				rlts_tmp->GetStartTime()->SetMinute(atoi(data_str.c_str()));
				this->list.push_back(rlts_tmp);
				dem = 0;
				rlts_tmp = new Relationship;
			}
		}
		infile.close();
	}
}

void Program::ReadPlanList()
{
	ifstream infile;
	infile.open("PlanList.txt");
	string data_str;
	infile >> data_str;
	if (data_str == "")
		infile.close();
	else
	{
		infile.close();
		infile.open("PlanList.txt");
		FuturePlan* pl_tmp = new FuturePlan;
		int dem = 0;
		while (!infile.eof() && getline(infile, data_str))
		{
			dem++;
			if (dem == 1)
			{
				//ID_Link_Account
				pl_tmp->SetID(data_str);
			}
			//
			else if (dem == 2)
			{
				pl_tmp->SetNamePlan(data_str);
			}
			else if (dem == 3)
			{
				pl_tmp->SetWhere(data_str);
			}
			else if (dem == 4)
			{
				pl_tmp->SetAddress(data_str);
			}
			//Time
			else if (dem == 5)
			{
				pl_tmp->GetOrderCalendar()->SetDay(atoi(data_str.c_str()));
			}
			else if (dem == 6)
			{
				pl_tmp->GetOrderCalendar()->SetMonth(atoi(data_str.c_str()));
			}
			else if (dem == 7)
			{
				pl_tmp->GetOrderCalendar()->SetYear(atoi(data_str.c_str()));
			}
			else if (dem == 8)
			{
				pl_tmp->GetOrderCalendar()->SetHours(atoi(data_str.c_str()));
			}
			else if (dem == 9)
			{
				pl_tmp->GetOrderCalendar()->SetMinute(atoi(data_str.c_str()));
				this->planList.push_back(pl_tmp);
				pl_tmp = new FuturePlan;
				dem = 0;
			}
		}
		infile.close();
	}
}

void Program::ReadHistoryPlanList()
{
	ifstream infile;
	infile.open("HistoryPlanList.txt");
	string data_str;
	infile >> data_str;
	if (data_str == "")
		infile.close();
	else
	{
		infile.close();
		infile.open("HistoryPlanList.txt");
		FuturePlan* history = new FuturePlan;
		int dem = 0;
		while (!infile.eof() && getline(infile, data_str))
		{
			dem++;
			if (dem == 1)
			{
				//ID_Link_Account
				history->SetID(data_str);
			}
			//
			else if (dem == 2)
			{
				history->SetNamePlan(data_str);
			}
			else if (dem == 3)
			{
				history->SetWhere(data_str);
			}
			else if (dem == 4)
			{
				history->SetAddress(data_str);
			}
			//Time
			else if (dem == 5)
			{
				history->GetOrderCalendar()->SetDay(atoi(data_str.c_str()));
			}
			else if (dem == 6)
			{
				history->GetOrderCalendar()->SetMonth(atoi(data_str.c_str()));
			}
			else if (dem == 7)
			{
				history->GetOrderCalendar()->SetYear(atoi(data_str.c_str()));
			}
			else if (dem == 8)
			{
				history->GetOrderCalendar()->SetHours(atoi(data_str.c_str()));
			}
			else if (dem == 9)
			{
				history->GetOrderCalendar()->SetMinute(atoi(data_str.c_str()));
			}
			else if (dem == 10)
			{
				history->SetDescribe(data_str);
				this->historys.push_back(history);
				history = new FuturePlan;
				dem = 0;
			}
		}
		infile.close();
	}
}

void Program::WriteRelationshipList()
{
	DeleteContentFile("RelationshipList.txt");
	ofstream outfile;
	outfile.open("RelationshipList.txt", ios::app);
	for (int i = 0; i < this->list.size(); i++)
	{
		//ID
		outfile << this->list[i]->GetIDLinkAccount() << "\n";
		outfile << this->list[i]->GetIDLinkPlan() << "\n";
		//Human1
		outfile << this->list[i]->GetHuman1()->GetName() << "\n";
		outfile << this->list[i]->GetHuman1()->GetDayOfBirth() << "\n";
		outfile << this->list[i]->GetHuman1()->GetMonthOfBirth() << "\n";
		outfile << this->list[i]->GetHuman1()->GetYearOfBirth() << "\n";
		outfile << this->list[i]->GetHuman1()->GetSex() << "\n";
		//Human2
		outfile << this->list[i]->GetHuman2()->GetName() << "\n";
		outfile << this->list[i]->GetHuman2()->GetDayOfBirth() << "\n";
		outfile << this->list[i]->GetHuman2()->GetMonthOfBirth() << "\n";
		outfile << this->list[i]->GetHuman2()->GetYearOfBirth() << "\n";
		outfile << this->list[i]->GetHuman2()->GetSex() << "\n";
		//Relationship
		outfile << this->list[i]->GetNameOfRelationship() << "\n";
		//Time
		outfile << this->list[i]->GetStartTime()->GetDay() << "\n";
		outfile << this->list[i]->GetStartTime()->GetMonth() << "\n";
		outfile << this->list[i]->GetStartTime()->GetYear() << "\n";
		outfile << this->list[i]->GetStartTime()->GetHours() << "\n";
		outfile << this->list[i]->GetStartTime()->GetMinute() << "\n";
	}
	outfile.close();
}


void Program::WriteAccountList()
{
	DeleteContentFile("AccountList.txt");
	ofstream outfile;
	outfile.open("AccountList.txt", ios::app);
	for (int i = 0; i < this->account.size(); i++)
	{
		//ID
		outfile << this->account[i]->GetID() << "\n";
		//UserName
		outfile << this->account[i]->GetUserName() << "\n";
		//Pass
		outfile << this->account[i]->GetPassWord() << "\n";
		//Name
		outfile << this->account[i]->GetName() << "\n";
		//DayOfBirth
		outfile << this->account[i]->GetDayOfBirth() << "\n";
		//MonthOfBirth
		outfile << this->account[i]->GetMonthOfBirth() << "\n";
		//YearOfBirth
		outfile << this->account[i]->GetYearOfBirth() << "\n";
		//Sex
		outfile << this->account[i]->GetSex() << "\n";
	}
	outfile.close();
}

void Program::WritePlanList()
{
	DeleteContentFile("PlanList.txt");
	ofstream outfile;
	outfile.open("PlanList.txt", ios::out);
	for (int i = 0; i < this->planList.size(); i++)
	{
		outfile << this->planList[i]->GetID() << "\n";
		outfile << this->planList[i]->GetNamePlan() << "\n";
		outfile << this->planList[i]->GetWhere() << "\n";
		outfile << this->planList[i]->GetAddress() << "\n";
		outfile << this->planList[i]->GetOrderCalendar()->GetDay() << "\n";
		outfile << this->planList[i]->GetOrderCalendar()->GetMonth() << "\n";
		outfile << this->planList[i]->GetOrderCalendar()->GetYear() << "\n";
		outfile << this->planList[i]->GetOrderCalendar()->GetHours() << "\n";
		outfile << this->planList[i]->GetOrderCalendar()->GetMinute() << "\n";
	}
	outfile.close();
}

void Program::WriteHistoryPlanList()
{
	DeleteContentFile("HistoryPlanList.txt");
	ofstream outfile;
	outfile.open("HistoryPlanList.txt", ios::out);
	for (int i = 0; i < this->historys.size(); i++)
	{
		outfile << this->historys[i]->GetID() << "\n";
		outfile << this->historys[i]->GetNamePlan() << "\n";
		outfile << this->historys[i]->GetWhere() << "\n";
		outfile << this->historys[i]->GetAddress() << "\n";
		outfile << this->historys[i]->GetOrderCalendar()->GetDay() << "\n";
		outfile << this->historys[i]->GetOrderCalendar()->GetMonth() << "\n";
		outfile << this->historys[i]->GetOrderCalendar()->GetYear() << "\n";
		outfile << this->historys[i]->GetOrderCalendar()->GetHours() << "\n";
		outfile << this->historys[i]->GetOrderCalendar()->GetMinute() << "\n";
		outfile << this->historys[i]->GetDescribe() << "\n";
	}
	outfile.close();
}

void Program::DeleteContentFile(string file)
{
	ofstream outfile;
	outfile.open(file, ios::out);
	outfile.close();
}

void Program::AddHistory()
{
	time_t today = time(0);
	tm* ltm = localtime(&today);
	int day = ltm->tm_mday;
	int month = 1 + ltm->tm_mon;
	int year = 1900 + ltm->tm_year;
	int hours = ltm->tm_hour;
	int minutes = 1 + ltm->tm_min;
	vector<FuturePlan*>fp = this->planList;
	this->planList.clear();
	for (int i = 0; i < fp.size(); i++)
	{
		if (day == fp[i]->GetOrderCalendar()->GetDay() &&
			month == fp[i]->GetOrderCalendar()->GetMonth() &&
			year == fp[i]->GetOrderCalendar()->GetYear())
		{
			if (hours > fp[i]->GetOrderCalendar()->GetHours())
			{
				this->historys.push_back(fp[i]);
				fp.erase(fp.begin() + i);
				i = 0;
			}
			else if (hours == fp[i]->GetOrderCalendar()->GetHours())
			{
				if (minutes > fp[i]->GetOrderCalendar()->GetMinute())
				{
					this->historys.push_back(fp[i]);
					fp.erase(fp.begin() + i);
					i = 0;
				}
			}
		}
		else if (day > fp[i]->GetOrderCalendar()->GetDay() &&
			month == fp[i]->GetOrderCalendar()->GetMonth() &&
			year == fp[i]->GetOrderCalendar()->GetYear())
		{
			this->historys.push_back(fp[i]);
			fp.erase(fp.begin() + i);
			i = 0;
		}
		else if (month > fp[i]->GetOrderCalendar()->GetMonth() &&
			year == fp[i]->GetOrderCalendar()->GetYear())
		{
			this->historys.push_back(fp[i]);
			fp.erase(fp.begin() + i);
			i = 0;
		}
		else if (year > fp[i]->GetOrderCalendar()->GetYear())
		{
			this->historys.push_back(fp[i]);
			fp.erase(fp.begin() + i);
			i = 0;
		}
	}
	this->planList = fp;
	WriteHistoryPlanList();
	WritePlanList();
}

vector<FuturePlan*> Program::FilterPlan()
{
	time_t today = time(0);
	tm* ltm = localtime(&today);
	int day = ltm->tm_mday;
	int month = 1 + ltm->tm_mon;
	int year = 1900 + ltm->tm_year;
	int hours = ltm->tm_hour;
	int minutes = 1 + ltm->tm_min;
	vector<FuturePlan*>htr = this->historys;
	vector<FuturePlan*>tmp;
	for (int i = 0; i < htr.size(); i++)
	{
		if (htr[i]->GetID() == idPlan)
			tmp.push_back(htr[i]);
	}
	WriteHistoryPlanList();
	return tmp;
}

void Program::Remind()
{
	vector<Relationship*> re = ListTmp();
	vector<FuturePlan*> fp = this->planList;
	int x = 45;
	int y = 22;
	console.gotoXY(x + 25, y);
	cout << "NHAC NHO BAN NE !!!";
	for (int i = 0; i < fp.size(); i++)
	{
		if (fp[i]->Remind() == true)
		{
			for (int j = 0; j < re.size(); j++)
			{
				if (fp[i]->GetID() == re[j]->GetIDLinkPlan())
				{
					console.gotoXY(x - 10, y + 2);
					cout << "-> Dung quen, ban va " << re[j]->GetHuman2()->GetName();
					cout << " co lich hen " << fp[i]->GetNamePlan() << " cung nhau o ";
					cout << fp[i]->GetWhere();
					cout << " vao " << fp[i]->GetOrderCalendar()->GetDay() << "/";
					cout << fp[i]->GetOrderCalendar()->GetMonth() << "/";
					cout << fp[i]->GetOrderCalendar()->GetYear() << "  ";
					cout << fp[i]->GetOrderCalendar()->GetHours() << ":";
					cout << fp[i]->GetOrderCalendar()->GetMinute() << " nhe!!!";
					y++;
				}
			}
		}
	}
}
