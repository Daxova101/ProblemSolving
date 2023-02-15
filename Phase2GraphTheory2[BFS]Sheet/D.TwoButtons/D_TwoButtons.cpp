#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int n, m, moves=1000000;
bool vis[1000000];
queue<pair<int, int> > nextn;

void bfs(int x, int count) {
	nextn.pop();
	vis[x] = 1;
	if (x < m) {
		if (x-1 > 0 && vis[x-1] != 1) {
			nextn.push(make_pair(x-1, count+1));
		}
		if (vis[x*2] != 1) {
			nextn.push(make_pair(x*2, count+1));
		}
	}
	else if (x == m) {
		if (count < moves) {
			moves = count;
		}
		return;
	}
	else if (x > m) {
		if (count+(x-m) < moves) {
			moves = count+(x-m);
		}
		return;
	}
}

int main() {
	cin>>n>>m;
	nextn.push(make_pair(n, 0));
	if (n < m) {
		while (!nextn.empty()) {
			bfs(nextn.front().first, nextn.front().second);
		}
		cout<<moves;
	}
	else {
		cout<<n-m;
	}
}