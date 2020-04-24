#include <iostream>
#include <algorithm>
using namespace std;

char c[51][51];
int ret;

int main() {
	int x, y;
	cin >> x >> y;
	for (int i = 0;i < x;i++)for (int j = 0;j < y;j++)cin >> c[i][j];

	char t1,t2;
	int cnt1,cnt2;
	ret = 100;
	for (int i = 0;i < x - 7;i++) {
		for (int j = 0;j < y - 7;j++) {
			cnt1 = 0,cnt2=0;
			t1 = 'B',t2 = 'W';
			for (int a = 0;a < 8;a++) {
				for (int b = 0;b < 8;b++) {
					if (t1 != c[i+a][j+b])cnt1++;
					if (t2 != c[i+a][j+b])cnt2++;
					if (b != 7) {
						if (t1 == 'B')t1 = 'W';
						else t1 = 'B';
						if (t2 == 'B')t2 = 'W';
						else t2 = 'B';
					}
				}
			}
			cnt1 = min(cnt1, cnt2);
			ret = min(ret, cnt1);

		}
	}
	cout << ret;

}