#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m, d;
int r[1000001];

int find(int a) {
	if (r[a] < 0)return a;
	r[a] = find(r[a]);
	return r[a];
}

void merge(int a, int b) {
	if (r[a] == -1 && r[b] == -1) {
		r[max(a, b)] = min(a, b);
		r[min(a, b)]--;
	}
	a = find(a), b = find(b);
	if (a == b)return;
	r[min(a, b)] += r[max(a, b)];
	r[max(a, b)] = min(a, b);
}



int main() {
	int a, b;
	cin >> n >> m;

	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(r, -1, sizeof(r));
	for (; m; m--) {
		cin >> d >> a >> b;
		if (d == 0) {
			merge(a, b);
		}
		else {
			if (find(a) == find(b))cout << "YES\n";
			else cout << "NO\n";
		}
	}


}