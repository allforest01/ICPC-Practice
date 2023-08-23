#include <bits/stdc++.h>
using namespace std;

#define rank def_rank

struct Dsu {
  int n; vector<int> root, rank;
  Dsu(int n): n(n), root(n), rank(n) {
    for (int i = 0; i < n; i++) {
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
  int n, q;
  cin >> n >> q;
  Dsu dsu(n);
  while (q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0) dsu.unite(u, v);
    else cout << (dsu.find(u) == dsu.find(v)) << '\n';
  }
}
