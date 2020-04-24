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

	//����Ŭ �����϶��� finished�� üũ���ش�
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
//���������� �ٷ� ����ϸ� �����ϰ� �ȴ�.
//���� �ִ°��� ���� ����ϱ⶧���� �������ϸ� �ذ�