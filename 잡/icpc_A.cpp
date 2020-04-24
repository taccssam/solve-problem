#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int gap[1001][1001];
pair<int, int> c[1001];

int main() {

	cin >> n >> k;
	for (int i = 0;i < n;i++)cin >> c[i].first >> c[i].second;

	
	sort(&c[0],&c[n]);

	for (int i = 0;i < n;i++) {
		for (int j = i;j < n;j++) {
			gap[i][j] = (c[j].first - c[i].first) * c[j].second;
		}
	}
	int ret = 987654321;

	

	if (k == 1) {
		int mi = 0;
		for (int i = 0;i < n;i++) {
			mi = max(mi, gap[0][i]);
		}
		ret = mi+30;
	}
	if(k == 2){
		int mi = -1,a=0;
		for (int i = 0;i < n;i++) {
			a = max(a, gap[0][i]);
			mi = -1;
			for (int j = i+1;j < n;j++) {
				if (gap[0][i] >= gap[0][j])continue;
				mi = max(mi, gap[i+1][j]);
			}
			if (mi == -1)ret = min(ret,a + 30);
			else ret = min(ret, mi + a + 60);
		}

	}
	if(k == 3){
		int mi = -1, a = 0,b = 0,c = 0;
		for (int i = 0;i < n;i++) {
			a = max(a, gap[0][i]);
			mi = -1;
			for (int j = i + 1;j < n;j++) {
				if (gap[0][i] >= gap[0][j])continue;
				if (mi < gap[i + 1][j]) {
					mi = gap[i + 1][j];
					c = i;
				}
			}
			if (mi == -1) {
				if (ret > a + 30) {
					ret = a + 30;
					b = -1;
				}
			}
			else {
				if (ret > mi + a + 60) {
					ret = a + 60;
					b = c;
				}
			}
		}
		int ret1 = 987654321;
		if (b != -1) {
			a = 0,mi = -1;
			for (int i = b+1;i < n;i++) {
				a = max(a, gap[b+1][i]);
				mi = -1;
				for (int j = i + 1;j < n;j++) {
					if (gap[b+1][i] >= gap[b+1][j])continue;
					mi = max(mi, gap[i + 1][j]);
				}
				if (mi == -1)ret1 = min(ret1, a);
				else ret1 = min(ret1, mi + a + 30);
			}
			ret += ret1;
		}
		

	}
	
	cout << ret;

}