#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n, k, a[3001];

int f(int i, int sum, int cnt) {
	if (cnt == 0) {
		if (i == n)return sum;
		else return 987654321;
	}
	int ret = 987654321;
	if (cnt != 1)
	{
		for (int j = i;j <= n - cnt;j++) {
			ret = min(ret, f(j + 1, sum + a[j] - a[i], cnt - 1));
		}
	}
	else ret = min(ret, f(n, sum + a[n - 1] - a[i], cnt - 1));
	return ret;
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < n;i++)cin >> a[i];
	int ret = f(0, 0, k);
	cout << ret;

}


/*
sw4¹ø
SELECT STAGE, ROUND(SUM(STUDENT_NUM) / COUNT(STUDENT_NUM)) AS A, ROUND(SUM(STUDENT_NUM) / SUM(TEACHER_NUM), 1) AS B FROM SCHOOLS  GROUP BY STAGE ORDER BY A DESC, B DESC;
*/