#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define M 1000000000

int n,dp[10][101][1 << 10];

int solve(int s,int e, int ok) {
	if (e == n) {
		if (ok == (1 << 10) - 1)return 1;
		else return 0;
	}

	if (dp[s][e][ok] != -1)return dp[s][e][ok];
	dp[s][e][ok] = 0;

	if (s > 0) {
		dp[s][e][ok] += solve(s - 1, e + 1, ok | (1 << (s - 1)));
		dp[s][e][ok] %= M;
	}
	if (s < 9) {
		dp[s][e][ok] += solve(s + 1, e + 1, ok | (1 << (s + 1)));
		dp[s][e][ok] %= M;
	}
	return dp[s][e][ok];
}


int main() {
	cin >> n;
	int ok = 0;
	int ret = 0;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < 10; i++) {
		ret += solve(i,1, ok | (1 << i));
		ret %= M;
	}
	cout << ret;
}
//10 * 100 * 1000짜리 배열이라 가능하다.