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
//dp������ �ƴ϶� p�� �̻��� ���������� �� �������� �ִ�...
//�㹫�� ����
//������ �� ������ ��ġ�� �Ϳ� �ּҷθ� �ϸ� �������ִ�.
//�������� ������ üũ�� �����༭ ���� �׻� �����ɷ� �Ѱ���� (������ �ҽ�)
//�� ����� 0�� �����ҵ� �ִ�...
