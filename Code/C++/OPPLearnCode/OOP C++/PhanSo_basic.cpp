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
class PhanSo{
	int tu, mau;
	public:
		PhanSo(){
			tu=0;
			mau=1;
		}
		void nhap(){
			cout << "\nNhap tu so: "; cin >> tu;
			cout << "\nNhap mau so: "; cin >> mau;
		}
		void in(){
			cout << tu <<"/" << mau << endl;
		}
		PhanSo operator + (PhanSo a){
			PhanSo p;
			int bc = BCNN(mau, a.mau);
			int tu1 = tu *(bc /mau);
			int tu2 = a.tu *(bc /a.mau);
			 
			p.tu = tu1 + tu2;
			p.mau=bc;
			
			int uc = UCLN(p.tu,p.mau);
			p.tu /= uc;
		    p.mau /= uc;
		    
		    return p;
		}
		
		PhanSo operator + (int k){
			PhanSo p;
		    p.tu = tu + k * mau;
		    p.mau = mau;
		
		    int uc = UCLN(p.tu, p.mau);
		    p.tu /= uc;
		    p.mau /= uc;
		
		    return p;
		}
};

int main(){
	PhanSo p1, p2,p3, p4;
	p1.nhap();
	p1.in();
	p2.nhap();
	p2.in();
	cout << "\nTong hai phan so la: ";
	p3=p1+p2;
	p3.in();
	int k;
	cout << "\nNhap so nguyen can cong: "; cin  >> k;
	cout << "\nTong khi cong voi k la: ";
	p4 = p1+k;
	p4.in();
}