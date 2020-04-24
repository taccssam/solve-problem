#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define M 1000001
int fail[M];
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (1) {
		getline(cin, s);
		if (s == ".")break;
		int j = 0;
		int cnt = 0;
		for (int i = 1; i < s.size(); i++) {
			if( s[i] != s[j])j = 0;
			if (s[i] == s[j])++j;
			else cnt = i;
			fail[i] = j;
		}
		cnt++;
		if (!(fail[s.size() - 1] % cnt))cout << fail[s.size() - 1] / cnt + 1 << "\n";
		else cout << 1 << "\n";
	}
}

//fail 찾을때 0으로 바로가면 시간이 줄여진다. 
//어차피 첫위치에서 그만큼의 최대 길이를 찾는 것이기 때문이다.