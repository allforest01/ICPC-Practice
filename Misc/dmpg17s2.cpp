#include <bits/stdc++.h>
using namespace std;

struct Dsu {

  vector<int> root, hang;

  Dsu(int n) {
    root.resize(n + 1);
    hang.resize(n + 1);
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
  int n, q;
  cin >> n >> q;
  Dsu dsu(n);
  for (int i = 1; i <= q; i++) {
    char c; int x, y;
    cin >> c >> x >> y;
    if (c == 'A') {
      dsu.unite(x, y);
    }
    else {
      x = dsu.find(x);
      y = dsu.find(y);
      cout << (x == y ? 'Y' : 'N') << '\n';
    }
  }
}
