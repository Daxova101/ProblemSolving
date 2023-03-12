#include<iostream>
#include<cmath>
using namespace std;

int n, k;
long long h[100005], dp[100005];

int main() {
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		cin>>h[i];
	}
	dp[n-1] = 0;
	for(int i=n-2;i>=0;i--) {
		long long mini=10000000000000000;
		for(int j=1;j<=k && i+j<=n-1;j++) {
			long long x = abs(h[i]-h[i+j])+dp[i+j];
			if (x < mini) mini = x;
		}
		dp[i] = mini;
	}
	cout<<dp[0];
}