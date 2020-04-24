#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;

int n, k;
string ans,num;
map<string, int> m;
queue<string> q;

int bfs(string b) {

	m[b] = 0;
	int ret = 987654321;
	string t,h;
	
	while (q.size()) {
		h = q.front();
		q.pop();
		if (h == ans)return m[h];

		for (int i = 0; i < n - k + 1; i++) {
			t = h;
			reverse(t.begin() + i, t.begin() + i + k);
			if (m.find(t) != m.end())continue;
			q.push(t);
			m[t] = m[h] + 1;
		}
	}
	return -1;
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		char t;
		cin >> t;
		num += t;
		ans += (i + 1) + '0';
	}
	q.push(num);
	cout << bfs(num);
}
//비트연산을 해야할까