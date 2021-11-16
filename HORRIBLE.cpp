#include <bits/stdc++.h>
using namespace std;

#define int long long

struct SegTree {
  int n; vector<int> tree, lazy;
  SegTree(int n): n(n), tree(n * 4 + 5), lazy(n * 4 + 5) {}
  void down(int i, int l, int m, int r) {
    tree[i * 2] += lazy[i] * (m - l + 1);
    lazy[i * 2] += lazy[i];
    tree[i * 2 + 1] += lazy[i] * (r - m);
    lazy[i * 2 + 1] += lazy[i];
    lazy[i] = 0;
  }
  void update(int i, int l, int r, int u, int v, int val) {
    if (r < u || l > v) return;
    if (l >= u && r <= v) {
      tree[i] += val * (r - l + 1);
      lazy[i] += val;
      while (i /= 2) tree[i] = tree[i * 2] + tree[i * 2 + 1];
      return;
    }
    int m = (l + r) / 2;
    down(i, l, m, r);
    update(i * 2, l, m, u, v, val);
    update(i * 2 + 1, m + 1, r, u, v, val);
  }
  int get(int i, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (l >= u && r <= v) return tree[i];
    int m = (l + r) / 2;
    down(i, l, m , r);
    return get(i * 2, l, m, u, v) + get(i * 2 + 1, m + 1, r, u, v);
  }
  void update(int u, int v, int val) {
    update(1, 1, n, u, v, val);
  }
  int get(int u, int v) {
    return get(1, 1, n, u, v);
  }
  void debug(int i, int l, int r) {
    cout << "> " << l << ' ' << r << ' ' << tree[i] << '\n';
    if (l == r) return;
    int m = (l + r) / 2;
    down(i, l, m, r);
    debug(i * 2, l, m);
    debug(i * 2 + 1, m + 1, r);
  }
  void debug() {
    debug(1, 1, n);
  }
};

void Main() {
  int n, q;
  cin >> n >> q;
  SegTree st(n);
  while (q--) {
    int t; cin >> t;
    if (t == 0) {
      int u, v, val;
      cin >> u >> v >> val;
      st.update(u, v, val);
//      cout << '\n';
    }
    else {
      int u, v;
      cin >> u >> v;
      cout << st.get(u, v) << '\n';
    }
//    for (int i = 1; i <= n; i++) {
//      cout << st.get(i, i) << ' ';
//    }
//    cout << '\n';
//    st.debug();
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
