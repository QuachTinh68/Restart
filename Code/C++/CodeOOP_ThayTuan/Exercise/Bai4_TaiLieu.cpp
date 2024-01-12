#include <bits/stdc++.h>
using namespace std;
class TaiLieu{
	string ma,tenTaiLieu;
	public:
		virtual void nhapThongTin(){
			cout << "\nNhap ma tai lieu: ";
			getline(cin,ma);
			cout << "\nNhap ten tai lieu: ";
			getline(cin,tenTaiLieu);
		}
		virtual void inThongTin(){
			cout << "\nMa tai lieu: " << ma;
			cout << "\nTen tai lieu: " << tenTaiLieu;
		}
		bool operator > (TaiLieu a){
			return tenTaiLieu > a.tenTaiLieu;
		}
		virtual string timMaSach(){
			return " ";
		}
		virtual int timNam(){
			return 0;
		}
		string get_ma(){
			return ma;
		}
		string get_ten(){
			return tenTaiLieu;
		}
};

class Sach : public TaiLieu{
	string tenTG,tenNXB;
	int soTrang;
	public:
		void nhapThongTin(){
			TaiLieu::nhapThongTin();
			cout << "\nNhap ten tac gia: ";
			getline(cin,tenTG);
			cout << "\nNhap so trang: ";
			cin >> soTrang;cin.ignore();
			cout << "\nNhap ten nha xuat ban: ";
			getline(cin,tenNXB);
		}
		void inThongTin(){
			TaiLieu::inThongTin();
			cout << "\nTen tac gia: " << tenTG;
			cout <<"\nSo Trang: " << soTrang;
			cout << "\nTen nha xuat ban: " << tenNXB;
		}
		string timMaSach(){
			return get_ten();
		}
};

class TapChi : public TaiLieu{
	string soPH, maPH;
	int namPH;
	public:
		void nhapThongTin(){
			TaiLieu::nhapThongTin();
			cout << "\nNhap so phat hanh: ";
			getline(cin,soPH);
			cout << "\nNhap ma phat hanh: ";
			getline(cin,maPH);
			cout << "\nNhap nam phat hanh: ";
			cin >> namPH;
			cin.ignore();
		}
		void inThongTin(){
			TaiLieu::inThongTin();
			cout << "\nSo phat hanh " << soPH;
			cout <<"\nMa phat hanh: " << maPH;
			cout << "\nNam phat hanh: " << namPH;
		}
		int timNam(){
			return namPH;
		}
};
class Quanli{
	TaiLieu *tl[100];
	int check,n;
	public:
		void nhapds(){
			do{
				cout << "\nNhap so luong tai lieu: ";
				cin >> n;
				cin.ignore();
				if (n>100 || n<0){
					cout << "\nGia tri sai, vui long nhap lai!!" <<endl;
				}
			}while(n>100);
			for(int i=0;i<n;i++){
				do{
					cout << "\nNhap loai tai lieu (1-Sach __ 2-Tap chi): ";
					cin >> check;
					cin.ignore();
				}while( check!=1 && check!=2);
				if (check == 1){
					Sach *p = new Sach;
					p->nhapThongTin();
					tl[i]=p;
				}else{
					TapChi *p = new TapChi;
					p->nhapThongTin();
					tl[i]=p;
				}
				for (int j=0;j<i;j++){
					if (tl[i]->get_ma() == tl[j]->get_ma()){
						cout << "\nMa da ton tai, vui long nhap lai." << endl;
						delete tl[i];
						--i;
	                    break;
					}
				}
			}
		}
		void xoa(){
			string s;
			cout << "\nNhap ma tai lieu can xoa: ";
			getline(cin,s);
			int i=0;
			do{
				if (tl[i]->get_ma() == s){
					for (int j=i;j<n-1;j++){
						tl[j]=tl[j+1];
					}
					--n;
				}else i++;
			}while(i<n);
			
			cout << "\nDanh sach sau khi xoa la: " << endl;
			for (int i=0;i<n;i++){
				tl[i]->inThongTin();
				cout << endl;
			}
		}
		void timKiem(){
			string search;
			cout << "\nNhap cum tu can tim kiem: ";
			getline(cin,search);
			cout << "Cac sach chua tu khoa '" << search << "':" <<  endl;
			for (int i=0;i<n;i++){
				if (tl[i]->timMaSach().find(search) !=  string::npos){
					tl[i]->inThongTin();
					cout << endl;
				}
			}
		}
		void inNam(){
			int y;
			cout << "\nNhap nam can tim kiem: ";
			cin >> y; cin.ignore();
			cout << "\nDanh sach cac tap chi nam " << y << ":" << endl;
			for (int i=0;i<n;i++){
				if (tl[i]->timNam() == y){
					tl[i]->inThongTin();
					cout << endl;
				}
			}
		}
		void sapXep(){
			for (int i=0;i<n;i++){
				for (int j=i+1;j<n;j++){
					if (*tl[i] > *tl[j]){
						TaiLieu *tmp;
						tmp=tl[i];
						tl[i]=tl[j];
						tl[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach sau khi sap xep la: " << endl;
			for (int i=0;i<n;i++){
				tl[i]->inThongTin();
				cout << endl;
			}
		}
		
};

int main(){
	Quanli ob;
	ob.nhapds();
	ob.xoa();
	ob.timKiem();
	ob.inNam();
	ob.sapXep();
}


