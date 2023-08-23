#include <bits/stdc++.h>
using namespace std;

#define int long long

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void Main() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> lmin(n + 1), rmin(n + 1);
  for (int i = 1; i <= n; i++) {
    int j = i - 1;
    while (j >= 1 && a[j] > a[i]) j = lmin[j];
    lmin[i] = j;
  }
  for (int i = n; i >= 1; i--) {
    int j = i + 1;
    while (j <= n && a[j] > a[i]) j = rmin[j];
    rmin[i] = j;
  }
  vector<int> lmax(n + 1), rmax(n + 1);
  for (int i = 1; i <= n; i++) {
    int j = i - 1;
    while (j >= 1 && a[j] < a[i]) j = lmax[j];
    lmax[i] = j;
  }
  for (int i = n; i >= 1; i--) {
    int j = i + 1;
    while (j <= n && a[j] < a[i]) j = rmax[j];
    rmax[i] = j;
  }
  vector<int> dp(n + 1, n + 1);
  for (int i = 1; i <= n; i++) {
    chmin(dp[lmin[i]], rmax[i]);
    chmin(dp[lmax[i]], rmin[i]);
  }
  int ans = n * (n + 1) / 2;
  for (int i = n; i >= 1; i--) {
    if (i < n) chmin(dp[i], dp[i + 1]);
    ans -= (n + 1) - dp[i];
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
