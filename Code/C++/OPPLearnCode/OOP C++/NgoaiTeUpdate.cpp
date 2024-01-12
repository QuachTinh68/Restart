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
    cout << D << '/' << M << '/' << Y << " " ;
}

class GiaoDich{
	string ma;
	float sotien;
	public:
		Date date;
		GiaoDich(){
			ma=" ";
			sotien=0;
		}
		GiaoDich(string m, float t){
			ma=m;
			sotien=t;
		}
		void set_ma(string m){
			ma=m;
		}
		void set_sotien(float t){
			sotien=t;
		}
		string get_ma(){
			return ma;
		}
		float get_tien(){
			return sotien;
		}
		void nhap(){
			cout << "\nNhap ma giao dich: "	;
			getline(cin,ma);
//			cout << "\nNhap so tien giao dich: ";
//			cin >> sotien;
//			cin.ignore();
			date.nhap();
		}
		void in(){
			cout << ma << " "; 
			date.xuat();
		}
};

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
		NgoaiTe(int s, float tg, string lt){
			soluong =s;
			tygia=tg;
			loaitien=lt;
		}
		void set_soluong(int s){
			soluong = s;
		}
		void set_tygia(float tg){
			tygia=tg;
		}
		void set_loaitien(string lt){
			loaitien=lt;
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
			nhap();
			cout << "\nNhap so luong ngoai te: ";
			cin >> soluong;
			cout << "\nNhap ty gia: ";
			cin >> tygia;
			cin.ignore();
			cout << "\nNhap loai tien: ";
			getline(cin,loaitien);
			
		}
		float thanhTien(){
			return soluong*tygia;
		}
		void inN(){
			in();
			cout << soluong << " " << tygia << " " << loaitien 
			<< fixed << setprecision(0) << thanhTien();
		}
		bool operator == (NgoaiTe a){
			return loaitien == a.loaitien;
			
		}
};

class Quanli{
	NgoaiTe a[50];
	int n;
	public: 
		void nhapds(){
			do{
				cout << "\nNhap so luong giao dich: ";
				cin >> n;
				cin.ignore();
				if (n > 50 || n<0){
					cout << "\nNhap sai, vui long nhap lai!!" << endl;
				}
			}while(n<0 || n>50);
			for (int i=0;i<n;i++){
				a[i].nhapN();
			}
		}
		
		void tinhTong(){
			int tong=0;
			for (int i=0;i<n-1;i++){
				for (int j=i+1;j<n;j++){
					if (a[i].get_loaitien() != a[j].get_loaitien()){
						NgoaiTe tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			for (int i=0;i<n;i++){
				tong+=a[i].thanhTien();
			}
			cout << "\nTong so tien giao dich la: " << tong<< endl;
		}
		
		void xuatDieuKien(){
			long long dk=1000000000;
			cout << "\nDanh sach giao dich co so tien hon 1 ty la: " << endl;
			for (int i=0;i<n;i++){
				if (a[i].thanhTien() >= dk){
					a[i].inN();
				}
			}
		}
		
		void sapXep(){
			for (int i=0;i<n-1;i++){
				for (int j=i+1;j<n;j++){
					if (a[i].thanhTien() > a[j].thanhTien()){
						NgoaiTe tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach sau khi sap xep la: " << endl;
			for (int i=0;i<n;i++){
					a[i].inN();
			}
		}
};
 
int main(){
	Quanli ob;
	ob.nhapds();
	ob.tinhTong();
	ob.xuatDieuKien();
	ob.sapXep();
}