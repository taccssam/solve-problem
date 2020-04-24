#include <iostream>
using namespace std;

int l, p, v,cnt = 0;
int main() {
	for (;;) {
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)break;
		cout << "Case " << ++cnt << ": " << (v/p*l)+(v%p > l? l:v%p) << "\n";
	}
}