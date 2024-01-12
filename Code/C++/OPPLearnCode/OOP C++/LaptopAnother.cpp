#include <bits/stdc++.h>
using namespace std;
class Computer{
	string ma, hang;
	int nam;
	double gia;
	private:
		Computer(){
			ma = hang = " ";
			nam = 0;
			gia=0.0;
		}
		Computer(string m , string h, int n, double g){
			ma = m;
			hang = h;
			nam = n;
			gia = g;
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
		void set_gia(double g){
			gia = g;
		}
		string get_ma(){
			return ma;
		}
		string get_hang(){
			return hang;
		}
		int get_nam(){
			return nam;
		}
		double get_gia(){
			return gia;
		}
		void nhap();
		void in();
};
void Computer::nhap(){
	cout << "\nNhap ma may tinh: ";
	getline(cin, ma);
	cout << "\nNhap hang may tinh: ";
	getline(cin, hang);
	cout << "\nNhap nam san xuat may tinh: ";
	cin >> nam;
	cin.ignore();
	cout << "\nNhap gia may tinh: ";
	cin >> gia;
	cin.ignore();
}
void Computer::in(){
	cout << ma <<" "
	<< hang <<" "
	<< nam <<" "
	<< gia <<" ";	
}

class Laptop : public Computer{
	float can, doday, kt;
	string hdh;
	public:
		Laptop(){
			can = doday = kt = 0.0;
			hdh=" ";
		}
		Laptop(float c, float d, float k, string h){
			can =c ;
			daoday = d;
			kt = k;
			hdh = h;
		}
		void set_can(float can){
			can = c;
		}
		void set_dd(float d){
			doday = d;
		}
		void set_kt(float k){
			kt = k;
		}
		void set_dd(float d){
			doday = d;
		}
		float get_can(){
			return can;
		}
		float get_dd(){
			return doday;
		}
		float get_kt(){
			return kt;
		}
		string get_hdh(){
			return hdh;
		}
		void nhapL();
		void inL();
		void tinhGia();
		int tinhNam();
		bool operator > (Laptop a);
};
float Laptop::tinhGia(){
	float cost;
	int nam=tinhNam();
	if (hdh == "Windows"){
		cost = gia - (nam * 0.1)*gia;
	}else{
		cost = gia - (nam*0.05)*gia;
	}
	return cost;
}

int Laptop::tinhNam(){
	return 2023-nam;
}
void Laptop::nhapL(){
	nhap();
	cout << "\nNhap can nang: ";
	cin >> can;
	cout << "\nNhap do day: ";
	cin >> doday;
	cout << "\nNhap kich thuoc: ";
	cin >> kt;
	cout << "\nNhap he dieu hanh: ";
	getline(cin,hdh);
}
void Laptop::inL(){
	cout << ma << " "
	<< hang << " "
	<< nam << " "
	<< gia << " " 
	<< can << " (gram) "
	<< doday << " (mm) "
	<< kt << " (inch) "
	<<	tinhNam() << " " << tinhGia() << endl;
}
bool Laptop::operator > (Laptop a){
	return tinhGia() > a.tinhGia();
}

class Quanli{
	Laptop a[50];
	int n;
	public:
		void nhapds();
		void inds();
		void sapXep();
		void inMax();
		void xoa();
};

void Quanli::nhapds(){
	do{
		cout << "\nNhap so luong laptop: ";
		cin >> n;
		cin.ignore();
	}while(n < 0 || n > 50);
	for (int i=0;i<n;i++){
		a[i].nhapL();
	}
}
void hv(Laptop &a, Laptop &b){
	Laptop tmp;
	tmp=a;
	a=b;
	b=tmp;
}
void Laptop::sapXep(){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (a[i] > a[j]){
				hv(a[i], a[j]);
			}
		}
	}
	cout <<"\nThong tin sau khi sap xep: " <<endl;
	for (int i=0;i<n;i++){
		a[i].inL();
	}
}

