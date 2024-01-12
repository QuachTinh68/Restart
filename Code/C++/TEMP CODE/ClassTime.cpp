#include <iostream>
using namespace std;

class Time {
private:
    int h, m, s; // h: gio, m: phut, s: giay
public:
    // Cac ham tao
    Time(); // Ham tao mac dinh
    Time(int a, int b, int c); // Ham tao co 3 tham so
    // Ham nhap, xuat
    void nhap();
    void xuat();

    void chuanhoa(); // Chuan hoa gio, phut va giay theo quy dinh
    void giatang(int a, int b, int c); // Tang gio hien tai theo a: gio, b: phut, c: giay
    void dieuchinh(int a, int b, int c); // Dieu chinh lai gio hien tai theo chuan hoa
};

Time::Time() {
    h = m = s = 0;
}

Time::Time(int a, int b, int c) {
    h = a;
    m = b;
    s = c;
}

void Time::nhap() {
    while (1) {
        cout << "Nhap vao gio, phut va giay: ";
        cin >> h >> m >> s;
        if (h >= 0 and m >= 0 and s >= 0)
            break;
        cout << "Nhap sai! Hay nhap lai." << endl;
    }
}

void Time::xuat() {
    cout << h << ":" << m << ":" << s << "\n";
}

void Time::chuanhoa() {
    int tong = h * 3600 + m * 60 + s;
    h = (tong / 3600) % 24;
    m = (tong / 60) % 60;
    s = tong % 60;
}

void Time::giatang(int a, int b, int c) {
    h = h + a;
    m = m + b;
    s = s + c;
    chuanhoa();
}

void Time::dieuchinh(int a, int b, int c) {
    h = a;
    m = b;
    s = c;
    chuanhoa();
}

int main() {
    Time ob1(25, 65, 75), ob2;
    cout << "\n Doi tuong ob1: ";
    ob1.xuat();
    cout << "\n Sau khi chuan hoa ob1: ";
    ob1.chuanhoa(); // 2:6:15
    ob1.xuat();

    cout << "\n Gia tang ob1: ";
    ob1.giatang(20, 50, 70); // tang gio len 20, phut tang 50, giay tang 90
    cout << "\n ob1 sau khi gia tang: ";
    ob1.xuat(); // 22:57:25

    cout << "\n Dieu chinh ob1: ";
    ob1.dieuchinh(15, 70, 90);
    cout << "\n ob1 sau khi dieu chinh: ";
    ob1.xuat(); // 16:11:30

    cout << "\n Nhap doi tuong ob2: \n ";

    ob2.nhap();
    cout << "\n Doi tuong ob2: \n";
    ob2.xuat();
    cout << "\n Sau khi chuan hoa ob2: ";
    ob2.chuanhoa();
    ob2.xuat();

    return 0;
}
