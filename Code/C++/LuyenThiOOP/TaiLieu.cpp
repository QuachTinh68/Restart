#include <bits/stdc++.h>
using namespace std;

class TaiLieu{
	string ma, ten;
	public:
		virtual void nhap(){
			cout << "\nNhap ma tai lieu: ";
			getline(cin,ma);
			cout << "\nNhap ten tai lieu: ";
			getline(cin, ten);
		}
		virtual void in(){
			cout << ma << " " << ten <<" ";
		}
		bool operator > (TaiLieu a){
			return ten > a.ten;
		}
		string get_ma(){
			return ma;
		}
		string get_ten(){
			return ten;
		}
		virtual string kiemtra(){
			return " ";
		}
		virtual int get_nam(){
			return 0;
		}
};

class Sach : public TaiLieu{
	string tentacgia, tenNXB;
	int sotrang;
	public:
		void nhap(){
			TaiLieu::nhap();
			cout << "\nNhap ten tac gia: ";
			getline(cin, tentacgia);
			cout << "\nNhap ten nha xuat ban: ";
			getline(cin,tenNXB);
			cout << "\nNhap so trang: ";
			cin >> sotrang;
			cin.ignore();
		}
		void in(){
			TaiLieu::in();
			cout << tentacgia <<" " << tenNXB << " " << sotrang << endl;
		}
		string kiemtra(){
			return "Sach";
		}
};

class TapChi : public TaiLieu{
	string maPH;
	int soPH;
	public:
		void nhap(){
			TaiLieu::nhap();
			cout << "\nNhap ma phat hanh: ";
			getline(cin,maPH);
			cout << "\nNhap so phat hanh(nam): ";
			cin >> soPH;
			cin.ignore();
		}
		void in(){
			TaiLieu::in();
			cout << maPH << " " << soPH << endl;
		}
		string kiemtra(){
			return "TC";
		}
		int get_nam(){
			return soPH;
		}
};

class Quanli{
	TaiLieu *a[50];
	int n;
	public:
		void nhapds(){
			do{
				cout << "\nNhap so luong tai lieu: ";
				cin >> n;
				cin.ignore();
				if (n<=0 || n>50){
					cout <<"\nNhap sai, vui long nhap lai." << endl;
				}
			}while(n<=0 || n>50);
			for (int i=0;i<n;i++){
				int check;
				do{
					cout << "\nNhap loai tai lieu (1-Sach 2-Tap Chi): ";
					cin >> check;
					cin.ignore();
					if (check !=1 && check!=2){
						cout << "\nNhap sai, vui long nhap lai." << endl;
					}
				}while(check !=1 && check!=2);
				if (check==1){
					Sach *p = new Sach;
					p->nhap();
					a[i]=p;
				}else{
					TapChi *p = new TapChi;
					p->nhap();
					a[i]=p;
				}
				for (int j=0;j<i;j++){
					if (a[i]->get_ma() == a[j]->get_ma()){
						cout << "\nMa bi trung, nhap lai." << endl;
						delete a[i];
						--i;
						break;
					}
				}
			}
		}
		
		void xoa(){
			string xoa;
			bool check=true;
			cout << "\nNhap ma can xoa: ";
			getline(cin, xoa);
			for (int i=0;i<n;i++){
				if (a[i]->get_ma() == xoa){
					delete a[i];
					check=0;
					for (int j=i;j<n-1;j++){
						a[j]=a[j+1];
					}
					--n;
				}
				cout << "\nDa xoa tai lieu co ma: " << xoa << endl;
				return;
			}
			if(!check){
				cout << "\nKhong co ma tai lieu trong danh sach." << endl;
			}
		}
		void timKiem(){
			int cnt=0;
			string s;
			cout << "\nNhap cum tu can tim kiem: ";
			getline(cin,s);
			for (int i=0;i<n;i++){
				if (a[i]->kiemtra() == "Sach"){
					if (a[i]->get_ten().find(s)!= string::npos){
						a[i]->in();
						cnt++;
					}
				}
			}
			if (cnt==0){
				cout << "\nKhong co cum tu nay." <<endl;
			}
		}
		void timTapChi(){
			int cnt=0, nam;
			cout << "\nNhap nam can tim: ";
			cin>> nam; cin.ignore();
			for(int i=0;i<n;i++){
				if (a[i]->get_nam() == nam){
					a[i]->in();
					cnt++;
				}
			}
			if(cnt==0){
				cout << "\nKhong co thong tin dung" << endl;
			}
		}
		void sapXep(){
			for (int i=0;i<n;i++){
				for (int j=i+1;j<n;j++){
					if (*a[i] > *a[j]){
						TaiLieu *tmp =a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach sau khi sap xep la: " << endl;
			for (int i=0;i<n;i++){
				a[i]->in();
			}
		}
};

int main(){
	Quanli ob;
	ob.nhapds();
	ob.sapXep();
	ob.timKiem();
	ob.timTapChi();
	ob.xoa();
}