#include <bits/stdc++.h>
using namespace std;

#define int long long

struct SegTree {
  int n; vector<int> tree;
  SegTree(int n): n(n), tree(n * 4 + 5) {}
  void update(int i, int l, int r, int pos, int val) {
    if (r < pos || l > pos) return;
    if (l == r) {
      tree[i] += val;
      return;
    }
    int m = (l + r) / 2;
    update(i * 2, l, m, pos, val);
    update(i * 2 + 1, m + 1, r, pos, val);
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
  }
  int get(int i, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (l >= u && r <= v) {
      return tree[i];
    }
    int m = (l + r) / 2;
    return get(i * 2, l, m, u, v) + get(i * 2 + 1, m + 1, r, u, v);
  }
  void update(int pos, int val) {
    update(1, 1, n, pos, val);
  }
  int get(int u, int v) {
    return get(1, 1, n, u, v);
  }
};

signed main() {
  int n; cin >> n;
  vector<array<int,4>> v;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += 1e6 + 3; y1 += 1e6 + 3; x2 += 1e6 + 3; y2 += 1e6 + 3;
    if (x1 == x2) {
      v.push_back({y1, 0, x1, +1});
      v.push_back({y2, 0, x1, -1});
    }
    else {
      v.push_back({y1, 1, x1, x2});
    }
  }
  sort(v.begin(), v.end());
  int ans = 0;
  SegTree st(2e6 + 5);
  for (int i = 0; i < v.size(); i++) {
    int type = v[i][1];
    if (type == 0) {
      st.update(v[i][2], v[i][3]);
    }
    else {
      ans += st.get(v[i][2], v[i][3]);
    }
  }
  cout << ans << '\n';
}
