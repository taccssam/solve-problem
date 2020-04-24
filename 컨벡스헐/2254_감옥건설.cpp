#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long 
using namespace std;

struct point {
	 ll x, y, p =0,q= 0;

	 bool operator <(point& d) {
		 if (q * d.p != p * d.q)return q * d.p < p* d.q;
		 if (y != d.y)return y < d.y;
		 return x < d.x;
	 }
};

vector<point> v;
int n,cx,cy;

int main() {
	cin >> n >> cx >> cy;
	point t;
	for (int i = 0; i < n; i++) {
		point t;
		cin >> t.x >> t.y;
		v.push_back(t);
	}
	
	int ret = 0,ok = 0;
	vector<int> ch;
	while (1) {
		sort(v.begin(), v.end());
		for (int i = 1; i < v.size(); i++) {
			v[i].p = v[i].x - v[0].x;
			v[i].q = v[i].y - v[0].y;
		}
		sort(v.begin() + 1, v.end());

		//큰 테두리만듬
		vector<point> nextv;
		ch.push_back(0); ch.push_back(1);
		for (int i = 2; i < v.size();) {
			while (ch.size() >= 2) {
				int p1 = ch[ch.size() - 2], p2 = ch[ch.size() - 1], p3 = i;
				ll ccw = (v[p2].x - v[p1].x) * (v[p3].y - v[p1].y) - (v[p3].x - v[p1].x) * (v[p2].y - v[p1].y);
				if (ccw > 0)break;
				else {
					point t;
					t.x = v[p2].x, t.y = v[p2].y;
					nextv.push_back(t);
					ch.pop_back();
				}
			}
			ch.push_back(i++);
		}
		//점이 속하는지 검사
		ch.push_back(ch[0]);
		for (int i = 0; i < ch.size() -1; i++) {
			int p2 = ch[i], p3 = ch[i+1];
			ll ccw = (v[p2].x - cx) * (v[p3].y - cy) - (v[p3].x - cx) * (v[p2].y - cy);
			if (ccw <= 0) {
				ok = 1;
				break;
			}
		}

		//결과도출 후 다음 컨벡스헐 구하기
		if (ok == 0) {
			ret++;
			if (nextv.size() == 0)break;
			v = nextv;
			ok = 0;
			ch.clear();
		}
		else break;
	}
	cout << ret;
}