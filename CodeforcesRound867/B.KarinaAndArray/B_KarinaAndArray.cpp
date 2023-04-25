#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int testcases;
	cin>>testcases;
	while (testcases > 0) {
		long long len, p1=-10000000000, p2=-10000000001, n1=10000000000, n2=100000000000, res1, res2;
		cin>>len;
		for(int i=0;i<len;i++) {
			int x;
			cin>>x;
			if (x > p1 && x >= 0) {
				swap(p1, p2);
				p1 = x;
			}
			else if (x > p2 && x >= 0) p2 = x;
			else if (x < n1 && x < 0) {
				swap(n1, n2);
				n1 = x;
			}
			else if (x < n2 && x < 0) n2 = x;
		}
		if (p1 >= 0 && p2 >= 0) res1 = p1*p2;
		else res1 = -10000000000;
		if (n1 < 0 && n2 < 0) res2 = n1*n2;
		else res2 = -10000000000;
		long long res = max(res1, res2);
		if (res < 0) res = p1*n1;
		cout<<res<<"\n";
		testcases--;
	}
}