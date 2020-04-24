#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, b , visited[32001];
vector<int> v[32001],s;

void dfs(int i) {
	visited[i] = 1;
	for (int j : v[i]) {
		if (visited[j] == 0)dfs(j);
		//if(finished[j] == 0)cycle = 1;
	}

	//사이클 유무일때는 finished로 체크해준다
	//finished[i] = true;
	s.push_back(i);
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n;i++) {
		if(visited[i] == 0)dfs(i);
	}
	for (int i = s.size() - 1;i > -1;i--) {
		cout << s[i] << ' ';
	}

}
//역방향으로 바로 출력하면 가능하게 된다.
//위에 있는것을 먼저 출력하기때문에 역방향하면 해결