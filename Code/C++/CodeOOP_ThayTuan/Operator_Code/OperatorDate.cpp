#include <bits/stdc++.h>
using namespace std;
class Date
{
private:
	int D,M,Y; //ngày, tháng, nam
	public:
	bool nhuan(); //kiem tra nam nhuan
	int ngaythang(); //tra ve so ngay trong thang
	
	void nhap(); //co kiem tra du lieu
	void xuat();
	void cong_1(); //cong 1 ngay vao doi tuong
	Date cong_k(int k); //tang doi tuong ngay len k ngay
	bool operator < (Date d);
	bool operator <= (Date d);
	bool operator == (Date d);
	bool operator != (Date d);
	Date operator += (int k);
	bool operator > (Date d);
	bool operator >= (Date d);
};

bool Date::operator >=(Date d){
	return (Y >= d.Y) || (Y == d.Y && M >= d.M) || (Y == d.Y && M == d.M && D >= d.D);
}

bool Date::operator > (Date d){
	if (Y > d.Y) return 1;
	else if ( Y == d.Y && M > d.M) return 1;
	else if ( Y == d.Y && M == d.M && D > d.D ) return 1;
	return 0;
}



bool Date::operator != (Date d){
	if ( Y != d.Y || M != d.M || D != d.D ) return 1;
	return 0;	
}


void Date::cong_1() //tang ngay hien tai len 1 ngay
{
	int S; //vi du nhap vao 31 12 2020, luc do D =31 M =12 Y =2020
	S =ngaythang(); //S la so ngay cua thang M, S = 31
	if (++D>S) //tang D len 1 roi kiem tra> S ?
	{
	D = 1;
	if (++M>12)
		{ M = 1;
		Y = Y + 1;
		}
	}
//ta co ket qua tang 1 ngay: 1 1 2021
}
Date Date::operator +=(int k){
	for (int i=1;i<=k;i++) //lap k lan cua ham cong_1
		cong_1();
	return *this;
}

bool Date::operator < (Date d){
	if (Y < d.Y) return 1;
	else if ( Y == d.Y && M < d.M) return 1;
	else if ( Y == d.Y && M == d.M && D < d.D ) return 1;
	return 0;
}
bool Date::operator <=(Date d){
	return (Y <= d.Y) || (Y == d.Y && M <= d.M) || (Y == d.Y && M == d.M && D <= d.D);
}


bool Date::nhuan() //tra ve true neu Y nhuan, false neu khong nhuan
{	
	if ((Y % 4 == 0 and Y % 100 != 0) or (Y % 400 == 0))
	return true; //Y la nam nhuan
	else
	return false; //Y khong phai nam nhuan
}

int Date::ngaythang() //ham nay tra ve so ngay cua thang M
{

	if (M==4 or M==6 or M==9 or M==11)
	return 30;
	else if (M==2)
	return 28 + nhuan();
	else
	return 31;
}

void Date::nhap()
{
	int S; //S de tim so ngay cua thang Ma
	bool k; //bien kiem tra viec nhap co hop le khong
	do
	{
	cout<<"\nNhap vao ngay thang nam : "<<endl;
	cin>>D>>M>>Y;
	
	S = ngaythang(); //S la so ngay cua thang M da nhap
	if ((D > 0) and (D <= S) and (M >= 1) and (M <= 12 ) and Y > 0)
	
	k = true; //hop le
	else
	{ cout<<"\nSai ngay! Hay nhap lai. "<<endl;
	k = false; //khong hop le
	}
	} while(k == false);
	}
	
	void Date::xuat()
	{
	cout<<D<<'/'<<M<<'/'<<Y<<endl;
}
bool Date::operator == (Date d){
	if (Y == d.Y && M == d.M && D == d.D); return 1;
	return 0;
}


Date Date::cong_k(int k) //ham tra ve doi tuong moi sau khi tang k ngay cua doi hien tai
{
	Date t;
	t.D = D;
	t.M= M;
	t.Y = Y;
	for (int i=1;i<=k;i++) //lap k lan cua ham cong_1
	t.cong_1();
	return t;
}


int main()
{
	Date d,d2, d3;
	cout<<"\n Nhap doi tuong d: ";
	d.nhap();
	cout<<"\n Du lieu cua doi tuong: ";
	d.xuat();
	cout<<"\n Nhap doi tuong d2: ";
	d2.nhap();
	cout<<"\n Du lieu cua doi tuong d2: ";
	d2.xuat();
	
	cout << "\nSu sung toan tu < : " << endl;
	if ( d < d2){
		cout << "\nD1 be hon D2: " << endl;
	}else {
		cout << "\nD1 khong be hon D2" << endl;
	}
	
	cout << "\nSu sung toan tu > : " << endl;
	if ( d > d2){
		cout << "\nD1 lon hon D2: " << endl;
	}else {
		cout << "\nD1 khong lon hon D2" << endl;
	}
	
	cout << "\nSu sung toan tu == : " << endl;
	if ( d == d2){
		cout << "\nD1 bang D2 " << endl;
	}else {
		cout << "\nD1 khong bang D2" << endl;
	}

	cout << "\nSu sung toan tu >= : " << endl;
	if ( d >= d2){
		cout << "\nD1 lon hon hoac bang D2 " << endl;
	}else {
		cout << "\nD1 khong lon hon hoac bang D2" << endl;
	}
	
	cout << "\nSu sung toan tu <= : " << endl;
	if ( d <= d2){
		cout << "\nD1 be hon hoac bang D2 " << endl;
	}else {
		cout << "\nD1 khong be hon hoac bang D2" << endl;
	}
	
	cout << "\nSu sung toan tu != : " << endl;
	if ( d != d2){
		cout << "\nD1 khac D2 " << endl;
	}else {
		cout << "\nD1 khong khac D2" << endl;
	}	
	
	
	int k;
	cout << "\nNhap so luong ngay (k): "; cin >> k;
	d += k;
	cout << "\nKet qua sau khi cong k ngay la: ";
	d.xuat();
	
	return 0;
}
