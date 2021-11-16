#include <bits/stdc++.h>
using namespace std;

#define rank def_rank

struct DSU {
  int n; vector<int> root, rank;
  DSU(int n): n(n), root(n + 1), rank(n + 1) {
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

int main() {
  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    dsu.unite(u, v);
  }
  bitset<100001> dp(1);
  for (int i = 1; i <= n; i++) {
    if (dsu.root[i] == i) {
      dp |= dp << dsu.rank[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dp[i];
  }
  cout << '\n';
}