#include<iostream>
#include<map>
#include<iterator>
#include<cstring>
using namespace std;

int n, x[100005], h[100005], ans=1;

int main() {
	int testcases=1;
	//cin>>testcases;
	while (testcases > 0) {
		cin>>n;
		for(int i=0;i<n;i++) {
			cin>>x[i]>>h[i];
		}
		for(int i=n-2;i>=0;i--) {
			if (x[i]+h[i] < x[i+1]) ans++;
			else if (i==0) ans++;
			else if (x[i]-h[i] > x[i-1]) {x[i]-=h[i];ans++;}
		}
		cout<<ans;
		testcases--;
	}
}