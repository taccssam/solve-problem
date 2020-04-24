#include <iostream>
#include <algorithm>
using namespace std;

long long n,ret,dp[100001];
int main() {
	cin >> n;
	cin >> dp[0];
	ret = dp[0];
	for (int i = 1;i < n;i++) {
		cin >> dp[i];
		dp[i] = max(dp[i - 1] + dp[i], dp[i]);
		ret = max(ret, dp[i]);
	}
	cout << ret;
}