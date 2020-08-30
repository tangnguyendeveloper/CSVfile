#include "CRow.h"

Row::Row(const Row& x) {
	this->data = x.data;
}

Row::Row(const string& value) {
	stringstream t(value);
	string m = "";
	while (getline(t, m, ','))
		this->data.push_back(m);
}
