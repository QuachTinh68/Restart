#include <bits/stdc++.h>
using namespace std;
class Date {
private:
    int D, M, Y; //ngày, tháng, năm
public:
    int nhuan(); //kiểm tra năm nhuận
    int ngaythang(); //trả về số ngày trong tháng
    void nhap(); //có kiểm tra tính hợp lệ
    void xuat();
	int get_D(){
		return D;
	}
	int get_M(){
		return M;
	}
	int get_Y(){
		return Y;
	}
};
int Date::nhuan() {
	if ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0))
	    return 1;
	else
	    return 0;
	}
	
int Date::ngaythang() {
	if (M == 4 || M == 6 || M == 9 || M == 11)
	    return 30;
	else if (M == 2)
	    return 28 + nhuan();
	else
	    return 31;
}
	
void Date::nhap() {
	int S, k;
	do {
	    cout << "Nhap vao ngay thang nam: " << endl;
	    cin >> D >> M >> Y;
	    S = ngaythang();
	    if (D > 0 && D <= S && M >= 1 && M <= 12 && Y > 0)
	        k = 1;
	    else {
	        cout << "Khong co ngay nay trong nam!" << endl;
	        k = 0;
	    }
	} while (k == 0);
}

void Date::xuat(){
	cout << D << '/' << M << '/' << Y ;
}

class Canbo{
	string ma, hoten;
	public:
		Date ns;
		Canbo(){
			ma=hoten=" ";
		}
		Canbo (string m, string t){
			ma=m;
			hoten=t;
		}
		void set_ma(string m){
			ma=m;
		}
		void set_ten(string t){
			hoten=t;
		}
		string get_ma(){
			return ma;
		}
		string get_ten(){
			return hoten;
		}
		void nhapcb();
		void incb();
		bool operator > (Canbo a);
};
void Canbo::nhapcb(){
	cout << "\nNhap ma can bo: ";
	getline(cin,ma);
	cout << "\nNhap ten can bo: ";
	getline(cin,hoten);
	cout << "\nNgay sinh (dd/mm/yy): ";
	ns.nhap();
	cin.ignore();
}
void Canbo::incb(){
	cout << "\nMa can bo la: " << ma;
	cout << "\nTen can bo la: " << hoten;
	cout << "\nNgay vao co quan: "; ns.xuat();
}

bool Canbo::operator > (Canbo a){
	if (ns.get_Y() != a.ns.get_Y()){
		return ns.get_Y() > a.ns.get_Y();
	}
	if ( ns.get_M() != a.ns.get_M()){
		return ns.get_M() > a.ns.get_M();
	}
	if (ns.get_D() != a.ns.get_D()){
		return ns.get_D() > a.ns.get_D();
	}
	return 0;
}

class Giangvien : public Canbo{
	string donvi;
	float heso, phucap;
	public:
		Giangvien(){
			donvi=" ";
			heso=phucap =0.0;
		}
		Giangvien(string dv, float hs, float pc){
			donvi=dv;
			heso=hs;
			phucap=pc;
		}
		void set_dv(string dv){
			donvi=dv;
		}
		void set_heso(float hs){
			heso=hs;
		}
		void set_pc(float pc){
			phucap=pc;
		}
		string get_dv(){
			return donvi;
		}
		float get_hs(){
			return heso;
		}
		float get_pc(){
			return phucap;
		}
		void nhapgv();
		void ingv();
		float tinhTien();
};

void Giangvien::nhapgv(){
	nhapcb();
	cout << "\nNhap thong tin don vi: "; 
	getline(cin,donvi);
	cout << "\nNhap he so luong: ";
	cin >> heso;
	cout << "\nNhap phu cap chuc vu: ";
	cin >> phucap;
	cin.ignore();
}
float Giangvien::tinhTien(){
	return heso *1490000 + phucap;
}
void Giangvien::ingv(){
	incb();
	cout << "\nDon vi: " << donvi;
	cout << "\nHe so: " << heso;
	cout << "\nPhu cap: " << phucap;
	cout << "\nTien luong: " << fixed <<setprecision(0) << tinhTien() << endl;
}
class Quanli{
	Giangvien gv[50];
	int n;
	public:
		void nhapds();
		void inds();
		void sapxep();
		void intrungbinh();
		void indonvi();
};

void Quanli::nhapds(){
	do{
		cout << "\nNhap so luong giang vien: ";cin >> n;
		cin.ignore();
	}while (n>50);
	
	for (int i=0;i<n;i++){
		cout << "\nNhap thong tin can bo thu: " << i+1 << endl;
		gv[i].nhapgv();
	}
}
void Quanli::inds(){
	for(int i=0;i<n;i++){
		gv[i].ingv();
	}
}
void hoanvi(Giangvien &a, Giangvien &b){
	Giangvien tmp;
	tmp=a;
	a=b;
	b=tmp;
}

void Quanli::sapxep(){
	for (int i=0;i<n+1;i++){
		for (int j=i+1;j<n;j++){
			if (gv[i] > gv[j]){
				hoanvi(gv[i],gv[j]);
			}
		}
	}
	cout << "\nThong tin giang vien sau khi sap xep: "<<endl;
	for (int i=0;i<n;i++){
		gv[i].ingv();
	}
}

void Quanli::intrungbinh(){
	float tongluong=0;
	for(int i=0;i<n;i++){
		tongluong+=gv[i].tinhTien();
	}
	cout << "\nTONG SO LUONG CUA CAC GIANG VIEN LA: " 
	<< fixed << setprecision(0) << tongluong/n;
}

void Quanli::indonvi(){
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if(gv[i].get_dv() > gv[j].get_dv()){
					hoanvi(gv[i],gv[j]);
				}
	for (int i=0;i<n;i++){
		if (i==0 || gv[i].get_dv() != gv[i-1].get_dv())
			cout << "\n---MA DON VI: " << gv[i].get_dv() <<" ---" << endl;
		gv[i].ingv();
	}
}

int main(){
	Quanli ob;
	ob.nhapds();
	ob.sapxep();
	ob.intrungbinh();
	ob.indonvi();
}

