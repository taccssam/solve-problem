#include <iostream>
using namespace std;

int main() {
	int a, x ,n;
	cin >> a >> x;
	for (;a;a--) {
		cin >> n;
		if (n < x)cout << n << ' ';
	}
}