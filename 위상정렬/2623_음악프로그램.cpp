#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m , cv[1001];
vector<int> v[1001],ret;
priority_queue<int> q;
int main() {

	cin >> n >> m;
	for (;m;m--) {
		int t ,a,b;
		cin >> t >> a;
		for (;t - 1;t--) {
			cin >> b;
			v[a].push_back(b);
			cv[b]++;
			a = b;
		}
	}
	for (int i = 1; i <= n;i++)if (cv[i] == 0)q.push(i);

	int ok = 0 , t;
	while (q.size() != 0) {
		t = q.top();
		ok++;
		q.pop();
		for (int i : v[t]) {
			cv[i]--;
			if (cv[i] == 0)q.push(i);
		}
		ret.push_back(t);
		if (q.size() == 0 && ok != n) {
			cout << 0;
			return 0;
		}
	}
	for (int i : ret)cout << i << endl;

}
//큐로 빼는 위상이 더 간단한것 같다는 느낌 
//쉽게 했다.