#include <bits/stdc++.h>
using namespace std;
class CanBo{
	string ma, hoten, gioitinh;
	public:
		string get_ma(){
			return ma;
		}
		string get_hoten(){
			return hoten;
		}
		string get_gioitinh(){
			return gioitinh;
		}
		void nhap(){
			cout << "\nNhap ma: ";
			getline(cin,ma);
			cout << "\nNhap ho ten: ";
			getline(cin, hoten);
			int c;
			do{
				cout << "\nNhap gioi tinh (1-Nam 2-Nu): "; cin >> c;
				if (c!=1 && c!=2){
					cout << "\nNhap sai, nhap lai." << endl;
				}
			}while(c!=1 && c!=2);
			if (c==1){
				gioitinh="Nam";
			}else{
				gioitinh="Nu";
			}
		}
		void in(){
			cout << ma << " " << hoten << " " << gioitinh << " ";
		}
};

class Date {
private:
    int D, M, Y; 
public:
	int get_day(){
		return D;
	}
	int get_month(){
		return M;
	}
	int get_year(){
		return Y;
	}
	void set_D(int d){
		D=d;
	}
	void set_M(int m){
		M=m;
	}
	void set_Y(int y){
		Y=y;
	}
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
    cout << D << '/' << M << '/' << Y << " ";
}


class CongNhan : public CanBo{
	int bac, songay;
	Date date;
	public:
		void set_bac(int b){
			bac=b;
		}
		void set_songay(int d){
			songay=d;
		}
		void set_date(int d, int m, int y){
			date.set_D(d);
			date.set_M(m);
			date.set_Y(y);
		}
		int get_bac(){
			return bac;
		}
		int get_songay(){
			return songay;
		}
		Date get_ngay(){
			return date;	
		}
		void nhapC(){
			nhap();
			do{
				cout << "\nNhap bac cua cong nhan(1-2-3): ";
				cin >> bac;
				if (bac!=1 && bac!=2 && bac!=3){
					cout << "\nNhap sai, nhap lai." << endl;
				}
			}while(bac!=1 && bac!=2 && bac!=3);
			cout << "\nNhap so ngay lam viec: "; cin >> songay;
			cin.ignore();
			cout << "\nNhap vao ngay ki hop dong: " << endl;
			date.nhap();
			cin.ignore();
		}
		long long tienLuong(){
			int tien;
			if (bac=1){
				tien=300000;
			}else if (bac=2){
				tien=350000;
			}else{
				tien=400000;
			}
			return songay*tien;
		}
		void inC(){
			
			in();
			cout << bac <<" "  << songay <<  " " <<  
			tienLuong() << endl;
		}
		bool operator > (CongNhan a){
			if (date.get_year() != a.date.get_year()){
				return date.get_year() > a.date.get_year();
			}
			if (date.get_month() != a.date.get_month()){
				return date.get_month() > a.date.get_month();
			}else{
				return date.get_day() > a.date.get_day();
			}
		}
};
class Quanli{
	CongNhan a[50];
	int n;
	public:
		void nhapds(){
			do{
				cout << "\nNhap so luong cong nhan: ";
				cin >> n;
				cin.ignore();
				if (n<=0 || n>50){
					cout << "\nNhap sai, vui long nhap lai." << endl;
				}
			}while(n<=0 || n>50);
			for (int i=0;i<n;i++){
				a[i].nhapC();
				for (int j=0;j<i;j++){
					if (a[j].get_ma() == a[i].get_ma()){
						cout << "\nNhap ma cong nhan bi trung, vui long nhap lai." << endl;
						a[i].nhapC();
						cout << endl;
					}
				}
			}
		}
		void sapXep(){
			for (int i=0;i<n-1;i++){
				for (int j=i+1;j<n;j++){
					if (a[i] > a[j]){
						CongNhan tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach cong nhan sau khi sap xep la: " << endl;
			for (int i=0;i<n;i++){
				a[i].inC();
			}
		}
		void inTB(){
			int cnt=0;
			long long tong=0;
			for (int i=0;i<n;i++){
				if (a[i].get_gioitinh() == "Nu"){
					tong+=a[i].tienLuong();
					cnt++;
				}
			}
			if (cnt!=0){
				cout << "\nLuong trung binh cua cac cong nhan nu la: "
				<< tong/cnt << endl;
			}else{
				cout << "\nKhong co nhan vien nu trong danh sach." << endl;
			}
		}
};
int main(){
	Quanli ob;
	ob.nhapds();
	ob.sapXep();
	ob.inTB();
}