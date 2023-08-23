#include <bits/stdc++.h>
using namespace std;

#define ar array

const int N = 105;
const int K = 10005;
const int INF = 0x3f3f3f3f;

int n, m, k;
vector<array<int,3>> adj[N];
int vst[N][K], dis[N][K];

void solve() {
  if (fopen("in", "r")) {
    freopen("in", "r", stdin);
  }
  cin >> k >> n >> m;
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int u, v, w, c;
    cin >> u >> v >> w >> c;
    adj[u].push_back({w, c, v});
  }
  memset(vst, 0x00, sizeof(vst));
  memset(dis, 0x3f, sizeof(dis));
  priority_queue<ar<int,3>, vector<ar<int,3>>, greater<ar<int,3>>> pq;
  pq.push({0, 0, 1});
  while (pq.size()) {
    auto i = pq.top(); pq.pop();
    if (vst[i[2]][i[1]]) continue;
    vst[i[2]][i[1]] = 1;
    dis[i[2]][i[1]] = i[0];
    for (auto &j : adj[i[2]]) {
      if (dis[j[2]][i[1] + j[1]] > i[0] + j[0]) {
        dis[j[2]][i[1] + j[1]] = i[0] + j[0];
        pq.push({i[0] + j[0], i[1] + j[1], j[2]});
      }
    }
  }
  int ans = INF;
  for (int i = 0; i <= k; i++) {
    ans = min(ans, dis[n][i]);
  }
  if (ans == INF) ans = -1;
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) solve();
}
