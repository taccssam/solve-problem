#include <iostream>
#include <algorithm>
using namespace std;

char b[51][51];
int n;
int candy() {
	int ret = 0,cnt;
	char t;
	for (int i = 0;i < n;i++) {
		t = b[i][0];
		cnt = 0;
		for (int j = 0;j < n;j++) {
			if (t != b[i][j]) {
				t = b[i][j];
				ret = max(ret, cnt);
				cnt = 1;
			}
			else cnt++;
		}
		ret = max(ret, cnt);
		t = b[0][i];
		cnt = 0;
		for (int j = 0;j < n;j++) {
			if (t != b[j][i]) {
				t = b[j][i];
				ret = max(ret, cnt);
				cnt = 1;
			}
			else cnt++;
		}
		ret = max(ret, cnt);
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> b[i][j];
		}
	}

	int ret = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (b[i][j] != b[i + 1][j] && i+1<n) {
				swap(b[i][j], b[i + 1][j]);
				ret = max(ret, candy());
				swap(b[i][j], b[i + 1][j]);
			}
			if (b[i][j] != b[i][j + 1] && j+1<n) {
				swap(b[i][j], b[i][j+1]);
				ret = max(ret, candy());
				swap(b[i][j], b[i][j+1]);
			}
		}
	}
	cout << max(ret,candy());
}

///원래 길게 나오는 건가...후