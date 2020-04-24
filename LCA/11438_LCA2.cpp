#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001][23];
int n,check[100001];
int depth[100001];
vector<int> tree[100001];

int dfs(int p) {
	int cnt = 1;
	for (int i = 2; i < depth[p]; i *= 2) {
		dp[p][cnt] = dp[dp[p][cnt - 1]][cnt - 1];
		cnt++;
	}

	for (int i : tree[p]) {
		if (depth[i] == 0) {
			dp[i][0] = p;
			depth[i] = depth[p] + 1;
			dfs(i);
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int a, b;
	for (int i = 0; i< n - 1;i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	depth[1] = 1;
	dfs(1);
	/*for (int i = 1; i < 17; i++) {
		for (int j = 1; j <= n; j++) {
			if(dp[j][i-1] != 0)dp[j][i] = dp[dp[j][i - 1]][i - 1];
		}
	}*/

	cin >> n;
	for (; n; n--) {
		cin >> a >> b;
		int cnt = 0;
		if (depth[a] < depth[b])swap(a, b);
		int gap = depth[a] - depth[b];
		while (gap) {
			if (gap % 2) {
				a = dp[a][cnt];
			}
			gap /= 2;
			cnt++;
		}
		while (1) {
			if (a == b) {
				cout << a << "\n";
				break;
			}
			cnt = 0;
			while (1) {
				if (dp[a][cnt+1] == dp[b][cnt+1]) {
					a = dp[a][cnt], b = dp[b][cnt];
					break;
				}
				cnt++;
			}
		}
		/*
		if (a != b) {
			for (int i = 17; i > -1; i--) {
				if (dp[a][i] != 0 && dp[a][i] != dp[b][i]) {
					a = dp[a][i];
					b = dp[b][i];
				}
			}

			a = dp[a][0];
		}
		cout << a << "\n";
		*/
	}
}

//이문제는 트리가 순서대로 생성되지 않습니다.