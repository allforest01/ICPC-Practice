#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

struct Dsu {
  int n; vector<int> root, vsiz;
  Dsu(int n): n(n) {
    root.resize(n);
    vsiz.resize(n);
    for (int i = 0; i < n; i++) {
      root[i] = i;
      vsiz[i] = 1;
    }
  }
  int find(int i) {
    if (i == root[i]) return i;
    return root[i] = find(root[i]);
  }
  bool unite(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (vsiz[u] < vsiz[v]) swap(u, v);
    vsiz[u] += vsiz[v];
    root[v] = u;
    return true;
  }
  int size(int i) {
    return vsiz[find(i)];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  Dsu dsu(N);
  for (int i = 0; i < n; i++) {
    dsu.unite(a[i], a[n - i - 1]);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (i == dsu.find(i)) {
      ans += dsu.size(i) - 1;
    }
  }
  cout << ans << '\n';
}
