#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int testcases;
	cin>>testcases;
	while (testcases > 0) {
		int Qm=0;
		string s;
		cin>>s;
		for(int i=0;i<s.length();i++) {
			if (s[i] == '?') Qm++;
		}
		int ans = pow(10, Qm);
		if (s[0] == '?') ans -= pow(10, Qm-1);
		if (Qm == 0 && (stoi(s) == 0 || (stoi(s) > 0 && s[0] == '0')) ) {
			ans=0;
		}
		if (s[0] == '0') ans=0;
		cout<<ans<<"\n";
		testcases--;
	}
}