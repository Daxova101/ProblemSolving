#include<iostream>
#include<vector>
using namespace std;

int di[8] = {1,-1,0,0,1,-1,1,-1};
int dn[8] = {0,0,1,-1,1,1,-1,-1};

int ans=0, count=0;

void dfs(vector<string> grid, bool vis[25][25], int i, int n) {
	vis[i][n] = true;
	count++;
	for(int x=0;x<8;x++) {
		if (n+dn[x] < grid[i].length() && n+dn[x] >= 0 && i+di[x] < (int) grid.size() && i+di[x] >= 0 && grid[i+di[x]][n+dn[x]] == '1' && !vis[i+di[x]][n+dn[x]]) {
			dfs(grid, vis, i+di[x], n+dn[x]);
		}
	}
}

int main() {
	int testcases;
	cin>>testcases;
	while (testcases > 0) {
		ans=0;
		vector<string> grid;
		bool vis[25][25] = {false};
		string s = "";
		while (s == "") {
			getline(cin, s);
		}
		while (s != "") {
			grid.push_back(s);
			getline(cin, s);
		}
		for(int i=0;i<(int) grid.size();i++) {
			for(int n=0;n< grid[i].length();n++) {
				if (grid[i][n] == '1' && !vis[i][n]) {
					count=0;
					dfs(grid, vis, i, n);
					if (ans < count) ans = count;
				}
			}
		}
		cout<<ans<<"\n";
		if (testcases > 1) {
			cout<<"\n";
		}
		testcases--;
	}
}