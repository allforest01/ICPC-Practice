#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, q, dist[N][N];
vector<pair<int,int>> adj[N];

void dfs(int i, int dist[]) {
  for (auto &j : adj[i]) {
    if (!dist[j.second]) {
      dist[j.second] = min(dist[i], j.first);
      dfs(j.second, dist);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("mootube.in" , "r", stdin );
  freopen("mootube.out", "w", stdout);
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back(make_pair(c, v));
    adj[v].push_back(make_pair(c, u));
  }
  for (int i = 1; i <= n; i++) {
    dist[i][i] = INT_MAX;
    dfs(i, dist[i]);
  }
  while (q--) {
    int k, v;
    cin >> k >> v;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (dist[v][i] >= k && i != v) ans++;
    }
    cout << ans << '\n';
  }
}
