#include <bits/stdc++.h>
using namespace std;
bool isValidDate(int day, int month, int year) {
    if (year < 0) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1) {
        return false;
    }
    int maxDay = 31; 
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDay = 30; 
    } else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            maxDay = 29; 
        } else {
            maxDay = 28;
        }
    }
    if (day > maxDay) {
        return false;
    }

    return true;
}


class Khachhang{
	string ma, ten, diachi;
	long long v;
	int ngay, thang, nam;
	public:
		void nhap();
		void in();
		double dongia();
};

void Khachhang::nhap(){
	cout << "\nNhap ma khach hang: " ;
	getline(cin, ma);
	cout << "\nNhap ho ten khach hang: " ;
	getline(cin, ten);
	cout << "\nNhap dia chi khach hang: " ;
	getline(cin,diachi);
	cout << "\nNhap so met khoi khach hang da dung: " ;
	cin >> v;
	cin.ignore();
	int d, m, y;
	do {
		cout << "\nNhap ngay thang nam tinh tien dd/mm/yy: "; cin >> d >> m >> y;
	}while(!isValidDate(d,m ,y));
	ngay =d;
	thang =m;
	nam =y;
}
void Khachhang::in(){
	cout << ma << " " 
		<< ten << " "
		<< diachi << " "
		<< v << "m^3" << " "
		<< ngay <<"/" <<thang<<"/"<<nam << endl;
}

double Khachhang::dongia(){
	double sotien=0, dongia=0;
	if (v <= 100) dongia = 2000;
	if ( v >100 && v <= 200) dongia = 3000;
	if (v > 200) dongia = 5000;
	sotien = v * dongia;
	return sotien;
}

class Quanli{
	Khachhang kh[100];
	int n;
	public:
		void inds();
		void nhapds();
		void inmax();
		void sapxep();
};

void Quanli::nhapds(){
	cout <<"\nNhap so luong khach hang: "; cin >> n;
	cin.ignore();
	for (int i=0;i<n;i++){
		cout <<"\nNhap thong tin khach hang thu " << i+1 << endl;
		kh[i].nhap();
		cin.ignore();
	}
}
void Quanli::inds(){
	for (int i=0;i<n;i++){
		kh[i].in();
	}
}
void Quanli::inmax(){
	double max;
	max = kh[0].dongia();
	for (int i=0;i<n;i++){
		if (max < kh[i].dongia()){
			max = kh[i].dongia();
		}
	}
	cout <<"\nDANH SACH KHACH HANG CO SO TIEN PHAI TRA CAO NHAT" <<endl;
	for (int i=0;i<n;i++){
		if (kh[i].dongia() == max){
			kh[i].in();
			cout << fixed << setprecision(2) << kh[i].dongia();
		}
	}
}

int main(){
	Quanli ob;
	ob.nhapds();
	ob.inds();
	cout << "------" << endl;
	ob.inmax();
}