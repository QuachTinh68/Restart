#include <bits/stdc++.h>
using namespace std;
class Hang{
	string ma;
	int soluong, giaban;
	public:
		Hang(){
			ma="";
			soluong=giaban=0;
		}
		Hang(string m, int sl, int gb){
			ma=m;
			soluong=sl;
			giaban=gb;
		}
		void set_ma(string m){
			ma=m;
		}
		void set_soluong(int sl){
			soluong=sl;
		}
		void set_giaban(int gb){
			giaban=gb;
		}
		string get_ma(){
			return ma;
		}
		int get_soluong(){
			return soluong;
		}
		int get_giaban(){
			return giaban;
		}
		void nhap(){
			cout << "\nNhap ma: ";
			getline(cin,ma);
			cout << "\nNhap so luong: ";
			cin >> soluong;
			cout << "\nNhap gia ban: ";
			cin >> giaban;
			cin.ignore();
		}
		int tinhTong(){
			return giaban*soluong;
		}
		void in(){
			cout << ma << " " << soluong << " " << tinhTong() << " ";
		}
};

class dienThoai : public Hang{
	string maudt, hangsanxuat;
	int thoigianbh;
	public:
		dienThoai(){
			maudt=hangsanxuat="";
			thoigianbh=0;
		}
		dienThoai(string m, string h, int tg){
			maudt=m;
			hangsanxuat=h;
			thoigianbh=tg;
		}
		void set_mau(string m){
			maudt=m;
		}
		void set_hang(string h){
			hangsanxuat=h;
		}
		void set_thoigianbh(int tg){
			thoigianbh=tg;
		}
		string get_mau(){
			return maudt;
		}
		string get_hang() {
			return hangsanxuat;
		}
		int get_thoigianbh(){
			return thoigianbh;
		}
		void nhapDT(){
			nhap();
			cout << "\nNhap mau dien thoai: ";
			getline(cin, maudt);
			cout << "\nNhap hang san xuat: ";
			getline(cin, hangsanxuat);
			cout << "\nNhap thoi gian bao hang: ";
			cin >> thoigianbh;
			cin.ignore();
		}
		void inDT(){
			cout << maudt << " " << hangsanxuat << " "  
			<<  get_soluong() <<" "<< get_giaban() << 
			" "  << thoigianbh<< endl;
		}
		bool operator < (dienThoai a){
			return get_giaban() > a.get_giaban();
		}
};

class Quanli{
	dienThoai a[50];
	int n;
	public:
		void nhapds(){
			do{
				cout << "\nNhap so luong doi tuong: ";
				cin >> n;
				cin.ignore();
				if(n<=0 || n>50){
					cout << "\nNhap sai, nhap lai." << endl;
				}
			}while(n<=0 || n>50);
			for (int i=0;i<n;i++){
				a[i].nhapDT();
				for(int j=0;j<i;j++){
					if(a[i].get_ma() == a[j].get_ma()){
						cout << "\nMa bi trung, nhap lai." <<endl;
						a[i].nhapDT();
						cout << endl;
					}
				}
			}
		}
		
		void inTongHang(){
			long tong=0;
			for(int i=0;i<n;i++){
				for (int j=i+1;j<n;j++){
					if (a[i].get_hang() > a[j].get_hang()){
						dienThoai tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			for(int i=0;i<n;i++){
				tong+=a[i].tinhTong();
				if (i==0 || a[i].get_hang() != a[i+1].get_hang()){
					cout << "Hang " << a[i].get_hang()<<":" << tong << endl;
					tong=0;
				}
			}
		}
		
		void inBH(){
			int m=a[0].get_thoigianbh();
			for (int i=0;i<n;i++){
				if (a[i].get_thoigianbh() > m){
					m=a[i].get_thoigianbh();
				}
			}
			cout << "\nThong tin cac dien thoai co thoi gian bao hanh lau nhat: " << endl;
			for (int i=0;i<n;i++){
				if (a[i].get_thoigianbh()==m){
					a[i].inDT();
				}
			}
		}
		
		void sapxep(){
			for(int i=0;i<n;i++){
				for (int j=i+1;j<n;j++){
					if (a[i] < a[j]){
						dienThoai tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach sau khi sap xep la: " << endl;
			for(int i=0;i<n;i++){
				a[i].inDT();
			}
		}
};

int main(){
	Quanli ob;
	ob.nhapds();
	ob.inTongHang();
	ob.inBH();
	ob.sapxep();
}