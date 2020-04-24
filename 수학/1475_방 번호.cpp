#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int a[10] = {0};
	string s;
	cin >> s;
	for (int i = 0;i < s.size();i++) {
		if (s[i] - '0' == 9)a[6]++;
		else a[s[i] - '0']++;
	}
	int ret = 0;
	a[6] = a[6]%2 + a[6]/2;
	for (int i = 0;i < 9;i++) {
		ret = max(ret, a[i]);
	}
	cout << ret;
}