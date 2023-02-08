#include<iostream>
#include<cmath>
using namespace std;

int seq, up=0;

void solve(int n) {
	if (seq==up) {
		return;
	}
	int ans[n] = {0}, tmp =up;
	for(int i=n-1;i>=0;i--) {
		ans[i] = tmp%2;
		tmp /= 2;
	}
	for(int i=0;i<n;i++) {
		cout<<ans[i];
	}
	cout<<"\n";
	up++;
	solve(n);
}

int main() {
	int testcases;
	cin>>testcases;
	while (testcases > 0) {
		up=0;
		int n;
		cin>>n;
		seq = pow(2, n);
		solve(n);
		testcases--;
	}
}