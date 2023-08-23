#include <bits/stdc++.h>
using namespace std;

#define rank abcdef_rank

struct Dsu {
  int n; vector<int> root, rank;
  Dsu(int n): n(n) {
    root.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++) {
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
  int n; cin >> n;
  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    a[x].first = y;
    a[x].second = i;
  }
  Dsu dsu(n);
  set<pair<int,int>> s;
  for (int i = 0; i < n; i++) {
    int y, idx;
    tie(y, idx) = a[i];
    int mi = y;
    for (auto it = s.begin(); it != s.end(); ) {
      int yi, idxi;
      tie(yi, idxi) = *it;
      if (yi > y) break;
      dsu.unite(idx, idxi);
      mi = min(mi, yi);
      auto tmp = it;
      it++;
      s.erase(tmp);
    }
    s.insert(make_pair(mi, idx));
  }
  for (int i = 0; i < n; i++) {
    cout << dsu.rank[dsu.find(i)] << '\n';
  }
}
