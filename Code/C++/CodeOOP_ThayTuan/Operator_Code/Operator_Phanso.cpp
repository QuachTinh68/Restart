#include <bits/stdc++.h>
using namespace std;

int UCLN(int A, int B) {
    if (B == 0)
        return A;
    return UCLN(B, A%B);
}

int BCNN(int a, int b){
	return a*b/ UCLN(a,b);
} 

void RutGonPhanSo(int& tu, int& mau) {
    int ucln = UCLN(tu, mau);
    tu /= ucln;
    mau /= ucln;
}

class Phanso{
	private:
		int tu;
		int mau;
	public:
		void nhap();
		void xuat();
		Phanso operator += (Phanso p);
		Phanso operator -= (Phanso p);
		Phanso operator *= (Phanso p);
		Phanso operator /= (Phanso p);
		
		
		bool operator == (Phanso p);
		bool operator != (Phanso p);
		bool operator < (Phanso p);
		bool operator <= (Phanso p);
		bool operator > (Phanso p);
		bool operator >= (Phanso p);
};


bool Phanso::operator >= (Phanso p){
	int tu1 = tu, mau1 = mau,tu2 = p.tu, mau2 = p.mau;
    RutGonPhanSo(tu1, mau1);
    RutGonPhanSo(tu2, mau2);
    
    return (tu1 * mau2) >= (tu2 * mau1);
}


bool Phanso::operator > (Phanso p){
	int tu1 = tu, mau1 = mau,tu2 = p.tu, mau2 = p.mau;
    RutGonPhanSo(tu1, mau1);
    RutGonPhanSo(tu2, mau2);
    
    return (tu1 * mau2) > (tu2 * mau1);
}

bool Phanso::operator <= (Phanso p){
	int tu1 = tu, mau1 = mau,tu2 = p.tu, mau2 = p.mau;
    RutGonPhanSo(tu1, mau1);
    RutGonPhanSo(tu2, mau2);
    
    return (tu1 < mau2) <= (tu2 * mau1);
}

bool Phanso::operator < (Phanso p){
	int tu1 = tu, mau1 = mau,tu2 = p.tu, mau2 = p.mau;
    RutGonPhanSo(tu1, mau1);
    RutGonPhanSo(tu2, mau2);
    
    return (tu1 * mau2) < (tu2 * mau1);
}

bool Phanso::operator !=(Phanso p){
	int tu1 = tu, mau1 = mau,tu2 = p.tu, mau2 = p.mau;
    RutGonPhanSo(tu1, mau1);
    RutGonPhanSo(tu2, mau2);
    
    return (tu1 != tu2) || (mau1 != mau2);
}


bool Phanso::operator ==(Phanso p){
	int tu1 = tu, mau1 = mau,tu2 = p.tu, mau2 = p.mau;
    RutGonPhanSo(tu1, mau1);
    RutGonPhanSo(tu2, mau2);
    
    return (tu1 == tu2) && (mau1 == mau2);
}


void Phanso::nhap(){
	cout << "Nhap tu so: " << endl;
	cin >> tu;cin.ignore();
	cout << "Nhap mau so: " << endl;
	cin >> mau; cin.ignore();
}

void Phanso::xuat(){

	cout << "PHAN SO CUA BAN LA: " << endl;
	cout << "\t["<<tu << "/" << mau<< "]\t"<< endl;
}

Phanso Phanso::operator += (Phanso p){
	tu = tu+p.mau + mau*p.tu;
	mau = mau *p.mau;
	RutGonPhanSo(tu, mau);

 
    return *this;
}

//Phanso Phanso::Tru(Phanso p2){
//	Phanso p;
//    int bscnn = BCNN(mau, p2.mau);
//    int tu1 = tu * (bscnn / mau);
//    int tu2 = p2.tu * (bscnn / p2.mau);
//    
//    p.tu = tu1 - tu2;
//    p.mau = bscnn;
//    
//    int ucln = UCLN(p.tu, p.mau);
//    p.tu /= ucln;
//    p.mau /= ucln;
//    
//    return p;
//}
//Phanso Phanso::Nhan(Phanso p2) {
//    Phanso p;
//    
//    p.tu = tu * p2.tu;
//    p.mau = mau * p2.mau;
//    
//    int ucln = UCLN(p.tu, p.mau);
//    p.tu /= ucln;
//    p.mau /= ucln;
//    
//    return p;
//}
//
//Phanso Phanso::Chia(Phanso p2) {
//    Phanso p;
//    
//    if (p2.tu == 0) {
//        cout << "Khong the chia cho phan so 0." << std::endl;
//        return p;
//    }
//    
//    p.tu = tu * p2.mau;
//    p.mau = mau * p2.tu;
//    
//    int ucln = UCLN(p.tu, p.mau);
//    p.tu /= ucln;
//    p.mau /= ucln;
//    
//    return p;
//}
int main() {
    Phanso p1, p2;
	
    cout << "Nhap phan so thu nhat:" << endl;
    p1.nhap();
    cout << "Nhap phan so thu hai:" << endl;
    p2.nhap();

    cout << "Phan so thu nhat: ";
    p1.xuat();
    cout << "Phan so thu hai: ";
    p2.xuat();
    p1+=p2;
    p1.xuat();
    
//    
//	cout << "\nSu dung toan tu == " << endl;
//    if (p1 == p2) {
//        cout << "Hai phan so bang nhau." << endl;
//    } else {
//        cout << "Hai phan so khac nhau." << endl;
//    }
//	cout << "\nSu dung toan tu != " << endl;
//    if (p1 != p2) {
//        cout << "Hai phan so khac nhau." << endl;
//    } else {
//        cout << "Hai phan so bang nhau." << endl;
//    }
//	cout << "\nSu dung toan tu < " << endl;
//    if (p1 < p2) {
//        cout << "Phan so thu nhat nho hon phan so thu hai." << endl;
//    } else {
//        cout << "Phan so thu nhat lon hon hoac bang phan so thu hai." << endl;
//    }
//	cout << "\nSu dung toan tu <= " << endl;
//    if (p1 <= p2) {
//        cout << "Phan so thu nhat nho hon hoac bang phan so thu hai." << endl;
//    } else {
//        cout << "Phan so thu nhat lon hon phan so thu hai." << endl;
//    }
//	cout << "\nSu dung toan tu > " << endl;
//    if (p1 > p2) {
//        cout << "Phan so thu nhat lon hon phan so thu hai." << endl;
//    } else {
//        cout << "Phan so thu nhat nho hon hoac bang phan so thu hai." << endl;
//    }
//
//	cout << "\nSu dung toan tu >= " << endl;
//    if (p1 >= p2) {
//        cout << "Phan so thu nhat lon hon hoac bang phan so thu hai." << endl;
//    } else {
//        cout << "Phan so thu nhat nho hon phan so thu hai." << endl;
//    }

    return 0;
}
