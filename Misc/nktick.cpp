#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> t(n + 1), r(n + 1), dp(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  for (int i = 2; i <= n; i++) {
    cin >> r[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + t[i];
    if (i >= 2) dp[i] = min(dp[i], dp[i - 2] + r[i]);
  }
  cout << dp[n] << '\n';
}
