#include <iostream>
#include <stdlib.h>
using namespace std;

class DaThuc {
    int heSo[100]; // Lưu các hệ số của đa thức
    int bac; // Bậc của đa thức
public:
    void Nhap();
    void Xuat();
    DaThuc operator + (DaThuc p);
    DaThuc operator - (DaThuc p);
    
};

DaThuc DaThuc::operator - (DaThuc p) {
    DaThuc c;
    int i;

    if (bac > p.bac) {
        c.bac = bac;
    } else {
        c.bac = p.bac;
    }

    for (i = 0; i <= c.bac; i++) {
        int heso1 = (i <= bac) ? heSo[i] : 0;
        int heso2 = (i <= p.bac) ? p.heSo[i] : 0;
        c.heSo[i] = heso1 - heso2;
    }

    return c;
}


void DaThuc::Nhap() {
    cout << "Nhap vao bac cua da thuc: ";
    cin >> bac;
    cout << "Nhap vao cac he so cua da thuc: ";

    for (int i = 0; i <= bac; i++) {
        cout << "He so bac " << i << " la: ";
        cin >> heSo[i];
    }
}

void DaThuc::Xuat() {
    for (int i = 0; i <= bac; i++) {
        if (heSo[i] != 0) {
            cout << heSo[i] << "x^" << i;
            if (i < bac) {
                cout << " + ";
            }
        }
    }
    cout << endl;
}


DaThuc DaThuc::operator + (DaThuc p) {
    DaThuc c;
    int i;

    if (bac < p.bac) {
        c.bac = p.bac;

        for (i = 0; i <= bac; i++) {
            c.heSo[i] = heSo[i] + p.heSo[i];
        }

        for (i = bac + 1; i <= p.bac; i++) {
            c.heSo[i] = p.heSo[i];
        }
    } else {
        c.bac = bac;

        for (i = 0; i <= p.bac; i++) {
            c.heSo[i] = heSo[i] + p.heSo[i];
        }

        for (i = p.bac + 1; i <= bac; i++) {
            c.heSo[i] = heSo[i];
        }
    }

    return c;
}


int main() {
    DaThuc ob1, ob2, ob3, ob4;
    ob1.Nhap();
    ob2.Nhap();

    cout << "\nDa thuc thu nhat: ";
    ob1.Xuat();
    cout << endl;

    cout << "\nDa thuc thu hai: ";
    ob2.Xuat();
    cout << endl;
	cout << "\nTong cua hai da thuc su dung toan tu +" ;
    ob3 = ob1 + ob2;

    cout << "\nDa thuc tong: ";
    ob3.Xuat();
    cout << endl;
    
    cout << "\nHieu cua hai da thuc su dung toan tu -" ;
    ob4 = ob1 - ob2;

    cout << "\nDa thuc hieu: ";
    ob4.Xuat();
    cout << endl;

    return 0;
}
