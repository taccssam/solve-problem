#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;

int co[101][101][101]; //전역은 선언시 자동으로 0값 default

void coin() {

	co[0][0][0] = 1;

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; k <= 100; k++) {
				if(i != 0 && j!= 0 && k!= 0)co[i][j][k] = 0;
				for (int t = 1; t <= 3; t++) {
					if (i - t >= 0 && co[i - t][j][k] == 0)co[i][j][k] = 1;
					if (j - t >= 0 && co[i][j -t][k] == 0)co[i][j][k] = 1;
					if (k - t >= 0 && co[i][j][k -t] == 0)co[i][j][k] = 1;
				}
			}
		}
	}
}

int main() {

	ifstream fin;
	ofstream fout;

	fin.open("coin.inp");
	fout.open("coin.out");
	int c;
	fin >> c;

	coin();
	while (c--) {
		int n1, n2, n3;
		fin >> n1 >> n2 >> n3;
		if(co[n1][n2][n3] == 0)
		fout << '(' << n1 << ' ' << n2 << ' ' << n3 << ") : " << -1 << endl;
		else if(co[n1][n2][n3] ==1)fout << '(' << n1 << ' ' << n2 << ' ' << n3 << ") : " << 1 << endl;
	}

	fin.close();
	fout.close();
}
