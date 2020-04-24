#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

string L, l[501];
int fail[501][10001],n,dp[100001];
bool sw[100001][501];

int solve(int p) {

	//����
	if (p == L.size())return 0;

	//dp�� �ִ��� üũ
	if (dp[p] != -1)return dp[p];
	dp[p] = 0;

	//����
	for (int i = 0; i < n; i++) {
		if (sw[p][i]) {
			dp[p] = max(dp[p], solve(p + l[i].size()) + (int)l[i].size());
		}
	}
	dp[p] = max(dp[p], solve(p + 1));
	return dp[p];
}

int main() {
	cin >> L >> n;
	int j = 0;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		j = 0;
		for (int k = 1; k < l[i].size(); k++) {
			while (j > 0 && l[i][k] != l[i][j])j = fail[i][j- 1];
			if (l[i][k] == l[i][j])fail[i][k] = ++j;
		}
		j = 0;
		for (int k = 0; k < L.size(); k++) {
			while (j > 0 && l[i][j] != L[k])j = fail[i][j - 1];
			if (l[i][j] == L[k]) {
				if (j == l[i].size()-1) {
					sw[k - l[i].size() + 1][i] = 1;
					j = fail[i][j];
				}
				else j++;
				
			}
		}
	}
	cout << solve(0);
}

//���� ������ �ڿ������� dp�� ��������.
//�߿��Ѱ��� bool����, ��ġ ǥ��
//dp+kmp������ dp���� �� ���� ����
//kmpȰ�� ������ ���� �����ߴ�.