#include <bits/stdc++.h>
using namespace std;

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
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  Dsu dsu(n + 1);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    dsu.unite(x, i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dsu.find(i) == i) ans++;
  }
  cout << ans << '\n';
}
