#include <bits/stdc++.h>
using namespace std;

#define ar array
#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<array<int,2>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int k, u, v, l;
    cin >> k >> u >> v >> l;
    adj[u].push_back({l, v});
    if (k == 2) {
      adj[v].push_back({l, u});
    }
  }
  vector<int> vst(n + 1), dis(n + 1, 1e9), cnt(n + 1);
  dis[1] = 0;
  cnt[1] = 1;
  priority_queue<ar<int,2>, vector<ar<int,2>>, greater<ar<int,2>>> pq;
  pq.push({0, 1});
  while (pq.size()) {
    auto i = pq.top(); pq.pop();
    if (vst[i[1]]) continue;
    vst[i[1]] = 1;
    for (auto &j : adj[i[1]]) {
      int d = i[0] + j[0];
      if (d < dis[j[1]]) {
        dis[j[1]] = d;
        cnt[j[1]] = cnt[i[1]];
        pq.push({d, j[1]});
      }
      else if (d == dis[j[1]]) {
        cnt[j[1]] += cnt[i[1]];
      }
    }
  }
  cout << dis[n] << ' ' << cnt[n] << '\n';
}
