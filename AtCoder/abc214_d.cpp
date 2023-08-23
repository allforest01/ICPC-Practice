#include <bits/stdc++.h>
using namespace std;

#define ar array
#define int long long
#define rank def_rank

struct Dsu {
  int n; vector<int> root, rank;
  Dsu(int n): n(n), root(n + 1), rank(n + 1) {
    for (int i = 1; i <= n; i++) {
      root[i] = i;
      rank[i] = 1;
    }
  }
  int find(int i) {
    if (i == root[i]) return i;
    return root[i] = find(root[i]);
  }
  bool unite(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (rank[u] < rank[v]) swap(u, v);
    rank[u] += rank[v];
    root[v] = u;
    return true;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<ar<int,3>> edges;
  for (int i = 1; i < n; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    edges.push_back({x, u, v});
  }
  sort(edges.begin(), edges.end());
  int ans = 0;
  Dsu dsu(n);
  for (auto &e : edges) {
    int x = e[0], u = e[1], v = e[2];
    ans += dsu.rank[dsu.find(u)] * dsu.rank[dsu.find(v)] * x;
    dsu.unite(u, v);
  }
  cout << ans << '\n';
}
