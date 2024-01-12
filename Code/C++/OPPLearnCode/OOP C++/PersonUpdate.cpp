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
		Person(string h,string t, int age){
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
			tuoi=age;
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
		void nhap(){
			cout << "\nNhap ho: ";getline(cin,ho);
			cout << "\nNhap ten: "; getline(cin,ten);
			cout << "\nNhap tuoi: "; cin >> tuoi;
			cin.ignore();
		}
		void in(){
			cout << ho << " " << ten << " " << tuoi << " ";
		}
		bool operator > (Person a){
			if (ho != a.ho){
				return ho > a.ho;
			}
			if (ten != a.ten){
				return ten > a.ten;
			}
			return 0;
		}		
};
class Student : public Person{
	string ma, nganh;
	float dtb;
	public:
		Student(){
			ma=nganh=" ";
			dtb=0;
		}
		Student(string m,string n, float d){
			ma=m;
			nganh=n;
			dtb=d;
		}
		void set_ma(string m){
			ma=m;
		}
		void set_nganh(string n){
			nganh=n;
		}
		void set_dtb(float d){
			dtb=d;
		}
		string get_ma(){
			return ma;
		}
		string get_nganh(){
			return nganh;
		}
		float get_diem(){
			return dtb;
		}
		void nhapS(){
			nhap();
			cout << "\nNhap ma sinh vien: ";
			getline(cin,ma);
			cout << "\nNhap nganh dao tao: ";
			getline(cin,nganh);
			cout << "\nNhap diem trung binh: ";
			cin >> dtb; cin.ignore();
		}
		string tinhDiem(){
			string s;
			if (dtb >= 5){
				return s="Dat";
			}else{
				return s="Khong Dat";
			}
		}
		void inS(){
			in();
			cout << ma << " " << nganh << " " << dtb << " " << tinhDiem() << endl;
		}
};

class Quanli{
	Student a[50];
	int n;
	public: 
		void nhapds(){
			do{
				cout << "\nNhap so luong sinh vien: ";
				cin >> n; 
				cin.ignore();
				if ( n<=0 || n>50){
					cout << "\nNhap sai, vui long nhap lai. " << endl;
				}
			}while(n <=0 || n>50);
			for(int i=0;i<n;i++){
				cout << "\nNhap so luong sinh vien thu: " << i+1 <<endl;
				a[i].nhapS();
			}
		}
		void sapXep(){
			for (int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if (a[i] > a[j]){
						Student tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach sau khi sap xep la: " << endl;
			for (int i=0;i<n;i++){
				a[i].inS();
			}
		}
		void inTB(){
			float diem=a[0].get_diem();
			for (int i=0;i<n;i++){
				if (diem < a[i].get_diem()){
					diem = a[i].get_diem();
				}
			}
			cout << "\nDanh sach sinh vien co diem trung binh cao nhat la: " << endl;
			for (int i=0;i<n;i++){
				if (a[i].get_diem() == diem){
					a[i].inS();
				}
			}
		}
		void tinhtuoi(){
			int cnt,tong=0;
			for (int i=0;i<n;i++){
				if (a[i].tinhDiem() == "Dat"){
					tong+=a[i].get_tuoi();
					cnt++;
				}
			}
			cout << "\nTuoi trung binh cua sinh vien xep loat dat la: " 
			<< fixed << setprecision(0) << tong/cnt;
		}
		void xoa(string ndt){
			int i=0;
			do{
				if (a[i].get_nganh() == ndt){
					for (int j=i;j<n-1;j++){
						a[j]=a[j+1];
					}
					n--;
				}
				else{
					i++;
				}
			}while(i<n);
			cout << "\nDanh sach sau khi xoa la: " << endl;
			for (int i=0;i<n;i++){
				a[i].inS();
			}
		}
		void them(){
			if (n<50){
				Student ns;
				ns.nhapS();
				a[n]=ns;
				n++;
			}else{
				cout << "\nDanh sach day!" << endl;
			}
			cout << "\nDanh sach sau khi them la: " << endl;
			for (int i=0;i<n;i++){
				a[i].inS();
			}
		}
};
int main(){
	Quanli ob;
	ob.nhapds();
	ob.sapXep();
	ob.inTB();
	ob.tinhtuoi();
	string s="ndt";
	ob.xoa(s);
}
