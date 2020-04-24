#include <iostream>
#include <vector>
using namespace std;
#define ll long long 
#define M 1000001
ll n, m, k, a, b, c, arr[M][2];

struct seg {
	ll sum, s, e;
};

seg stree[3*M];

ll maketree(int s, int e,int cnt) {

	if (s == e) {
		stree[cnt].sum = arr[s][0];
		arr[s][1] = cnt;
		stree[cnt].s = stree[cnt].e = s;
		return stree[cnt].sum;
	}
	ll mid = (s + e) / 2;
	stree[cnt].sum = maketree(s, mid, cnt * 2) + maketree(mid + 1, e, cnt * 2 + 1);
	stree[cnt].s = s;
	stree[cnt].e = e;
	return stree[cnt].sum;
}

ll findsum(int s, int e,int cnt) {
	
	if (s == stree[cnt].s && e == stree[cnt].e)return stree[cnt].sum;
	ll mid = (stree[cnt].s + stree[cnt].e) / 2;
	ll sum = 0;
	if (e <= mid)sum = findsum(s, e, cnt * 2);
	else if (s > mid)sum = findsum(s, e, cnt * 2 + 1);
	else sum = findsum(s, mid, cnt * 2) + findsum(mid + 1, e, cnt * 2 + 1);
	return sum;
}

void changetree(int s,int num) {
	int p = arr[s][1];
	ll gap = num - arr[s][0];
	arr[s][0] = num;
	while (p != 0) {
		stree[p].sum += gap;
		p /= 2;
	}
}


int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)cin >> arr[i][0];
	maketree(1, n, 1);
	for (;;) {
		cin >> a >> b >> c;
		if (a == 1) {
			changetree(b, c);
			m--;
		}
		if (a == 2) {
			cout << findsum(b, c ,1) << "\n";
			k--;
		}
		if (m == 0 && k == 0)break;
	}

}