#include "CSVfile.h"

CSVfile::CSVfile(const char* file_name) {
	this->filename = file_name;
}

CSVfile::CSVfile(const char* file_name, const Table& value) {
	this->filename = file_name;
	fstream fi(this->filename, ios::out);
	string nextcolumn = ",", nextrow = "\n";
	int n = value.row;
	for (int i = 0; i < n; i++) {
		static int m = value.data[i].size();
		for (int j = 0; j < m; j++) {
			fi << value.data[i][j] << nextcolumn;
		}
		fi << nextrow;
	}
	fi.close();
}

void CSVfile::Write(const char* file_name, const Table& value) {
	fstream fi(file_name, ios::out);
	string nextcolumn = ",", nextrow = "\n";
	int n = value.row;
	for (int i = 0; i < n; i++) {
		static int m = value.data[i].size();
		for (int j = 0; j < m; j++) {
			fi << value.data[i][j] << nextcolumn;
		}
		fi << nextrow;
	}
	fi.close();
}

Row CSVfile::Read_Row(const int& row) {
	fstream fi(this->filename, ios::in);
	string s = "", m = "";
	for (int i = 1; i <= row; i++) getline(fi, s);
	Row kq(s);
	fi.close();
	return kq;
}

string CSVfile::Read_Cell(const char& collumn, const int& row) {
	Row kq = this->Read_Row(row);
	return kq.data[(int)collumn - 65];
}

Row CSVfile::Read_Collumn(const char& collumn) {
	fstream fi(this->filename, ios::in);
	Row kq;
	int dem = 0;
	string s = "", m = "";
	while (getline(fi, s)) {
		stringstream t(s);
		dem = 0;
		while (getline(t, m, ',')) {
			if (dem == (int)collumn - 65)
				kq.data.push_back(m);
			dem++;
		}	
	}
	fi.close();
	return kq;
}

Table CSVfile::Read_Table(const int& rowbegin, const int& rowend) {
	fstream fi(this->filename, ios::in);
	string s = "", m = "";
	int n = rowend - rowbegin + 1;
	Table kq(n);
	for (int i = 1; i <= rowbegin; i++) getline(fi, s);
	kq.data[0] = Row(s).data;
	for (int i = 1; i < n; i++) {
		getline(fi, s);
		kq.data[i] = Row(s).data;
	}
	fi.close();
	return kq;
}

void CSVfile::Insert(Row& value) {
	fstream fi(this->filename, ios::app);
	string nextcolumn = ",", nextrow = "\n";
	int n = value.data.size();
	for (int i = 0; i < n; i++) {
		fi << value.data[i] << nextcolumn;
	}
	fi << nextrow;
	fi.close();
}

void CSVfile::Update_Row(const string& key, Row& value) {
	fstream fi(this->filename, ios::in);
	fstream fin(("new" + this->filename), ios::out);
	string nextcolumn = ",", nextrow = "\n", m;
	Row te;
	while (getline(fi, m)) {
		te = Row(m);
		if (te.data[0] == key) {
			int n = value.data.size();
			for (int i = 0; i < n; i++) {
				fin << value.data[i] << nextcolumn;
			}
			fin << nextrow;
			continue;
		}
		int n = te.data.size();
		for (int i = 0; i < n; i++) {
			fin << te.data[i] << nextcolumn;
		}
		fin << nextrow;
	}

	fi.close();
	fin.close();

	remove(this->filename.c_str());
	rename(("new" + this->filename).c_str(), this->filename.c_str());

}

void CSVfile::Delete_Row(const string& key) {
	fstream fi(this->filename, ios::in);
	fstream fin(("new" + this->filename), ios::out);
	string nextcolumn = ",", nextrow = "\n", m;
	Row te;
	while (getline(fi, m)) {
		te = Row(m);
		if (te.data[0] == key) {
			continue;
		}
		int n = te.data.size();
		for (int i = 0; i < n; i++) {
			fin << te.data[i] << nextcolumn;
		}
		fin << nextrow;
	}

	fi.close();
	fin.close();

	remove(this->filename.c_str());
	rename(("new" + this->filename).c_str(), this->filename.c_str());

}

void CSVfile::TO_MS_EXCEL_FILE() {
	rename(this->filename.c_str(), "input.csv");
	system("toxlsx.exe");
	rename("input.csv", this->filename.c_str());
}

void CSVfile::CRIATE_CSV_FILE(const char* filename) {
	rename(filename, "input.xlsx");
	system("tocsv.exe");
	rename("input.xlsx", filename);
	rename("output.csv", this->filename.c_str());
}