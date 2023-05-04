#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int n, arr[105], dp[105][60000];

int dfs(int i, int s1, int s2) {
	if (i == n) return abs(s1-s2);
	if (dp[i][abs(s1-s2)] != -1) return dp[i][abs(s1-s2)];
	int x = dfs(i+1, s1+arr[i], s2);
	int y = dfs(i+1, s1, s2+arr[i]);
	dp[i][abs(s1-s2)] = min(x,y);
	return dp[i][abs(s1-s2)];
}

int main() {
	int testcases;
	cin>>testcases;
	while(testcases>0) {
		cin>>n;
		for(int i=0;i<n;i++) cin>>arr[i];
		memset(dp, -1, sizeof(dp));
		cout<<dfs(0, 0, 0)<<"\n";
		testcases--;
	}
}