#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unordered_set<int> s, as = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	string t;
	int m,n;
	cin >> m;
	for (; m; m--) {
		cin >> t;
		if (t == "add") {
			cin >> n;
			s.insert(n);
		}
		if (t == "remove") {
			cin >> n;
			s.erase(n);
		}
		if (t == "check") {
			cin >> n;
			if (s.find(n) == s.end())cout << "0\n";
			else cout << "1\n";
		}
		if (t == "toggle") {
			cin >> n;
			if (s.find(n) == s.end())s.insert(n);
			else s.erase(n);
		}
		if (t == "all")s = as;
		if (t == "empty")s.clear();
	}

}
//비트연산을 해야할까