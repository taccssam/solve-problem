#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int t, n, m, x, y;
int scn, cnt, visited[100001], finished[100001],check[100001];
vector<int> v[100001];
vector<vector<int>> scc;
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
		vector<int>sccc;
		while (1) {
			h = s.top();
			s.pop();
			finished[h] = scn;
			sccc.push_back(h);
			if (h == i)break;
		}
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
		for (int i = 1; i < 100001; i++)v[i].clear();
		for (; scc.size(); scc.pop_back()) {}
		scn = 0, cnt = 0;
		cin >> n >> m;
		for (; m; m--) {
			cin >> x >> y;
			v[x].push_back(y);
		}
		for (int i = 1; i <= n; i++)if (visited[i] == 0)dfs(i);
		int ret = 0;
	//이 부분 간결하게 맞았지만 수정해보자.
		/*for (int i = 0; i < scn; i++) {
			for (int j : scc[i]) {
				for (int k : v[j]) {
					if (finished[k] != finished[j])check[finished[k]] = 1;
				}
			}
		}*/
	//수정-> 그냥 점마다 다 체크해주면 되는것이었다 굳이 scc별로 나눌 필요도 없는 문제였다.
	//하지만 이 방법을 생각해 비슷하게 간 것이 대단..
		for (int i = 1; i <= n; i++) {
			for (int j : v[i])if (finished[i] != finished[j])check[finished[j]] = 1;
		}

		for (int i = 0; i < scn; i++)if (check[i] == 0)ret++;
		cout << ret << "\n";

	}


}
//scc간 간선체크를 더 용이하게 해보자.
