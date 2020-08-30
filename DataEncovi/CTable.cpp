#include "CTable.h"

Table::Table() {
	this->row = 1;
	this->data = new Vector[1];
}

Table::Table(int row) {
	this->row = row;
	this->data = new Vector[row];
}

Table::Table(const Table& t) {
	this->row = t.row;
	this->data = new Vector[t.row];
	for (int i = 0; i < t.row; i++) {
		int n = t.data[i].size();
		for (int j = 0; j < n; j++) {
			this->data[i].push_back(t.data[i][j]);
		}
	}
}

Table::Table(int row, const Table t) {
	delete[] this->data;
	this->row = row;
	this->data = new Vector[row];
	for (int i = 0; i < row; i++) {
		int n = t.data[i].size();
		for (int j = 0; j < n; j++) {
			this->data[i].push_back(t.data[i][j]);
		}
	}
}

Table::~Table() {
	delete[] this->data;
}

void Table::resize(int row) {
	Table::Table(row, *this);
}

Table& Table::operator=(const Table& t) {
	delete[] this->data;
	this->row = t.row;
	this->data = new Vector[t.row];
	for (int i = 0; i < t.row; i++) {
		int n = t.data[i].size();
		for (int j = 0; j < n; j++) {
			this->data[i].push_back(t.data[i][j]);
		}
	}
}
