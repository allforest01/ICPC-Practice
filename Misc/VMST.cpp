#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

struct DSU {
  int n;
  vector<int> root, hang;
  void reset() {
    for (int i = 1; i <= n; i++) {
      root[i] = i;
      hang[i] = 1;
    }
  }
  DSU(int n): n(n) {
    root.resize(n + 1);
    hang.resize(n + 1);
    reset();
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
  vector<pii> edges(m);
  for (auto &i : edges) {
    cin >> i.first >> i.second;
  }
  DSU dsu;
  vector<pii> spt, rmn;
  for (auto &i : edges) {
    if (dsu.unite(i.first, i.second)) {
      spt.push_back(i);
    }
    else rmn.push_back(i);
  }
  vector<vector<pii>> res;
  for (int i = 0; i < n - 1; i++) {
    dsu.reset();
    vector<pii> cur;
    for (int j = 0; j < n - 1; j++) {
      if (j == i) continue;
      dsu.unite(spt[j.first], spt[j.second]);
      cur.push_back(j);
    }
    for (auto &i : rmn) {
      if (dsu.unite(i.first, i.second)) {
        cur.push_back(i);
        break;
      }
    }
  }
}
