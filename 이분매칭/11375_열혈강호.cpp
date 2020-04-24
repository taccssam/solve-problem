#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m,ret,check[1001],v[1001];
vector<int> p[1001];

int dfs(int s) {

	if (v[s])return 0;
	v[s] = 1;
	for (int i : p[s]) {
		if (!check[i] || dfs(check[i])) {
			check[i] = s;
			return 1;
		}
	}
	return 0;
}

int main() {
	cin >> n >> m;
	int a, b;
	ret = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (; a; a--) {
			cin >> b;
			p[i].push_back(b);
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(v, 0, sizeof(v));
		ret += dfs(i);
	}
	cout << ret;
}

//visited로 무한루프 안돌게