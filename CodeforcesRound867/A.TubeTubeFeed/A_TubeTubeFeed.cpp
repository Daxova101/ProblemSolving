#include<iostream>
using namespace std;

int main() {
	int testcases;
	cin>>testcases;
	while (testcases > 0) {
		int v, t, flag=0, biggest=0, posi=-2;
		cin>>v>>t;
		int secs[v], ent[v]={0};
		for(int i=0;i<v;i++) {
			cin>>secs[i];
			if (t-i >= secs[i]) {
				flag=1;
				ent[i] = 1;
			}
		}
		for(int i=0;i<v;i++) {
			int pos=0;
			if (ent[i]) pos=1;
			cin>>ent[i];
			if (pos && biggest < ent[i]) {
				posi = i;
				biggest = ent[i];
			}
		}
		cout<<posi+1<<"\n";
		testcases--;
	}
}