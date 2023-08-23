#include <bits/stdc++.h>
using namespace std;

struct Dsu {
  vector<int> root, hang;
  Dsu(int n): root(n), hang(n) {
    for (int i = 0; i < n; i++) {
      root[i] = i;
      hang[i] = 1;
    }
  }
  int find(int i) {
    if (i == root[i]) return i;
    return root[i] = find(root[i]);
  }
  bool unite(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (hang[u] < hang[v]) swap(u, v);
    hang[u] += hang[v];
    root[v] = u;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) return 0;
    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; i++) {
      cin >> edges[i].first >> edges[i].second;
    }
    bool ok = 1;
    for (int i = 0; i < m; i++) {
      Dsu dsu(n);
      for (int j = 0; j < m; j++) {
        if (i == j) continue;
        int u, v;
        tie(u, v) = edges[j];
        dsu.unite(u, v);
      }
      if (dsu.hang[dsu.find(0)] != n) ok = 0;
    }
    cout << (!ok ? "Yes" : "No") << '\n';
  }
}
