#include <iostream>
#include <vector>

class PhanSo {
protected:
    int tu;
    int mau;

public:
    PhanSo(int t = 0, int m = 1) : tu(t), mau(m) {}

    void nhapPhanSo() {
        std::cout << "Nhap tu so: ";
        std::cin >> tu;
        do {
            std::cout << "Nhap mau so (khac 0): ";
            std::cin >> mau;
        } while (mau == 0);
    }

    void hienThiPhanSo() const {
        std::cout << tu << "/" << mau;
    }

    PhanSo operator+(const PhanSo& other) const {
        PhanSo result;
        result.tu = tu * other.mau + mau * other.tu;
        result.mau = mau * other.mau;
        return result;
    }

    PhanSo operator+(int number) const {
        PhanSo result;
        result.tu = tu + mau * number;
        result.mau = mau;
        return result;
    }

    bool operator>(const PhanSo& other) const {
        return (tu * other.mau > mau * other.tu);
    }
};

class HonSo : public PhanSo {
private:
    int phanNguyen;

public:
    HonSo(int pn = 0, int t = 0, int m = 1) : PhanSo(t, m), phanNguyen(pn) {}

    void nhapHonSo() {
        PhanSo::nhapPhanSo();
        std::cout << "Nhap phan nguyen: ";
        std::cin >> phanNguyen;
    }

    void hienThiHonSo() const {
        std::cout << phanNguyen << "." << tu << "/" << mau;
    }

    HonSo operator+(const HonSo& other) const {
        HonSo result;
        result.tu = tu * other.mau + mau * other.tu;
        result.mau = mau * other.mau;
        result.phanNguyen = phanNguyen + other.phanNguyen;
        result.phanNguyen += result.tu / result.mau;
        result.tu %= result.mau;
        return result;
    }

    bool operator>(const HonSo& other) const {
        int thisValue = phanNguyen * mau + tu;
        int otherValue = other.phanNguyen * other.mau + other.tu;
        return thisValue > otherValue;
    }
};

int main() {
    int n;
    std::cout << "Nhap so luong hon so (n <= 50): ";
    std::cin >> n;

    std::vector<HonSo> danhSachHonSo(n);

    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap hon so thu " << i + 1 << ":\n";
        danhSachHonSo[i].nhapHonSo();
    }

    HonSo tongHonSo;
    for (const HonSo& honSo : danhSachHonSo) {
        tongHonSo = tongHonSo + honSo;
    }

    HonSo maxHonSo = danhSachHonSo[0];
    HonSo minHonSo = danhSachHonSo[0];
    for (const HonSo& honSo : danhSachHonSo) {
        if (honSo > maxHonSo) {
            maxHonSo = honSo;
        }
        if (honSo > maxHonSo) {
            minHonSo = honSo;
        }
    }

    std::cout << "Tong cac hon so: ";
    tongHonSo.hienThiHonSo();
    std::cout << std::endl;

    std::cout << "Hon so lon nhat: ";
    maxHonSo.hienThiHonSo();
    std::cout << std::endl;

    std::cout << "Hon so nho nhat: ";
    minHonSo.hienThiHonSo();
    std::cout << std::endl;

    return 0;
}
