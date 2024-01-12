#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class TaiLieu {
protected:
    string maTaiLieu;
    string tenTaiLieu;

public:
    TaiLieu() : maTaiLieu(""), tenTaiLieu("") {}

    TaiLieu(string ma, string ten) : maTaiLieu(ma), tenTaiLieu(ten) {}

    void nhapThongTin() {
        cout << "Nhap ma tai lieu: ";
        cin >> maTaiLieu;
        cout << "Nhap ten tai lieu: ";
        cin.ignore();
        getline(cin, tenTaiLieu);
    }

    void xuatThongTin() const {
        cout << "Ma tai lieu: " << maTaiLieu << endl;
        cout << "Ten tai lieu: " << tenTaiLieu << endl;
    }

    bool operator>(const TaiLieu& other) const {
        return tenTaiLieu > other.tenTaiLieu;
    }

    const string& getMaTaiLieu() const {
        return maTaiLieu;
    }

    const string& getTenTaiLieu() const {
        return tenTaiLieu;
    }
};

class Sach : public TaiLieu {
private:
    string tenTacGia;
    int soTrang;
    string tenNXB;

public:
    Sach() : tenTacGia(""), soTrang(0), tenNXB("") {}

    void nhapThongTinSach() {
        nhapThongTin();
        cout << "Nhap ten tac gia: ";
        getline(cin, tenTacGia);
        cout << "Nhap so trang: ";
        cin >> soTrang;
        cout << "Nhap ten nha xuat ban: ";
        cin.ignore();
        getline(cin, tenNXB);
    }

    void xuatThongTin() const {
        TaiLieu::xuatThongTin();
        cout << "Ten tac gia: " << tenTacGia << endl;
        cout << "So trang: " << soTrang << endl;
        cout << "Ten nha xuat ban: " << tenNXB << endl;
    }
};

class TapChi : public TaiLieu {
private:
    string soPhatHanh;
    string maPhatHanh;

public:
    TapChi() : soPhatHanh(""), maPhatHanh("") {}

    void nhapThongTinTapChi() {
        nhapThongTin();
        cout << "Nhap so phat hanh (n0/yyyy): ";
        getline(cin, soPhatHanh);
        cout << "Nhap ma phat hanh (ISSN xxxx-xxxx): ";
        getline(cin, maPhatHanh);
    }

    void xuatThongTin() const {
        TaiLieu::xuatThongTin();
        cout << "So phat hanh: " << soPhatHanh << endl;
        cout << "Ma phat hanh: " << maPhatHanh << endl;
    }

    const string& getSoPhatHanh() const {
        return soPhatHanh;
    }
};

void menu(vector<TaiLieu*>& danhSachTaiLieu) {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Nhap tai lieu (Sach hoac Tap chi)\n";
        cout << "2. Xoa tai lieu theo ma\n";
        cout << "3. Chinh sua tai lieu\n";
        cout << "4. Tim kiem sach theo ten\n";
        cout << "5. Tim kiem tap chi theo nam xuat ban\n";
        cout << "6. Sap xep danh sach tai lieu theo ten\n";
        cout << "7. Xuat danh sach tai lieu\n";
        cout << "8. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int type;
                cout << "Chon loai tai lieu (1. Sach / 2. Tap chi): ";
                cin >> type;
                if (type == 1) {
                    Sach* sach = new Sach();
                    sach->nhapThongTinSach();
                    danhSachTaiLieu.push_back(sach);
                } else if (type == 2) {
                    TapChi* tapChi = new TapChi();
                    tapChi->nhapThongTinTapChi();
                    danhSachTaiLieu.push_back(tapChi);
                }
                break;
            }
            case 2: {
			    string maXoa;
			    cout << "Nhap ma tai lieu can xoa: ";
			    cin >> maXoa;
			    danhSachTaiLieu.erase(
			        remove_if(danhSachTaiLieu.begin(), danhSachTaiLieu.end(),
			                  [&](TaiLieu* tl) { return tl->getMaTaiLieu() == maXoa; }),
			        danhSachTaiLieu.end());
			    break;
			}

            // Các case khác d? th?c hi?n các yêu c?u khác trong menu
            // ...
            case 7: {
                cout << "\nDanh sach tai lieu:\n";
                for (const auto& tl : danhSachTaiLieu) {
                    tl->xuatThongTin();
                    cout << endl;
                }
                break;
            }
            default:
                break;
        }
    } while (choice != 8);
}

int main() {
    vector<TaiLieu*> danhSachTaiLieu;
    menu(danhSachTaiLieu);

    // Gi?i phóng b? nh? khi k?t thúc chuong trình
    for (auto& tl : danhSachTaiLieu) {
        delete tl;
    }

    return 0;
}

