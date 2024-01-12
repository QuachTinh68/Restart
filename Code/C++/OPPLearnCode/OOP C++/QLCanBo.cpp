#include <bits/stdc++.h>
using namespace std;

class CanBo{
	string hoten, gioitinh, diachi;
	int tuoi;
	public:
		CanBo(){
			hoten=gioitinh=diachi=" ";
			tuoi=0;
		}
		CanBo(string ht, string gt, string dc, int t){
			hoten=ht;
			gioitinh=gt;
			diachi=dc;
			tuoi=t;
		}
		string get_hoten(){
			return hoten;
		}
		string get_dc(){
			return diachi;
		}
		string get_gt(){
			return gioitinh;
		}
		int get_tuoi(){
			return tuoi;
		}
		string set_ht(string ht){
			hoten=ht;
			return hoten;	
		}
		string set_dc(string dc){
			diachi=dc;
			return diachi;	
		}
		string set_gt(string gt){
			gioitinh=gt;
			return gioitinh;	
		}
		int set_t(int t){
			tuoi=t;
			return tuoi;
		}
		string catTen();
		void nhap();
		void in();
};
void CanBo::nhap(){
	cout <<"\nNhap ten can bo: ";
	getline(cin, hoten);
	cout <<"\nNhap tuoi can bo: ";
	cin>> tuoi;
	cin.ignore();
	cout <<"\nNhap gioi tinh can bo: ";
	getline(cin, gioitinh);
	cout <<"\nNhap dia chi can bo: ";
	getline(cin,diachi);
	
}
void CanBo::in(){
	cout << hoten << " "
	<< tuoi << " "
	<< gioitinh <<  " "
	<< diachi << endl;
}
string CanBo::catTen(){
	string s=get_hoten();
	string ten;
	for (int i=s.size()-1; i>=0 ;--i){
        if (s[i] == ' ') {
            break;
        }
        ten = s[i] + ten;
    }
	return ten;
}

class QLCB{
	CanBo *cb;
	int n;
	public:
		void nhapds();
		void inds();
		void themcb();
		void sapXep();
};
void QLCB::nhapds(){
	cout << "\nNhap so luong can bo: ";
	cin >> n;
	cin.ignore();
	cb = new CanBo[n];
	if (cb == NULL){
		cout <<"\nLoi cap phat bo nho !" << endl;
		exit(0);
	}else{
		cout <<"\nNhapp thong tin can bo: " << endl;
		for (int i=0;i<n;i++){
			cb[i].nhap();
		}
	}
}
void QLCB::inds(){
	cout << "\nDanh sach can bo la: " <<endl;
	for (int i=0;i<n;i++){
		cb[i].in();
	}
}

void QLCB::themcb(){
	CanBo cbn;
	cout << "\nNhap thong tin can bo can them: " << endl;
	cbn.nhap();
	n++;
	CanBo *mangMoi = new CanBo[n];
	for (int i = 0; i < n - 1; i++) {
            mangMoi[i] = cb[i];
        }
    mangMoi[n - 1] = cbn;
    delete[] cb;
    cb = mangMoi;
}
void hoanvi(CanBo &a, CanBo &b){
	CanBo tem;
	tem=a;
	a=b;
	b=tem;
}
void QLCB::sapXep(){
	for (int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if (cb[i].catTen()  > cb[j].catTen()){
				hoanvi(cb[i],cb[j]);
			}
		}
	}
}


int main(){
	QLCB ob;
	ob.nhapds();
	ob.inds();
	ob.themcb();
	ob.sapXep();
	cout << "\Danh sach can bo sau khi sap xep la: " <<endl;
	ob.inds();
}