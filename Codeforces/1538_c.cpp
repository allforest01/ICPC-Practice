#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int pl, pr, pi, pa;
    pl = 0; pr = i - 1; pi = -1;
    while (pl <= pr) {
      int m = (pl + pr) / 2;
      if (a[m] + a[i] >= l) {
        pi = m;
        pr = m - 1;
      }
      else pl = m + 1;
    }
    pl = 0; pr = i - 1; pa = -1;
    while (pl <= pr) {
      int m = (pl + pr) / 2;
      if (a[m] + a[i] <= r) {
        pa = m;
        pl = m + 1;
      }
      else pr = m - 1;
    }
    if (pa >= pi && pi != -1 && pa != -1) ans += pa - pi + 1;
  }
  cout << ans << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
