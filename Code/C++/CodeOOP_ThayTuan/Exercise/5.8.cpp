#include <bits/stdc++.h>
using namespace std;
class HVUONG{
	float canh;
	public:
		void nhap(){
			cout << "\nNhap do dai canh: ";
			cin>>canh;
		}
		void in(){
			cout << "\nDo dai canh la: ";
			cout << canh << endl;
		}
		float get_canh(){
			return canh;
		}
		float dientich(){
			float res= canh*canh;
			return res;
		}
		float chuvi(){
			float res=canh*4;
			return res;
		}
	
};
class CHUNHAT : public HVUONG
{
	float canh2;
	public:
		void nhapCN(){
			nhap();
			cout << "\nNhap do danh canh 2: "; 
			cin >> canh2;
		}
		void inH(){
			in();
			cout << "\nDo dai canh 2 la: " << canh2 << endl;
		}
		float dt(){
			float res= get_canh()*canh2;
			return res;
		}
		float cv(){
			float res=(get_canh()+canh2)*2;
			return res;
		}
};

int main(){
	HVUONG hv;
	hv.nhap();
	hv.in();
	cout << hv.chuvi() <<endl;
	cout << hv.dientich() << endl;
	CHUNHAT c;
	c.nhapCN();
	c.inH();
	cout << c.cv() <<endl;
	cout << c.dt() <<endl;
	
}