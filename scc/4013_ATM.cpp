#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int n, m, x, y, visited[500001], finished[500001], atm[500001], s, p , cnt, scn, check[500001];
int retatm[500001],sccatm[500001];
bool rest[500001],sccrest[500001];
vector<int> v[500001], scc[500001];
stack<int> st;
queue<int> q;

int dfs(int i) {
	visited[i] = ++cnt;
	st.push(i);
	int ok = visited[i];
	for (int j : v[i]) {
		if (visited[j] == 0)ok = min(ok,dfs(j));
		if (finished[j] == 0)ok = min(ok, visited[j]);
	}
	if (ok == visited[i]) {
		long long h,sum  = 0;
		scn++;
		while (1) {
			h = st.top();
			st.pop();
			finished[h] = scn;
			sum += atm[h];
			if (h == i)break;
		}
		sccatm[scn] = sum;
		retatm[scn] = sum;
	}
	return ok;
}

int main() {
	cin >> n >> m;
	for (; m; m--) {
		cin >> x >> y;
		v[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)cin >> atm[i];
	cin >> s >> p;
	for (; p; p--) {
		cin >> x;
		rest[x] = true;
	}
	for (int i = 1; i <= n; i++)if (visited[i] == 0)dfs(i);

	//scc �� ��������
	for (int i = 1; i <= n; i++) {
		for (int j : v[i]) {
			if (finished[i] != finished[j])
			{
				scc[finished[i]].push_back(finished[j]);
				check[finished[j]]++;
			}
		}
		if (rest[i] == 1)sccrest[finished[i]] = 1;
	}

	//���� ã�Ƴ���
	int ret = 0, h;
	for (int i = 1; i <= scn; i++) {
		if (check[i] == 0)q.push(i);
		//visited�� ������ scc�� ����� ģ���� üũ�� ���
		visited[i] = 0;
	}
	visited[finished[s]] = 1;
	while (q.size()) {
		h = q.front();
		q.pop();
		for (int j : scc[h]) {
			check[j]--;
			if (visited[h] == 1) {
				retatm[j] = max(retatm[j], sccatm[j] + retatm[h]);
				visited[j] = 1;
			}
			if (check[j] == 0)q.push(j);
		}
	}
	for (int i = 1; i <= scn; i++)if (visited[i] == 1 && sccrest[i] == 1)ret = max(ret, retatm[i]);

	
	cout << ret;

}
//�޸� �ʰ�
//scc ���� �������ķ� ã�� ���
//for���� ���������� �޸� �ʰ��� ���ϰ� ���� ������ �� �����ϰ� ����.