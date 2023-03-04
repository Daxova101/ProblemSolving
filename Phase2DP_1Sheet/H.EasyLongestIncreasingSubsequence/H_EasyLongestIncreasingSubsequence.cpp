#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n], dp[n], big=1;
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	dp[n-1] = 1;
	for(int i=n-2;i>=0;i--) {
		int IS = 1;
		for(int j=i+1;j<n;j++) {
			if (arr[i] < arr[j] && IS < 1+dp[j]) IS = dp[j]+1;
		}
		dp[i] = IS;
		if (big < dp[i]) big = dp[i];
	}
	cout<<big;
}