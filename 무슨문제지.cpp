#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, m,mnum,num,t;
vector<pair<int , int> > s;
int c[501];


int main() {

	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		mnum = 0;

		for (int j = 1;j <= n;j++) {
			cin >> num;
			s.push_back(make_pair(num, j));
		}
		sort(s.begin(),s.end());

		t = 0,mnum = 0;
		for (int j = 0;j < n;j++) {
			if (s[j].first == 0)continue;
			if (mnum != s[j].first) {
				t++;
				mnum = s[j].first;
			}
			c[s[j].second] += t;
			
		}
		t++;
		for (int j = 0;j < n;j++) {
			if (s[j].first != 0)break;
			c[s[j].second] += t;
		}
		while (s.size())s.pop_back();
	}

	mnum = 987654321;
	for (int i = 1;i <= n;i++) {
		mnum = min(mnum, c[i]);
	}

	for (int i = 1;i <= n;i++) {
		if (c[i] == mnum)cout << i << ' ';
	}


}