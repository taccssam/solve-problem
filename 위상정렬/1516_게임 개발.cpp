#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, cv[501], tv[501] , sv[501]; // c = ����� ī��Ʈ , t �� ���� �ð� , s�� �ѽð�
vector<int> v[501];
priority_queue<int> q;

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> tv[i];
		sv[i] = tv[i];
		int a;
		for (;;) {
			cin >> a;
			if (a == -1)break;
			v[a].push_back(i);
			cv[i]++;
		}
	}
	for (int i = 1;i <= n;i++)if (cv[i] == 0)q.push(i);

	int t,k;
	while (q.size() != 0) {
		t = q.top();
		q.pop();
		for (int i : v[t]) {
			cv[i]--;
			sv[i] = max(sv[t] + tv[i],sv[i]);
			if (cv[i] == 0)q.push(i);
		}
	}
	for (int i = 1;i <= n;i++)cout << sv[i] << endl;
}

//���ÿ��� ����Ǳ⶧���� ��θ����ϴ� �ִ�ð������Ѵ�. �̺κ� ����!!