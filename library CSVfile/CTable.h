#pragma once
#include "CRow.h"
// Dinh nghia cau truc cua mot bang tinh
class Table {
public:
	Vector* data;
	int row;

	Table();
	Table(int row);
	Table(const Table& t);
	Table(int row, const Table t);
	~Table(); 
	void resize(int row); 
	Table& operator=(const Table& t);
};

