#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int depth[40001],n,v[40001],dp[40001][18][2];
vector<pair<int,int >> tree[40001];

int dfs(int p) {
	for (pair<int,int> i : tree[p]) {
		if (depth[i.first] == 0) {
			depth[i.first] = depth[p] + 1;
			dp[i.first][0][0] = p;
			dp[i.first][0][1] = i.second;
			dfs(i.first);
		}
	}
	return 0;
}
int main() {
	cin >> n;
	int num,a,b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> num;
		tree[a].push_back(make_pair(b,num));
		tree[b].push_back(make_pair(a,num));
	}
	depth[1] = 1;
	dfs(1);
	for (int i = 0; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[j][i][0] != 0) {
				dp[j][i + 1][0] = dp[dp[j][i][0]][i][0];
				dp[j][i + 1][1] = dp[dp[j][i][0]][i][1] + dp[j][i][1];
			}
		}
	}
	cin >> n;
	int ret = 0;
	for (; n; n--) {
		cin >> a >> b;
		ret = 0;
		if (depth[a] < depth[b])swap(a, b);
		int gap = depth[a] - depth[b];
		for (int i = 0; gap; i++) {
			if (gap % 2) {
				ret += dp[a][i][1];
				a = dp[a][i][0];
			}
			gap /= 2;
		}
		if (a != b) {
			for (int i = 17; i > -1; i--) {
				if (dp[a][i][0] != 0 && dp[a][i][0] != dp[b][i][0]) {
					ret += dp[a][i][1];
					ret += dp[b][i][1];
					a = dp[a][i][0];
					b = dp[b][i][0];
				}
			}
			ret += dp[a][0][1];
			ret += dp[b][0][1];
		}
		cout << ret << "\n";
	}



}