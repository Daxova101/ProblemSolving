#include<bits/stdc++.h>
using namespace std;

vector<string> sortme;

void rec(string s, string nexts, int x) {
	if (nexts != "") {
		sortme.push_back(nexts);
	}
	for(int i=x, looped=1;i<s.length();i++, looped++) {
		nexts += s[i];
		rec(s, nexts, x+looped);
		nexts = nexts.replace(nexts.length()-1, 1, "");
	}
}

int main() {
	string s, nexts="";
	cin>>s;
	rec(s, nexts, 0);
	sort(sortme.begin(), sortme.end());
	for(int i=0;i<(int) sortme.size();i++) {
		cout<<sortme[i]<<"\n";
	}
}