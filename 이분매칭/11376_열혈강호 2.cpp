#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int n, m,v[1001],c[1001],check[1001][2];
vector<int> p[1001];

int dfs(int s) {

	if (v[s] == 1)return 0;
	v[s] = 1;
	for (int i : p[s]) {
		if (!check[i][0] || dfs(check[i][0])) {
			check[i][0] = s;
			return 1;
		}
		else if (!check[i][1] || dfs(check[i][1])) {
			check[i][1] = s;
			return 1;
		}
	}
	return 0;
}


int main() {
	cin >> n >> m;
	int a,b;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			p[b].push_back(i);
		}
	}
	int ret = 0;
	for (int i = 1; i <= m; i++) {
		memset(v, 0, sizeof(v));
		ret+=dfs(i);
	}
	cout << ret;


}