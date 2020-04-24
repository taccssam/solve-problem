#include <iostream>
#include <math.h>
using namespace std;

long long v[10001][2],n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> v[i][0] >> v[i][1];

	long long  ret = 0;
	for (int i = 1; i < n - 1; i++) {
		ret += ((v[i][0] - v[0][0]) * (v[i + 1][1] - v[0][1]) - (v[i + 1][0] - v[0][0]) * (v[i][1] - v[0][1]));
	}
	
	if (ret < 0)ret *= -1;
	cout.precision(1);
	cout<<fixed;
	cout << (double)ret/2;
}