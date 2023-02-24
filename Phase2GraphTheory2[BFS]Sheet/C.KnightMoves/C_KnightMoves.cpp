#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int di[8] = {2,2,-2,-2,1,1,-1,-1};
int dj[8] = {1,-1,1,-1,2,-2,2,-2};
int ans=-1, Tx, Ty;

void bfs(queue<pair<pair<int, int>, int> > nextsq, bool vis[8][8], int x, int y, int count) {
	vis[x][y] = true;
	nextsq.pop();
	if (x == Tx && y == Ty) {
		if (ans == -1 || ans > count) ans = count;
		return;
	}
	for(int i=0;i<8;i++) {
		if (x+di[i] >= 0 && x+di[i] < 8 && y+dj[i] >= 0 && y+dj[i] < 8 && !vis[x+di[i]][y+dj[i]]) {
			if ((ans != -1 && count+1 < ans) || ans == -1) nextsq.push(make_pair(make_pair(x+di[i], y+dj[i]), count+1));
		}
	}
	if (nextsq.empty()) return;
	bfs(nextsq, vis, nextsq.front().first.first, nextsq.front().first.second, nextsq.front().second);
}

int main() {
	string cur, to;
	while (cin>>cur>>to) {
		queue<pair<pair<int, int>, int> > nextsq;
		bool vis[8][8] = {false};
		int Cx = cur[0] - 'a';
		int Cy = cur[1] - '1';
		Tx = to[0] - 'a';
		Ty = to[1] - '1';
		nextsq.push(make_pair(make_pair(Cx, Cy), 0));
		ans = -1;
		bfs(nextsq, vis, nextsq.front().first.first, nextsq.front().first.second, nextsq.front().second);
		cout<<"To get from "<<cur<<" to "<<to<<" takes "<<ans<<" knight moves.\n";
	}
}