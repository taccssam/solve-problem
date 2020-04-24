#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int n, m, cnt,scnt,visited[20001],finished[20001];
vector<int> v[20001];
stack<int> s;

int DFS(int i) {
	visited[i] = ++cnt;
	s.push(i);
	int ok = visited[i];
	for (int j : v[i]) {
		if (visited[j] == 0)ok = min(ok, DFS(j));
		if (finished[j] == 0)ok = min(ok, visited[j]);
	}
	if (ok == visited[i]) {
		int t;
		scnt++;
		while (1) {
			t = s.top();
			s.pop();
			finished[t] = scnt;
			if (t == i)break;
		}
	}
	return ok;
}

int main() {

	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n;i++) {
		cin >> a >> b;
		v[m - a].push_back(m + b);
		v[m - b].push_back(m + a);
	}
	for (int i = 0;i <= 2 * m;i++) {
		if (i == m)continue;
		if (visited[i] == 0)DFS(i);
	}
	for (int i = 1;i <= m;i++) {
		if (finished[m - i] == finished[m + i]) {
			cout << "OTL";
			return 0;
		}
	}
	cout << "^_^";
}