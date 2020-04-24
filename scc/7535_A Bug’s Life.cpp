#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int t,n,m,x,y;
int scn,cnt,visited[4001], finished[4001];
vector<int> v[4001];
stack<int> s;

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
		while (1) {
			h = s.top();
			s.pop();
			finished[h] = scn;
			if (h == i)break;
		}
	}
	return ok;
}

int main() {
	cin >> t;
	for (int c = 1; c <= t; c++) {
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		for (int i = 0; i < 4001; i++)v[i].clear();
		cnt = 0, scn = 0;

		cin >> n >> m;
		for (; m; m--) {
			cin >> x >> y;
			v[n - x].push_back(n + y);
			v[n - y].push_back(n + x);
			v[n + x].push_back(n - y);
			v[n + y].push_back(n - x);
		}
		for (int i = 0; i <= 2 * n; i++) {
			if (i == n)continue;
			if (visited[i] == 0)dfs(i);
		}
		int ok = 0;
		for (int i = 0; i < n; i++)if (finished[i] == finished[2 * n - i])ok = 1;

		cout << "Scenario #" << c << ":\n";
		if (ok == 0) {
			cout << "No suspicious bugs found!\n\n";
		}
		else cout << "Suspicious bugs found!\n\n";


	}


}