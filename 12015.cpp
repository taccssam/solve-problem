#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;

int t, n, num[1000100][2], m[1000100], ret;

int main() {

	cin >> n;
	cin >> num[0][0];
	m[1] = num[0][0];
	m[0] = -1;
	ret = 1, num[0][1] = 1;
	for (int i = 1; i < n; i++) {
		cin >> num[i][0];
		if (num[i][0] <= m[1]) {
			m[1] = num[i][0];
			num[i][1] = 1;
		}
		else if (num[i][0] > m[ret]) {
			ret++;
			m[ret] = num[i][0];
			num[i][1] = ret;
		}
		else {
			int k = lower_bound(m + 1, m + ret, num[i][0]) - m;
			m[k] = num[i][0];
			num[i][1] = k;
		}
	}


	cout << ret << endl;

}