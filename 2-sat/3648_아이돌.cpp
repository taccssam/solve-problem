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
//�ʱ�ȭ n�ߺ��� �ʱ�ȭ ������ ��� Ʋ�ȴ�.
//vector<int> i:v �� �����ұ�? i = v[0] ~v[n]???
//�ذ� = �������� i���� �׳� �����̱⶧���� i.clear(); �� �ۿ����� �ʾҴ����̴�. ���� ���ó�� ���� ������ ����Ҽ��� ������
//���������� i�� �ǵ鿩 v�� ����Ҽ��� ���� ���̴�. �ſ��߿�....
//int i:v[k] �� �����ϴ� i = v[k][0] ~v[k][n] 