#include<iostream>
using namespace std;

int ans=0;

void solve(int n) {
	if (n==1) {
		ans++;
		return;
	}
	if (n%2 == 0) {
		solve(n/2);
		ans++;
		return;
	}
	solve(3*n+1);
	ans++;
	return;
}

int main() {
	int n;
	cin>>n;
	solve(n);
	cout<<ans;
}