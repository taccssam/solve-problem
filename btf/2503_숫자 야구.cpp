#include <iostream>
#include <string.h>
using namespace std;

int b[10][10][10],t;

int main() {
	cin >> t;
	int x1,x2,x3,st,ba,stc,bac;
	for (int i = 1;i < 10;i++) {
		for (int j = 1;j < 10;j++) {
			for (int k = 1;k < 10;k++) {
				if (i == j || j == k || k == i)b[i][j][k] = 1;
			}
		}
	}
	for (;t;t--) {
		cin >> x1 >> st >> ba;
		x3 = x1 % 10, x2 = (x1 / 10) % 10, x1 = x1 / 100;
	
		
		for (int i = 1;i < 10;i++) {
			for (int j = 1;j < 10;j++) {
				for (int k = 1;k < 10;k++) {
					if (b[i][j][k] == 1)continue;
					stc = 0, bac = 0;
					if (x1 == i)stc++;
					else if (i == x2 || i == x3)bac++;
					if (x2 == j)stc++;
					else if (j == x1 || j == x3)bac++;
					if (x3 == k)stc++;
					else if (k == x1 || k == x2)bac++;
					if (stc != st || bac != ba)b[i][j][k] = 1;
				}
			}
		}
		

	}
	int ret = 0;
	for (int i = 1;i < 10;i++) {
		for (int j = 1;j < 10;j++) {
			for (int k = 1;k < 10;k++) {
				if (b[i][j][k] == 0)ret++;
			}
		}
	}
	cout << ret;
}