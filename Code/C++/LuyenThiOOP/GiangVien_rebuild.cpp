#include <bits/stdc++.h>
using namespace std;


class Date {
private:
    int D, M, Y; 
public:
	Date(){
		D=M=Y=0;
	}
	Date(int d, int m, int y){
		D=d;
		M=m;
		Y=y;
	}
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


class Canbo{
	string ma, hoten;
	Date date;
	public:
		Canbo(){
			ma=hoten="";
			date=Date();
		}
		Canbo(string m, string ht, Date ngay){
			ma=m;
			hoten=ht;
			date=ngay;
		}
		void set_ma(string m){
			ma=m;
		}
		void set_hoten(string ht){
			hoten=ht;
		}
		void set_date(Date ngay){
			date=ngay;
		}
		string get_ma(){
			return ma;
		}
		string get_hoten(){
			return hoten;
		}
		Date get_date(){
			return date;
		}
		void nhap(){
			cout << "\nNhap ma can bo: ";
			getline(cin,ma);
			cout << "\nNhap ho ten can bo: ";
			getline(cin,hoten);
			cout << "\nNhap ngay vao co quan: ";
			date.nhap();
			cin.ignore();
		}
		void in(){
			cout << ma <<  " "
			<< hoten << " ";
			date.xuat(); 
		}
		bool operator > (Canbo a){
			if (date.get_year() != a.date.get_year()){
				return date.get_year() > a.date.get_year();
			}
			if (date.get_month() != a.date.get_month()){
				return date.get_month() > a.date.get_month();
			}
			else{
				return date.get_day() > a.date.get_day();
			}
		}
};

class Giangvien : public Canbo{
	string donvi;
	float heso;
	long phucap;
	public:
		Giangvien(){
			donvi="";
			heso=0;
			phucap=0;
		}
		Giangvien(string dv, float hs, long pc){
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
		void set_phucap(long pc){
			phucap=pc;
		}
		string get_donvi(){
			return donvi;
		}
		float get_heso(){
			return heso;
		}
		long get_phucap(){
			return phucap;
		}
		void nhapG(){
			nhap();
			cout << "\nNhap don vi: ";
			getline(cin,donvi);
			cout << "\nNhap he so luong: ";
			cin >> heso;
			cout << "\nNhap phu cap: ";
			cin >> phucap;
			cin.ignore();
		}
		long tinhTien(){
			return (heso * 1490000) + phucap;
		}
		void inG(){
			in();
			cout << donvi <<" " << heso << " " << phucap 
			<< " " << tinhTien() << endl;
	}
};

class Quanli{
	Giangvien a[50];
	int n;
	public:
		void nhapds(){
			do{
				cout << "\nNhap so luong giang vien: "; cin >> n;
				cin.ignore();
				if (n<=0 || n>50){
					cout << "\nNhap sai, vui long nhap lai." << endl;
				}
			}while(n<=0 || n>50);
			cout << "\nNhap thong tin cho cac Giang Vien: " << endl;
			for (int i=0;i<n;i++){
				a[i].nhapG();
				for (int j=0;j<i;j++){
					if (a[i].get_ma() == a[j].get_ma()){
						cout << "\nNhap ma bi trung, nhap lai: " << endl;
						a[i].nhapG();
						cout << endl;
					}
				}
				
			}
		}
		void sapXep(){
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if (a[i] > a[j]){
						Giangvien tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach Giang vien sau khi sap xep tang theo ngay thang: " << endl;
			for (int i=0;i<n;i++){
				a[i].inG();
			}
		}
		void inTB(){
			int cnt=0;
			int tong=0;
			for (int i=0;i<n;i++){
				tong +=a[i].tinhTien();
				cnt++;
			}
			if (cnt != 0){
				cout << "\nLuong trung binh cua cac giang vien da nhap la: ";
				cout << tong/cnt << endl;
			}else{
				cout << "\nDanh sach rong." << endl;
			}
		}
		void inBangLuong(){
			for (int i=0;i<n-1;i++){
				for (int j=i+1;j<n;j++){
					if (a[i].get_donvi() > a[j].get_donvi()){
						Giangvien tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;		
					}
				}
			}
			cout << "\nBang luong theo don vi la: " << endl;
			for(int i=0;i<n;i++){
				if (i==0 || a[i].get_donvi() != a[i-1].get_donvi()){
					cout << "\nDon vi: " << a[i].get_donvi() << endl;
				}
				a[i].inG();
			}
		}
		void them(){
			if (n >= 50) {
		        cout << "\nDanh sach giang vien da day, khong the them moi." << endl;
		        return;
		    }
			Giangvien add;
			cout << "\nNhap thong tin giang vien muon them: " << endl;
			add.nhapG();
			bool check=true;
			for (int i=0;i<n;i++){
				if (a[i].get_ma() == add.get_ma()){
					check=false;
				}
			}
			if (check){
				a[n]=add;
				n++;
				cout << "\nDa them giao vien." << endl;
			}else{
				cout << "\nMa giang vien moi them bi trung." << endl;
			}
			cout << "\nDanh sach giang vien la sau khi them la: " << endl;
			for (int i=0;i<n;i++){
				a[i].inG();
			}
		}
	void xoa() {
	    string s;
	    cout << "\nNhap ma giao vien muon xoa: ";
	    getline(cin, s);
	    int i;
	    for (i = 0; i < n; i++) {
	        if (a[i].get_ma() == s) {
	            break; // Tìm vị trí của giảng viên cần xóa
	        }
	    }
	    if (i == n) {
	        cout << "\nKhong tim thay giao vien co ma " << s << endl;
	        return;
	    }
	    // Dịch chuyển các phần tử sau vị trí i lên 1 vị trí
	    for (int j = i; j < n - 1; j++) {
	        a[j] = a[j + 1];
	    }
	    n--; // Giảm số lượng giảng viên sau khi xóa
	    cout << "\nDa xoa giao vien co ma " << s << endl;
	}
	void inMax(){
		long h=a[0].tinhTien();
		for(int i=0;i<n;i++){
			if (a[i].tinhTien() > h){
				h=a[i].tinhTien();
			}
		}
		cout << "\nThong tin giang vien co luong cao nhat: " << endl;
		for (int i=0;i<n;i++){
			if(a[i].tinhTien() == h){
				a[i].inG();
			}
		}
	}
	
	void inLuongTheoTungDonvi(){
		for (int i=0;i<n-1;i++){
			for (int j=i+1;j<n;j++){
				if(a[i].get_donvi() > a[j].get_donvi()){
					Giangvien tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
				}
			}
		}
		long long tong=0;
		cout << "\nDanh sach tong luong cua tung don vi la: " << endl;
		for(int i=0;i<n;i++){
			tong+=a[i].tinhTien();
			if (a[i].get_donvi()!=a[i+1].get_donvi()){
				cout <<"\nDon vi: " << a[i].get_donvi() << ": " << tong;
				tong=0;
			}
		}
	}
	
	void timKiemTheoDonVi() {
	    string tukhoa;
	    cout << "\nNhap tu khoa can tim kiem: " << endl;
	    getline(cin, tukhoa);
	    bool found = false;
	    cout << "Cac giao vien co chua tu khoa can tim kiem la: " << endl;
	    for (int i = 0; i < n; i++) {
	        if (a[i].get_donvi().find(tukhoa) != string::npos) {
	            a[i].inG();
	            cout << endl;
	            found = true;
	        }
	    }
	    if (!found) {
	        cout << "Khong tim thay giang vien nao chua tu khoa " << tukhoa << endl;
	    }
	}

//		Làm thêm các chức năng thêm, sửa, xóa, ...
};
 
int main(){
	Quanli ob;
	ob.nhapds();
//	ob.inBangLuong();
//	ob.inTB();
//	ob.sapXep();
//	ob.them();
//	ob.xoa();
//	ob.inMax();
//	ob.inLuongTheoTungDonvi();
	ob.timKiemTheoDonVi();
}
/**
10
GV001
Nguyen Van A
1 1 2023
Khoa A
3.5
2000000
GV002
Tran Thi B
15 5 2022
Khoa B
2.7
1500000
GV003
Le Van C
10 10 2023
Khoa A
3.2
180000
GV004
Pham Van D
5 6 2024
Khoa C
2.9
1600000
GV005
Hoang Thi E
12 12 2023
Khoa B
3.0
1700000
GV006
Tran Van F
8 8 2024
Khoa A
3.8
2100000
GV007
Do Thi G
20 4 2022
Khoa C
2.5
1400000
GV008
Nguyen Van H
11 9 2024
Khoa A
3.4
1900000
GV009
Le Van I
9 3 2023
Khoa B
2.8
1600000
GV010
Vu Thi K
25 7 2022
Khoa C
2.6
1700000
*/