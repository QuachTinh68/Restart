#include <bits/stdc++.h>
using namespace std;
class CanBo{
	string ma,madv, hoten, ngaysinh;
	public:
		void nhap();
		void in();
		string get_madv(){
			return madv;
		}
};
void CanBo::nhap(){
	cout << "Nhap ma can bo: ";
    getline(cin,ma);
    cout << "Nhap ma don vi: ";
    getline(cin,madv);
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
    cout << "Nhap ngay sinh: ";
    getline(cin, ngaysinh);
}
void CanBo::in(){
	cout << ma << " " << madv << " " << hoten << " " <<ngaysinh << " ";
	
}
class Luong : public CanBo{
	float phucap, hs, baohiem;
	public:
		float tinhLuong();
		void nhapL();
		void inL();
};
void Luong::nhapL(){
	nhap();
    cout << "Nhap phu cap: ";
    cin >> phucap;
    cout << "Nhap he so luong: ";
    cin >> hs;
    cout << "Nhap bao hiem: ";
    cin >> baohiem;
    cin.ignore();
}
float Luong::tinhLuong(){
	return  hs * 1350000 - baohiem;
}

void Luong::inL(){
	in();
	cout << phucap << " " << hs << " " << baohiem 
	<< fixed << setprecision(0) << tinhLuong() << endl;
}

class QuanLi{
	Luong cb[50];
	int n;
	public:
		void nhapds();
		void inds();
		void inDonVi();
};
void QuanLi::nhapds(){
	do{
		cout << "\nNhap so luong can bo: "; cin>> n;
		cin.ignore();
	}while(n<0 || n> 50);
	for (int i=0;i<n;i++){
		cb[i].nhapL();
	}
}
void QuanLi::inds(){
	for (int i=0;i<n;i++){
		cb[i].inL();
	}
}
void QuanLi::inDonVi(){
	for (int i=0;i<n;i++){
		if (i==0 || cb[i].get_madv() != cb[i-1].get_madv() ){
			cout << " MA DON VI : " << cb[i].get_madv() << endl;
			cb[i].inL();
		}
	}
}

int main(){
	QuanLi ob;
	ob.nhapds();
	ob.inDonVi();
}