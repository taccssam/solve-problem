#include <iostream>
using namespace std;

int dp[200001][20],n,m,q,x;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m;
	for (int i = 1;i <=m; i++) {
		cin >> dp[i][0];
	}
	for (int i = 0; i < 19; i++) {
		for(int j= 1;j<=m;j++){
			dp[j][i + 1] = dp[dp[j][i]][i];
		}
	}
	cin >> q;
	for (; q; q--) {
		cin >> n >> x;
		for (int i = 0; n; i++) {
			if (n % 2)x = dp[x][i];
			n /= 2;
		}
		cout << x << "\n";
	}
}