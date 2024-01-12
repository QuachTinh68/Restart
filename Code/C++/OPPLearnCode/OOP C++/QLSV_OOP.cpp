#include <bits/stdc++.h>
using namespace std;
class Date {
private:
    int D, M, Y; //ngày, tháng, năm
public:
    int nhuan(); //kiểm tra năm nhuận
    int ngaythang(); //trả về số ngày trong tháng
    void nhap(); //có kiểm tra tính hợp lệ
    void xuat();
    bool operator <= (Date d);
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

void Date::nhap() {
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
    cout << D << '/' << M << '/' << Y << endl;
}

bool Date::operator <=(Date d){
	if (Y > d.Y) {
		return 0;
	}
	else if ( Y == d.Y and M >d.M){
		return 0;
	}else if (Y == d.Y and M == d.M and D > d.D){
		return 0;
	}else {
		return 1;
	}
	
}


class SinhVien{
	string ma, hodem, ten;
	public:
	Date ns;
	friend istream & operator >> (istream &in, SinhVien &s);
	friend ostream & operator << (ostream &out, SinhVien &s);
	bool operator >= (SinhVien a);
};
istream & operator >> (istream &in, SinhVien &s){
	cout <<"\nNhap ma sinh vien: ";
	getline(in, s.ma);
	cout <<"\nNhap ho dem: ";
	getline(in, s.hodem);
	cout <<"\nNhap ten: ";
	getline(in, s.ten);
	s.ns.nhap();
	return in;
}
ostream & operator << (ostream &out, SinhVien &s){
	out << endl
         << setw(6) << left << s.ma << " | "
         << setw(10) << left << s.hodem << " | "
         << setw(5) << left << s.ten << " | ";
    s.ns.xuat();
    return out;
}

bool SinhVien::operator >= (SinhVien a){
	if (ten == a.ten){
		if (hodem < a.hodem){
			return 0;
		}else{
			return 1;
		}
	}else if (ten < a.ten){
		return 0;
	}
	return 1;
}

class QuanLi{
	SinhVien sv[100];
	int n;
	public:
		void nhap();
		void in();
		void sapTen();
		void sapNgay();
};

void QuanLi::nhap(){
	cout << "\nNhap so luong sinh vien: ";
	cin>> n;
	cin.ignore();
	for (int i=0;i<n;i++){
		cin >> sv[i];
		cin.ignore();
	}
}
void QuanLi::in(){
	for (int i=0;i<n;i++){
		cout << sv[i];
	}
}
void hoanvi(SinhVien &a, SinhVien &b){
	SinhVien tmp;
	tmp=a;
	a=b;
	b=tmp;
}

void QuanLi::sapNgay(){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (sv[i].ns <= sv[j].ns){
				hoanvi(sv[i], sv[j]);
			}
		}
	}
}

void QuanLi::sapTen(){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (sv[i] >= sv[j]){
				hoanvi(sv[i], sv[j]);
			}
		}
	}
}
int main(){
	QuanLi ob;
	ob.nhap();
	ob.in();
	ob.sapNgay();
	cout <<"\nDanh sach sau khi sap theo ngay la: " <<endl;
	ob.in();
	ob.sapTen();
	cout <<"\nDanh sach sau khi sap theo ten la: " <<endl;
	ob.in();
}