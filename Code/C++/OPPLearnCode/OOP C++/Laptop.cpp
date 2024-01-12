#include <bits/stdc++.h>
using namespace std;

class Computer{
		string ma, hang;
		int nam;
		float gia;
	public:
		Computer(){
			ma=hang=" ";
			nam=0;
			gia=0;
		}
		Computer(string m, string h, int n, float g){
			ma=m;
			hang=h;
			nam=n;
			gia=g;
			
		}
		void set_ma(string m){
			ma = m;
		}
		void set_hang(string h){
			hang = h;
		}		
		void set_nam(int n){
			nam = n;
		}
		void set_gia(int g){
			gia = g;
		}
		int get_nam(){
			return nam;
		}
		string get_ma(){
			return ma;
		}
		string get_hang(){
			return hang;
		}
		float get_gia(){
			return gia;
		}
		void nhap();
		void in();
};

void Computer::nhap(){
	cout <<"\nNhap ma may: ";
	getline(cin,ma);
	cout <<"\nNhap hang san xuat may: ";
	getline(cin,hang);
	cout <<"\nNhap nam san xuat may: ";
	cin >> nam;
	cin.ignore();
	cout <<"\nNhap gia ban may: ";
	cin >> gia;
	cin.ignore();
}
void Computer::in(){
	cout << ma << " " 
	<< hang << " "
	<< nam << " "
	<< gia << " ";
}

class Laptop:public Computer{
	float can, doday, kichthuoc;
	string hedieuhanh;
	public:
		Laptop(){
			can = doday = kichthuoc=0;
			hedieuhanh=" ";
		}
		void set_can(float c){
			can  = c;
		}
		void set_doday(float d){
			doday=d;
		}
		void set_kichthuoc(float k){
			kichthuoc=k;
		}
		void set_hdh(string h){
			hedieuhanh=h;
		}
		float get_can(){
			return can;
		}
		float get_doday(){
			return doday;
		}
		float get_kichthuoc(){
			return kichthuoc;
		}
		string get_hdh(){
			return hedieuhanh;
		}
		void nhapL();
		void inL();
		int tinhnam();
		float tinhGia();
		bool operator > (Laptop a);	
};
void Laptop::nhapL(){
	nhap();
	cout <<"\nNhap can nang: "; cin >> can;
	cin.ignore();
	cout <<"\nNhap do day: "; cin >> doday;
	cin.ignore();
	cout <<"\nNhap kich thuoc: "; cin >> kichthuoc;
	cin.ignore();
	cout <<"\nNhap he dieu hanh: "; 
	getline(cin,hedieuhanh);
}
void Laptop::inL(){
	in();
	cout << can<< " " << doday 
	<< " " << kichthuoc << " " << hedieuhanh << " "
	<< tinhnam() <<" "
	<< fixed << setprecision(0)<< tinhGia() << endl;
}
int Laptop::tinhnam(){
	int namsd;
	namsd = 2023 - get_nam();
	return namsd;	
}

float Laptop::tinhGia(){
	float giaban;
	if (hedieuhanh == "Windows"){
		giaban = get_gia() - ((tinhnam()*0.1)*get_gia()); 
	}else{
		giaban = get_gia() - ((tinhnam()*0.05)*get_gia());
	}
	return giaban;
}

bool Laptop::operator > (Laptop a){
	if (tinhGia() > a.tinhGia()){
		return 1;
	}
	return 0;
}

class Ql{
	Laptop lp[50];
	int n;
	public:
		void nhapds();
		void inds();
		void sapXep();
		void inMax();
		void Xoa();
};
void Ql::nhapds(){
	do{
		cout << "\nNhap so luong laptop: ";
		cin >> n;
		cin.ignore();
	}while (n < 0 || n>=50);
	for (int i=0;i<n;i++){
		lp[i].nhapL();
	}
}
void hv(Laptop &a, Laptop &b){
	Laptop tmp;
	tmp=a;
	a=b;
	b=tmp;
}
void Ql::sapXep(){
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (lp[i] > lp[j]){
				hv(lp[i], lp[j]);
			}
		}
	}
	cout <<"\nDanh sach sau kho da sap xep theo gia: "<< endl;
	for (int i=0;i<n;i++){
		lp[i].inL();
	}
}
void Ql::inMax(){
	int nam;
	nam=lp[0].tinhnam();
	for (int i=0;i<n;i++){
		if (nam < lp[i].tinhnam()){
			nam =lp[i].tinhnam();
		}
	}
	cout <<"\nLaptop co so nam su dung nhieu nhat la: " << endl;
	for (int i=0;i<n;i++){
		if (lp[i].tinhnam()==nam){
			lp[i].inL();
		}
	}
}
void Ql::Xoa(){
	string hsx;
	cout <<"\nNhap hang san xuat can xoa: ";
	getline(cin,hsx);
	int j,i=0;
	do{
		if (lp[i].get_hang() == hsx){
			for (j=i;j<n-1;j++){
				lp[j]=lp[j+1];
			}
			--n;
		}
		else i++;
	}while(i<n);
	
	cout <<"\nDanh sach cac phan tu sau khi xoa la: " << endl;
	for (int i=0;i<n;i++){
		lp[i].inL();
	}
}


int main(){
	Ql ob;
	ob.nhapds();
	ob.sapXep();
	ob.inMax();
	ob.Xoa();
}