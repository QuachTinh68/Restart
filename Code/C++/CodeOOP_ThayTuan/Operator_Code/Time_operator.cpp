#include <iostream>
using namespace std;

class Date {
private:
    int D, M, Y; //ngày, tháng, năm
public:
    bool nhuan(); //kiem tra nam nhuan
    int ngaythang(); //tra ve so ngay trong thang

    void nhap(); //co kiem tra du lieu
    void xuat();
  	bool operator == (Date a);
  	bool operator != (Date a);
  	bool operator += (Date a);
  	bool operator < (Date a);
  	bool operator <= (Date a);
  	bool operator > (Date a);
  	bool operator >= (Date a);
};


bool Date::operator <= (Date a){
	return (*this < a) || (*this == a);
}

bool Date::operator <(Date a){
	if (Y < a.Y){
		return true;
	}
	if (Y == a.Y and M < a.M){
		return true;
	}
	if (Y == a.Y and M == a.M and D < a.D){
		return true;
	}
	return false;
}

bool Date::operator !=(Date a){
	return return Y != a.Y || M != a.M || D != a.D;
}

bool Date::operator ==(Date a){
	return Y == a.Y && M == a.M && D == a.D;
}



bool Date::nhuan() {
    if ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0))
        return true; // Y la nam nhuan
    else
        return false; // Y khong phai nam nhuan
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
    int S; // S de tim so ngay cua thang M
    bool k; // bien kiem tra viec nhap co hop le khong
    do {
        cout << "\nNhap vao ngay thang nam: " << endl;
        cin >> D >> M >> Y;

        S = ngaythang(); // S la so ngay cua thang M da nhap
        if ((D > 0) && (D <= S) && (M >= 1) && (M <= 12) && Y > 0)
            k = true; // hop le
        else {
            cout << "\nSai ngay! Hay nhap lai." << endl;
            k = false; // khong hop le
        }
    } while (!k);
}

void Date::xuat() {
    cout << D << '/' << M << '/' << Y << endl;
}

void Date::cong_1() {
    int S;
    S = ngaythang();
    if (++D > S) {
        D = 1;
        if (++M > 12) {
            M = 1;
            Y = Y + 1;
        }
    }
}

Date Date::cong_k(int k) {
    Date t;
    t.D = D;
    t.M = M;
    t.Y = Y;
    for (int i = 1; i <= k; i++)
        t.cong_1();
    return t;
}

int main() {
    Date d;
    int k;
    cout << "\n Nhap doi tuong d: ";
    d.nhap();
    cout << "\n Du lieu cua doi tuong: ";
    d.xuat();
    d.cong_1();
    cout << "\n Sau khi tang 1 ngay: ";
    d.xuat();

    cout << "\n Nhap k (> 0) ";
    cin >> k;

    Date d1, d2;
    cout << "\n Nhap d1: ";
    d1.nhap();

    d2 = d1.cong_k(k);

    cout << "\n Sau khi tang " << k << " ngay : ";
    d2.xuat();
    return 0;
}
