#include<iostream>
#include<vector>
using namespace std;

bool flag=0;
int countHis[300];

void dfs(vector<int> gr[300], bool vis[300], int n, int par, int count) {
	vis[n] = 1;
	countHis[n] = count;
	for(int i=0;i<(int) gr[n].size() && flag==0;i++) {
		if (vis[gr[n][i]] == 0) dfs(gr, vis, gr[n][i], n, count+1);
		else if (vis[gr[n][i]] == 1 && gr[n][i] != par && (count+1-countHis[gr[n][i]])%2 != 0 && par != -1) {
			flag=1;
		}
	}
}

int main() {
	int n, e;
	cin>>n;
	while (n != 0) {
		cin>>e;
		int n1, n2;
		vector<int> gr[300];
		bool vis[300] = {false};
		for(int i=0;i<e;i++) {
			cin>>n1>>n2;
			gr[n1].push_back(n2);
			gr[n2].push_back(n1);
		}
		flag=0;
		dfs(gr, vis, n1, -1, 0);
		if (flag) cout<<"NOT BICOLORABLE.\n";
		else cout<<"BICOLORABLE.\n";
		cin>>n;
	}
}