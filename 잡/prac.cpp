#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<n; i++)
using namespace std;
using ll=long long;
const int MAXN = 447216;

template<class T> struct segtree {
	int N, M;
	vector<T> A;
	segtree(const int sz) : N(sz - 1), M(1 << 32 - __builtin_clz(N) + 1), A(M) {}
	segtree(const vector<T>& B) : segtree(B.size()) { build(B, 0, N, 1); }
	inline T f(const T& x, const T& y) const { return max(x, y); }
	T build(const vector<T>& B, int s, int e, int i) {
		if (s == e) return A[i] = B[s];
		int m = s + e >> 1;
		return A[i] = f(build(B, s, m, i * 2), build(B, m + 1, e, i * 2 + 1));
	}
	T get(int l, int r, int s, int e, int i) const {
		if (e < l || r < s) return 0;
		if (l <= s && e <= r) return A[i];
		int m = s + e >> 1;
		return f(get(l, r, s, m, i * 2), get(l, r, m + 1, e, i * 2 + 1));
	}
	T get(int l, int r) const { return get(l, r, 0, N, 1); }
};
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int TC;
	cin >> TC;
	vector<ll> A(MAXN);
	vector<int> D(MAXN);
	D[0] = 0; D[20] = 8; D[119] = 20; D[461] = 38; D[594] = 43; D[1172] = 59;
	for (int i = 1; i < MAXN; i++) {
		A[i] = A[i - 1] + i;
		if (A[i] < MAXN) D[A[i]] = i;
	}
	for (int i = 2, p = 0; i < MAXN; i++) {
		while (A[p + 1] <= i) p++;
		if (!D[i]) D[i] = D[i - p * (p + 1) / 2] + p;
	}
	segtree<int> t(D);
	for (int T = 1; T <= TC; T++) {
		cout << "Case #" << T << '\n';
		ll L, R;
		cin >> L >> R;
		if (R >= MAXN) {
			int i = upper_bound(begin(A), end(A), R) - begin(A) - 1;
			int x = max(t.get(0, R - A[i]) + i, t.get((A[i - 1] < L) * (L - A[i - 1]), i - 1) + i - 1);
			cout << x << '\n';
		}
		else {
			cout << t.get(L, R) << '\n';
		}
	}
}