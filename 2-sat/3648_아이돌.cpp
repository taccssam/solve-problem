#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;

int n, m,visited[2001],finished[2001],cnt,sccn;
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
	int h = -1;
	if (ok == visited[i]) {
		sccn++;
		while (h != i) {
			h = s.top();
			s.pop();
			finished[h] = sccn;
		}
	}
	return ok;
}

int main() {

	while (cin >> n >> m) {
		int a, b;
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		for (int i = 0;i < 2001;i++)v[i].clear();
		cnt = 0;
		sccn = 0;
		for (;m;m--) {
			cin >> a >> b;
			v[n - a].push_back(n+b);
			v[n - b].push_back(n+a);
		}
		v[n - 1].push_back(n + 1);
		v[n - 1].push_back(n + 1);
		for (int i = 0;i <= 2 * n;i++) {
			if (i == n)continue;
			if(visited[i] == 0)dfs(i);
		}
		int ok = 0;
		for (int i = 0;i < n;i++)if (finished[i] == finished[2*n - i])ok = 1;
		if (ok == 0)cout << "yes\n";
		else cout << "no\n";

	}


}
//초기화 n잘보기 초기화 때문에 계속 틀렸다.
//vector<int> i:v 는 가능할까? i = v[0] ~v[n]???
//해결 = 그이유는 i값에 그냥 참조이기때문에 i.clear(); 가 작용하지 않았던것이다. 위의 경우처럼 값을 가져와 사용할수는 있지만
//직접적으로 i를 건들여 v를 사용할수는 없던 것이다. 매우중요....
//int i:v[k] 는 가능하다 i = v[k][0] ~v[k][n] 