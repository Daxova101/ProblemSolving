#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int testcases;
	cin>>testcases;
	while (testcases > 0) {
		long long n;
		cin>>n;
		cout<<(n*(n+2))+2<<"\n";
		testcases--;
	}
}