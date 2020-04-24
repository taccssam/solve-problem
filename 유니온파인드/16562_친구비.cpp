#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int m, n, r[10001],money[10001];
int k;
int find(int a) {
	if (r[a] < 0)return a;
	r[a] = find(r[a]);
	return r[a];
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b)return;
	money[a] = min(money[a],money[b]);
	r[b] = a;
}

int main() {
	memset(r, -1, sizeof(r));
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)cin >> money[i];

	int a, b;
	for (; m; m--) {
		cin >> a >> b;
		merge(a, b);
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (r[i] < 0)ret += money[i];
	}
	if (ret > k) {
		cout << "Oh no";
	}
	else cout << ret ;
}
//하 짜증난다 oh no의 o가 대문자다...