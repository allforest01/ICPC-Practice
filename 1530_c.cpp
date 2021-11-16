#include <bits/stdc++.h>
using namespace std;

#define int long long

void Main() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());
  vector<int> sa(n), sb(n);
  for (int i = 0; i < n; i++) {
    sa[i] = a[i];
    sb[i] = b[i];
    if (i > 0) {
      sa[i] += sa[i - 1];
      sb[i] += sb[i - 1];
    }
  }
  int l = 0, r = 1e9, ans = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    int d = (n + m) / 4;
    int ca = sa[n - 1] + m * 100;
    if (d >= 1) {
      if (d <= n) ca -= sa[d - 1];
      else ca -= sa[n - 1] - 100 * (d - n);
    }
    int cb = sb[min(n + m - d, n) - 1];
    if (ca >= cb) {
      ans = m;
      r = m - 1;
    }
    else l = m + 1;
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
