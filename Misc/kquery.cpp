#include <bits/stdc++.h>
using namespace std;

struct WT {
  vector<int> b; int l, r; WT *pl, *pr;
  WT(int l, int r, int x, int y, vector<int> &a):
  l(l), r(r), pl(NULL), pr(NULL) {
    if (l >= r || x > y) return;
    int m = (l + r) / 2;
    b.resize(y - x + 2);
    for (int i = x; i <= y; i++) {
      b[i - x + 1] = b[i - x] + (a[i] <= m);
    }
    auto p = stable_partition(a.begin() + x, a.begin() + y + 1, 
      [m](int n)->bool { return n <= m; });
    pl = new WT(l, m, x, p - a.begin() - 1, a);
    pr = new WT(m + 1, r, p - a.begin(), y, a);
  }
  int lek(int x, int y, int k) {
    // if (x > y) return 0;
    // cerr << x << ' ' << y << ' ' << k << '\n';
    int m = (l + r) / 2;
    if (m > k) {
      // cerr << "?" << '\n';
      if (pl == NULL) return 0;
      return pl->lek(b[x - 1] + 1, b[y], k);
    }
    else {
      // cerr << b[y] << ' ' << b[x] << '\n';
      if (pr == NULL) return b.size() ? b[y] - b[x - 1] : 0;
      return b[y] - b[x - 1] + pr->lek(x - b[x - 1], y - b[y], k);
    }
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  WT wt(1, 1e9, 1, n, a);
  int q; cin >> q;
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << (r - l + 1) - wt.lek(l, r, k) << '\n';
  }
}
