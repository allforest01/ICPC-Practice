#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n, m, b, r;
vector<int> adj[N];
int vst[N], res[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> b >> r;
  queue<array<int,2>> q;
  for (int i = 0; i < b; i++) {
    int x; cin >> x;
    q.push({0, x});
  }
  vector<int> p(r);
  for (auto &i : p) {
    cin >> i;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  while (q.size()) {
    auto i = q.front(); q.pop();
    if (vst[i[1]]) continue;
    vst[i[1]] = 1;
    res[i[1]] = i[0];
    for (auto &j : adj[i[1]]) {
      q.push({i[0] + 1, j});
    }
  }
  for (auto &i : p) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}
