#pragma once
#include <string>
#include <sstream>
#include "Vector.h" // Vector duoc dinh nghia bang danh sach lien ket

using namespace std;

// Dinh nghia cau truc cua mot hang trong bang tinh
// Dung tuong tu de bieu dien mot cot cua bang tinh
class Row {
public:
	Vector data;
	Row() {}

	Row(const Row& x);

	Row(const string& value);

};
