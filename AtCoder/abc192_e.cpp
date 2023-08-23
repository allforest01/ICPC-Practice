#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;

vector<vector<int>> adj[N];

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  for (int i = 1; i <= m; i++) {
    int u, v, t, k;
    cin >> u >> v >> t >> k;
    adj[u].push_back({t, k, v});
    adj[v].push_back({t, k, u});
  }
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push({0, x});
  vector<int> vst(n + 1);
  while (pq.size()) {
    auto i = pq.top(); pq.pop();
    if (i.second == y) {
      cout << i.first << '\n';
      return 0;
    }
    if (vst[i.second]) continue;
    vst[i.second] = 1;
    for (auto &j : adj[i.second]) {
      int nt = (i.first + j[1] - 1) / j[1] * j[1];
      pq.push(make_pair(nt + j[0], j[2]));
    }
  }
  cout << -1 << '\n';
}
