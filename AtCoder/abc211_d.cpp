#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 1e9 + 7;

vector<int> adj[N];

int dist[N], dp[N], vst[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(dist, 0x3f, sizeof(dist));
  queue<int> q; q.push(1);
  dist[1] = dp[1] = 1;
  while (q.size()) {
    int i = q.front(); q.pop();
    if (vst[i]) continue;
    vst[i] = 1;
    for (auto &j : adj[i]) {
      if (dist[j] > dist[i] + 1) {
        dist[j] = dist[i] + 1;
        q.push(j);
      }
      if (dist[j] == dist[i] + 1) {
        dp[j] += dp[i];
        dp[j] %= MOD;
      }
    }
  }
  cout << dp[n] << '\n';
}
