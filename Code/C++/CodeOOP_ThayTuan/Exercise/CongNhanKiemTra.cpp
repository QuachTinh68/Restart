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
    int get_nam(){
    	return Y;
	}
	int get_thang(){
		return M;
	}
	int get_ngay(){
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
        cout << "\nNhap vao ngay thang nam ki hop dong(dd mm yy): " << endl;
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
    cout << D << '/' << M << '/' << Y << endl;
}

class Canbo{
	string ma, hoten, gioitinh;
	public:
		Canbo(){
			ma=hoten=gioitinh=" ";
		}
		Canbo(string m, string ht, string gt){
			ma=m;
			hoten=ht;
			gioitinh=gt;
		}
		void set_ma(string m){
			ma=m;
		}
		void set_hoten(string ht){
			hoten=ht;
		}
		void set_gioitinh(string gt){
			gioitinh=gt;
		}
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
			cout <<"\nNhap ma can bo: ";
			getline(cin,ma);
			cout <<"\nNhap ho ten can bo: ";
			getline(cin, hoten);
			int n;
		    do {
		        cout << "\nNhap gioi tinh 1 hoac 2 (1:Nam -- 2:Nu): ";
		        cin >> n;
		        if (n != 1 && n != 2) {
		            cout << "\nNhap sai, vui long nhap lai." << endl;
		        }
		    } while (n != 1 && n != 2);
		
		    if (n == 1) {
		        gioitinh = "Nam";
		    } else{
		        gioitinh = "Nu";
		    	}
		}
		void in(){
			cout << ma<< " " << hoten << " " << gioitinh <<" ";
		}	
};

class Congnhan : public Canbo{
	int bac, songay;
	public:
		Date date;
		Congnhan(){
			bac=songay=0;
		}
		Congnhan(int b,int n){
			bac=b;
			songay=n;
		}
		int get_bac(){
			return bac;
		}
		int get_songay(){
			return songay;
		}
		void nhapC(){
			nhap();
			int b;			
			do{
				cout << "\nNhap bac cua cong nhan(1,2,3): ";
				cin >> b;
				if (b!=1 && b!=2 && b!=3){
					cout << "\nNhap sai, vui long nhap lai." << endl;
				}
			}while(b!=1 && b!=2 && b!=3);
			bac=b;
			cout << "\nNhap so ngay lam viec: "; cin >> songay;
			cin.ignore();
			date.nhap();
			cin.ignore();
		}
		float tinhTien(){
			float tienluong=0;
			if(bac==1){
				tienluong=songay*300000;
			}else if (bac==2){
				tienluong=songay*350000;
			}else{
				tienluong=songay*400000;
			}
			return tienluong;
		}
		void inC(){
			in();
			cout << bac << " " << songay << " " 
			<< fixed << setprecision(0) << tinhTien() << " ";
			date.xuat();
		}
		bool operator > (Congnhan a){
			if (date.get_nam() != a.date.get_nam()){
				return date.get_nam() > a.date.get_nam();
			}
			if (date.get_thang() != a.date.get_thang()){
				return date.get_thang() > a.date.get_thang();
			}
			if (date.get_ngay() != a.date.get_ngay()){
				return date.get_ngay() >  a.date.get_ngay();
			}
			return 0;
		}
};

class Quanli{
	Congnhan a[50];
	int n;
	public:
		void nhapds(){
			do{
				cout << "\nNhap so luong cong nhan: ";cin >> n;
				cin.ignore();
				if (n<=0 || n>50){
					cout << "\nNhap sai vui long nhap lai." << endl;
				}
			}while(n<=0 || n>50);
			for(int i=0;i<n;i++){
				cout << "\nNhap thong tin cong nhan thu: " << i+1 << endl;
				a[i].nhapC();
				for (int j=0;j<i;j++){
					if (a[i].get_ma() == a[j].get_ma()){
						cout << "\nMa bi trung vui long nhap lai." << endl;
						a[i].nhapC();
						cout << endl;
					}
				}
			}
		}
		void sapXep(){
			for (int i=0;i<n-1;i++){
				for (int j=i+1;j<n;j++){
					if (!(a[i] > a[j])){
						Congnhan tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach sau khi sap xep giam dan la: " << endl;
			for(int i=0;i<n;i++){
				a[i].inC();
			}
		}
		
		void inTB(){
			int tong=0, cnt=0;
			for (int i=0;i<n;i++){
				if (a[i].get_gioitinh() == "Nu"){
					tong+=a[i].tinhTien();
					cnt++;
				}
			}
			if (cnt != 0) {
			    cout << "\nLuong trung binh cua cong nhan nu la: " 
			    << fixed << setprecision(0) << tong/cnt << endl;
			} else {
			    cout << "\nKhong co cong nhan nu nao de tinh luong trung binh." << endl;
			}
		}
};

int main(){
	Quanli ob;
	ob.nhapds();
	ob.sapXep();
	ob.inTB();
}