#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int t, n, m,visited[100001],finished[100001],scn,cnt,check[100001];
vector<int> v[100001],sccv[100001];
stack<int> s;
vector<vector<int>> scc;
int dfs(int i) {
	visited[i] = ++cnt;
	s.push(i);
	int ok = visited[i];
	for (int j : v[i]) {
		if (visited[j] == 0)ok = min(ok, dfs(j));
		if (finished[j] == 0)ok = min(ok, visited[j]);
	}
	if (ok == visited[i]) {
		int h;
		vector<int> sccc;
		scn++;
		while (1) {
			h = s.top();
			s.pop();
			finished[h] = scn;
			sccc.push_back(h);
			if (h == i)break;
		}
		sort(sccc.begin(), sccc.end());
		scc.push_back(sccc);
	}
	return ok;
}

int main() {
	cin >> t;
	for (; t; t--) {
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		memset(check, 0, sizeof(check));
		for (int i = 0; i < 100001; i++) {
			v[i].clear();
			sccv[i].clear();
		}
		scc.clear();
		scc.push_back({ 0 });
		scn = cnt = 0;
		cin >> n >> m;
		int x, y;
		for (; m; m--) {
			cin >> x >> y;
			v[x+1].push_back(y+1);
		}
		for (int i = 1; i <= n; i++)if (visited[i] == 0)dfs(i);

		for (int i = 1; i <= n; i++) {
			for (int j : v[i]) {
				if (finished[i] != finished[j]) {
					int ok = 0;
					for (int k : sccv[i])if (k == finished[j])ok = 1;
					if (ok == 0) {
						sccv[i].push_back(finished[j]);
						check[finished[j]]++;
					}
				}
			}
		}

		int ok = 0;
		int ret = 0;
		for (int i = 1; i <= scn; i++){
			if (check[i] == 0) {
				if (ret == 0)ret = i;
				else ok++;
			}
		}
		if (ok == 0 && ret!= 0) {
			for (int i : scc[ret])cout << i -1 << "\n";
		}
		else cout << "Confused\n";
		cout << "\n";

	}

}
//최댓값 잘보자 100001개다....