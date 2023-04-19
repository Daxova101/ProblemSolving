#include<iostream>
using namespace std;

int main() {
	int n,x=0,y=0,z=0,k=0, ans=0, rc=0;
	cin>>n;
	int arr[n][n];
	for(int i=0;i<n;i++){
		for(int x=0;x<n;x++) {
			cin>>arr[i][x];
		}
	}
	for(int i=0;i<n*n;i++){
		for(;y<n;y++,z++) {
			if (arr[x][y] == arr[z][k]) ans++;
		}
		if (ans==n) rc++;
		ans=0;
		y=0;
		z=0;
		k++;
		if(k==n) {
			x++;
			k=0;
		}
	}
	cout<<rc;
}