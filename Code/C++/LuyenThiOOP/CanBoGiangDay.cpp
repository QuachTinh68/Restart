#include <bits/stdc++.h>
using namespace std;
class Canbo{
	string ma, ho, ten, donvi;
	float heso;
	public:
		Canbo(){
			ma=ho=ten=donvi="";
			heso=0;
		}
		Canbo(string m, string h,string t, string dv, float hs){
			ma=m;
			ho=h;
			ten=t;
			donvi=dv;
			heso=hs;
		}
		void set_ma(string m){
			ma=m;
		}
		void set_ho(string h){
			ho=h;
		}
		void set_ten(string t){
			ten=t;
		}
		void set_donvi(string dv){
			donvi=dv;
		}
		void set_heso(float hs){
			heso=hs;
		}
		string get_ma(){
			return ma;
		}
		string get_ho(){
			return ho;
		}
		string get_ten(){
			return ten;
		}
		string get_donvi(){
			return donvi;
		}
		float get_heso(){
			return heso;
		}
		void nhap(){
			cout << "\nNhap ma can bo: ";
			getline(cin,ma);
			cout << "\nNhap ho: ";
			getline(cin,ho);
			cout << "\nNhap ten can bo: ";
			getline(cin,ten);
			cout << "\nNhap don vi: ";
			getline(cin,donvi);
			cout << "\nNhap he so :";
			cin >> heso;
			cin.ignore();
		}
		void in(){
			cout << "\nHo va ten: " << ho+" "+ten;
			cout << "\nDon vi: " << donvi;
			cout << "\nHe so luong: " << heso;
		}
		bool operator > (Canbo a){
			if (ten==a.ten){
				return ho > a.ho;
			}
			return ten > a.ten;
		}
		
};

class CanBoGiangDay : public Canbo{
	float hesocv;
	int nam;
	public:
		CanBoGiangDay(){
			hesocv=0.0;
			nam=0;
		}
		CanBoGiangDay(float cv, int y){
			hesocv=cv;
			nam=y;
		}
		void set_hesocv(float cv){
			hesocv=cv;
		}
		void set_nam(int y){
			nam=y;
		}
		float get_hesocv(){
			return hesocv;
		}
		int get_nam(){
			return nam;
		}
		void nhapC(){
			nhap();
			cout << "\nNhap he so chuc vu: ";
			cin >>hesocv;
			cout << "\nNhap nam bat dau cong tac: ";
			cin >> nam;
			cin.ignore();
		}
		int tinhNam(){
			return 2024-nam;
		}
		float tinhLuong(){
			float hesopc;
			if (nam < 5){
				hesopc=0;
			}else if (nam >=5 and nam <15){
				hesopc=0.1;
			}else if(nam >=15 and nam < 25){
				hesopc=0.2;
			}else if(nam >=25){
				hesopc=0.3;
			}
			return 1800000*(get_heso() + hesocv +hesopc);
		}
		void inC(){
			in();
			cout << "\nHe so chuc vu: " << hesocv;
			cout << "\nSo nam cong tac: " << tinhNam();
			cout << "\nLuong: "<< 
			fixed << setprecision(0)<< tinhLuong() << endl;
		}
		
};

class Quanli{
	CanBoGiangDay a[50];
	int n;
	public:
		void nhapds(){
			do{
				cout << "\nNhap so luong can bo: ";
				cin >> n; cin.ignore();
				if (n<=0 || n>50){
					cout << "\nNhap sai, nhap lai" <<endl;
				}
			}while(n<=0 || n>50);
			for (int i=0;i<n;i++){
				a[i].nhapC();
				for(int j=0;j<i;j++){
					if(a[i].get_ma() == a[j].get_ma()){
						cout << "\nNhap ma bi trung, nhap lai" << endl;
						a[i].nhapC();
					}
				}
			}
		}
		
		void sapXep(){
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if (a[i] > a[j]){
						CanBoGiangDay tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach sau khi sap xep la: " <<endl;
			for (int i=0;i<n;i++){
				a[i].inC();
			}
		}
		void inNamItNhat(){
			int m=a[0].tinhNam();
			for(int i=0;i<n;i++){
				if (a[i].tinhNam() < m){
					m=a[i].tinhNam();
				}
			}
			cout << "\nDanh sach can bo co nam cong tac it nhat: " << endl;
			for(int i=0;i<n;i++){
				if (a[i].tinhNam() == m){
					a[i].inC();
				}
			}
		}
		void tinhLuongCaoNhat(){
		    for (int i = 0; i < n; i++) {
		        for (int j = i + 1; j < n; j++) {
		            if (a[i].get_donvi() > a[j].get_donvi()) {
		                CanBoGiangDay tmp = a[i];
		                a[i] = a[j];
		                a[j] = tmp;
		            }
		        }
		    }
		
		    cout << "\nCan bo co luong cao nhat theo tung don vi la: " << endl;
		
		    string currentUnit = ""; 
		    int maxSalary = 0; 
		
		    for (int i = 0; i < n; i++) {
		        if (a[i].get_donvi() != currentUnit) { 
		            if (maxSalary > 0) {
		                cout << "\nDon vi: " << currentUnit << endl;
		                for (int j = 0; j < n; j++) {
		                    if (a[j].get_donvi() == currentUnit && a[j].tinhLuong() == maxSalary) {
		                        a[j].inC();
		                    }
		                }
		            }
		
		            currentUnit = a[i].get_donvi(); 
		            maxSalary = 0;
		        }
		
		        if (a[i].tinhLuong() > maxSalary) { 
		            maxSalary = a[i].tinhLuong();
		        }
		    }
		
		    if (maxSalary > 0) { 
		        cout << "\nDon vi: " << currentUnit << endl;
		        for (int j = 0; j < n; j++) {
		            if (a[j].get_donvi() == currentUnit && a[j].tinhLuong() == maxSalary) {
		                a[j].inC();
		            }
		        }
		    }
		}
};

int main(){
	Quanli ob;
	ob.nhapds();
	ob.sapXep();
	ob.inNamItNhat();
	ob.tinhLuongCaoNhat();
}