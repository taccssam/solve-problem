#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, m, sccn, finished[10001],visited[10001],cnt;
vector<int> v[10001];
vector<vector<int>> scc;
stack<int> s;

int DFS(int i) {
	visited[i] = cnt++;
	s.push(i);
	int ok = visited[i];
	for (int j: v[i]) {
		if (visited[j] == 0) ok = min(ok, DFS(j));
		else if(finished[j] == 0)ok = min(ok, visited[j]);
	}
	int t;
	vector<int> sccc;
	if (ok == visited[i]) {
		while (1) {
			t = s.top();
			finished[t] = 1;
			sccc.push_back(t);
			s.pop();
			if (t == i) {
				sccn++;
				break;
			}
		}
		sort(sccc.begin(), sccc.end());
		scc.push_back(sccc);
	}
	return ok;
}

int main() {
	int a, b;
	cnt = 1;
	sccn = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n;i++)sort(v[i].begin(), v[i].end());
	for (int i = 1; i <= n;i++)
	{
		if(visited[i] == 0)DFS(i);
	}

	sort(scc.begin(), scc.end());

	cout << sccn << endl;
	for (int i = 0; i < sccn;i++) {
		for (int j = 0; j < scc[i].size();j++)cout << scc[i][j] << ' ';
		cout <<"-1"<< endl;
	}

}