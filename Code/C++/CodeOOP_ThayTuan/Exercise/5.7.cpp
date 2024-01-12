#include <bits/stdc++.h>
using namespace std;
class Sach{
	string tensach, tacgia;
	int sotrang;
	float giaban;
	public:
		void nhap();
		void in();
};
void Sach::in(){
	cout << tensach << " " << tacgia << " " << sotrang <<  " " << giaban << " ";
}
void Sach::nhap(){
	cout << "\nNhap ten sach: ";
	getline(cin,tensach);
	cout << "\nNhap tac gia: ";
	getline(cin,tacgia);
	cout << "\nNhap so trang: ";
	cin >> sotrang;
	cout << "\nNhap gia ban: ";
	cin >> giaban;
	cin.ignore();
}

class Bia : public Sach {
	string ma;
	float tienve;
	public:
		void nhapB();
		void inB();
};
void Bia::nhapB(){

	cout << "\nNhap ma hinh anh: ";
	getline(cin,ma);
	cout << "\nNhap so tien ve: ";
	cin >> tienve;
	cin.ignore();
}
void Bia::inB(){
	in();
	cout << ma << " " << tienve <<" ";
}

class Hoasi{
	string ten, diachi;
	public:
		void nhapH();
		void inH();
};

void Hoasi::nhapH(){
	cout << "\nNhap ten hoa si: ";
	getline(cin,ten);
	cout << "\nNhap dia chi: ";
	getline(cin,diachi);
}
void Hoasi::inH(){
	cout << ten<< " " << diachi << endl;
}

class SachVeBia : public Bia, public Hoasi{
	public:
		void nhapds();
		void inds();
};

void SachVeBia::nhapds(){
	nhap();
	nhapH();
	nhapB();
}
void SachVeBia::inds(){
	in();
	inB();
	inH();
}
int main(){
	SachVeBia ob[50];
	Sach a[50];
	int n,m;
	cout << "\nNhap so luong sach co bia: ";cin>>n; 
	cin.ignore();
	cout<< endl;
	for (int i=0;i<n;i++){
		ob[i].nhapds();
	for (int i=0;i<n;i++){
	}
		ob[i].inds();
	}
	cout << "\nNhap so luong sach khong co bia: ";cin>>m;
	cin.ignore();
	cout<< endl;
	for (int i=0;i<m;i++){
		a[i].nhap();
	}
	for (int i=0;i<m;i++){
		a[i].in();
	}
}