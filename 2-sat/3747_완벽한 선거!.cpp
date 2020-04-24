#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int n,m,x,y;
char xc, yc;
int cnt, scn,visited[2001],finished[2001];
vector<int> v[2001];
stack<int> s;

int dfs(int i) {
	visited[i] = ++cnt;
	s.push(i);
	int ok = visited[i];
	for (int j : v[i]) {
		if (visited[j] == 0)ok = min(ok, dfs(j));
		if (finished[j] == 0)ok = min(ok, visited[j]);
	}
	int h;
	
	if (ok == visited[i]) {
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

	while (cin >> n >> m) {
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		for (int i = 0; i < 2001; i++)v[i].clear();
		for (; m; m--) {
			cin >> xc >> x >> yc >> y;
			if (xc == '-')x *= -1;
			if (yc == '-')y *= -1;
			v[n - x].push_back(n + y);
			v[n - y].push_back(n + x);
		}

		for (int i = 0; i <= 2 * n; i++) {
			if (i == n)continue;
			if (visited[i] == 0)dfs(i);
		}
		int ok = 1;
		for (int i = 0; i < n; i++)if (finished[i] == finished[2 * n - i])ok = 0;
		cout << ok << '\n';
	}
}