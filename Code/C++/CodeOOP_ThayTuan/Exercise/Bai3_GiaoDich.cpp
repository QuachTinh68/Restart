#include <bits/stdc++.h>
using namespace std;

class Date {
private:
    int D, M, Y;
public:
    int nhuan();
    int ngaythang(); 
    void nhap(); 
    void xuat();
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

void Date::xuat() {
    cout << D << '/' << M << '/' << Y ;
}

class GiaoDich{
	string ma;
	float sotien;
	public:
		Date ngayGD;
		GiaoDich(){
			ma=" ";
			sotien=0.0;
		}
		GiaoDich(string m, float t){
			ma=m;
			sotien=t;
		}
		void set_ma(string m){
			ma=m;
		}
		void set_tien(float t){
			sotien=t;
		}
		string get_ma(){
			return ma;
		}
		float get_tien(){
			return sotien;
		}
		void nhap();
		void in();
};
void GiaoDich::nhap(){
	cout << "\nNhap ma giao dich: ";
	getline(cin,ma);
	cout << "\nNhap ngay giao dich: ";
	ngayGD.nhap();
//	cout << "\nNhap so tien giao dich: ";
//	cin >> sotien;
//	cin.ignore();
}
void GiaoDich::in(){
	cout << "\nMa giao dich la: " << ma;
	cout << "\nNgay giao dich la: "; ngayGD.xuat();
//	cout << "\nSo tien giao dich la: "<<fixed << setprecision(0) << sotien;
}

class NgoaiTe : public GiaoDich{
	int soluong;
	float tygia;
	string loaitien;
	public:
		NgoaiTe(){
			soluong=0;
			tygia=0.0;
			loaitien=" ";
		}
		NgoaiTe(int sl, float tg, string l){
			soluong=sl;
			tygia=tg;
			loaitien=l;
		}
		void set_soluong(int sl){
			soluong=sl;
		}
		void set_tyia(float tg){
			tygia=tg;
		}
		void set_loai(string l){
			loaitien=l;
		}
		int get_sl(){
			return soluong;
		}
		float get_tygia(){
			return tygia;
		}
		string get_loaitien(){
			return loaitien;
		}
		void nhapNT();
		void inNT();
		bool operator == (NgoaiTe a);
		float tinhTien(){
			return tygia*soluong;
		}
		
};
void NgoaiTe::nhapNT(){
	nhap();
	cout << "\nNhap so luong: "; cin >> soluong;
	cout << "\nNhap ty gia: " ; cin >> tygia;
	cin.ignore();
	cout << "\nNhap loai tien: ";getline(cin,loaitien);
}
void NgoaiTe::inNT(){
	in();
	cout << "\nSo luong ngoai te la: " << soluong;
	cout << "\nTy gia ngoai te la: " << tygia;
	cout << "\nLoai tien ngoai te la: " << loaitien;
	cout << "\nSo tien giao dich la: " << fixed << setprecision(0)<< tinhTien() << endl;
}
bool NgoaiTe::operator == (NgoaiTe a){
	return loaitien == a.loaitien;
}

class QuanLi{
	NgoaiTe nt[50];
	int n;
	public:
		void nhapds();
		void tinhTong();
		void xuatDieuKien();
		void sapXep();
};

void QuanLi::nhapds(){
	do{
		cout << "\nNhap so luong doi tuong: ";
		cin>> n;
		cin.ignore();
	}while(n>50);
	for(int i=0;i<n;i++){
		cout << "\nNhap thong tin giao dich thu: " << i+1 << endl;
		nt[i].nhapNT();
	}
}
void QuanLi::tinhTong(){
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (nt[i].get_loaitien() > nt[j].get_loaitien()){
				NgoaiTe tmp;
				tmp = nt[i];
				nt[i]= nt[j];
				nt[j]=tmp;
			}
		}
	}
	long long tong=0;
	for (int i=0;i<n;i++){
		tong+=nt[i].tinhTien();
		if (nt[i].get_loaitien() != nt[i+1].get_loaitien()){
			cout << "Tong tien: " << nt[i].get_loaitien() << " | " << tong << endl;
			tong=0;
		}
	}
}
void QuanLi::xuatDieuKien(){
	int dk=1000000000;
	cout << "\nDanh sach cac giao dich tu 1 ty tro len la: " << endl;
	for (int i=0;i<n;i++){
		if (nt[i].tinhTien()>=dk){
			nt[i].inNT();
		}
	}
}
void QuanLi::sapXep(){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (nt[i].tinhTien() > nt[j].tinhTien()){
				NgoaiTe tmp;
				tmp = nt[i];
				nt[i]= nt[j];
				nt[j]=tmp;
			}
		}
	}
	cout << "\nDanh sach sau khi sap xep la: " << endl;
	for(int i=0;i<n;i++){
		nt[i].inNT();
	}
}


int main(){
	QuanLi ob;
	ob.nhapds();
	ob.tinhTong();
	ob.sapXep();
	ob.xuatDieuKien();
	
}