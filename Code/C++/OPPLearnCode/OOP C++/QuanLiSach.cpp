#include <bits/stdc++.h>
using namespace std;

bool isValidDate(int day, int month, int year) {
	// Kiểm tra năm có hợp lệ
	if (year < 1900 || year > 2099) {
		return false;
	}

	// Kiểm tra tháng có hợp lệ
	if (month < 1 || month > 12) {
		return false;
	}

	// Kiểm tra ngày có hợp lệ
	if (day < 1) {
		return false;
	}

	int maxDay = 31; // Mặc định tháng có 31 ngày

	if (month == 4 || month == 6 || month == 9 || month == 11) {
		maxDay = 30; // Tháng 4, 6, 9, 11 có 30 ngày
	} else if (month == 2) {
		// Kiểm tra năm nhuận
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			maxDay = 29; // Năm nhuận tháng 2 có 29 ngày
		} else {
			maxDay = 28; // Tháng 2 có 28 ngày
		}
	}

	if (day > maxDay) {
		return false;
	}

	return true;
}

class Sach {
	private:
		string ma, ten, tacgia;
		int socuon;
		int ngay, thang, nam;
	public:
		void nhap();
		void in();
		int get_socuon() {
			return socuon;
		};
		int get_ngay() {
			return ngay;
		}
		int get_thang() {
			return thang;
		}
		int get_nam() {
			return nam;
		}
};

void Sach::nhap() {
	cout<< "\nNhap ma dau sach: ";
	getline(cin, ma);
	cout<< "\nNhap ten dau sach: ";
	getline(cin, ten);
	cout <<"\nNhap tac gia: ";
	getline(cin, tacgia);
	cout <<"\nNhap so cuon sach: ";
	cin >> socuon;
	cin.ignore();
	int d,m,y;
	do {
		cout<< "\nNhap ngay nhap: ";
		cin >> d >> m >> y;
	} while(!isValidDate(d,m,y));
	ngay =d;
	thang = m;
	nam = y;
	cin.ignore();
}

void Sach::in() {
	cout << ma <<" "
	     << ten <<" "
	     << tacgia <<" "
	     << socuon <<" "
	     << ngay<<"/"<<thang<<"/"<<nam<< endl;
}

class quanly {
	private:
		Sach s[200];
		int n;
	public:
		void nhapds();
		void inds();
		void insll();
		void sapxep();
		void xoa();
};

void quanly::nhapds() {
	cout <<"\nNhap so luong dau sach: ";
	cin >> n;
	cin.ignore();
	for (int i=0; i<n; i++) {
		cout <<"\nNhap thong tin dau sach thu: " << i+1 << endl;
		s[i].nhap();
	}
}

void quanly::inds() {
	for (int i=0; i<n; i++) {
		s[i].in();
	}
}

void quanly::insll() {
	int l=0;
	l=s[0].get_socuon();
	for (int i=0; i<n; i++) {
		if (l < s[i].get_socuon()) {
			l=s[i].get_socuon();
		}
	}
	cout <<"\nThong tin dau sach co so cuon nhieu nhat la" << endl;
	for (int i=0; i<n; i++) {
		if (s[i].get_socuon() == l) {
			s[i].in();
		}
	}
	cout << endl;
}

void quanly::xoa() {
	int count=0;
	for (int i=0; i<n; i++) {
		if (s[i].get_socuon() != 0) {
			s[count]= s[i];
			count++;
		}
	}
	n=count;
	cout <<"\nDanh sach sau khi da xoa: " << endl;
	for (int i=0;i<n;i++){
		s[i].in();
	}
}
void hoanvi(Sach &a, Sach &b){
	Sach temp = a;
	a=b;
	b=temp;
}
void quanly::sapxep(){
	for (int i = 0; i < n - 1; i++) {
	    for (int j = i + 1; j < n; j++) {
	        if (s[i].get_nam() > s[j].get_nam() ||
	            (s[i].get_nam() == s[j].get_nam() && s[i].get_thang() > s[j].get_thang()) ||
	            (s[i].get_nam() == s[j].get_nam() && s[i].get_thang() == s[j].get_thang() && s[i].get_ngay() > s[j].get_ngay())) {
	            	hoanvi(s[i], s[j]);
	        }
	    }
	}	
    cout << "DANH SACH SACH THEO THU TU TANG DAN CUA NGAY NHAP:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Thong tin sach thu " << i + 1 << ":" << endl;
        s[i].in();
    }	
}

int main() {
	quanly s;
	s.nhapds();
	s.inds();
	s.insll();
	s.sapxep();
	s.xoa();
}