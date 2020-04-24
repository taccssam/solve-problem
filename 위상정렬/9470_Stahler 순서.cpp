#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int t, k, m, p, cv[1001] ,a,b ,sv[1001];
vector<int>v[1001],tv[1001];
priority_queue<int> q;

int main() {
	cin >> t;
	for (;t;t--) {
		memset(cv, 0, sizeof(cv));
		memset(sv, 0, sizeof(sv));
		for (int i = 0; i < 1001;i++)v[i].clear();
		cin >> k >> m >> p;
		for (;p;p--) {
			cin >> a >> b;
			v[a].push_back(b);
			cv[b]++;
		}
		for (int i = 1;i <= m;i++) {
			if (cv[i] == 0) {
				q.push(i);
				tv[i].push_back(1);
			}
		}
		int h,ret,ok;
		while (q.size() != 0) {
			h = q.top();
			q.pop();
			ret = 0, ok = 0;
			for (int i : tv[h]) {
				if (ret == i) {
					ok = 1;
				}
				else if(ret < i){
					ret = i;
					ok = 0;
				}
			}
			sv[h] = ret + ok;
			tv[h].clear();

			for (int i : v[h]) {
				cv[i]--;
				if (cv[i] == 0)q.push(i);
				tv[i].push_back(sv[h]);
			}
			
		}

		cout << k << ' ' << sv[m] << endl;
	}

}