#include <iostream>
#include <algorithm>

using namespace std;

int n, k, s[10001],sgap[10001],ret;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> s[i];
	sort(s, s + n);
	for (int i = 0; i < n-1; i++) {
		sgap[i] = s[i + 1] - s[i];
		ret += sgap[i];
	}
	sort(sgap, sgap+ n, greater<int>());
	for (int i = 0; i < k - 1; i++)ret -= sgap[i];
	cout << ret;
}
