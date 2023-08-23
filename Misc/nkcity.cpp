#include <bits/stdc++.h>
using namespace std;

struct Dsu {
  int n; vector<int> root, hang;
  Dsu(int n): n(n), root(n + 1), hang(n + 1) {
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
    if (hang[u] < hang[v]) swap(u, v);
    hang[u] += hang[v];
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
    cin >> i[0] >> i[1] >> i[2];
  }
  auto check = [&](int x) {
    Dsu dsu(n);
    for (auto &i : edges) {
      if (i[2] <= x) {
        dsu.unite(i[0], i[1]);
      }
    }
    return dsu.hang[dsu.find(1)] == n;
  };
  int l = 0, r = 2e9, ans = -1;
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      r = x - 1;
    }
    else l = x + 1;
  }
  cout << ans << '\n';
}
