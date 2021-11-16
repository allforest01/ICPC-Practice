#include <bits/stdc++.h>
using namespace std;

struct Dsu {
  int n; vector<int> root, rank;
  Dsu(int n): n(n), root(n + 1), rank(n + 1) {
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
  cin.tie(0)->sync_with_stdio(0);
  freopen("in" , "w", stdout);
  srand(time(NULL));
  int n = rand() % 1000 + 1;
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    int x1 = rand() % 10000, x2 = rand() % 10000 + x1;
    int y1 = rand() % 10000, y2 = rand() % 10000 + y1;
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
  }
}
