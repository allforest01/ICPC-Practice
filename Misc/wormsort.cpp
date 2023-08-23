#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, a[N];
vector<array<int,3>> edges;

struct Dsu {
  vector<int> root, hang;
  Dsu(int n): root(n + 1), hang(n + 1) {
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
  bool same(int u, int v) {
    return find(u) == find(v);
  }
};

bool check(int x) {
  Dsu dsu(n + 1);
  for (auto &e : edges) {
    if (e[2] >= x) {
      dsu.unite(e[0], e[1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!dsu.same(a[i], i)) return false;
  }
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("wormsort.in" , "r", stdin );
  freopen("wormsort.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    edges.push_back({u, v, c});
  }
  int l = 1, r = 1e9 + 1, ans = -1;
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      l = x + 1;
    }
    else r = x - 1;
  }
  if (ans == 1e9 + 1) cout << -1 << '\n';
  else cout << ans << '\n';
}
