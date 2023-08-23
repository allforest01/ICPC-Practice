#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

bool chmin(int &a, int b) {
  return a > b ? (a = b, 1) : 0;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  while (true) {
    int n, m, q;
    cin >> n >> m >> q;
    if (n == 0 && m == 0 && q == 0) {
      return 0;
    }
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
      dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      chmin(dist[u][v], w);
    }
    for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (dist[i][k] != INF && dist[k][j] != INF) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
    vector<vector<bool>> bad(n, vector<bool>(n));
    for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
        bad[i][j] = 1;
      }
    }
    for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if ((dist[i][k] != INF && bad[k][j]) || (bad[i][k] && dist[k][j] != INF)) {
        bad[i][j] = 1;
      }
    }
    while (q--) {
      int u, v;
      cin >> u >> v;
      if (dist[u][v] == INF) cout << "Impossible" << '\n';
      else if (bad[u][v]) cout << "-Infinity" << '\n';
      else cout << dist[u][v] << '\n';
    }
  }
}