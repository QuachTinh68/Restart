#include <bits/stdc++.h>
using namespace std;
void matrix(int n, int m){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cout << j+i<< " ";
		}
		cout << endl;
	}
}
int main(){
	int n,m ; cin >> n >> m;
	matrix(n,m);
}