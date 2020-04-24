#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m,cv[32001];
vector<int> v[32001];
priority_queue<int> q;
int main() {

	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= m;i++) {
		cin >> a >> b;
		v[a].push_back(b);
		cv[b]++;
	}
	for (int i = 1; i <= n; i++)if (cv[i] == 0)q.push(-1*i);

	int h;
	while (q.size() != 0) {
		h = -1*q.top();
		q.pop();
		for (int i : v[h]) {
			cv[i]--;
			if (cv[i] == 0)q.push(-1*i);
		}
		cout << h << ' ';
	}


}
//������ �����ϴµ��� �ʹ� �������.
//���� ����ϴ� ������ �ϳ��� ���ŵǴ� ���������� ����ϸ� ť���� ������ �͸����ε� ���� �ذ��Ҽ��ִ�.