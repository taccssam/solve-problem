#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <set>
using namespace std;

int l[2250001],p[2250001],g[2];
int r, c;
queue<int> q;
int find(int a) {
	if (p[a] < 0)return a;
	return p[a] = find(p[a]);
}

void merge(int a,int b) {
	a = find(a), b = find(b);
	if (a == b)return;
	p[b] = a;
}


int main() {
	cin >> r >> c;
	char t;
	memset(p, -1, sizeof(p));
	int cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> t;
			if (t == '.')l[i * c + j] = 0;
			if (t == 'X')l[i*c+j] = 1;
			if (t == 'L') {
				l[i * c + j] = 0;
				g[cnt++] = i * c + j;
			}
			if (t == '.' || t == 'L') {
				if (i > 0 && l[(i - 1) * c + j] == 0)merge((i - 1) * c + j, i * c + j);
				if (j > 0 && l[i * c + j - 1] == 0)merge(i * c + j - 1, i * c + j);
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (l[i * c + j] == 1) {
				if ((i > 0 && l[(i - 1) * c + j] == 0) || (j > 0 && l[i * c + j - 1] == 0) ||
					(i < r - 1 && l[(i + 1) * c + j] == 0) || (j < c - 1 && l[i * c + j + 1] == 0))q.push(i * c + j);
			}
		}
	}
	cnt = 0;
	while (1) {

		queue<int> q1,q2;
		set<int> s;
		int h,i,j;
		if (find(g[0]) == find(g[1])) {
			cout << cnt;
			break;
		}
		else cnt++;


		while(q.size()){
			h = q.front();
			q.pop();
			i = h / c, j = h % c;
			if (i > 0 && l[(i - 1) * c + j] == 0)merge((i - 1) * c + j, i * c + j);
			if (j > 0 && l[i * c + j - 1] == 0)merge(i * c + j - 1, i * c + j);
			if (i < r - 1 && l[(i + 1) * c + j] == 0)merge((i + 1) * c + j, i * c + j);
			if (j < c - 1 && l[i * c + j + 1] == 0)merge(i * c + j+1, i * c + j);
			l[i * c + j] = 0;
			q1.push(i * c + j);
		}
	
		for (; q1.size(); q1.pop()) {
			i = q1.front() / c, j = q1.front() % c;
			if (i > 0 && l[(i - 1) * c + j] == 1) {
				if (s.find((i - 1) * c + j) == s.end())
				{
					s.insert((i - 1) * c + j);
					q.push((i - 1) * c + j);
				}
			}
			if (j > 0 && l[i * c + j - 1] == 1) {
				if (s.find(i * c + j - 1) == s.end()) {
					s.insert(i * c + j - 1);
					q.push(i * c + j - 1);
				}
			}
			if (i < r - 1 && l[(i + 1) * c + j] == 1) {
				if (s.find((i + 1) * c + j) == s.end()) {
					s.insert((i + 1) * c + j);
					q.push((i + 1) * c + j);
				}
			}
			if (j < c - 1 && l[i * c + j + 1] == 1) {
				if (s.find(i * c + j + 1) == s.end()) {
					s.insert(i * c + j + 1);
					q.push(i * c + j + 1);
				}
			}
		}
		
		
		
	}
}
//시간초과 너무 여러본다....
//bfs 처럼 해볼까?
//큐로 사용해서 풀어야 빠르게 풀린다