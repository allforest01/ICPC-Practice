#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200005;

array<int,2> a[N];

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  sort(a + 1, a + n + 1);
  auto check = [&](int x)->bool {
    vector<int> ri_mi(n + 2, INT_MAX), ri_ma(n + 2, INT_MIN);
    for (int i = n; i >= 1; i--) {
      ri_mi[i] = min(a[i][1], ri_mi[i + 1]);
      ri_ma[i] = max(a[i][1], ri_ma[i + 1]);
    }
    int j = 1, mi = INT_MAX, ma = INT_MIN;
    for (int i = 1; i <= n; i++) {
      while (j <= n && a[j][0] - a[i][0] < x) {
        j++;
      }
      if (j > n) break;
      mi = min(mi, a[i][1]);
      ma = max(ma, a[i][1]);
      if (abs(mi - ri_ma[j]) >= x) return true;
      if (abs(ma - ri_mi[j]) >= x) return true;
    }
    return false;
  };
  int l = 0, r = 1e9, ans = 0;
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(x)) {
      l = x + 1;
      ans = x;
    }
    else r = x - 1;
  }
  cout << ans << '\n';
}
