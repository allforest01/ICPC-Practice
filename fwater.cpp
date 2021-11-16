#include <bits/stdc++.h>
using namespace std;

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
    if (rank[u] == rank[v]) rank[u]++;
    if (rank[u] < rank[v]) swap(u, v);
    root[v] = u;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  Dsu dsu(n + 1);
  vector<array<int,3>> edges;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    edges.push_back({x, i, n + 1});
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    int x; cin >> x;
    edges.push_back({x, i, j});
  }
  sort(edges.begin(), edges.end());
  int ans = 0;
  for (auto &edge : edges) {
    if (dsu.unite(edge[1], edge[2])) {
      ans += edge[0];
    }
  }
  cout << ans << '\n';
}
