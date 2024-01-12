#include <bits/stdc++.h>
using namespace std;
class Date {
private:
    int D, M, Y; // Ng?y, th?ng, nam
public:
    int nhuan(); // Ki?m tra nam nhu?n
    int ngaythang(); // Tr? v? s? ng?y trong th?ng
    void nhap(); // C? ki?m tra t?nh h?p l?
    void xuat();
    bool operator >= (Date d);
};

bool Date::operator >= (Date d){
	if (Y >= d.Y){
		return 1;
	}else if (M >= d.M){
		return 1;
	}else if (D >= d.D){
		return 1;
	}else {
		return 0;
	}
}
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
        cout << "Nhap vao ngay thang nam: " << endl;
        cin >> D >> M >> Y;
        S = ngaythang();
        if (D > 0 && D <= S && M >= 1 && M <= 12 && Y > 0) {
            k = 1;
        } else {
            cout << "Kh?ng co ngay nay trong nam" << endl;
            k = 0; 
        }
    } while (k == 0);
}

void Date::xuat() {
    cout << D << '/' << M << '/' << Y << endl;
}




class Sinhvien{
	private:
		string ma, hodem, ten;
	public:
		Date ngaySinh;
		friend istream & operator >> (istream &Input, Sinhvien &sv);
		friend ostream & operator << (ostream &Output, Sinhvien &sv);
		bool operator >= (Sinhvien sv);
};

istream &operator >> (istream &Input, Sinhvien &sv){
	cout << "\nNhap ma sinh vien: ";
	getline(Input, sv.ma);
	cout <<"\nNhap ho dem: ";
	getline(Input, sv.hodem);
	cout << "\nNhap ten sinh vien: ";
	getline(Input, sv.ten);
	cout << "\nNhap nay sinh (dd/mm/yy): ";
	sv.ngaySinh.nhap();
	return Input;
}
ostream &operator << (ostream &Output, Sinhvien &sv){
	cout << endl;
	Output << setw(6) << left << sv.ma << "|"
			<< setw(10) << left << sv.hodem << "|"
			<< setw(10) << left << sv.ten <<"|";
			sv.ngaySinh.xuat();
	return Output;		
}

bool Sinhvien::operator >= (Sinhvien sv){
	if (ten == sv.ten){
		if (hodem >= sv.hodem){
			return 1;
		}
	}else if (ten > sv.ten){
		return 1;
	}
	else {
		return 0;
	}
}

class Quanli{
	private:
		Sinhvien a[100];
		int n;
	public:
		void nhapds();
		void inds();
		void sapXepNgay();
		void sapXepTen();
};

void Quanli::nhapds(){
	cout << "\nNhap so luong sinh vien: "; cin >> n;
	cin.ignore();
	for (int i=0;i<n;++i){
		cin >> a[i];
		cin.ignore();
	}
}
void Quanli::inds(){
	cout <<"\nDANH SACH SINH VIEN: " << endl;
	for (int i=0;i<n;++i){
		cout << a[i];
	}
}

void Hoanvi(Sinhvien &a, Sinhvien &b){
	Sinhvien temp;
	temp=a;
	a=b;
	b=temp;
}
void Quanli::sapXepNgay(){
	for (int i=0;i<n-1;++i){
		for (int j=i+1;j<n;j++){
			if (a[i].ngaySinh >= a[i].ngaySinh){
				Hoanvi(a[i], a[j]);
			}
		}
	}
}
void Quanli::sapXepTen(){
	for (int i=0;i<n-1;++i){
		for (int j=i+1;j<n;j++){
			if (a[i] >= a[i]){
				Hoanvi(a[i], a[j]);
			}
		}
	}	
}

int main(){
	Quanli ob;
	ob.nhapds();
	ob.inds();
	cout <<"\nSinh vien sap xep theo ngay sinh: " << endl;
	ob.sapXepNgay();
	ob.inds();
	cout <<"\nDanh sach sinh vien sap xep theo ten: " << endl;
	ob.sapXepTen();
	ob.inds();
	
}
