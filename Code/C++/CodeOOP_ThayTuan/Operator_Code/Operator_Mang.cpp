#include <bits/stdc++.h>
using namespace std;

class Mang{
	int a[1000];
	int n;
	public:
		void nhap();
		void in();
		Mang operator + (Mang arr);
		Mang operator - (Mang arr);
		bool operator == (Mang arr);
		bool operator != (Mang arr);
};

bool Mang::operator == (Mang arr){
	if (n == arr.n){
		for (int i=0;i<n;i++){
			if (a[i] == arr.a[i]){
				return 1;
				}
			}
		}
	return 0;
}

bool Mang::operator !=(Mang arr){
	if (n != arr.n){
		return 1;
	}else {
		for (int i=0;i<n;i++){
			if (a[i]!= arr.a[i]){
				return 1;
				}
			}
		}
	return 0;
}


void Mang::nhap(){
	cout << "\nNhap so luong phan tu cua mang: "; cin >> n;
	cin.ignore();
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
}
void Mang::in(){
	cout << "\nCac phan tu cua mang: "; 
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
Mang Mang::operator + (Mang arr){
	Mang sum;
	if (n != arr.n){
		cout << "Khong the thuc hien phep cong. Hai mang co kich thuoc khac nhau." <<endl;
//		exit(0);
	}else {
		for (int i=0;i<n;i++){
			sum.a[i] = a[i]+ arr.a[i];
		}
	}
	sum.n = n;
	return sum;
}

Mang Mang::operator - (Mang arr){
	Mang sub;
	if (n != arr.n){
		cout << "Khong the thuc hien phep tru. Hai mang co kich thuoc khac nhau." <<endl;
//		exit(0);
	}else{
		for (int i=0;i<n;i++){
			sub.a[i] = a[i] - arr.a[i];
		}
	}
	sub.n = n;
	return sub;
}



int main(){
	Mang a, a2, a3, a4;
	a.nhap();
	a.in();
	a2.nhap();
	a2.in();
	
	a3 = a+a2;
	cout <<"Tong hai mang la: "<< endl;
	a3.in();
	
	a4 = a-a2;
	cout <<"Hieu hai mang la: "<< endl;
	a4.in();
	
	cout << "\nSo sanh hai mang != " << endl;
	if (a != a2){
		cout << "\nMang a1 khac mang a2 " << endl;
	}else{
		cout << "\nMang a1 khong khac mang a2" << endl;
	}
	
	cout << "\nSo sanh hai mang != " << endl;
	if (a == a2){
		cout << "\nMang a1 bang mang a2 " << endl;
	}else{
		cout << "\nMang a1 khong bang mang a2" << endl;
	}
	
}