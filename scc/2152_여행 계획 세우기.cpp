#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int n, m, st, t;
int cnt, scn, visited[10001], finished[10001],r[10001],rt[10001],check[10001];
vector<int> v[10001],sccv[10001];
stack<int> s;
int dfs(int i) {
    visited[i] = ++cnt;
    s.push(i);
    int ok = visited[i];
    for (int j : v[i]) {
        if (visited[j] == 0)ok = min(ok, dfs(j));
        if (finished[j] == 0)ok = min(ok, visited[j]);
    }
    if (ok == visited[i]) {
        int h, ret = 0;
        scn++;
        while (1) {
            h = s.top();
            s.pop();
            finished[h] = scn;
            ret++;
            if (h == i)break;
        }
        rt[scn] = ret;
        r[scn] = ret;
    }
    return ok;
 }

int main() {
    cin >> n >> m >> st >> t;
    int x, y;
    for (; m; m--) {
        cin >> x >> y;
        v[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)if (visited[i] == 0)dfs(i);

    for (int i = 1; i <= n; i++) {
        for (int j : v[i]) {
            if (finished[i] != finished[j]) {
                sccv[finished[i]].push_back(finished[j]);
                check[finished[j]]++;
            }
        }
        visited[i] = 0;
    }
    visited[finished[st]] = 1;
    queue<int> q;
    for (int i = 1; i <= scn; i++)if (check[i] == 0)q.push(i);
    int h;
    while (q.size()) {
        h = q.front();
        q.pop();
        for (int i : sccv[h]) {
            check[i]--;
            if (visited[h] == 1) {
                r[i] = max(r[i], rt[i] + r[h]);
                visited[i] = 1;
            }
            if (check[i] == 0)q.push(i);
        }
    }
    int ret = 0;
    if (visited[finished[t]] == 1)cout << r[finished[t]];
    else cout << 0;

}