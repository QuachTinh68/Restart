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
//    int sosanh(Date d);
	int get_Y(){
		return Y;
	}
	int get_M(){
		return M;
	}
	int get_D(){
		return D;
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

void Date::xuat() {
    cout << D << '/' << M << '/' << Y << " ";
}

class Canbo{
	string ma,hoten;
	public:
		Date ngay;
		Canbo(){
			ma=hoten=" ";
		}
		Canbo(string m, string ht){
			ma=m;
			hoten=ht;
		}
		void set_ma(string m){
			ma=m;
		}
		void set_hoten(string ht){
			hoten=ht;
		}
		string get_ma(){
			return ma;
		}
		string get_hoten(){
			return hoten;
		}
		void nhap(){
			cout << "\nNhap ma can bo: ";
			getline(cin,ma);
			cout << "\nNhap ho ten can bo: ";
			getline(cin,hoten);
			ngay.nhap();
		}
		void in(){
			cout << ma  << " " << hoten << " " ; ngay.xuat();
		}
		bool operator > (Canbo a){
			if (ngay.get_Y() != a.ngay.get_Y()){
				return ngay.get_Y() >  a.ngay.get_Y();
			}
			if (ngay.get_M() != a.ngay.get_M()){
				return ngay.get_M() >  a.ngay.get_M();
			}
			if (ngay.get_D() != a.ngay.get_D()){
				return ngay.get_D() >  a.ngay.get_D();
			}
			return 0;		
		}
};

class Giangvien : public Canbo{
	string donvi;
	float heso, phucap;
	public:
		Giangvien(){
			donvi=" ";
			heso=phucap=0.0;
		}
		Giangvien(string dv, float hs, float pc){
			donvi=dv;
			heso=hs;
			phucap=pc;
		}
		void set_donvi(string dv){
			donvi=dv;
		}
		void set_heso(float hs){
			heso=hs;
		}
		void set_phucap(float pc){
			phucap=pc;
		}
		string get_donvi(){
			return donvi;
		}
		float get_heso(){
			return heso;
		}
		float get_phucap(){
			return phucap;
		}
		void nhapGV(){
			nhap();
			cin.ignore();
			cout << "\nNhap don vi: ";
			getline(cin,donvi);
			cout << "\nNhap he so luong: ";
			cin >> heso;
			cout << "\nNhap phu cap: ";
			cin >> phucap;
			cin.ignore();
		}
		float tinhLuong(){
			return heso*1490000 + phucap;
		}
		void inGV(){
			in();
			cout << donvi <<" "<< heso << " " << phucap 
			<< fixed << setprecision(0) << tinhLuong() << endl;
		}
};

class Quanli{
	Giangvien gv[50];
	int n;
	public:
		void nhapds(){
			do{
				cout << "\nNhap so luong giang vien: ";
				cin >> n; cin.ignore();
				if (n>50 || n ==0){
					cout << "Nhap sai, vui long nhap lai.";
				}
			}while (n<=0 && n>50);
			for (int i=0;i<n;i++){
				cout << "\nNhap giang vien thu: " << i+1 << endl;
				gv[i].nhapGV();
				for (int j=0;j<i;j++){
					if (gv[i].get_ma() == gv[j].get_ma()){
						cout << "\nMa bi trung vui long nhap lai." << endl;
						gv[i].nhapGV();
						cout << endl;
					}
				}
			}
		}
		void sapXep(){
			for (int i=0;i<n;i++){
				for (int j=i+1;j<n;j++){
					if (gv[i] > gv[j]){
						Giangvien tmp;
						tmp=gv[i];
						gv[i]=gv[j];
						gv[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach sau khi sap xep la: " << endl;
			for (int i=0;i<n;i++){
				gv[i].inGV();
				cout << endl;
			}
		}
		void inLuong(){
			int cnt=0;
			long long tong=0;
			for (int i=0;i<n;i++){
				tong+=gv[i].tinhLuong();
				cnt++;
			}
			cout << "\nLuong trung binh cua cac giang vien da nhap la: " << tong/cnt << endl;
		}
		void inBangLuong(){
			for (int i=0;i<n;i++){
				for (int j=i+1;j<n;j++){
					if (gv[i].get_donvi() > gv[j].get_donvi()){
						Giangvien tmp;
						tmp=gv[i];
						gv[i]=gv[j];
						gv[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach bang luong theo tung don vi la: " << endl;
			for (int i=0;i<n;i++){
				if (i==0 || gv[i].get_donvi() != gv[i-1].get_donvi()){
					cout << "\n ---MA DON VI: " <<gv[i].get_donvi() << "---" << endl;
				}
				gv[i].inGV();
				cout << endl;
			}
		}
		void xoa(){
			cout << "\nNhap ma can bo can xoa: ";
			string s;
			getline(cin,s);
			int i=0;
			do{
				if (gv[i].get_ma() == s){
					for (int j=i;j<n-1;j++){
						gv[j]=gv[j+1];
					}
					n--;
				}else i++;
			}while (i<n);
			cout << "\nDanh sach sau khi xoa la: " << endl;
			for (int i=0;i<n;i++){
				gv[i].inGV();
				cout << endl;
			}
		}
		void them(){
			if(n<50){
				Giangvien gvn;
				cout << "\nNhap giao vien can them: " <<endl;
				gvn.nhapGV();
				gv[n]=gvn;
				n++;
			}else{
				cout << "\nDanh sach day!!" << endl;
			}
		}
		void timKiem(){
			cout << "\nNhap tu khoa can tim kiem: " << endl;
			string s;
			getline(cin,s);
			cout << "\nDanh sach don vi co tu khoa " << s << " la: " <<endl;
			for (int i=0;i<n;i++){
				if (gv[i].get_donvi().find(s) != string::npos){
					gv[i].inGV();
					cout << endl;
				}
			}
		}
	
};

int main(){
	Quanli ob;
	ob.nhapds();
	ob.sapXep();
	ob.inLuong();
	ob.inBangLuong();
	ob.them();
	ob.xoa();
	ob.timKiem();
}
