#include <iostream>
using namespace std;

int t;


int main() {

	cin >> t;
	int sum,c = 1;
	while (t--) {
		sum = 0;
		int num;
		for (int i = 0;i < 10;i++) {
			cin >> num;
			if (num % 2 == 1)sum += num;
		}
		cout << '#' << c++ << ' ' << sum << '\n';

	}


}