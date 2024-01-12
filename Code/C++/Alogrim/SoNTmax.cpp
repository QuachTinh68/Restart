#include <bits/stdc++.h>
using namespace std;

bool check(int n){
	if (n<2){
		return 0;
	}
	for (int i=2;i<=sqrt(n);i++){
		if (n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	int max=a[0];
	for (int i=0;i<n;i++){
		if (check(a[i])){
			if (max < a[i]){
				max=a[i];
			}
		}
	}
	cout << max;
}