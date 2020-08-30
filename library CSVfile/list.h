#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Data {
	string n;
};

struct Note {
	Data data;
	Note* next;
};

struct List {
	Note* begin;
	Note* end;
};

inline void NhapData(Data& t) {
	getline(cin, t.n);
}

inline void XuatData(Data t) {
	cout << t.n;
}

inline Note* CreateNote(Data value) {
	Note* p = new Note;
	if (p == NULL) exit(1);
	p->data = value;
	p->next = NULL;
	return p;
}

inline void innit(List& ls) {
	ls.begin = ls.end = NULL;
}
// do dai danh sach
inline int len(const List& ls) {
	int dem = 0;
	Note* p = ls.begin;
	while (p) {
		dem += 1;
		p = p->next;
	}
	return dem;
}

inline bool List_NULL(List ls) {
	if (!ls.begin) return true;
	return false;
}
// chen node
inline void insert(List& ls, Note* value, int index) {
	switch (index)
	{
	case 0:
	{
		if (len(ls) == 0) ls.begin = ls.end = value;
		else {
			value->next = ls.begin;
			ls.begin = value;
		}
		break;
	}
	case -1:
	{
		if (len(ls) == 0) ls.begin = ls.end = value;
		else {
			ls.end->next = value;
			ls.end = value;
		}
		break;
	}
	default:
	{
		int size = len(ls);
		if (index <= size && index >= 0) {
			if (index == size) insert(ls, value, -1);
			else if (index == 0) insert(ls, value, 0);
			else {
				int dem = -1;
				Note* p = ls.begin;
				while (p) {
					dem += 1;
					if (dem == index - 1) {
						value->next = p->next;
						p->next = value;
						break;
					}
					p = p->next;
				}
			}
		}
		break;
	}
	}
}
//tra ve node vi tri thu i
inline Note* get(const List& ls, int index) {
	int dem = -1;
	Note* p = ls.begin;
	while (p) {
		dem += 1;
		if (dem == index) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

inline void Delete(List& ls, int index = -2) {
	Note* p;
	if (ls.begin == NULL) return;
	if (ls.begin == ls.end) {
		delete ls.end;
		ls.begin = ls.end = NULL;
		return;
	}
	if (index >= -1) {
		if (index == 0) {
			p = ls.begin;
			ls.begin = ls.begin->next;
			delete p;
		}
		else if (index == -1) {
			p = ls.begin;
			while (p->next->next != NULL)
				p = p->next;
			ls.end = p;
			ls.end->next = NULL;
			delete p->next;
		}
		else {
			p = get(ls, index - 1);
			p->next = p->next->next;
			delete p;
		}
	}
	else {
		while (ls.begin) Delete(ls, 0);
		ls.begin = ls.end = NULL;
	}
}

inline void NhapList(List& ls) {
	Data* x;
	Note* p;
	while (true) {
		x = new Data;
		NhapData(*x);
		if (x->n == "") return;
		p = CreateNote(*x);
		insert(ls, p, -1);
	}
}
// tron danh sach
inline void Connect_Mere_Data(List& A, List B, List C) {
	Note* p = B.begin;
	Note* q = C.begin;
	while (p || q) {
		if (p) {
			insert(A, CreateNote(p->data), -1);
			p = p->next;
		}
		if (q) {
			insert(A, CreateNote(q->data), -1);
			q = q->next;
		}
	}
}

inline void XuatList(List& ls) {
	Note* p = ls.begin;
	if (p == NULL) return;
	while (p) {
		XuatData(p->data);
		cout << " ";
		p = p->next;
	}
}

