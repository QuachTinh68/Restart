#include <bits/stdc++.h>
using namespace std;
class airship{
	int sokhach;
	float taitrong;
	public:
		void nhap();
		void in();
};
void airship::nhap(){
	cout << "\nNhap so khach: ";
	cin >> sokhach;
	cout << "\nNhap tai trong toi da: ";
	cin >> taitrong;
}
class airplane : public airship{
	string kieu;
	public:
		void nhapA();
		void inA();
};

void airplane::nhapA(){
	int n;
	nhap();
	do{
		cout << "\nNhap thong tin kieu dong co (0:Canh Quat--1:Phan luc): ";
		cin >> n;
		
	}while(n!=0 && n!=1);
	if (n==0){
		kieu="Canh Quat";
	}else{
		kieu ="Phan luc";
	}
}

class balloon : public airship{
	string nhienlieu;
	public:
		void nhapB();
		void inB();
};

void balloon::nhapB(){
	int n;
	nhap();
	do{
		cout << "\nNhap thong tin kieu nhien lieu (0:Hydrogen--1:Helium): ";
		cin >> n;
		
	}while(n!=0 && n!=1);
	if (n==0){
		nhienlieu="Hydrogen";
	}else{
		nhienlieu ="Helium";
	}
}