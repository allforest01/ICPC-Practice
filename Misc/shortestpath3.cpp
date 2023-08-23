#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

bool chmin(int &a, int b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, q, s;
  while (cin >> n >> m >> q >> s) {
    if (n == 0 && m == 0 && q == 0 && s == 0) {
      return 0;
    }
    vector<array<int,3>> edges(m);
    for (auto &i : edges) {
      cin >> i[1] >> i[2] >> i[0];
    }
    vector<int> dist(n, INF); dist[s] = 0;
    for (int i = 1; i <= (n - 1) * 2; i++) {
      for (auto &e : edges) {
        if (dist[e[1]] != INF && chmin(dist[e[2]], dist[e[1]] + e[0]) && i >= n) {
          dist[e[2]] = -INF;
        }
      }
    }
    while (q--) {
      int x; cin >> x;
      if (dist[x] == INF) cout << "Impossible" << '\n';
      else if (dist[x] == -INF) cout << "-Infinity" << '\n';
      else cout << dist[x] << '\n';
    }
  }
}