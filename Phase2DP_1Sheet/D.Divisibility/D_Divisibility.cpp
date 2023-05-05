#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int n, k, arr[10005];
int dp[10005][1000];

bool dfs(int i, int value) {
	if(i==n) return value%k==0?true:false;
	if (dp[i][(value%k)] == 1) return true;
	if (dp[i][(value%k)] != -1) return false;
	if(dfs(i+1, value+arr[i])) return dp[i][(value%k)]=1;
	if(dfs(i+1, value-arr[i])) return dp[i][(value%k)]=1;
	return dp[i][(value%k)]=0;
}

int main() {
	int testcases;
	cin>>testcases;
	while(testcases > 0) {
		cin>>n>>k;
		for(int i=0;i<n;i++) cin>>arr[i];
		memset(dp, -1, sizeof(dp));
		if(dfs(1, arr[0])) cout<<"Divisible";
		else cout<<"Not divisible";
		cout<<"\n";
		testcases--;
	}
}