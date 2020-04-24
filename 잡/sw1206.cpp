#include <iostream>
#include <algorithm>
using namespace std;

int ap[1010], lm, rm;


int main() {

	int ret,n;
	for (int c = 1;c < 11;c++) {
		ret = 0;
		cin >> n;
		for (int i = 0;i < n;i++)cin >> ap[i];

		lm = 0, rm = max(ap[3], ap[4]);
		for (int i = 2;i < n - 2;i++) {
			if (ap[i] > lm && ap[i] > rm) {
				ret += ap[i] - max(lm, rm);
			}
			lm = max(ap[i], ap[i - 1]);
			rm = max(ap[i + 2], ap[i + 3]);
			
		}


		cout << '#' << c << ' ' << ret << '\n';
	}


}