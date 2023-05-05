#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int n, w, wei[105], val[105], dp[105][100005], total=0;

int dfs(int i, int value) {
	if (i==n) return value==0?0:1000000000;
	if (dp[i][value] != -1) return dp[i][value];
	dp[i][value] = 1000000000;
	dp[i][value] = min(dp[i][value], dfs(i+1, value-val[i])+wei[i]);
	dp[i][value] = min(dp[i][value], dfs(i+1, value));
	return dp[i][value];
}

int main() {
	cin>>n>>w;
	for(int i=0;i<n;i++) {
		cin>>wei[i]>>val[i];
		total+=val[i];
	}
	memset(dp, -1, sizeof(dp));
	for(int i=total;i>=0;i--) {
		if (dfs(0, i) <= w) {
			total = i;
			break;
		} 
	}
	cout<<total;
}