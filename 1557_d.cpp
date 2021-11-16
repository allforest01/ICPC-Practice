#include <bits/stdc++.h>
using namespace std;

bool chmax(int &a, int b) {
  if (a < b) { a = b; return 1; }
  return 0;
}

struct SegmentTree {
  int n; vector<int> tree, lazy, posi, lzps;
  SegmentTree(int n):
    n(n), tree(n * 8 + 1, -1), lazy(n * 8 + 1, -1),
    posi(n * 8 + 1, -1), lzps(n * 8 + 1, -1) {}
  void down(int i) {
    if (chmax(tree[i * 2], lazy[i])) posi[i * 2] = lzps[i];
    if (chmax(lazy[i * 2], lazy[i])) lzps[i * 2] = lzps[i];
    if (chmax(tree[i * 2 + 1], lazy[i])) posi[i * 2 + 1] = lzps[i];
    if (chmax(lazy[i * 2 + 1], lazy[i])) lzps[i * 2 + 1] = lzps[i];
    lazy[i] = -1;
    lzps[i] = -1;
  }
  void update(int i, int l, int r, int u, int v, int val, int pos) {
    if (r < u || l > v) return;
    if (l >= u && r <= v) {
      if (chmax(tree[i], val)) posi[i] = pos;
      if (chmax(lazy[i], val)) lzps[i] = pos;
      while (i /= 2) {
        int f = tree[i * 2];
        int s = tree[i * 2 + 1];
        if (f > s) {
          tree[i] = f;
          posi[i] = posi[i * 2];
        }
        else {
          tree[i] = s;
          posi[i] = posi[i * 2 + 1];
        }
      }
      return;
    }
    down(i);
    int m = (l + r) / 2;
    update(i * 2, l, m, u, v, val, pos);
    update(i * 2 + 1, m + 1, r, u, v, val, pos);
  }
  array<int,2> get(int i, int l, int r, int u, int v) {
    if (r < u || l > v) return {-1, -1};
    if (l >= u && r <= v) return {tree[i], posi[i]};
    down(i);
    int m = (l + r) / 2;
    auto f = get(i * 2, l, m, u, v);
    auto s = get(i * 2 + 1, m + 1, r, u, v);
    if (f[0] > s[0]) return f; else return s;
  }
  void update(int u, int v, int val, int pos) {
    update(1, 1, n, u, v, val, pos);
  }
  array<int,2> get(int u, int v) {
    return get(1, 1, n, u, v);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<array<int,2>>> segs(n + 1);
  set<int> s;
  for (int i = 0; i < m; i++) {
    int x, l, r;
    cin >> x >> l >> r;
    segs[x].push_back({l, r});
    s.insert(l);
    s.insert(r);
  }
  vector<int> v(s.begin(), s.end());
  for (int i = 1; i <= n; i++) {
    for (auto &j : segs[i]) {
      int &l = j[0], &r = j[1];
      l = lower_bound(v.begin(), v.end(), l) - v.begin() + 1;
      r = lower_bound(v.begin(), v.end(), r) - v.begin() + 1;
    }
  }
  int ans = 0, sps = 0;
  SegmentTree smt(v.size());
  vector<int> trace(n + 1);
  for (int i = 1; i <= n; i++) {
    int ma = 1, ps = i;
    for (auto &j : segs[i]) {
      int l = j[0], r = j[1];
      auto t = smt.get(l, r);
      if (chmax(ma, t[0] + 1)) ps = t[1];
    }
    trace[i] = ps;
    for (auto &j : segs[i]) {
      int l = j[0], r = j[1];
      smt.update(l, r, ma, i);
    }
    if (chmax(ans, ma)) sps = i;
  }
  cout << n - ans << '\n';
  set<int> res;
  for (int i = 1; i <= n; i++) {
    res.insert(i);
  }
  while (true) {
    res.erase(sps);
    if (sps == trace[sps]) break;
    sps = trace[sps];
  }
  for (auto &i : res) cout << i << ' ';
  cout << '\n';
}