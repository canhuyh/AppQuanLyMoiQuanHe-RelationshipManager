//
//  Kmin.cpp
//  LCNNLT_Buoi12_ClassSnake
//
//  Created by Bao Vu on 8/24/18.
//  Copyright © 2018 kmin. All rights reserved.
//

#include "Kmin.hpp"
int km::Console::MAX_WIDTH = 120;
int km::Console::MIN_WIDTH = 20;
int km::Console::MAX_HEIGHT = 40;
int km::Console::MIN_HEIGHT = 10;

// Khởi tạo mặc định
km::Console::Console()
{
	width = 120;
	height = 30;
	textWidth = 11;
	textHeight = textWidth * 2;
	changeWindowSize(width, height);
}

// Khởi tạo có tham số
// Tham số: chiều rộng console, chiều cao console
km::Console::Console(int width, int height)
{
	this->width = width;
	this->height = height;
	changeWindowSize(width, height);
}

// Khởi tạo có tham số
// Tham số: chiều rộng console, chiều cao console, kích thước text
km::Console::Console(int width, int height, int textSize)
{
	this->width = width;
	this->height = height;
	this->textWidth = textSize;
	changeTextSize(textSize);
	changeWindowSize(width, height);
}

// Thay đổi chiều rộng của console
// Tham số: chiều rộng
void km::Console::setWidth(int width)
{
	if (width < MIN_WIDTH)
		width = MIN_WIDTH;
	else if (width > MAX_WIDTH)
		width = MAX_WIDTH;

	this->width = width;
}

// Thay đổi chiều cao của console
// Tham số: chiều cao
void km::Console::setHeight(int height)
{
	if (height < MIN_HEIGHT)
		height = MIN_HEIGHT;
	else if (height > MAX_HEIGHT)
		height = MAX_HEIGHT;
	
	this->height = height;
}

// Thay đổi màu chữ
// Tham số: màu chữ
void km::Console::setColor(int color)
{
	if (color >= 0 && color <= 255)
		this->color = color;
}

// Trả về chiều rộng console
int km::Console::getWidth()
{
	return width;
}

// Trả về chiều cao console
int km::Console::getHeight()
{
	return height;
}

// Trả vê màu chữ
int km::Console::getColor()
{
	return color;
}
// Lấy nút bàn phím do người dùng bấm
// Trả về: Mã của phím
int km::Console::inputKey()
{
    if (_kbhit())
    {
        int key = _getch();
        
        if (key == 224)
        {
            key = _getch();
            return key + 1000;
        }
        
        return key;
    }
    else
    {
        return km::KEY_NONE;
    }
    
    return km::KEY_NONE;
}

// Xóa màn hình
void km::Console::clrscr()
{
    CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
    HANDLE	hConsoleOut;
    COORD	Home = {0,0};
    DWORD	dummy;
    
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    
    FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
    csbiInfo.dwCursorPosition.X = 0;
    csbiInfo.dwCursorPosition.Y = 0;
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}

// Di chuyển con trỏ console đến vị trí có tọa độ (x, y)
void km::Console::gotoXY (int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

// Di chuyển con trỏ console theo %
void km::Console::gotoXY(float x, float y)
{
	COORD coord;
	coord.X = this->width * x - 1;
	coord.Y = this->height * y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Lấy tọa độ x hiện tại của con trỏ console
int km::Console::whereX()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.X;
    return -1;
}

// Lấy tọa độ y hiện tại của con trỏ console
int km::Console::whereY()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.Y;
    return -1;
}

// Xóa con trỏ nháy
void km::Console::noCursorType()
{
    CONSOLE_CURSOR_INFO info;
    info.bVisible = FALSE;
    info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void km::Console::cursorType()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = TRUE;
	info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

// Đổi màu chữ
// Tham số: Mã màu
void km::Console::changeColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}

// Đổi size chữ
// Tham số: Size
void km::Console::changeTextSize(int width, int height)
{
	if(width >= 1)
		textWidth = width;
	textHeight = height;

	if (height < 1)
	{
		textHeight = textWidth * 2;
	}

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = textWidth;					// chiều rộng của chữ
	cfi.dwFontSize.Y = textHeight;                // chiều cao của chữ
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

// Trả về chiều rộng của chữ
int km::Console::getTextWidth()
{
	return textWidth;
}

// Trả về chiều cao của chữ
int km::Console::getTextHeight()
{
	return textHeight;
}

// Đổi kích thước console
// Tham số: chiều rộng, chiều cao
void km::Console::changeWindowSize(int width, int height)
{
	setWidth(width);
	setHeight(height);

	HWND console = GetConsoleWindow();
	resizeConsole(console, this->width, this->height, getTextWidth(), getTextHeight());
}

// Đổi chiều rộng console
// Tham số: chiều rộng
void km::Console::changeWindowWidth(int width)
{
	setWidth(width);

	HWND console = GetConsoleWindow();
	resizeConsole(console, this->width, this->height, getTextWidth(), getTextHeight());
}

// Đổi chiều cao console
// Tham số: chiều cao
void km::Console::changeWindowHeight(int height)
{
	setHeight(height);

	HWND console = GetConsoleWindow();
	resizeConsole(console, this->width, this->height, getTextWidth(), getTextHeight());
}

// Resize kích thước console
// Tham số: màn hình console, chiều rộng, chiều cao, độ rộng chữ, độ cao chữ
void km::Console::resizeConsole(HWND console, int width, int height, int textWidth, int textHeight)
{
	MoveWindow(console, 0, 0, width * textWidth, height * textHeight, TRUE);
}