#include <iostream>
using namespace std;
#define M 1000001

int n,a[M];
int self(int i) {
	int ret = i;
	for (;i;i /= 10) {
		ret += i % 10;
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 1;i < M;i++) {
		if(a[self(i)] == 0)a[self(i)] = i;
	}
	cout << a[n];
}