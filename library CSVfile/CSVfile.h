
/*
	THU VIEN XU LY FILE EXCEL 
	Nguoi viet: Nguyen Tan Tang
	Thoi gian: 6/2020;
*/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Vector.h" // Vector duoc dinh nghia bang danh sach lien ket
#include "CRow.h" // class Row
#include "CTable.h" // class Table

using namespace std;

// Dinh nghia doi tuong la mot file .csv
// Dinh nghia cac phuong thuc can cho viec doc ghi file
class CSVfile
{
public:
	string filename;

	CSVfile(const char* file_name);
	CSVfile(const char* file_name, const Table& value);
	//Chuyen file .xlsx sang file .csv de xu ly
	void CREATE_CSV_FILE(const char* filename);
	// Chuyen sang file .xlsx
	void TO_MS_EXCEL_FILE();
	// Mo file len de xem
	void Screens_out() {
		system(this->filename.c_str());
		system("pause");
	}
	//Doc cac thanh phan trong bang tinh
	string Read_Cell(const char& collumn, const int& row);
	Row Read_Row(const int& row);
	Row Read_Collumn(const char& collumn);
	//Doc mot phan hoac ca table
	Table Read_Table(const int& rowbegin, const int& rowend);
	//Ghi mot Table ra file .csv
	void Write(const char* file_name, const Table& value);
	// Chen them mot hang vai file
	void Insert(Row& value);
	// Xoa Mot hang trong bang
	void Delete_Row(const string& key);
	//Cap nhap mot hang cu the
	void Update_Row(const string& key, Row& value);
};

