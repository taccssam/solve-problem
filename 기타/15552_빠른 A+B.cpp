#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int t, a, b;
	cin >> t;
	for (;t;t--) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
}