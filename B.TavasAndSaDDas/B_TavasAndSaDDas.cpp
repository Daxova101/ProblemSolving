#include<iostream>
using namespace std;

int main() {
	string x;
	cin>>x;
	long long ans = (1 << x.length()) - 2;
	for(long long i=x.length()-1;i>=0;i--) {
		if (x[i] == '7') ans += (1 << (x.length()-i-1));
	}
	cout<<ans+1;
}