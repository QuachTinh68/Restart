#include <bits/stdc++.h>
using namespace std;
class DaiLi{
	string ten;
	int sonam;
	public:
		int static chietkhau;
		void nhap(){
			cout << "\nNhap ten dai li: ";
			getline(cin,ten);
			cout << "\nNhap so nam hop tac: ";
			cin >> sonam;
			cin.ignore();
		}
		float tinhTien(){
			return chietkhau * sonam * 0.1;
		}
		void in(){
			cout << ten <<  " " << sonam <<  " " <<
			fixed << setprecision(0) <<tinhTien() <<  " ";
		} 
};
int DaiLi::chietkhau= 300000;
class BanLe : public DaiLi{
	int doanhso;
	public:
		void nhapQT(){
			nhap();
			cout << "\nNhap doanh so: ";
			cin>> doanhso;
			cin.ignore();
			
		}
		float HoaHong(){
			float hoahong;
			if (doanhso >= 50000000){
					hoahong= doanhso*0.15;
			}else if (doanhso >= 20000000 && doanhso < 50000000){
					hoahong= doanhso*0.1;
			}else if (doanhso < 20000000){
					hoahong= doanhso*0.05;
			}else{
					hoahong=0;
			}
			return hoahong;
		}
		float tinh(){
			return chietkhau+HoaHong();
		}
		void inQT(){
			in();
			cout << doanhso << " " << tinh() << endl;
		}
		bool operator > (BanLe a){
			return tinh() > a.tinh();
		}
};
int main(){
	BanLe ob1, ob2;
	ob1.nhapQT();
	ob1.inQT();
	ob2.nhapQT();
	ob2.inQT();
	if (ob1.tinh() > ob2.tinh()){
		cout << "\nTong tien hoa hong cua dai li 1 lon hon" << endl;
	}else{
		cout << "\nTong tien hoa hong cua dai li 2 lon hon" << endl;
	}
	
}