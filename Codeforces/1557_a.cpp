#include <bits/stdc++.h>
using namespace std;

#define int long long

void Main() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  vector<int> r(n + 2);
  for (int i = n; i >= 1; i--) {
    r[i] = a[i] + r[i + 1];
  }
  double ans = INT_MIN;
  int l = 0;
  for (int i = 1; i < n; i++) {
    l += a[i];
    ans = max(ans, ((double) l / i) + ((double) r[i + 1] / (n - i)));
    // cout << (double) l / i << ' ' << (double) r[i + 1] / (n - i) << '\n';
  }
  cout << setprecision(10) << fixed << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
