#include <iostream>
using namespace std;

int main() {
	int n,ret;
	cin >> n;
	ret = n / 5;
	n %= 5;
	while (ret != -1) {
		if (n % 3 == 0) {
			ret += n / 3;
			break;
		}
		else {
			ret--;
			n += 5;
		}
	}
	cout << ret;
}