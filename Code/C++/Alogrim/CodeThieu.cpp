#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ans= sqrt(n);
	if (ans==sqrt(n)){
		cout<<"YES";
	}
	else{
		cout<<"NO " <<ans*ans;
	}
}