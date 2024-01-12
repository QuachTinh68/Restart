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


class Giaodich{
	string ma;
	Date ngay;
	long sotien;
	public:
		Giaodich(){
			ma="";
			ngay=Date();
			sotien=0;
		}
		GiaoDich(string m, Date d, long st){
			ma=m;
			ngay=d;
			sotien = st;
		}
		void set_ma(string m){
			ma=m;
		}
		void set_ngay(Date d){
			ngay=d;
		}
		void set_sotien(long st){
			sotien = st;
		}
		string get_ma(){
			return ma;
		}
		Date get_ngay(){
			return ngay;
		}
		long get_sotien(){
			return sotien;
		}
		void nhap(){
			cout << "\nNhap ma giao dich: ";
			getline(cin, ma);
			cout << "\nNhap ngay giao dich: ";
			ngay.nhap();
			cin.ignore();
		}
		void in(){
			cout << ma << " " ; ngay.xuat();
		}
};
class Ngoaite : public Giaodich {
	int soluong;
	int tygia;
	string loaitien;
	public:
		Ngoaite(){
			soluong=tygia=0;
			loaitien="";
		}
		Ngoaite(int sl, int tg, string lt){
			soluong=sl;
			tygia=tg;
			loaitien=lt;
		}
		void set_sl(int sl){
			soluong=sl;
		}
		void set_tg(int tg){
			tygia=tg;
		}
		void set_lt(string lt){
			loaitien=lt;
		}
		int get_soluong(){
			return soluong;
		}
		int get_tygia(){
			return tygia;
		}
		string get_loatien(){
			return loaitien;
		}
		void nhapN(){
			nhap();
			cout << "\nNhap so luong: "; cin >> soluong;
			cout << "\nNhap ty gia: "; cin >> tygia;
			cin.ignore();
			cout << "\nNhap loai tien: ";
			getline(cin,loaitien);
		}
		long thanhTien(){
			return soluong*tygia;
		}
		void inN(){
			in();
			cout << loaitien << " " << soluong << " " 
			<< tygia << " " << thanhTien() << endl;
		}
		bool operator == (Ngoaite a){
			return loaitien == a.loaitien;
		}
};

class Quanli{
	int n;
	Ngoaite a[50];
	public:
		void nhapds(){
			do{
				cout << "\nNhap so luong doi tuong: ";
				cin >> n;
				cin.ignore();
				if (n<=0 || n>50){
					cout << "\nNhap sai,nhap lai." <<endl;
				}
			}while(n<=0 || n>50);
			for (int i=0;i<n;i++){
				a[i].nhapN();
				for (int j=0;j<i;j++){
					if (a[i].get_ma()==a[j].get_ma()){
						cout << "\nMa bi trung, nhap lai." << endl;
						a[i].nhapN();
						cout << endl;
					}
				}
			}
		}
};


int main(){
	Quanli ob;
	ob.nhapds();
}