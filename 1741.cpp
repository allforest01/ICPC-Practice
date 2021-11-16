#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
struct SegTree {
  int n; vector<int> val, cnt, laz;
  void build(int i, int l, int r) {
    cnt[i] = r - l + 1;
    if (l == r) return;
    int m = (l + r) / 2;
    build(i * 2, l, m);
    build(i * 2 + 1, m + 1, r);
  }
  SegTree(int n): n(n), val(n * 4 + 5), cnt(n * 4 + 5), laz(n * 4 + 5) {
    build(1, 1, n);
  }
  void down(int i) {
    val[i * 2] += laz[i];
    laz[i * 2] += laz[i];
    val[i * 2 + 1] += laz[i];
    laz[i * 2 + 1] += laz[i];
    laz[i] = 0;
  }
  void merge(int i) {
    if (val[i * 2] < val[i * 2 + 1]) {
      val[i] = val[i * 2];
      cnt[i] = cnt[i * 2];
    }
    else if (val[i * 2] > val[i * 2 + 1]) {
      val[i] = val[i * 2 + 1];
      cnt[i] = cnt[i * 2 + 1];
    }
    else {
      val[i] = val[i * 2];
      cnt[i] = cnt[i * 2] + cnt[i * 2 + 1];
    }
  }
  void update(int i, int l, int r, int u, int v, int t) {
    if (r < u || l > v) return;
    if (l >= u && r <= v) {
      val[i] += t;
      laz[i] += t;
      return;
    }
    int m = (l + r) / 2;
    down(i);
    update(i * 2, l, m, u, v, t);
    update(i * 2 + 1, m + 1, r, u, v, t);
    merge(i);
  }
  void update(int u, int v, int t) {
    update(1, 1, n, u, v, t);
  }
};
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<array<int,4>> vec;
  const int add = 1;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += add; y1 += add; x2 += add; y2 += add;
    vec.push_back({x1, y1, y2 - 1,  1});
    vec.push_back({x2, y1, y2 - 1, -1});
  }
  sort(vec.begin(), vec.end());
  ll ans = 0;
  SegTree st(30001);
  for (int i = 0; i < (int) vec.size(); i++) {
    if (i > 0) ans += (ll) st.cnt[1] * (vec[i][0] - vec[i - 1][0]);
    st.update(vec[i][1], vec[i][2], vec[i][3]);
  }
  cout << (ll) 30001 * (vec.back()[0] - vec[0][0]) - ans << '\n';
}