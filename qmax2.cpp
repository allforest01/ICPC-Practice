#include <bits/stdc++.h>
using namespace std;

#define int long long

void chmax(int &a, int b) {
  if (a < b) a = b;
}

struct SegmentTree {
  int n; vector<int> tree, lazy;
  SegmentTree(int n): n(n), tree(n * 4), lazy(n * 4) {}
  void down(int i) {
    tree[i * 2] += lazy[i];
    lazy[i * 2] += lazy[i];
    tree[i * 2 + 1] += lazy[i];
    lazy[i * 2 + 1] += lazy[i];
    lazy[i] = 0;
  }
  void update(int i, int l, int r, int u, int v, int k) {
    if (r < u || l > v) return;
    if (l >= u && r <= v) {
      tree[i] += k;
      lazy[i] += k;
      while (i /= 2) tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
      return;
    }
    down(i);
    int m = (l + r) / 2;
    update(i * 2, l, m, u, v, k);
    update(i * 2 + 1, m + 1, r, u, v, k);
  }
  int get(int i, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (l >= u && r <= v) {
      return tree[i];
    }
    down(i);
    int m = (l + r) / 2;
    return max(get(i * 2, l, m, u, v), get(i * 2 + 1, m + 1, r, u, v));
  }
  void update(int u, int v, int k) {
    update(1, 1, n, u, v, k);
  }
  int get(int u, int v) {
    return get(1, 1, n, u, v);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  SegmentTree smt(n);
  while (q--) {
    int t; cin >> t;
    if (t == 0) {
      int u, v, k;
      cin >> u >> v >> k;
      smt.update(u, v, k);
    }
    else {
      int u, v;
      cin >> u >> v;
      cout << smt.get(u, v) << '\n';
    }
  }
}
