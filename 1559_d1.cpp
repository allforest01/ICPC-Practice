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
  bool can(int u, int v) {
    return find(u) != find(v);
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
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  Dsu dsu1(n), dsu2(n);
  for (int i = 0; i < m1; i++) {
    int u, v;
    cin >> u >> v;
    dsu1.unite(u, v);
  }
  for (int i = 0; i < m2; i++) {
    int u, v;
    cin >> u >> v;
    dsu2.unite(u, v);
  }
  vector<array<int,2>> res;
  for (int i = 1; i + 1 <= n; i++)
  for (int j = i + 1; j <= n; j++) {
    if (dsu1.can(i, j) && dsu2.can(i, j)) {
      dsu1.unite(i, j);
      dsu2.unite(i, j);
      res.push_back({i, j});
    }
  }
  cout << res.size() << '\n';
  for (auto &i : res) {
    cout << i[0] << ' ' << i[1] << '\n';
  }
}
