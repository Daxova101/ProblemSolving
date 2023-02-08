#include<iostream>
using namespace std;

unsigned long long int fastPower(unsigned long long int n, unsigned long long int m) {
	if (m == 1) {
		return n;
	}
	if (m%2 == 0) {
		unsigned long long int halved = fastPower(n, m/2);
		return (halved*halved)%1000000007;
	}
	return (n*fastPower(n, m-1))%1000000007;
}

int main() {
	unsigned long long int N, M;
	cin>>N>>M;
	N %= 1000000007;
	unsigned long long int ans = fastPower(N, M);
	cout<<ans%1000000007;
}