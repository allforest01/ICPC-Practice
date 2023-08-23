#include <bits/stdc++.h>
using namespace std;

void chmax(int &a, int b) {
  if (a < b) a = b;
}

struct SegmentTree {
  int n; vector<int> smt, lzy;
  SegmentTree(int n): n(n), smt(n * 8 + 1), lzy(n * 8 + 1) {}
  void down(int i) {
    chmax(smt[i * 2], lzy[i]);
    chmax(lzy[i * 2], lzy[i]);
    chmax(smt[i * 2 + 1], lzy[i]);
    chmax(lzy[i * 2 + 1], lzy[i]);
    lzy[i] = 0;
  }
  void update(int i, int l, int r, int u, int v, int val) {
    if (l >  v || r <  u) return;
    if (l >= u && r <= v) {
      chmax(smt[i], val);
      chmax(lzy[i], val);
      return;
    }
    down(i);
    int m = (l + r) / 2;
    update(i * 2, l, m, u, v, val);
    update(i * 2 + 1, m + 1, r, u, v, val);
  }
  int get(int i, int l, int r, int u, int v) {
    if (l >  v || r <  u) return 0;
    if (l >= u && r <= v) return smt[i];
    down(i);
    int m = (l + r) / 2;
    int lval = get(i * 2, l, m, u, v);
    int rval = get(i * 2 + 1, m + 1, r, u, v);
    return max(lval, rval);
  }
  void update(int u, int v, int val) {
    update(1, 0, n, u, v, val);
  }
  int get(int u, int v) {
    return get(1, 0, n, u, v);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  const int A = 300000;
  SegmentTree smt(A + 1);
  for (int i = 1; i <= n; i++) {
    int t = smt.get(a[i], a[i]) + 1;
    chmax(ans, t);
    smt.update(max(a[i] - k, 0), min(a[i] + k, A), t);
  }
  cout << ans << '\n';
}
