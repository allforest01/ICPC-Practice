#include <bits/stdc++.h>
using namespace std;

struct Dsu {
  int n; vector<int> root; vector<map<int,int>> hang;
  Dsu(int n): n(n), root(n + 1), hang(n + 1) {
    for (int i = 1; i <= n; i++) {
      root[i] = i;
    }
  }
  int find(int i) {
    if (i == root[i]) return i;
    return root[i] = find(root[i]);
  }
  bool unite(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (hang[u].size() < hang[v].size()) {
      swap(u, v);
    }
    for (auto &i : hang[v]) {
      hang[u][i.first] += i.second;
    }
    root[v] = u;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  Dsu dsu(n);
  for (int i = 1; i <= n; i++) {
    int c; cin >> c;
    dsu.hang[i][c] = 1;
  }
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      dsu.unite(x, y);
    }
    else {
      cout << dsu.hang[dsu.find(x)][y] << '\n';
    }
  }
}
