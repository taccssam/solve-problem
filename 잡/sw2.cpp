#include <iostream>
using namespace std;
int t, n, m, ok;
int g[51][51],v[51][51];
int main(){
	cin >> t;
	while (t--) {
		ok = 0;
		cin >> n >> m;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++)cin >> g[i][j];
		}
		memset(v, 0, sizeof(v));
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (g[i][j] == 1) {
					if (g[i][j + 1] == 1 && g[i + 1][j] == 1 && g[i + 1][j + 1] == 1) {
						v[i][j] = v[i + 1][j] = v[i][j + 1] = v[i + 1][j + 1] = 1;
					}
				}
			}
		}
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (g[i][j] != v[i][j])ok = 1;
			}
		}
		if (ok == 1)cout << "NO" << endl;
		else cout << "YES" << endl;

	}



}