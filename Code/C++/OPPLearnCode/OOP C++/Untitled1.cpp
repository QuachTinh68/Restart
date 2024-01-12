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
    int sosanh(Date d);
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

class Giaodich{
	string ma;
	float sotien;
	public:
		void nhap();
		void in();
		
};