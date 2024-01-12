#include <bits/stdc++.h>
using namespace std;
#define N 50
class Stack{
	int arr[N];
	int top;
	public:
		Stack(){
			top=-1;
		}
		void push(int i);
		int pop();
		int get_top(){
			return top;
		}
};
void Stack::push(int i){
	if (top==N-1){
		cout << "\nStack full !" << endl;
		return;
	}else{
		arr[++top]=i;
	}
}
int Stack::pop(){
	if (top == -1){
		cout << "\nStack rong !";
		return -1;
	}
	return arr[top--];
}

class chuyencoso : public Stack{
	int so, coso;
	public:
		void chuyendoi();
		void in();
		int get_coso(){
			return coso;
		}
};

void chuyencoso::chuyendoi(){
//	cin.ignore(1);
	cout << "\nNhap so nguyen duong he 10: ";
	cin >> so;
	cout << "\nNhap co so(2/8/16): "; cin >> coso;
	while(so!=0){
		int i=so%coso;
		push(i);
		so=so/coso;
	}
}
void chuyencoso::in(){
	cout << "\nChuyen sang he " << coso << " la: " << endl;
	while(get_top() != -1){
		if (coso == 16){
			cout << hex << pop();
		}else{
			cout << pop();
		}	
	}
}
int main(){
	chuyencoso ob;
	ob.chuyendoi();
	ob.in();
}