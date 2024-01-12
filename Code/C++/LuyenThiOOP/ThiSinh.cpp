#include <bits/stdc++.h>
using namespace std;
class Thisinh{
	string sobd, ho, ten, diachi;
	int diemUT;
	public:
		Thisinh(){
			sobd=ho=ten=diachi="";
		}
		Thisinh(string s, string h,string t,  string dc,int d){
			sobd=s;
			ho=h;
			ten=t;
			diachi=dc;
			diemUT=d;
		}
		string get_sobd(){
			return sobd;
		}
		string get_diachi(){
			return diachi;
		}
		int get_diemUT(){
			return diemUT;
		}
		virtual void nhap(){
			cout << "\nNhap so bao danh: ";
			getline(cin,sobd);
			cout << "\nNhap ho: ";
			getline(cin,ho);
			cout << "\nNhap ten: ";
			getline(cin,ten);
			cout << "\nNhap dia chi: ";
			getline(cin, diachi);
			cout << "\nNhap diem uu tien: ";
			cin >> diemUT;
		}
		virtual void in(){
			cout << sobd <<" " << ho <<" "<<ten << " " << diachi << " " << diemUT << " ";
		}
		bool operator > (Thisinh a){
			if (ten != a.ten){
				return ho > a.ho;
			}else{
				return ten > a.ten;
			}
		}
		virtual int TongDiem(){
			return 0;
		}
		virtual bool check(){
			return 0;
		}
		virtual bool checkKhoi(){
			return 0;
		}
};

class KhoiTN : public Thisinh{
	int diemToan, diemLy, diemHoa;
	public: 
		KhoiTN(){
			diemToan=diemLy=diemHoa=0;
		}
		KhoiTN(int t, int l, int h){
			diemToan=t;
			diemLy=l;
			diemHoa=h;
		}
		void nhap(){
			Thisinh::nhap();
			cout << "\nNhap diem Toan: ";
			cin >> diemToan;
			cout << "\nNhap diem Ly: ";
			cin >> diemLy;
			cout << "\nNhap diem Hoa: ";
			cin >>diemHoa;
			cin.ignore();
		}
		void in(){
			Thisinh::in();
			cout << diemToan << " " <<diemLy << " " << diemHoa << endl;
		}
		int TongDiem(){
			return diemToan+diemLy+diemHoa+get_diemUT();
		}
		bool check(){
			return TongDiem() > 22;
		}
		bool checkKhoi(){
			return 1;
		}
};

class KhoiXH : public Thisinh{
	int diemVan, diemSu, diemDia;
	public: 
		KhoiXH(){
			diemVan=diemSu=diemDia=0;
		}
		KhoiXH(int t, int l, int h){
			diemVan=t;
			diemSu=l;
			diemDia=h;
		}
		void nhap(){
			Thisinh::nhap();
			cout << "\nNhap diem Van: ";
			cin >> diemVan;
			cout << "\nNhap diem Su: ";
			cin >> diemSu;
			cout << "\nNhap diem Dia: ";
			cin >> diemDia;
			cin.ignore();
		}
		void in(){
			Thisinh::in();
			cout << diemVan << " " << diemSu << " " << diemDia << endl;
		}
		int TongDiem(){
			return diemVan + diemSu+ diemDia +get_diemUT();
		}
		bool check(){
			return TongDiem() > 19;
		}
		bool checkKhoi(){
			return 0;
		}
};


class Quanli{
	Thisinh *a[50];
	int n;
	public:
		void nhapds(){
			do{
				cout << "\nNhap so luog thi sinh: ";
				cin >> n; cin.ignore();
				if (n<=0 || n>50){
					cout << "\nNhap sai vui long nhap lai." << endl;
				}
			}while(n<=0 || n>50);
			for (int i=0;i<n;i++){
				int check;
				do{
					cout << "\nNhap khoi hoc cua thi sinh (1-Tu Nhien 2-Xa hoi): ";
					cin >> check;
					cin.ignore();
					if (check!=1 && check!=2){
					cout << "\nNhap sai vui long nhap lai." << endl;
					}
				}while(check!=1 && check!=2);
				if (check==1){
					KhoiTN *p = new KhoiTN;
					p->nhap();
					a[i]=p;	
				}else{
					KhoiXH *p = new KhoiXH;
					p->nhap();
					a[i]=p;
				}
				for(int j=0;j<i;j++){
					if (a[i]->get_sobd() == a[j]->get_sobd()){
						cout << "\nMa bi trung, nhap lai." << endl;
						delete a[i];
						--i;
						break;
					}
				}
			}
		}
		
		void sapXep(){
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if (!(*a[i] > *a[j])){
						Thisinh *tmp;
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			cout << "\nDanh sach sau khi sap xep la: " << endl;
			for (int i=0;i<n;i++){
				a[i]->in();
				cout << endl;
			}
		}
		void xuatTheoKhoi() {
			int cntXH=0, cntTN=0;
	        cout << "\nDanh sach theo tung khoi: " << endl;
	        cout << "\nKhoi Tu Nhien: " << endl;
	        for (int i = 0; i < n; ++i) {
	            if (a[i]->checkKhoi()) {
	                a[i]->in();
	                cntTN++;
	            }
	        }
	        cout << "\nKhoi Xa Hoi: " << endl;
	        for (int i = 0; i < n; ++i) {
	            if (!a[i]->checkKhoi()) {
	                a[i]->in();
	                cntXH++;
	            }
	        }
	        ///mot doan code de kiem tra neu khong co thi sinh nào thi cout ra 0
	    }
	    void xuatDau(){
	    	int cnt=0;
	    	cout << "\nDanh sach sinh vien dau la: " << endl;
	    	for (int i=0;i<n;i++){
	    		if (a[i]->check()){
	    			a[i]->in();
	    			cnt++;
				}
			}
			if(cnt==0){
				cout << "\nKhong co sinh vien nao dau." << endl;
			}
		}
		
		void inTBCong(){
			int tongXH=0, tongTN=0;
			int cntXH=0, cntTN=0;
			for (int i=0;i<n;i++){
				if (!(a[i]->checkKhoi())){
					tongXH+=a[i]->TongDiem();
					cntXH++;
				}else{
					tongTN+=a[i]->TongDiem();
					cntTN++;
				}
			}
			cout << "Diem trung binh khoi xa hoi la: " << tongXH/cntXH << endl;
			cout << "Diem trung binh khoi tu nhien la: " << tongTN/cntTN << endl;
			if (cntXH==0){
				cout << "\nKhong co thi sinh Xa Hoi trong danh sach." << endl;
			}
			if (cntTN == 0){
				cout << "\nKhong co thi sinh tu nhien trong danh sach." << endl;
			}
		}
		
		void xoa(){
			string s;
			bool check=1;
			cout << "\nNhap ma thi sinh can xoa: " << endl;
			getline(cin,s);
			for (int i=0;i<n;i++){
				if(a[i]->get_sobd() == s){
					delete a[i];
					check=0;
					for (int j=i;j<n-1;j++){
						a[j]=a[j+1];
					}
					--n;
					cout << "\nDa xoa thi sinh co ma: " << s ;
					return ;
				}
			}
			if (!check){
				cout << "\nKhong co ma thi sinh." ;
			}
		}
		
		void them() {
		    if (n >= 50) {
		        cout << "\nDanh sach da day, khong the them.";
		        return;
		    }
		    int check;
		    do {
		        cout << "\nNhap khoi hoc cua thi sinh (1-Tu Nhien 2-Xa hoi): ";
		        cin >> check;
		        cin.ignore();
		        if (check != 1 && check != 2) {
		            cout << "\nNhap sai, vui long nhap lai." << endl;
		        }
		    } while (check != 1 && check != 2);
		
		    Thisinh* p;
		    if (check == 1) {
		        KhoiTN* newKhoiTN = new KhoiTN;
		        newKhoiTN->nhap();
		        p = newKhoiTN;
		    } else {
		        KhoiXH* newKhoiXH = new KhoiXH;
		        newKhoiXH->nhap();
		        p = newKhoiXH;
		    }
		
		    for (int i = 0; i < n; i++) {
		        if (a[i]->get_sobd() == p->get_sobd()) {
		            cout << "\nMa bi trung, nhap lai." << endl;
		            delete p;
		            return;
		        }
		    }
		
		    a[n++] = p;
		    cout << "\nThem thi sinh thanh cong.";
		}
		
		void timKiem(){
			string s;
			cout << "\nNhap tu khoa can tim kiem: ";
			getline(cin,s);
			cout << "\nDanh sach cac thi sinh co dia chi : " << s << endl;
			for (int i=0;i<n;i++){
				if (a[i]->get_diachi().find(s) != string::npos){
					a[i]->in();
				}
			}
		}
};

int main(){
	Quanli ob;
	ob.nhapds();
	ob.sapXep();
	ob.xuatTheoKhoi();
	ob.xuatDau();
	ob.inTBCong();
	ob.xoa();
	ob.timKiem();

}