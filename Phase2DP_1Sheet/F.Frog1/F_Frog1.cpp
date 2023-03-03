#include<iostream>
#include<cmath>
using namespace std;

int n;
int h[100005], dp[100005];

int main() {
	int x,y;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>h[i];
	}
	dp[n-1] = 0;
	for(int i=n-2;i>=0;i--) {
		x = abs(h[i]-h[i+1])+dp[i+1];
		y = i+2<=n-1? abs(h[i]-h[i+2])+dp[i+2] : 1000000;
		dp[i] = min(x, y);
	}
	cout<<dp[0];
}