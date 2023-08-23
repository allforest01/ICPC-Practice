#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, m;
array<int,3> a[N];

struct SegmentTree {
  int n; vector<int> tree, lazy, mint;

  SegmentTree(int n): n(n), tree(n * 8 + 5), lazy(n * 8 + 5), mint(n * 8 + 5) {}
   
  void down(int i){
    tree[i * 2]     += lazy[i];
    tree[i * 2 + 1] += lazy[i];
    mint[i * 2]     += lazy[i];
    mint[i * 2 + 1] += lazy[i];
    lazy[i * 2]     += lazy[i];
    lazy[i * 2 + 1] += lazy[i];
    lazy[i] = 0;
  }
   
  void update(int i, int l, int r, int u, int v, int p){
    if (r <  u || l >  v) return;
    if (l >= u && r <= v) {
      tree[i] += p;
      mint[i] += p;
      lazy[i] += p;
      while (i /= 2) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
        mint[i] = min(mint[i * 2], mint[i * 2 + 1]);
      }
      return;
    }
    down(i);
    int m = (l + r) / 2;
    update(i * 2, l, m, u, v, p);
    update(i * 2 + 1, m + 1, r, u, v, p);
  }
   
  int get(int i, int l, int r, int u, int v){
    if (r <  u || l >  v) return INT_MAX;
    if (l >= u && r <= v) return mint[i];
    down(i);
    int m = (l + r) / 2;
    return min(get(i * 2, l, m, u, v), get(i * 2 + 1, m + 1, r, u, v));
  }

  void update(int u, int v, int p) {
    update(1, 1, n, u, v, p);
  }

  int getMin(int u, int v) {
    return get(1, 1, n, u, v);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][1] >> a[i][2] >> a[i][0];
    a[i][2]--;
  }
  sort(a + 1, a + n + 1);
  int ans = INT_MAX;
  SegmentTree smt(m);
  for (int i = 1, j = 1; i <= n; i++) {
    smt.update(a[i][1], a[i][2], 1);
    while (j <= i && smt.getMin(1, m - 1) >= 1) {
      ans = min(ans, a[i][0] - a[j][0]);
      smt.update(a[j][1], a[j][2], -1);
      j++;
    }
  }
  cout << ans << '\n';
}
