#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>
using namespace std;

int  n, m, visited[5001],finished[5001] ,scn,cnt,check[5001];
vector<int> v[5001],sccv[5001];
vector<vector<int>>scc;
stack<int> s;
queue<int> q;

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
		scn++;
		vector<int> sccc;
		while (1) {
			h = s.top();
			s.pop();
			sccc.push_back(h);
			finished[h] = scn;
			if (h == i)break;
		}
		sort(sccc.begin(), sccc.end());
		scc.push_back(sccc);
	}
	return ok;


}

int main() {
	int x, y;
	while (1) {
		cin >> n ;
		if (n == 0)break;
		cin >> m;
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		memset(check, 0, sizeof(check));
		scc.clear();
		scc.push_back({0});
		for (int i = 0; i < 5001; i++) {
			v[i].clear();
			sccv[i].clear();
		}
		scn = cnt = 0;

		for (; m; m--) {
			cin >> x >> y;
			v[x].push_back(y);
		}
		for (int i = 1; i <= n; i++)if (visited[i] == 0)dfs(i);

		for (int i = 1; i <= n; i++) {
			for (int j : v[i]) {
				if (finished[i] != finished[j]) {
					sccv[finished[i]].push_back(finished[j]);
					check[finished[j]]++;
				}
			}
		}
		
		for (int i = 1; i <= scn; i++)if (check[i] == 0)q.push(i);
		int h;
		vector<int> ret;
		while (q.size()) {
			h = q.front();
			q.pop();
			if (sccv[h].size() == 0)for (int j = 0; j < scc[h].size(); j++)ret.push_back(scc[h][j]);
			else for (int j : sccv[h]) {
				check[j]--;
				if (check[j] == 0)q.push(j);
			}
		}
		sort(ret.begin(), ret.end());
		for (int i : ret)cout << i << ' ';
		cout << "\n";
	}
}
//scc카운터가 finished와 같아야 하므로 앞에 빈벡터 추가하자.