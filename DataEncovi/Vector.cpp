#include "Vector.h"

Vector::Vector() {
	this->ds = new List;
	innit(*this->ds);
}

Vector::Vector(const List& l) {
	this->ds = new List;
	innit(*this->ds);
	int n = len(*this->ds);
	for (int i = 0; i < n; i++) {
		this->push_back(get(l, i)->data.n);
	}
}

Vector::~Vector() {
	Delete(*this->ds); 
	delete this->ds;
}

int Vector::size() const {
	return len(*this->ds);
}

void Vector::push_back(const string& value) {
	Data x;
	x.n = value;
	insert(*this->ds, CreateNote(x), -1);
}

bool Vector::empty() {
	return List_NULL(*this->ds);
}

void Vector::pop() {
	Delete(*this->ds, 0);
}

void Vector::back() {
	Delete(*this->ds, -1);
}

string Vector::operator[](int indext) const {
	return get(*this->ds, indext)->data.n;
}

istream& operator>>(istream& is, Vector& VT) {
	NhapList(*VT.ds);
	return is;
}

ostream& operator<<(ostream& out, const Vector& VT) {
	XuatList(*VT.ds);
	cout << endl;
	return out;
}

Vector& Vector::operator=(const Vector& x) {
	Delete(*this->ds);
	innit(*this->ds);
	int n = x.size();
	for (int i = 0; i < n; i++) {
		this->push_back(x[i]);
	}
	return *this;
}