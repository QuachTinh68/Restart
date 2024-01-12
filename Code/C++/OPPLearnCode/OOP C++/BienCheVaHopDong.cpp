#include <bits/stdc++.h>
using namespace std;
class Nguoi{
	string ma,hoten;
	public:
		void nhap();
		void in();
		string get_ma(){
			return ma;
		}
		string get_ten(){
			return hoten;
		}
};

void Nguoi::nhap(){
	cout << "\nNhap ma: ";
	getline(cin, ma);
	cout << "\nNhap ho ten: ";
	getline(cin, hoten);
}
void Nguoi::in(){
	cout  << ma << " " << hoten << " ";
}

class Bienche : public Nguoi{
	float heso, phucap;
	public:
		void nhapB();
		void inB();
		float tinhluong();
};

float Bienche::tinhluong(){
	return heso * 1350000 + phucap;
}

void Bienche::nhapB(){
	nhap();
	cout << "\nNhap he so luong: ";
	cin >> heso;
	cout << "\nNhap tien phu cap: ";
	
	cin >> phucap;
	cin.ignore();
	
}
void Bienche::inB(){
	in();
	cout << heso << " " << phucap  << endl;	
}

class Hopdong : public Nguoi{
	float tiencong,hesovg;
	int songay;
	
	public:
		void nhapH();
		void inH();
		float tinhluongH();
};
float Hopdong::tinhluongH(){
	return songay * tiencong * hesovg;
}

void Hopdong::nhapH(){
	nhap();
	cout << "\nNhap tien cong: ";
	cin >> tiencong;
	cout << "\nNhap so ngay lao dong: ";
	cin >> songay;
	cout << "\nNhap he so vuot gio: ";
	cin >> hesovg;
	cin.ignore();
	
}
void Hopdong::inH(){
	in();
	cout << tiencong << " " << songay << " " << hesovg << " " 
	<< fixed << setprecision(0) << tinhluongH() <<endl;	
}

class QL{
	Hopdong hp[50];
	Bienche bc[50];
	int n,m;
	public:
		void nhapds();
		void inds();		
};
void QL::nhapds(){
	cout << "\nNhap so luong can bo hop dong: ";cin >> n;
	cin.ignore();
	for (int i=0;i<n;i++){
		hp[i].nhapH();
	}
	cout << "\nNhap so luong can bo bien che: ";cin >> m;
	cin.ignore();
	for (int i=0;i<m;i++){
		bc[i].nhapB();
	}
}
void QL::inds(){
	cout << "\nThong tin can bo hop dong: " <<endl;
	for (int i=0;i<n;i++){
		hp[i].inH();
	}
	cout << "\nThong tin can bo bien che: " << endl;
	for (int i=0;i<m;i++){
		bc[i].inB();
	}
}


int main(){
	QL ob;
	ob.nhapds();
	ob.inds();
}