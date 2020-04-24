#include <iostream>
using namespace std;

int main() {
	char c;
	int ok = 0;
	while (cin >> c) {
		if (ok == 0) {
			cout << c;
			ok = 1;
		}
		if (c == '-')ok = 0;
	}
}
