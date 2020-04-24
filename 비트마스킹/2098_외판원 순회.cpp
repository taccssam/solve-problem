#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int n,w[16][16],dp[16][1<<16];

int tsp(int a,int b) {

	if (b == (1 << n) - 1) {
		if (w[a][0] == 0)return 987654321;
		else return w[a][0];
	}


	if (dp[a][b] != -1)return dp[a][b];
	dp[a][b] = 987654321;

	for (int i = 1; i < n; i++) {
		if (w[a][i] != 0 && !(b & (1<<i))) {
			dp[a][b] = min(dp[a][b], w[a][i] + tsp(i, b | (1 << i)));
		}
	}
	return dp[a][b];
}

int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	cout << tsp(0,1);
}

//dp+비트마스킹으로 해결