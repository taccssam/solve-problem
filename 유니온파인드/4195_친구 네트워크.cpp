#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <unordered_map>
using namespace std;

int r[100001], m, t;
unordered_map<string, int> p;

int find(int a) {
	if (r[a] < 0)return a;
	return r[a] = find(r[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b)return;
	r[a] += r[b];
	r[b] = a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (; t; t--) {
		p.clear();
		memset(r, -1, sizeof(r));
		cin >> m;
		string x, y;
		int a, b;
		int ind = 1;
		for (; m; m--) {
			cin >> x >> y;
			if (p[x] == 0)p[x] = ind++;
			if (p[y] == 0)p[y] = ind++;
			merge(p[x], p[y]);
			cout << r[find(p[y])] * -1 << "\n";
		}
	}

}
//unorderd_map »ç¿ë~~