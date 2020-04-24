#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n, m , cnt,sccn,visited[20001],finished[20001];
vector<int> v[20001];
stack<int> s;

int DFS(int i) {
	visited[i] = ++cnt;
	s.push(i);
	int ok = visited[i];
	for (int j : v[i]) {
		if (visited[j] == 0)ok = min(ok, DFS(j));
		else if (finished[j] == 0)ok = min(ok, visited[j]);
	}
	int t;
	vector<int> sccc;
	if (ok == visited[i]) {
		sccn++;
		while (1) {
			t = s.top();
			s.pop();
			finished[t] = sccn;
			if (t == i) {
				break;
			}
		}
	}
	return ok;

}

int main()
{
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[n - a].push_back(n + b);
		v[n - b].push_back(n + a);
	}
	for (int i = 0; i <= 2 * n;i++) {
		if (i == n)continue;
		if (visited[i] == 0)DFS(i);
	}
	int ok = 1;
	for (int i = 1;i <= n;i++) {
		if (finished[n - i] == finished[n + i]) {
			ok = 0;
			break;
		}
	}
	cout << ok << endl;
	if (ok == 1) {
		for (int i = 1;i <= n;i++) {
			cout << (finished[n + i] < finished[n - i]) << ' ';
		}
	}
}