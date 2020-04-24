#include <iostream>
using namespace std;

int n, cnt ,m;
int main() {
	cin >> m;
	n = m;
	n = (n % 10) * 10 + ((n / 10) + (n % 10)) % 10;
	cnt = 1;
	while(n != m){
		n = (n % 10) * 10 + ((n / 10) + (n % 10)) % 10;
		cnt++;
	}
	cout << cnt;
}
