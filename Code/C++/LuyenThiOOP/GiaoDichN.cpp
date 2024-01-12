#include <bits/stdc++.h>
using namespace std;
class Date {
private:
    int D, M, Y; 
public:
	Date(){
		D=M=Y=0;
	}
	Date(int n,int m, int y){
		D=n;
		M=m;
		Y=y;
	}
	int get_nam(){
		return Y;
	}
	int get_thang(){
		return M;
	}
	int get_ngay(){
		return D;
	}
	
	void setNgay(int n){
		D=n;
	}
	void setThang(int m){
		M=m;
	}
	void setNam(int y){
		Y=y;
	}
    int nhuan();
    int ngaythang(); 
    void nhap();
    void xuat();
    int sosanh(Date d);
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

class Giaodich{
	string ma;
	float sotien;
	Date date;
	public:
		Giaodich(){
			ma="";
			sotien=0;
			date = Date();
		}
		Giaodich(string m, float s, int n, int mo, int y){ 
			ma=m;
			sotien=s;
			date=Date(n,mo,y);
		}
		void set_ma(string m){
			ma=m;
		}
		void set_sotien(float s){
			sotien=s;
		}
		void set_date(int n,int m, int y){
			date.setNgay(n);
			date.setThang(m);
			date.setNam(y);
		}
		string get_ma(){
			return ma;
		}
		float get_tien(){
			return sotien;
		}
		int get_ngay(){
			return date.get_ngay();
		}
		int get_thang(){
			return date.get_thang();
		}
		int get_nam(){
			return date.get_nam();
		}
		void nhapG(){
			cout << "\nNhap ma giao dich: ";
			getline(cin,ma);
			cout << "\nNhap ngay giao dich: ";
			date.nhap();
			cin.ignore();
		}
		void inG(){
			cout << ma << " " ; date.xuat();
		}
};
class Ngoaite : public Giaodich{
	int soluong;
	float tygia;
	string loaitien;
	public:
		Ngoaite(){
			soluong=0;
			tygia=0.0;
			loaitien=" ";
		}
		Ngoaite(int s, int t,string lt){
			soluong =s;
			tygia=t;
			loaitien=lt;
		}
		void set_sl(int s){
			soluong =s;
			
		}
		void set_tg(float t){
			tygia=t;
		}
		void set_loaitien(string s){
			loaitien = s;
		}
		int get_soluong(){
			return soluong;
		}
		float get_tygia(){
			return tygia;
		}
		string get_loaitien(){
			return loaitien;
		}
		void nhapN(){
			nhapG();
			cout << "\nNhap so luong: "; cin >> soluong;
			cout << "\nNhap ty gia: "; cin >> tygia;
			cin.ignore();
			cout << "\nNhap loai tien: "; getline(cin,loaitien);
		}
		float thanhTien(){
			return soluong*tygia;
		}
		void inN(){
			inG();
			cout << loaitien << " " << soluong << " " << tygia << " "
			<< fixed << setprecision(0) << thanhTien() << endl;
		}
		bool operator == (Ngoaite a){
			return loaitien == a.loaitien;
		}
};

class Quanli{
	Ngoaite a[50];
	int n;
	public:
		void nhapds(){
			do{
				cout <<"\nNhap so luong doi tuong: ";
				cin >> n;
				cin.ignore();
				if(n<=0 || n>50){
					cout << "\nNhap sai, nhap lai." << endl;
				}
			}while(n<=0 || n>50);
			for(int i=0;i<n;i++){
				a[i].nhapN();
				for(int j=0;j<i;j++){
					if (a[i].get_ma() == a[j].get_ma()){
						cout << "\nMa bi trung, vui long nhap lai." <<endl;
						a[i].nhapN();
					}
				}
			}
		}
		void tinhTongLoai(){
			for (int i=0;i<n;i++){
				for (int j=i+1;j<n;j++){
					if (a[i].get_loaitien() > a[j].get_loaitien()){
						Ngoaite tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			long long tongTien=0;
			for (int i=0;i<n;i++){
				tongTien+=a[i].thanhTien();
				if (a[i].get_loaitien()!=a[i+1].get_loaitien()||i==n-1){
					cout << "\n--Loai tien--" << a[i].get_loaitien() <<":"
					<< " " << fixed << setprecision(0) << tongTien << endl;
					tongTien=0;
				}
			}
		}
		void xuatDK(){
			long dk = 1000000000;
			int cnt=0;
			cout << "\nCanh giao dich co so tien tu 1 ty tro len la: " << endl;
			for (int i=0;i<n;i++){
				if (a[i].thanhTien() >= dk){
					a[i].inN();
					cnt++;
				}
			}
			if(cnt ==0){
				cout << "\nKhong co giao dich nao tren 1 ty." << endl;
			}
		}
		void sapXep(){
			for (int i=0;i<n-1;i++){
				for (int j=i+1;j<n;j++){
					if (a[i].thanhTien() < a[i].thanhTien()){
						Ngoaite tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach sau khi sap xep giam dan la: "  << endl;
			for (int i=0;i<n;i++){
				a[i].inN();
			}
		}
};

int main(){
	Quanli ob;
	ob.nhapds();
	ob.tinhTongLoai();
	ob.xuatDK();
	ob.sapXep();
}