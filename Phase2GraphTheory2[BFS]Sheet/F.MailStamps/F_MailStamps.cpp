#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int n,x,y;
	cin>>n;
	map<int, vector<int> > mapp;
	queue<int> nextmail;
	for(int i=0;i<n;i++) {
		cin>>x>>y;
		mapp[x].push_back(y);
		mapp[y].push_back(x);
	}
	for(auto i:mapp) {
		if(i.second.size() == 1) {
			nextmail.push(i.first);
			break;
		}
	}
	int old=-1;
	for(;!nextmail.empty();) {
		x = nextmail.front();
		nextmail.pop();
		for(int i=0;i<mapp[x].size();i++) {
			if (mapp[x][i] != old) nextmail.push(mapp[x][i]);
		}
		cout<<x<<" ";
		old = x;
	}
}