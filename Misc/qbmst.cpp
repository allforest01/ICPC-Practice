#include <bits/stdc++.h>
using namespace std;

struct DSU {
  int n; vector<int> root, hang;
  DSU(int n): n(n), root(n + 1), hang(n + 1) {
    for (int i = 1; i <= n; i++) {
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
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) swap(u, v);
    root[v] = u;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<array<int,3>> edges(m);
  for (auto &i : edges) {
    cin >> i[1] >> i[2] >> i[0];
  }
  sort(edges.begin(), edges.end(), [](array<int,3> a, array<int,3> b) {
       return a[0] < b[0];
  });
  int ans = 0;
  DSU dsu(n);
  for (auto &i : edges) {
    if (dsu.unite(i[1], i[2])) {
      ans += i[0];
    }
  }
  cout << ans << '\n';
}
