#include "CSVfile.h"
#include "Color.h"

Vector luachon;
CSVfile file("file.csv");

void SetLuaChon(); // tao cac lua chon
void LuaChon(int n); // lua chon hien tai
void ThucThi(int n); // thuc thi lua chon
void MENU(); // quan ly lua chon

int main() {
	SetLuaChon();
	MENU();
	
	return 0;
}

void MENU() {
	int lc = 1, size = 0;;
	size = luachon.size();
	LuaChon(1);
	while (true) {
		if (GetAsyncKeyState(VK_DOWN)) {
			if (lc == size) lc = 1;
			else lc += 1;
			LuaChon(lc);
			Sleep(200);
			_flushall();
		}
		if (GetAsyncKeyState(VK_UP)) { 
			if (lc == 1) lc = size;
			else lc -= 1;
			LuaChon(lc);
			Sleep(200); 
			_flushall();
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			Sleep(200);
			ThucThi(lc);
			system("cls");
			LuaChon(lc);
			_flushall();
		}
		Sleep(400);
		if (GetAsyncKeyState(VK_ESCAPE)) break;
		
	}
	XoaManHinh();
}

void LuaChon(int n) {
	XoaManHinh();
	TextColor(10);
	for (int i = 1; i <= 100; i++) cout << "-";
	ToMau(48, 2, "MENU", 10);
	cout << "\n";
	TextColor(10);
	for (int i = 1; i <= 100; i++) cout << "-";
	TextColor(7);
	int lend = luachon.size();
	for (int i = 0; i < lend; i++) {
		if (i + 1 != n)
			ToMau(25, i + 5, luachon[i].c_str(), 14);
		else 
			ToMau(25, i + 5, luachon[i].c_str(), 47);
	}	
}

void SetLuaChon() {
	luachon.push_back("Import file .csv");
	luachon.push_back("Import file .xlsx");
	luachon.push_back("Chan doan NCOVI cho mot nguoi");
	luachon.push_back("Chan doan NCOVI cho du lieu trong file");
	luachon.push_back("Xem file da import");
	luachon.push_back("Xuat file ket qua .xlsx");
}

void ThucThi(int n) {
	switch (n)
	{
	case 1: // import file.csv
	{
		system("cls");
		ToMau(1, 1, "Nhap ten file (name.csv): ", 15);
		getline(cin, file.filename);
		ToMau(1, 3, file.filename.c_str(), 11);
		ToMau(1, 4, "Import thanh cong!\n", 11);
		system("pause");
		break;
	}
	case 2: //import file.xlsx
	{
		string s = "";
		system("cls");
		ToMau(1, 1, "Nhap ten file (name.xlsx): ", 15);
		getline(cin, s);
		ToMau(1, 2, "Nhap ten file (name.csv): ", 15);
		getline(cin, file.filename);
		file.CRIATE_CSV_FILE(s.c_str());
		ToMau(1, 3, file.filename.c_str(), 11);
		ToMau(1, 4, "Import thanh cong!\n", 11);
		system("pause");
		break;
	}
	case 5: // Xem file import
	{
		system("cls");
		file.Screens_out();
		break;
	}
	case 6: // xuat file .xlsx
	{
		system("cls");
		file.TO_MS_EXCEL_FILE();
		ToMau(1, 2, "Thanh Cong! output.xlsx\n", 11);
		system("pause");
		break;
	}
	case 3: // chan doan cho 1 nguoi
	{
		system("cls");
		Row Trieuchung = file.Read_Collumn('A');
		Row MucDo = file.Read_Collumn('B');
		ToMau(1, 1, "Vui nhap 1 neu co, nhap 0 neu khong co!\n", 11);
		int n = Trieuchung.data.size(), temp = 0;
		double  KetQua = 0;
		for (int i = 0; i < n; i++) {
			ToMau(1, i + 2, ("Co " + Trieuchung.data[i] + " khong? ").c_str(), 15);
			cin >> temp;
			cin.ignore();
			if (temp == 1) KetQua += stoi(MucDo.data[i]);
		}
		if (KetQua >= 1000) KetQua = 100;
		else KetQua = (KetQua * 100) / 1000;
		ToMau(20, n + 2, ("Kha Nang Nhiem ENCOVI la:\t" + to_string(KetQua) + "%\n").c_str(), 11);
		system("pause");
		system("cls");
		break;
	}
	case 4: // chan doan cho nhieu nguoi
	{
		system("cls");
		Row MucDo = file.Read_Collumn('B');
		
		string namefile = "";
		ToMau(1, 1, "Nhap ten (file.xlsx) chua danh sach can chan doan: ", 15);
		getline(cin, namefile);

		CSVfile temp("temp.csv");
		temp.CRIATE_CSV_FILE(namefile.c_str());
	
		Table table = temp.Read_Table(2, 21);
		Table KetQua(21);
		KetQua.data[0].push_back("STT");
		KetQua.data[0].push_back("Ho Va Ten");
		KetQua.data[0].push_back("Kha Nang Nhiem");
		int n = MucDo.data.size(); double diem = 0;
		TextColor(47);
		for (int i = 0; i < 20; i++) {
			diem = 0;
			cout << i << " ";
			for (int j = 0; j < n; j++) {
				if (stoi(table.data[i][j + 2]) == 1) {
					diem += stoi(MucDo.data[j]);
				}
			}
			if (diem >= 1000) diem = 100;
			else diem = (diem * 100) / 1000;
			KetQua.data[i + 1].push_back(to_string((int)stoi(table.data[i][0])));
			KetQua.data[i + 1].push_back(table.data[i][1]);
			KetQua.data[i + 1].push_back(to_string(diem));
		}
		temp.Write(temp.filename.c_str(), KetQua);
		TextColor(11);
		cout << "\nVu Long Cho...\n";
		TextColor(7);
		temp.TO_MS_EXCEL_FILE();
		remove("temp.csv");
		Sleep(1000);
		system("output.xlsx");
		system("pause");
		system("cls");
		break;
	}
	default:
		break;
	}
}