#include <bits/stdc++.h>
using namespace std;

#define int long long

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void chmax(int &a, int b) {
  if (a < b) a = b;
}

struct SegTree {
  int n; vector<int> Min, Max, Sum, Laz;
  SegTree(int n): n(n), Min(n * 4 + 5), Max(n * 4 + 5),
                  Sum(n * 4 + 5), Laz(n * 4 + 5, -1) {}
  void push_up(int i) {
    Min[i] = min(Min[i * 2], Min[i * 2 + 1]);
    Max[i] = max(Max[i * 2], Max[i * 2 + 1]);
    Sum[i] = Sum[i * 2] + Sum[i * 2 + 1];
  }
  void push_down(int i, int l, int m, int r) {
    if (Laz[i] == -1) return;
    Min[i * 2] = Max[i * 2] = Laz[i * 2] = Laz[i];
    Sum[i * 2] = Laz[i] * (m - l + 1);
    Min[i * 2 + 1] = Max[i * 2 + 1] = Laz[i * 2 + 1] = Laz[i];
    Sum[i * 2 + 1] = Laz[i] * (r - m);
    Laz[i] = -1;
  }
  void build(int i, int l, int r, vector<int> &a) {
    if (l == r) {
      Min[i] = Max[i] = Sum[i] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build(i * 2, l, m, a);
    build(i * 2 + 1, m + 1, r, a);
    push_up(i);
  }
  void point_update(int i, int l, int r, int pos, int val) {
    if (r < pos || l > pos) return;
    if (l == pos && r == pos) {
      Min[i] = Max[i] = Sum[i] = val;
      return;
    }
    int m = (l + r) / 2;
    push_down(i, l, m, r);
    point_update(i * 2, l, m, pos, val);
    point_update(i * 2 + 1, m + 1, r, pos, val);
    push_up(i);
  }
  void range_chmod(int i, int l, int r, int u, int v, int val) {
    if (r < u || l > v || Max[i] < val) return;
    if (l >= u && r <= v && Max[i] == Min[i]) {
      int tmp = Min[i] % val;
      Min[i] = Max[i] = tmp;
      Sum[i] = tmp * (r - l + 1);
      Laz[i] = tmp;
      return;
    }
    int m = (l + r) / 2;
    push_down(i, l, m, r);
    range_chmod(i * 2, l, m, u, v, val);
    range_chmod(i * 2 + 1, m + 1, r, u, v, val);
    push_up(i);
  }
  int range_sum(int i, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (l >= u && r <= v) {
      return Sum[i];
    }
    int m = (l + r) / 2;
    push_down(i, l, m, r);
    return range_sum(i * 2, l, m, u, v) + range_sum(i * 2 + 1, m + 1, r, u, v);
  }
  void point_update(int pos, int val) {
    point_update(1, 1, n, pos, val);
  }
  void range_chmod(int u, int v, int val) {
    range_chmod(1, 1, n, u, v, val);
  }
  int range_sum(int u, int v) {
    return range_sum(1, 1, n, u, v);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  SegTree st(n);
  st.build(1, 1, n, a);
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int l, r; cin >> l >> r;
      cout << st.range_sum(l, r) << '\n';
    }
    else if (type == 2) {
      int l, r, x; cin >> l >> r >> x;
      st.range_chmod(l, r, x);
    }
    else if (type == 3) {
      int k, x; cin >> k >> x;
      st.point_update(k, x);
    }
  }
}
