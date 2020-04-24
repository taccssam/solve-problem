#include <iostream>
using namespace std;

int t;

int main() {
	cin >> t;
	for (int c = 1;c <= t;c++) {
		int sum = 0,num;
		for (int i = 0;i < 10;i++) {
			cin >> num;
			sum += num;
		}
		if (sum % 10 >= 5)cout << '#' << c << ' ' << sum / 10 + 1 << '\n';
		else cout << '#' << c << ' ' << sum / 10 << '\n';
	}
}