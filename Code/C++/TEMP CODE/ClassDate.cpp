#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Date {
private:
    int D, M, Y; //ngày, tháng, năm
public:
	int get_day(){
		return D;
	}
	int get_month(){
		return M;
	}
	int get_year(){
		return Y;
	}
	void set_D(int d){
		D=d;
	}
	void set_M(int m){
		M=m;
	}
	void set_Y(int y){
		Y=y
	}
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

int Date::sosanh(Date d) {
    return (Y < d.Y) ? 1 : (Y > d.Y) ? 0 : (M < d.M) ? 1 : (M > d.M) ? 0 : (D < d.D) ? 1 : 0;
}

class Canbo {
private:
    string maSo;
    string hoTen;
    string chucVu;
    float hesoLuong;

public:
    Date ngaySinh;
    void Nhap();
    void Xuat();
    float luongThang();
};

void Canbo::Nhap() {
    cout << "\nMa so: ";
    cin >> maSo;
    cin.ignore();
    cout << "Ho ten: ";
    getline(cin, hoTen);
    cout << "Chuc vu: ";
    getline(cin, chucVu);
    cout << "He so luong: ";
    cin >> hesoLuong;
    cout << "Ngay sinh (dd/mm/yyyy): ";
    ngaySinh.nhap();
}

void Canbo::Xuat() {
    cout << endl
         << setw(6) << left << maSo << " | "
         << setw(25) << left << hoTen << " | "
         << setw(20) << left << chucVu << " | "
         << setw(5) << left << setprecision(2) << fixed << hesoLuong << " | "
         << setw(8) << left << setprecision(0) << fixed << luongThang() << " | ";
    ngaySinh.xuat();
}

float Canbo::luongThang() {
    int soTien;
    if (chucVu == "Truong Khoa")
        soTien = (hesoLuong + 0.5) * 1800000;
    else if (chucVu == "Pho Khoa" || chucVu == "Truong Bo mon")
        soTien = (hesoLuong + 0.4) * 1800000;
    else if (chucVu == "Pho Bo mon")
        soTien = (hesoLuong + 0.3) * 1800000;
    else
        soTien = hesoLuong * 1800000;
    return soTien;
}

class Quanly {
private:
    Canbo ds[50];
    int n;

public:
    void NhapDS();
    void XuatDS();
    void DS_ThapNhat();
    void sapXepTheoNgaysinh();
};

void Quanly::NhapDS() {
    do {
        cout << "\nNhap so can bo: ";
        cin >> n;
        if (n < 0 || n > 50)
            cout << "So can bo khong hop le! Vui long nhap lai!";
    } while (n < 0 || n > 50);

    for (int i = 0; i < n; i++) {
        cout << "\nCan bo " << i + 1 << endl;
        ds[i].Nhap();
    }
}

void Quanly::XuatDS() {
    for (int i = 0; i < n; i++)
        ds[i].Xuat();
}

void Quanly::DS_ThapNhat() {
    int minSoTien = ds[0].luongThang();

    for (int i = 1; i < n; i++)
        if (ds[i].luongThang() < minSoTien)
            minSoTien = ds[i].luongThang();

    for (int i = 0; i < n; i++)
        if (ds[i].luongThang() == minSoTien)
            ds[i].Xuat();
}

void Quanly::sapXepTheoNgaysinh() {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ds[i].ngaySinh.sosanh(ds[j].ngaySinh)) {
                Canbo temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
}

int main() {
    Quanly q;
    q.NhapDS();

    cout << "\nDanh sach can bo co luong thap nhat: \n";
    q.DS_ThapNhat();

    cout << "\nDanh sach can bo co sap xep giam dan theo ngay sinh: ";
    q.sapXepTheoNgaysinh();
    q.XuatDS();
    return 0;
}
