#include <bits/stdc++.h>
using namespace std;

#define ar array
#define vec vector

struct DSU {
  int n; vec<int> root, rank;
  DSU(int n): n(n), root(n + 1), rank(n + 1) {
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
    if (rank[u] == rank[v]) rank[u]++;
    if (rank[u] < rank[v]) swap(u, v);
    root[v] = u;
    return true;
  }
  bool sameSet(int u, int v) {
    return find(u) == find(v);
  }
  int size(int i) {
    return rank[find(i)];
  }
};

int n, m, q;
vec<int> res;
vec<ar<int,2>> eds, qrs;

void solve(int n, int l, int r, DSU dsu, vec<int> &pos) {
  if (l > r || pos.size() == 0) return;
  int m = (l + r) / 2;
  for (int i = 0; i <= m; i++) {
    dsu.unite(eds[i][0], eds[i][1]);
  }
  vec<int> pos_lf, pos_ri;
  for (auto &i : pos) {
    if (dsu.sameSet(qrs[i][0], qrs[i][1])) {
      res[i] = m + 1;
      pos_lf.push_back(i);
    }
    else {
      pos_ri.push_back(i);
    }
  }
  DSU dsn(n);
  solve(n, l, m - 1, dsn, pos_lf);
  solve(n, m + 1, r, dsn, pos_ri);
}

int main() {
  // cin.tie(0)->sync_with_stdio(0);
  freopen("in ", "r", stdin );
  freopen("out", "w", stdout);
  scanf("%d%d%d", &n, &m, &q);
  eds.resize(m);
  qrs.resize(q);
  res.resize(q, -1);
  for (auto &e : eds) {
    scanf("%d%d", &e[0], &e[1]);
  }
  for (auto &i : qrs) {
    scanf("%d%d", &i[0], &i[1]);
  }
  vec<int> pos(q);
  for (int i = 0; i < q; i++) {
    pos[i] = i;
  }
  DSU dsn(n);
  solve(n, 0, m - 1, dsn, pos);
  for (auto &i : res) printf("%d\n", i);
}
