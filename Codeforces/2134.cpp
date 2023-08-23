#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int val[N];
vector<int> adj[N];

struct SMT {
  int n; vector<int> tree;
  void init(int _n) {
    n = _n;
    tree.resize(n * 4 + 1);
  }
  void update(int i, int l, int r, int pos, int val) {
    if (r < pos || l > pos) return;
    if (l == pos && pos == r) {
      tree[i] = val;
      return;
    }
    int m = (l + r) / 2;
    update(i * 2, l, m, pos, val);
    update(i * 2 + 1, m + 1, r, pos, val);
    tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
  }
  int get(int i, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (l >= u && r <= v) {
      return tree[i];
    }
    int m = (l + r) / 2;
    return max(get(i * 2, l, m, u, v), get(i * 2 + 1, m + 1, r, u, v));
  }
  void update(int pos, int val) {
    update(1, 1, n, pos, val);
  }
  int get(int u, int v) {
    return get(1, 1, n, u, v);
  }
} smt;

void chmax(int &a, int b) {
  if (a < b) a = b;
}

struct HLD {
  int n, c = 0;
  vector<int> cid, cnt, hvy, hea, par, dep;
  void dfs(int i, int p) {
    cnt[i] = 1;
    for (auto &j : adj[i]) {
      if (j == p) continue;
      dep[j] = dep[i] + 1;
      par[j] = i;
      dfs(j, i);
      cnt[j] += cnt[i];
      if (!hvy[i] || cnt[j] > cnt[hvy[i]]) {
        hvy[i] = j;
      }
    }
  }
  void build(int i, int p, int h) {
    cid[i] = ++c;
    hea[i] = h;
    if (hvy[i]) build(hvy[i], i, h);
    for (auto &j : adj[i]) {
      if (j != p && j != hvy[i]) {
        build(j, i, j);
      }
    }
  }
  HLD(int n): n(n) {
    cid.resize(n + 1);
    cnt.resize(n + 1);
    hvy.resize(n + 1);
    hea.resize(n + 1);
    par.resize(n + 1);
    dep.resize(n + 1);
    dep[1] = 1;
    dfs(1, -1);
    build(1, -1, 1);
  }
  void update(int u, int val) {
    smt.update(cid[u], val);
  }
  int get(int u, int v) {
    int ret = 0;
    while (hea[u] != hea[v]) {
      if (dep[hea[u]] < dep[hea[v]]) swap(u, v);
      chmax(ret, smt.get(cid[hea[u]], cid[u]));
      u = par[hea[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    chmax(ret, smt.get(cid[u], cid[v]));
    return ret;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  smt.init(n);
  HLD hld(n);
  for (int i = 1; i <= n; i++) {
    hld.update(i, val[i]);
  }
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      hld.update(x, y);
    }
    else {
      cout << hld.get(x, y) << '\n';
    }
  }
}
