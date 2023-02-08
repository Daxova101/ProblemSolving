#include<iostream>
using namespace std;

int lines;

void pyramid(int x) {
	if (x==lines+1) {
		return;
	}
	for(int i=lines-x;i>0;i--) {
		cout<<" ";
	}
	for(int i=x+(x-1);i>0;i--) {
		cout<<"*";
	}
	if (x!=lines) {
		cout<<"\n";
	}
	pyramid(x+1);
}

int main() {
	cin>>lines;
	pyramid(1);
}