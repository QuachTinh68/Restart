#include <bits/stdc++.h>
using namespace std;

class SinhVien{
	string  ma, hoten;
	double diem;
	public:
		friend istream & operator >> (istream &in, SinhVien &s);
		friend ostream & operator << (ostream &out, SinhVien &s);
		bool operator <= (SinhVien s);
};
istream &operator >> (istream &in, SinhVien &s){
	cout << "\nNhap ma sinh vien: ";
	getline(in, s.ma);
	cout <<"\nNhap ho ten sinh vien: ";
	getline(in,s.hoten);
	cout << "\nNhap diem trung binh: "; cin >>s.diem;
	return in;
}
ostream &operator << (ostream &out, SinhVien &s){
	out << s.ma <<" " << s.hoten << " " << s.diem << endl;
	return out;
}
bool SinhVien::operator <=(SinhVien s){
	if (diem > s.diem){
		return 0;
	}
	return 1;
}

class QuanLi{
	SinhVien sv[100];
	int n;
	public:
		void nhap();
		void in();
		void sosanh();
};
void QuanLi::nhap(){
	cout <<"\nNhap so luong sinh vien: "; cin >> n;
	cin.ignore();
	for (int i=0;i<n;i++){
		cin >> sv[i];
		cin.ignore();
	}
}
void QuanLi::in(){
	cout <<"\nDANH SACH SINH VIEN: ";
	for (int i=0;i<n;i++){
		cout << sv[i];
	}
}
void hoanvi(SinhVien &a, SinhVien &b){
	SinhVien tmp;
	tmp=a;
	a=b;
	b=tmp;
}

void QuanLi::sosanh(){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (sv[i] <= sv[j]){
				hoanvi(sv[i], sv[j]);
			}
		}
	}
}

int main(){
	QuanLi ob;
	ob.nhap();
	ob.in();
	ob.sosanh();
	ob.in();
}