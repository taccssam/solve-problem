#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {

	ifstream fin;
	ofstream fout;
	fin.open("polygon.inp");
	fout.open("polygon.out");

	int count;
	fin >> count;

	while (count--) {

		int n, num, snum, anum;
		vector<int> ret, a, e;
		fin >> n;
		fin >> snum;
		e.push_back(snum);
		num = snum;
		for (int i = 0; i < n-1; i++) {
			
			if (num > 0)
			{
				fin >> num;
				e.push_back(num);
				if (num < 0)anum = num * -1;
				else anum = num;
				ret.push_back(anum*-1);
			}
			else {
				fin >> num;
				e.push_back(num);
				if (num < 0)anum = num * -1;
				else anum = num;
				ret.push_back(anum);
			}
			
		}
		if (num > 0) {
			if (snum < 0)anum = snum * -1;
			else anum = snum;
			ret.push_back(anum*-1);
		}
		else {
			if (snum < 0)anum = snum * -1;
			else anum = snum;
			ret.push_back(anum);
		}
		
		for (int i = 0; i < n; i++) {
			fin >> num;
			a.push_back(num);

		}
	
		//ºñ±³
		int t = 0, t1 = 0, t2 = 0;
		for (int i = 0; i < n; i++) {
			if (a[0] == ret[i]) {
				for (int s = 0; s < n; s++) {
					int k = i - s;
					if (k < 0)k += n;
					if (a[s] != ret[k])break;
					if (s == n - 1)t1 = 1;
				}
				

			}
			if (a[0] == e[i]) {
				for (int s = 0; s < n; s++) {
					if (a[s] != e[(i + s) % n])break;
					if (s == n - 1)t2 = 1;
				}

			}
		}
		
		if (t1 == 1 || t2 == 1)t = 1;
	
		fout << t << endl;
	}



	fin.close();
	fout.close();

}