#include<iostream>
using namespace std;

int r1, c1, r2, c2;
int arr1[102][102], arr2[102][102];
void solve(int ar1, int ac1, int ar2, int ac2) {
	if (ac2 == c2) {
		ac2=0;
		ar1++;
		cout<<"\n";
	}
	if (ar1 == r1) return;
	int sum=0;
	for(ac1=0, ar2=0;ac1<c1;ac1++, ar2++) {
		sum += arr1[ar1][ac1]*arr2[ar2][ac2];
	}
	cout<<sum<<" ";
	solve(ar1, ac1, ar2, ac2+1);
}

int main() {
	cin>>r1>>c1;
	for(int i=0;i<r1;i++) {
		for(int n=0;n<c1;n++) {
			cin>>arr1[i][n];
		}
	}
	cin>>r2>>c2;
	for(int i=0;i<r2;i++) {
		for(int n=0;n<c2;n++) {
			cin>>arr2[i][n];
		}
	}
	solve(0, 0, 0, 0);
}