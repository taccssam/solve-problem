#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
long long t, n, k,w, cv[1001],tv[1001],sv[1001];
vector<int> v[1001];
priority_queue<int> q;

int main() {
	cin >> t;
	while (t--) {
		memset(cv, 0, sizeof(cv));
		priority_queue<int> emp;
		swap(q, emp);
		q.emplace();
		for (int i = 0; i < 1001;i++)v[i].clear();
		cin >> n >> k;
		int a, b;
		for (int i = 1;i <= n;i++) {
			cin >> tv[i];
			sv[i] = tv[i];
		}
		for (;k;k--) {
			cin >> a >> b;
			v[a].push_back(b);
			cv[b]++;
		}

		cin >> w;
		for (int i = 1;i <= n;i++)if (cv[i] == 0)q.push(i);
		int h;
		while (q.size() != 0) {
			h = q.top();
			q.pop();
			for (int i : v[h]) {
				cv[i]--;
				if (cv[i] == 0)q.push(i);
				sv[i] = max(sv[i], sv[h] + tv[i]);
			}
			if (h == w)break;
		}
		cout << sv[w] << endl;
	}

}
//큐를 안비워서 고생했다. 비우자