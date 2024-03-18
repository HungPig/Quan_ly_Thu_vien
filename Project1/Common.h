#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
enum TATCA_NGUOIDUNG
{
	LOGIN = 1,
	ALL_NGUOIDUNG_EXIT,
};

enum NGUOI_DUNG_NHAP
{
	CHANGE_PASSWORD = 1,
	UPDATE_INFOR,
	LOGOUT,
	DISPLAY_USER,
	MANAGER_PARTRON,
	MANAGER_BOOK,
	BORROW_BOOK,
	RETURN_BOOK,
	NGUOIDUNG_USER_EXIT,
};

enum MANAGE_PARTRON_MENU
{
	VIEW_PARTRON = 1,
	ADD_PARTRON,
	EDIT_PARTRON,
	DELETE_PARTRON,
	SEARCH_BY_ID,
	BACK_TO_USER_DATA_MENU,
};
enum MANAGE_BOOK_MENU
{
	VIEW_BOOK = 1,
	ADD_BOOK,
	EDIT_BOOK,
	DELETE_BOOK,
	SEARCH_BY_ISBN,
	BACK_TO_BOOK_MENU,
};
// chinh sua giao dien 
