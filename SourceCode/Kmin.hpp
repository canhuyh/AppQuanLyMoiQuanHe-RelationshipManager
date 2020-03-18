//
//  Kmin.hpp
//  LCNNLT_Buoi12_ClassSnake
//
//  Created by Bao Vu on 8/24/18.
//  Copyright © 2018 kmin. All rights reserved.
//

#ifndef Kmin_hpp
#define Kmin_hpp

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cwchar>
#include <windows.h>
using namespace std;
namespace km
{
    enum COLOR
    {
        BLACK       = 0,
        DARK_BLUE   = 1,
        DARK_GREEN  = 2,
        DARK_CYAN   = 3,
        DARK_RED    = 4,
        DARK_PINK   = 5,
        DARK_YELLOW	= 6,
        DARK_WHITE	= 7,
        GREY		= 8,
        BLUE		= 9,
        GREEN		= 10,
        CYAN		= 11,
        RED			= 12,
        PINK		= 13,
        YELLOW		= 14,
        WHITE		= 15
    };
    enum KEY
    {
        KEY_UP		= 1072,
        KEY_DOWN	= 1080,
        KEY_LEFT	= 1075,
        KEY_RIGHT	= 1077,
        KEY_NONE	= -1
    };
    class Console
    {
	private:
		int width;
		int height;
		int color;
		int textWidth;
		int textHeight;
		static int MAX_HEIGHT;
		static int MIN_HEIGHT;
		static int MAX_WIDTH;
		static int MIN_WIDTH;

		// Resize kích thước console
		// Tham số: màn hình console, chiều rộng, chiều cao, độ rộng chữ, độ cao chữ
		void resizeConsole(HWND console, int width, int height, int textWidth, int textHeight);

    public:
		// Khởi tạo mặc định
		Console();

		// Khởi tạo có tham số
		// Tham số: chiều rộng console, chiều cao console
		Console(int width, int height);

		// Khởi tạo có tham số
		// Tham số: chiều rộng console, chiều cao console, kích thước text
		Console(int width, int height, int textSize);

		// Thay đổi chiều rộng của console
		// Tham số: chiều rộng
		void setWidth(int width);

		// Thay đổi chiều cao của console
		// Tham số: chiều cao
		void setHeight(int height);
		
		// Thay đổi màu chữ
		// Tham số: màu chữ
		void setColor(int color);
		
		// Trả về chiều rộng console
		int getWidth();
		
		// Trả về chiều cao console
		int getHeight();
		
		// Trả về màu chữ
		int getColor();
        
		// Lấy nút bàn phím do người dùng bấm
        // Trả về: Mã của phím
        int inputKey();
        
        // Xóa màn hình
        void clrscr();
        
        // Di chuyển con trỏ console đến vị trí có tọa độ (x, y)
        void gotoXY (int x, int y);

		// Di chuyển con trỏ console theo %
		void gotoXY(float x, float y);
        
        // Lấy tọa độ x hiện tại của con trỏ console
        int whereX();
        
        // Lấy tọa độ y hiện tại của con trỏ console
        int whereY();
        
        // Xóa con trỏ nháy
        void noCursorType();

		//Bật con trỏ nháy ( Cảnh định nghĩa nè =]] )
		void cursorType();
        
        // Đổi màu chữ
        // Tham số: Mã màu
        void changeColor (int color);

		// Đổi text size
		// Tham số: size
		void changeTextSize(int width, int height = -1);

		// Trả về chiều rộng của chữ
		int getTextWidth();

		// Trả về chiều cao của chữ
		int getTextHeight();

		// Đổi kích thước console
		// Tham số: chiều rộng, chiều cao
		void changeWindowSize(int width, int height);

		// Đổi chiều rộng console
		// Tham số: chiều rộng
		void changeWindowWidth(int width);
		
		// Đổi chiều cao console
		// Tham số: chiều cao
		void changeWindowHeight(int height);
    };
}

#endif /* Kmin_hpp */
