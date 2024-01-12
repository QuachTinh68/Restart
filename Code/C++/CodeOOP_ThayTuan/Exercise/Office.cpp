#include <bits/stdc++.h>
using namespace std;
class Office{
	string ma, hoten, donvi;
	double hesoluong, baohiem;
	public:
		void nhap();
		void in();
		double tinhluong();
		string get_donvi(){
			return donvi;
		}
};

void Office::nhap(){
	cout << "\nNhap ma can bo: ";
	getline(cin, ma);
	cout << "\nNhap ho ten can bo: ";
	getline(cin, hoten);
	cout << "\nNhap don vi can bo: ";
	getline(cin, donvi);
	cout << "\nNhap he so luong can bo: ";
	cin >> hesoluong;
	cin.ignore();
	cout << "\nNhap bao hiem can bo: ";
	cin >> baohiem;
	cin.ignore();
}

void Office::in(){
	cout << setw(6) << left << ma << "|"
	<< setw(15) << left << hoten << "|"
	<< setw(10) << left << left << donvi << "|"
	<<fixed << setprecision(2)<<hesoluong << "|"
	<<fixed << setprecision(0)<<baohiem << "|"
	<<fixed << setprecision(0)<<tinhluong() <<" ";
}

double Office::tinhluong(){
	long long sotien;
	sotien = hesoluong  * 1350000 - baohiem;
	return sotien;
}

class Employee: public Office {
	int ngay, thang, nam;
	public:
		void nhapE();
		void inE();
		bool operator > (Employee a);
};

void Employee::nhapE(){
	nhap();
	cout << "\nNhap ngay thang nam dd/mm/yy: ";
	cin >> ngay >> thang >> nam;
	cin.ignore();

}

void Employee::inE(){
	in();
	cout << ngay << '/' << thang << '/'<< nam << endl;
}

bool Employee::operator > (Employee a){
	if (nam > a.nam){
		return 1;
	}else if (nam == a.nam and thang > a.thang){
		return 1;
	}else if (nam == a.nam and thang == a.thang and ngay > a.ngay){
		return 1;
	}else{
		return 0;
	}
}

class Ql{
	Employee e[50];
	int n;
	public:
		void nhapds();
		void inds();
		void sapxep();
		void indonvi();
};

void Ql::nhapds(){
	do{
		cout << "\nNhap so luong can bo: "; 
		cin >> n;
		cin.ignore();
	}while(n <= 0 || n > 50);
	for (int i=0;i<n;i++){
		e[i].nhapE();
	}
}

void Ql::inds(){
	for (int i=0;i<n;i++){
		e[i].inE();
	}
}

void Ql::sapxep(){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (e[i] > e[j]){
				Employee temp;
				temp=e[i];
				e[i]=e[j];
				e[j]=temp;
			}
		}
	}
	cout << "\nDanh sach sau khi sap xep la: " << endl;
	for (int i=0;i<n;i++){
		e[i].inE();
	}
}

void Ql::indonvi(){
	string s;
	cout << "\nNhap thong tin don vi can hien thi: ";
	getline(cin,s);
	cout << "\nThong tin bang luong cua don vi: " << endl;
	for (int i=0;i<n;i++){
		if (e[i].get_donvi() == s){
			e[i].inE();
		}
	}
}

int main(){
	Ql ob;
	ob.nhapds();
	ob.inds();
	ob.sapxep();
	ob.indonvi();
}