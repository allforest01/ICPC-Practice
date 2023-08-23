#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int a[N];

struct WT {
  int x, y;
  vector<int> b;
  WT *lpt, *rpt;
  WT(int *l, int *r, int x, int y): x(x), y(y) {
    if (l > r || x == y) return;
    int m = (x + y) / 2;
    b.push_back(0);
    for (auto it = l; it <= r; it++) {
      b.push_back(b.back() + (*it <= m));
    }
    auto p = stable_partition(l, r + 1,
      [m](int x)->bool {
        return x <= m;
      }
    );
    lpt = new WT(l, p - 1, x, m);
    rpt = new WT(p, r, m + 1, y);
  }
  int KTH(int l, int r, int k) {
    if (x == y) return x;
    int inLeft = b[r] - b[l - 1];
    int pl = b[l - 1] + 1;
    int pr = b[r];
    if (k <= inLeft) return lpt->KTH(pl, pr, k);
    else return rpt->KTH(l - b[l - 1], r - b[r], k - inLeft);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  WT wt(a + 1, a + n, 0, 1e9);
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << wt.KTH(l + 1, r, k + 1) << '\n';
  }
}