#include <bits/stdc++.h>
using namespace std;

class Person{
	string ho, ten;
	int tuoi;
	public:
		Person(){
			ho=ten=" ";
			tuoi=0;
		}
		Person(string h, string t,int age){
			ho=h;
			ten=t;
			tuoi=age;
		}
		void set_ho(string h){
			ho=h;
		}
		void set_ten(string t){
			ten=t;
		}
		void set_tuoi(int age){
			tuoi = age;
		}
		string get_ho(){
			return ho;
		}
		string get_ten(){
			return ten;
		}
		int get_tuoi(){
			return tuoi;
		}
		void nhap();
		void in();
		bool operator > (Person a);
};

void Person::nhap(){
	cout << "\nNhap ho: ";
	getline(cin,ho);
	cout << "\nNhap ten: ";
	getline(cin,ten);
	cout << "\nNhap tuoi: ";
	cin >> tuoi;
	cin.ignore();
}

void Person::in(){
	cout << "\nHo: " <<ho;
	cout << "\nTen: " << ten;
	cout << "\nTuoi: " << tuoi ;
}

bool Person::operator > (Person a){
	if (ten != a.ten){
		return ten > a.ten;
	}
	return ho > a.ho;
}
class Student : public Person{
	string ma, nganh;
	float diemtb;
	public:
		Student(){
			ma=nganh=" ";
			diemtb=0.0;
		}
		Student(string m, string n,float d){
			ma=m;
			nganh=n;
			diemtb=d;
		}
		void set_ma(string m){
			ma=m;
		}
		void set_n(string n){
			nganh =n;
		}
		void set_dtb(float d){
			diemtb=d;
		}
		string get_ma(){
			return ma;
		}
		string get_nganh(){
			return nganh;
		}
		float get_diem(){
			return diemtb;
		}
		void nhapS();
		void inS();
		string xepLoai();		
};

void Student::nhapS(){
	nhap();
	cout << "\nNhap ma sinh vien: ";
	getline(cin,ma);
	cout << "\nNhap nganh hoc: ";
	getline(cin,nganh);
	cout << "\nNhap diem trung binh: ";
	cin >> diemtb;
	cin.ignore();
}

string Student::xepLoai(){
	string s;
	if (diemtb >= 5){
		s="Dat";
	}else{
		s="Khong dat";
	}
	return s;
}
void Student::inS(){
	in();
	cout << "\nMa sinh vien la: " << ma;
	cout << "\nNganh hoc: " << nganh;
	cout << "\nDiem trung binh: " << diemtb;
	cout << "\nXep loai: " << xepLoai() << endl;
}

class Quanli{
	Student s[50];
	int n;
	public:
		void nhapds();
		void sapXep();
		void inMax();
		void inTuoiTB();
		void xoa(string ndt);
};

void Quanli::nhapds(){
	do{
		cout << "\nNhap so luong sinh vien: "; 
		cin >> n;
		cin.ignore();
	}while (n>50);
	
	for (int i=0;i<n;i++){
		s[i].nhapS();
		for(int j=0;j<i;j++){
			while (s[i].get_ma() == s[j].get_ma()){
				cout << "\nMa sinh vien bi trung. Nhap lai!!" << endl;
				s[i].nhapS();
			}
		}
	}
}

void hv(Student &a, Student &b){
	Student tmp;
	tmp=a;
	a=b;
	b=tmp;
}

void Quanli::sapXep(){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (s[i] > s[j]){
				hv(s[i],s[j]);
			}
		}
	}
	cout << "\nThong tin sinh vien sau khi sap xep la: " <<endl;
	for (int i=0;i<n;i++){
		s[i].inS();
	}
}

void Quanli::inMax(){
	float diem=s[0].get_diem();
	for (int i=0;i<n;i++){
		if (diem < s[i].get_diem()){
			diem=s[i].get_diem();
		}
	}
	cout << "\nThong tin sinh vien co diem trung binh cao nhat: " << endl;
	for (int i=0;i<n;i++){
		if (s[i].get_diem() == diem){
			s[i].inS();
		}
	}
}
void Quanli::inTuoiTB(){
	int cnt=0, tongtuoi=0;
	for (int i=0;i<n;i++){
		if (s[i].xepLoai() == "Dat"){
			tongtuoi+=s[i].get_tuoi();
			cnt++;
		}
	}
	if (cnt !=0 ){
		cout << "\nTong tuoi trung binh cua cac sinh vien Dat la: " << endl;
		cout << tongtuoi/cnt;
	}else{
		cout << "\nKhong co sinh vien xep loai dat !!" << endl;
	}
}

void Quanli::xoa(string ndt){
	int i=0;

	do{
		if (s[i].get_nganh() == ndt){
			for (int j=i;j<n-1;j++){
				s[j]=s[j+1];
			}
			--n;
		}else i++;
	}while(i<n);
	
	cout << "\nDanh sach sau khi xoa la: " <<endl;
	for(int i=0;i<n;i++){
		s[i].inS();
	}
}

int main(){
	Quanli ob;
	ob.nhapds();
	ob.sapXep();
	ob.inMax();
	ob.inTuoiTB();
	string ndt="ndt";
	ob.xoa(ndt);
}