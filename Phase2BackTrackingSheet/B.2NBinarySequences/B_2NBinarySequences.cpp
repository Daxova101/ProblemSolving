#include<iostream>
#include<cmath>
using namespace std;

int seq, up=0;

void solve(int n) {
	if (seq==up) {
		return;
	}
	int ans[n] = {0}, tmp =up, sum1=0, sum2=0;
	for(int i=n-1;i>=0;i--) {
		if ((i+1) > n/2) {
			sum1+= tmp%2;
		}
		else {
			sum2+= tmp%2;
		}
		ans[i] = tmp%2;
		tmp /= 2;
	}
	for(int i=0;i<n && sum1==sum2;i++) {
		cout<<ans[i];
	}
	if (sum1 == sum2) {
		cout<<"\n";
	}
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
		seq = pow(2, n*2);
		solve(n*2);
		testcases--;
	}
}