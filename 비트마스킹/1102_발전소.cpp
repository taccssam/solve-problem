#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int n, b[16][16], dp[1 << 16] ,p;

int repair(int ok) {

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (ok & 1 << i)cnt++;
	}
	if (cnt >= p)return 0;

	if (dp[ok] != -1)return dp[ok];
	dp[ok] = 987654321;


	for (int i = 0; i < n; i++) {
		if (!(ok & 1 << i)) {
			for (int j = 0; j < n; j++) {
				if ((ok & 1 << j))dp[ok] = min(dp[ok], b[j][i] + repair(ok | 1 << i));
			}
		}
	}
	return dp[ok];

}


int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)cin >> b[i][j];
	}
	int ok = 0;
	char t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if(t == 'Y')ok |= (1 << i);
	}
	cin >> p;
	cout << (repair(ok) == 987654321 ? -1: repair(ok));
	
}
//dp결함이 아니라 p개 이상이 고쳐졌을때 더 적을수가 있다...
//허무한 문제
//하지만 그 공장을 고치는 것에 최소로만 하면 문제가있다.
//그이유는 없을때 체크를 안해줘서 였다 항상 다음걸로 넘겼었다 (이전의 소스)
//또 비용이 0인 발전소도 있다...
