#include <iostream>
#include<string>
#include <vector>
using namespace std;

string a, b;
vector<int> fail,ret;

int main() {
	getline(cin,a);
	getline(cin, b);

	int j = 0;
	fail.push_back(0);
	for (int i = 1; i < b.size(); i++) {
		while (j > 0 && b[i] != b[j])j = fail[j -1];
		if (b[i] == b[j]) {
			++j;
		}
		fail.push_back(j);
	}
	j = 0;
	for (int i = 0; i < a.size(); i++) {
		while (j > 0 && a[i] != b[j])j = fail[j -1];
		if(a[i] == b[j]){
			if (j == b.size() -1) {
				ret.push_back(i - b.size()+1);
				j = fail[j];
			}
			else j++;
		}
	}
	cout << ret.size() << "\n";
	for (int i : ret)cout << i+1 << " ";

}