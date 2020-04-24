#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m, r[201],d;

int find(int a) {
	if (r[a] < 0)return a;
	r[a] = find(r[a]);
	return r[a];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	r[a] = b;
}
int main() {
	cin >> n >> m;
	memset(r, -1, sizeof(r));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> d;
			if (d == 1) {
				merge(i, j);
			}
		}
	}
	int ret;
	cin >> d;
	m--;
	ret = find(d -1);
	for (; m; m--) {
		cin >> d;
		if (ret != find(d -1)) {
			cout << "NO";
			return 0;
		}

	}
	cout << "YES";

}