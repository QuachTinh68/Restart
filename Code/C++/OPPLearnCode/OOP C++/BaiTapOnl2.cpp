#include <bits/stdc++.h>
using namespace std;
class Xe{
	string hoten;
	int sogio;
	public:
		void nhap();
		void in();	
		virtual void inthongtin()=0;
		int get_gio(){
			return sogio;
		}
};

void Xe::nhap(){
	cout << "\nNhap ho ten nguoi thue: ";
	getline(cin,hoten);
	cout << "\nNhap so gio thue :";
	cin >>sogio;
	cin.ignore();
}
void Xe::in(){
	cout << hoten << " " << sogio << " ";
}

class XeDap : public Xe{
	string loaixe;
	public:
		float tienthue();
		void nhapD();
		void inthongtin();
};
void XeDap::nhapD(){
	nhap();
	cout << "\nNhap loai xe: ";
	getline(cin, loaixe);
}
void XeDap::inthongtin(){
	in();
	cout << loaixe <<" "<< fixed << setprecision(0) << tienthue() << endl;
}
float XeDap::tienthue(){
	return 30000 + (get_gio()-1)*20000;
}
class XeMay : public Xe{
	string  bienso;
	int phankhoi;
	public:
		float tinhtien();
		void nhapM();
		void inthongtin();
};

void XeMay::nhapM(){
	nhap();
	do{
		cout << "\nNhap loai xe (phan khoi: 100 hoac 250): ";
		cin >> phankhoi;
		cin.ignore();
	}while (phankhoi != 100 && phankhoi !=250);
	
	cout << "\nNhap bien so xe: ";
	getline(cin,bienso);
}

float XeMay::tinhtien(){
	int tien;
	if (phankhoi == 100){
		tien = 15000;
	}else{
		tien = 20000;
	}
	return get_gio() * tien;
}
void XeMay::inthongtin(){
	in();
	cout << phankhoi << " " <<bienso <<" "<< fixed <<setprecision(0) << tinhtien() << endl;
}
class Quanli{
	Xe *xe[100];
	int n,check;
	
	public: 
		void nhapds();
		void inds();
};

void Quanli::nhapds(){
	cout << "\nNhap so luong xe (ca xe dap va xe may): "; cin >> n;
	for (int i=0;i<n;i++){
		do{
			cout << "\nNhap loai xe: 1 - Xe Dap , 2- Xe May: ";
			cin >> check;
			cin.ignore();
		}while (check!=1 && check!=2);
		if (check ==1){
			XeDap *p = new XeDap;
			p->nhapD();
			xe[i]=p;
		}
		else{
			XeMay *p = new XeMay;
			p->nhapM();
			xe[i]=p;
		}
	}
}

void Quanli::inds(){
	cout << "\nThong tin thue xe la: " <<endl;
	for (int i=0;i<n;i++){
		xe[i]->inthongtin();
	}
}

int main(){
	Quanli ob;
	ob.nhapds();
	ob.inds();
}