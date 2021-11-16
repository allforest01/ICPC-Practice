#include <bits/stdc++.h>
using namespace std;

#define int long long

int sum(int l, int r) {
  return (r + l) * (r - l + 1) / 2;
}

struct SegTree1 {
  int n; vector<int> tree, lazy;
  SegTree1(int n): n(n), tree(n * 4 + 5), lazy(n * 4 + 5) {}
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
    down(i, l, m, r);
    return get(i * 2, l, m, u, v) + get(i * 2 + 1, m + 1, r, u, v);
  }
  void update(int u, int v, int val) {
    update(1, 1, n, u, v, val);
  }
  int get(int u, int v) {
    return get(1, 1, n, u, v);
  }
};

struct SegTree2 {
  int n; vector<int> tree, lazy;
  SegTree2(int n): n(n), tree(n * 4 + 5), lazy(n * 4 + 5) {}
  void down(int i, int l, int m, int r) {
    tree[i * 2] += sum(l, m) * lazy[i];
    lazy[i * 2] += lazy[i];
    tree[i * 2 + 1] += sum(m + 1, r) * lazy[i];
    lazy[i * 2 + 1] += lazy[i];
    lazy[i] = 0;
  }
  void update(int i, int l, int r, int u, int v) {
    if (r < u || l > v) return;
    if (l >= u && r <= v) {
      tree[i] += sum(l, r);
      lazy[i] += 1;
      while (i /= 2) tree[i] = tree[i * 2] + tree[i * 2 + 1];
      return;
    }
    int m = (l + r) / 2;
    down(i, l, m, r);
    update(i * 2, l, m, u, v);
    update(i * 2 + 1, m + 1, r, u, v);
  }
  int get(int i, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (l >= u && r <= v) return tree[i];
    int m = (l + r) / 2;
    down(i, l, m, r);
    return get(i * 2, l, m, u, v) + get(i * 2 + 1, m + 1, r, u, v);
  }
  void update(int u, int v) {
    update(1, 1, n, u, v);
  }
  int get(int u, int v) {
    return get(1, 1, n, u, v);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  SegTree1 st1(n);
  SegTree2 st2(n);
  for (int i = 1; i <= n; i++) {
    int t; cin >> t;
    st1.update(i, i, t);
  }
  while (q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 1) {
      st1.update(u, v, - u + 1);
      st2.update(u, v);
    }
    else {
      cout << st1.get(u, v) +st2.get(u, v) << '\n';
    }
  }
}