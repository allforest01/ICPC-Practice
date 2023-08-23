#include <bits/stdc++.h>
using namespace std;

#define rank abcdef_rank

struct DSU {
  int n; vector<int> root, rank;
  DSU(int n): n(n) {
    root.resize(n + 1);
    rank.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      root[i] = i;
      rank[i] = 1;
    }
  }
  int find(int i) {
    if (i == root[i]) return i;
    return root[i] = find(root[i]);
  }
  bool join(int u, int v) {
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
  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    dsu.join(u, v);
  }
  set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(dsu.find(i));
  }
  cout << s.size() - 1 << '\n';
}
