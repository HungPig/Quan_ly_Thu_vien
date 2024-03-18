#pragma once
#include "Windows.h"
#include "Common.h"
// vi tri
#define xTen 53
#define yTen 22
// mau
#define AQUA 3
#define PURPLE 5
#define LIGHT_AQUA 11
#define LIGHT_YELLOW 14
#define LIGHT_GREEN 124
#define BLACK 0
#define WHITE 7
#define GREEN 9
#define BRIGHT_WHITE 15
#define BLUE 1
#define LIGHT_RED 12
//goc toa do
#define xOrdinal 0
#define yOrdinal 0
// max
#define xMax 132
//
void TextColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//.stackoverflow.com/questions/55635791/how-to-use-function-gotoxyint-x-int-y
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}



void CayLoading(int Color)
{
	//SetColor(Color);
	for (int i = 72; i <= 40 + 100; i++)
	{
		gotoxy(i, 36);
		Sleep(15);
		std::cout << char(219);
    }
}
//.stackoverflow.com/colorizing-text-in-the-console-with-c
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//.stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void setFontSize(int x) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = x;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void UnNocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
// codelearn.com
// thang lon bu cu
void ThongTinChung() {
	TextColor(299); 
	gotoxy(82, 1); printf("                                                  ");
	TextColor(299); gotoxy(83, 2); printf("          CHUONG TRINH QUAN LY THU VIEN          ");
	gotoxy(82, 3); printf("                                                  ");
	TextColor(LIGHT_RED);	gotoxy(97, 0); printf("  DUY TAN UNIVERSITY  ");
	gotoxy(82, 4); printf("                                                  ");
	gotoxy(82, 1); printf("  "); gotoxy(82, 1); printf("  ");
	gotoxy(82, 2); printf("  "); gotoxy(82, 2); printf("  ");
	gotoxy(82, 3); printf("  "); gotoxy(82, 3); printf("  ");
	TextColor(299);
	char s[] = { "        CHUONG TRINH QUAN LY THU VIEN     " };
	TextColor(BRIGHT_WHITE);
	return;
}
// is me
void Hienthi()
{
	ShowCur(false);
	std::ifstream file("ManHinh.txt", std::ios::in);
	if (file.good())
	{
		while (!file.eof())
		{
			std::string a;
			getline(file, a);
			SetColor(LIGHT_RED);
			Sleep(100);
			std::cout << a << std::endl;
		}
	}
	else
	{
		std::cout << "Can't open file" << std::endl;
	}
	std::cout << std::endl;
	SetColor(WHITE);
	gotoxy(91, yTen + 2);
	std::cout << "========= DO AN NHOM =========";
	gotoxy(91, yTen + 3);
	std::cout << "HOTEN1 : DUONG_THANH_HUNG";
	gotoxy(91, yTen + 4);
	std::cout << "HOTEN2 : NGUYEN_TRAN_MINH_PHI";
	gotoxy(91, yTen + 5);
	std::cout << "MSSV  : 2544";
	std::cout << "MSSV  : 3370";
	gotoxy(91, yTen + 6);
	gotoxy(91, yTen + 7);
	std::cout << "LOP   : CMU-TMP12-CS311";
	gotoxy(91, yTen + 8);
	gotoxy(88, 35);
	std::cout << "Welcome to the Library Management System!" << std::endl;
	gotoxy(105, 25 + 1);
	CayLoading(LIGHT_RED);
	ShowCur(false);
	gotoxy(96, 37);
	std::cout << "Press Enter to continue..." << std::endl;
	while (!_kbhit()) {
		gotoxy(97, 30);
		SetColor(1 + rand() % 15);
		Sleep(100);
		std::cout << "DUY TAN UNIVERSITY";
	}
	SetColor(AQUA);
	std::cin.ignore();
	while (_kbhit()) {
		//getch();
	}

	SetColor(BRIGHT_WHITE);
	return;
}
// tao deo bik bu cu
void fullscreen() {
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}
// thich liem lo dit
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}


void VeKhungMenu()
{
	ShowCur(false);
	int i;
	gotoxy(xOrdinal, yOrdinal);
	// ve hang ngang tren
	for (i = 0; i <= xMax; i++)
	{
		SetColor(WHITE);
		std::cout << char(219);
	}

	// ve hang ngang duoi
	gotoxy(xOrdinal, yOrdinal + 15);
	for (i = 0; i <= xMax; i++)
	{
		SetColor(WHITE);
		std::cout << char(219);
	}

	// ve hang doc trai
	for (int i = 0; i < yOrdinal + 15; i++)
	{
		gotoxy(xOrdinal, yOrdinal + i);
		SetBGColor(WHITE);
		std::cout << "  ";
	}

	// ve hang doc phai
	for (int i = 0; i < yOrdinal + 15; i++)
	{
		gotoxy(xMax - 1, yOrdinal + i);
		SetBGColor(WHITE);
		std::cout << "   ";
	}
}


void CreateBox(int x, int y, std::string text, int length)
{
	gotoxy(x - 2, y - 1);
	std::cout << char(201) << std::setw(length) << std::setfill(char(205)) << char(205) << char(187);

	gotoxy(x - 2, y);
	std::cout << char(186) << text << std::setw(length - text.length() + 1) << std::setfill(' ') << char(186);

	gotoxy(x - 2, y + 1);
	std::cout << char(200) << std::setw(length) << std::setfill(char(205)) << char(205) << char(188);
}