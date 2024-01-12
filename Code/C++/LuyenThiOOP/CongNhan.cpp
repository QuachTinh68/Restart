#include <bits/stdc++.h>
using namespace std;

class Canbo{
	string ma, hoten, gioitinh;
	public:
		string get_ma(){
			return ma;
		}
		string get_hoten(){
			return hoten;
		}
		string get_gt(){
			return gioitinh;
		}
		void nhap(){
			cout << "\nNhap ma can bo: ";
			getline(cin,ma);
			cout << "\nNhap ho ten can bo: ";
			getline(cin,hoten);
			int gt;
			do{
				cout << "\nNhap gioi tinh (0=Nam --- 1=Nu) : ";
				cin >> gt;
				cin.ignore();
				if(gt!=0 &&  gt!=1){
					cout << "\nNhap sai vui long nhap lai." << endl;
				}
			}while(gt!=0 && gt!=1);
			if (gt==0){
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
    int D, M, Y; //ngày, tháng, năm
public:
	int get_D(){
		return D;
	}
	int get_M(){
		return M;
	}
	int get_Y(){
		return Y;
	}
    int nhuan(); //kiểm tra năm nhuận
    int ngaythang(); //trả về số ngày trong tháng
    void nhapD(); //có kiểm tra tính hợp lệ
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
void Date::nhapD() {
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


class Congnhan : public Canbo{
	int bac, songay;
	Date date;
	public:	
		int get_bac(){
			return bac;
		}
		int get_ngay(){
			return songay;
		}
		int get_thang(){
			return date.get_M();
		}
		int get_nam(){
			return date.get_Y();
		}
		void nhapC(){
			nhap();
			do{
				cout << "\nNhap bac can bo (1-2-3): ";
				cin >> bac;
				cin.ignore();
				if (bac !=1 && bac!=2 && bac!=3){
					cout << "\nNhap sai, nhap lai." << endl;
				}
			}while(bac !=1 && bac!=2 && bac!=3);
			cout << "\nNhap so ngay lam viec: "; cin >> songay;
			cin.ignore();
			cout << "\nNhap ngay ki hop dong " << endl;
			date.nhapD();
			cin.ignore();
		}
		long long tinhTien(){
			if(bac==1){
				return songay*300000;
			}else if (bac==2){
				return songay*350000;
			}else{
				return songay*400000;
			}
		}
		void inC(){
			   in();
			   cout << bac << " " << songay << " "; 
			   tinhTien() << endl;
		}
		bool operator > (Congnhan a){
			if (date.get_Y() != a.date.get_Y()){
				return date.get_Y() > a.date.get_Y();
			}
			if (date.get_M() != a.date.get_M()){
				return date.get_M() > a.date.get_M();
			}
			return date.get_D() > a.date.get_D();
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
				if (n<=0 || n > 50){
					cout << "\nNhap sai, nhap lai." << endl;
				}
			}while(n<=0 || n > 50);
			for (int i=0;i<n;i++){
				a[i].nhapC();
				for (int j=0;j<i;j++){
					if (a[i].get_ma() == a[j].get_ma()){
						cout << "\nNhap ma bi trung , nhap lai." << endl;
						a[i].nhapC();
						cout << endl;
					}
				}
			}
		}
		void sapXep(){
			for (int i=0;i<n;i++){
				for (int j=i+1;j<n;j++){
					if (a[i] > a[j]){
						Congnhan tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach sau khi sap xep la: " << endl;
			for (int i=0;i<n;i++){
				a[i].inC();
			}
		}
		void inNu(){
			int cnt=0;
			cout << "\nDanh sach cac cong nhan nu la: " << endl;
			for (int i=0;i<n;i++){
				if (a[i].get_gt()== "Nu"){
					a[i].inC();
					cnt++;
				}
			}
			if (cnt==0){
				cout << "\nKhong co cong nhan nu nao";
			}
		}
};

int main(){
	Quanli ob;
	ob.nhapds();
	ob.sapXep();
	ob.inNu();
}