/*
	VECTOR DINH NGHIA BANG DANH SACH LIEN KET
	Nguoi viet: Nguyen Tan Tang
	Thoi gien: 6/2020
*/


#pragma once
#include "list.h" // Mot danh sach lien ket don

//Dinh nghia mot vector dung danh sach lien ket
class Vector
{
public:
	List* ds;

	Vector();
	Vector(const List& l);
	~Vector();
	//Tra ve so phan tu trong danh sach
	int size() const;
	//Kiem tra rong
	bool empty();
	//Them mot phan tu
	void push_back(const string& value);
	//Xoa dau
	void pop();
	//Xoa cuoi
	void back();
	//Cac toan tu nhap, xuat
	friend istream& operator>>(istream& is, Vector& VT);
	friend ostream& operator<<(ostream& out, const Vector& VT);
	//Truy xuat gia tri theo index
	string operator[](int indext) const;
	//Toan tu gan
	Vector& operator=(const Vector& x);
};

