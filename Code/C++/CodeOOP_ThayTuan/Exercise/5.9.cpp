#include <iostream>
#include <string>
using namespace std;

class CANBO {
    string maCanBo, maDonVi, hoTen, ngaySinh;

public:
    void nhap() {
        cout << "Nhap ma can bo: ";
        cin >> maCanBo;
        cout << "Nhap ma don vi: ";
        cin >> maDonVi;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap ngay sinh: ";
        getline(cin, ngaySinh);
    }

    void in() {
        cout << "\nMa can bo: " << maCanBo;
        cout << "\nMa don vi: " << maDonVi;
        cout << "\nHo ten: " << hoTen;
        cout << "\nNgay sinh: " << ngaySinh;
    }
    string get_madv() {
        return maDonVi;
    }
};

class LUONG : public CANBO {
private:
    float phuCap, heSoLuong, baoHiem;

public:
    void nhapLuong() {
        nhap();
        cout << "Nhap phu cap: ";
        cin >> phuCap;
        cout << "Nhap he so luong: ";
        cin >> heSoLuong;
        cout << "Nhap bao hiem: ";
        cin >> baoHiem;
    }

    float tinhLuong() {
        return heSoLuong * 1350000 + phuCap - baoHiem;
    }

    
};

int main() {
    LUONG danhSachCanBo[50];
    int soLuongCanBo;
    cout << "Nhap so luong can bo: ";
    cin >> soLuongCanBo;

    for (int i = 0; i < soLuongCanBo; ++i) {
        cout << "\nNhap thong tin cua can bo thu " << i + 1 << ":\n";
        danhSachCanBo[i].nhapLuong();
    }

    cout << "\nBang luong theo tung don vi:\n";
    for (int i = 0; i < soLuongCanBo; ++i) {
        cout << "\nThong tin cua can bo thu " << i + 1 << ":\n";
        danhSachCanBo[i].hienThiThongTin();
        cout << "\nLuong: " << danhSachCanBo[i].tinhLuong() << endl;
    }

    return 0;
}
