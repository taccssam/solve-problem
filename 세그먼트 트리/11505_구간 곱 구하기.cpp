#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
#define ll long long
#define M 1000000
#define mod 1000000007
ll n, m, k , ssize = 1;
ll seg[4 * M];

void maketree() {
	for (ll i = ssize - 1; i > 0; i--) {
		seg[i] = (seg[i * 2] * seg[i * 2 + 1])%mod;
	}
}

void update(ll s, ll num) {
	s += ssize - 1;
	ll temp = seg[s];
	seg[s] = num;
	s /= 2;
	while (s > 0) {
		seg[s] = (seg[s*2] * seg[s*2+1])%mod;
		s /= 2;
	}
}

ll mul(ll s, ll e, ll root, ll nodeL, ll nodeR) {
	if (e < nodeL || s >nodeR)return 1;
	if (s <= nodeL && nodeR <= e)return seg[root];
	ll mid = (nodeL + nodeR) / 2;
	return (mul(s, e, root * 2, nodeL, mid) * mul(s, e, root * 2 + 1, mid + 1, nodeR))%mod;
}

int main() {
	for (ll i = 0; i < 4 * M; i++)seg[i] = 1;
	cin >> n >> m >> k;
	ll nt = n;
	if (nt % 2 == 0)nt--;
	while (nt > 0) {
		nt /= 2;
		ssize *= 2;
	}
	for (ll i = ssize; i < ssize + n; i++)cin >> seg[i];
	ll a, b, c;
	maketree();
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c);
		}
		else {
			cout << mul(b, c, 1, 1, ssize) <<"\n";
		}
	}
}
//포화기 때문에 찾을때 1~ ssize까지로 해야한다 ㅂㅅ아