#include <iostream>
using namespace std;
class Time
{
  private:	
	int h,m,s;  
  public:
	//cac ham tao
	Time(); //ham tao mac dinh
	Time(int a,int b,int c); //ham tao co 3 tham so
	
	int get_s(){
		return s;
	}
	int get_m(){
		return m;
	}
	int get_h(){
		return h;
	}
	
	
	void chuanhoa(); //chuan hoa gio, phut va giay theo quy dinh
	void giatang(int a, int b, int c);//tang gio hien tai theo
									  //a: gio, b: phut, c:giay
	void dieuchinh(int a, int b,int c);
	
	bool operator == (Time a);
	bool operator != (Time a);
	Time operator += (Time a);
	Time operator ++ ();
	Time operator -- ();
	friend istream & operator >> (istream &in, Time &t);
	friend ostream & operator << (ostream &out, Time &t);	
	
};
istream & operator >> (istream &in, Time &t){
	while(1)
    {
        cout << "Nhap vao gio, phut va giay: ";
        in>>t.h>>t.m>>t.s;
        if (t.h >= 0 and t.m >=0 and t.s>=0)
            break;
        cout << "Nhap sai! Hay nhap lai." << endl;
    }
    return in;
}
ostream & operator << (ostream &out, Time &t){
	out << t.h <<":"<<t.m<<":"<<t.s<<"\n";
	return out;
}

Time Time::operator --(){
	--h;
	--m;
	--s;
	chuanhoa();
	return (*this);
}

Time Time::operator ++(){
	++h;
	++m;
	++s;
	chuanhoa();
	return (*this);
}

bool Time::operator == (Time a){
	int tong = h*3600 + m*60 + s;
	int sum = a.h*3600 + a.m*60 + a.s; 
	return tong == sum;
}

bool Time::operator != (Time a) {
	return h != a.h or m !=a.m or s !=a.s;
}

Time Time::operator += (Time a){
	int tong = (h*3600 + m*60 + s) + (a.h*3600 + a.m*60 + a.s); 
	h = (tong/3600)%24;
    m = (tong/60)%60;
    s = tong%60;	
    return *this; 
}

Time::Time()
{	h=m=s=0; }

Time::Time(int a,int b,int c)
{	h=a; m=b; s = c;}

//void Time::nhap()
//{
//	while(1)
//    {
//        cout << "Nhap vao gio, phut va giay: ";
//        cin>>h>>m>>s;
//        if (h >= 0 and m >=0 and s>=0)
//            break;
//        cout << "Nhap sai! Hay nhap lai." << endl;
//    }	
//}

//void Time::xuat()
//{	cout<<h<<":"<<m<<":"<<s<<"\n"; }

void Time::chuanhoa()
{
    int tong = h*3600 + m*60 + s; 
    h = (tong/3600)%24;
    m = (tong/60)%60;
    s = tong%60;
}

int main(){
	Time a,b,c;
	//dung >>;
	cin >> a;
	cin >>b;
//	dung <<
	cout << "\nDoi tuong a: ";
	cout << a;
	cout << "\nDoi tuong b: ";
	cout << b;
	
	cout << "\nKiem tra co bang nhau khong : " <<endl;
	if (a == b){
		cout << "a bang b";
	}else {
		cout << "a khong bang b";
	}
	cout << "\nKiem tra co khac nhau khong: " << endl;
	if (a != b){
		cout << "a khac b";
	}else {
		cout << "a giong b";
	}
		
	cout << "\nSu dung toan tu +=: " << endl;
	a+=b;
	cout << a;
	
	cout << "\nSu dung toan tu ++: " << endl;
	++a;
	cout << a;
	
	cout << "\nSu dung toan tu --: " << endl;
	--a;
	cout << a;
	
}
  