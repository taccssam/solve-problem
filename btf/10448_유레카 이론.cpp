#include <iostream>
using namespace std;

int t[51] , sol[1001];
int k, n;

int main() {
	for (int i = 1;i < 51;i++)t[i] = i * (i + 1) / 2;
	for (int i = 1;i < 49;i++) {
		for (int j = 1;j < 50;j++) {
			for (int l = 1;l < 51;l++) {
				int m = t[i] + t[j] + t[l];
				if (m < 1001)sol[m] = 1;
			}
		}
	}
	cin >> k;
	for (;k;k--) {
		cin >> n;
		cout << sol[n] << '\n';
	}
}
