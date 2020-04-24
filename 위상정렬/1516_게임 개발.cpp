#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, cv[501], tv[501] , sv[501]; // c = 위상시 카운트 , t 는 각각 시간 , s는 총시간
vector<int> v[501];
priority_queue<int> q;

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> tv[i];
		sv[i] = tv[i];
		int a;
		for (;;) {
			cin >> a;
			if (a == -1)break;
			v[a].push_back(i);
			cv[i]++;
		}
	}
	for (int i = 1;i <= n;i++)if (cv[i] == 0)q.push(i);

	int t,k;
	while (q.size() != 0) {
		t = q.top();
		q.pop();
		for (int i : v[t]) {
			cv[i]--;
			sv[i] = max(sv[t] + tv[i],sv[i]);
			if (cv[i] == 0)q.push(i);
		}
	}
	for (int i = 1;i <= n;i++)cout << sv[i] << endl;
}

//동시에도 생산되기때문에 모두만족하는 최대시간으로한다. 이부분 유의!!