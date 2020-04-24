#include <iostream>
#include <string.h>
using namespace std;

int t, num[200001] , n;

int main() {
	cin >> t;

	for (int c = 1;c <= t;c++) {
		cin >> n;
		int count = 0,m;
		memset(num, 0, sizeof(num));
		for (int i = 0;i < n;i++) {
			cin >> m;
			num[m] = 1;
			if (num[m - 1] == 0)count++;
		}
		cout << '#' << c << ' ' << count << '\n';
	}
}