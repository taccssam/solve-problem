#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {

	long long x, y, p = 0, q = 0;
	bool operator < (point& d) {
		if (1LL * q * d.p != 1LL * p * d.q)return 1LL*q * d.p < 1LL*p* d.q;
		if (y != d.y)return y < d.y;
		return x < d.x;
	}
};

point p[100001];
int n,ret;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	sort(p, p + n);
	for (int i = 1; i < n; i++) {
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	sort(p+1, p + n);
	vector<int> ch;
	ch.push_back(0);
	ch.push_back(1);
	for (int i = 2; i < n;) {
		while (ch.size() >= 2) {
			int p1 = ch[ch.size() - 2], p2 = ch[ch.size() - 1], p3 = i;
			long long ccw = 1LL * (p[p2].x - p[p1].x) * (p[p3].y - p[p1].y) - 1LL * (p[p3].x - p[p1].x) * (p[p2].y - p[p1].y);
				if (ccw > 0) {
					break;
				}
				else {
					ch.pop_back();
				}
		}
		ch.push_back(i++);
	}
	cout << ch.size();
}