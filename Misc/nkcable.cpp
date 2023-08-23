#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 2; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(2, 1e9));
  dp[1][0] = 0;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = dp[i - 1][1];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
  }
  cout << dp[n][1] << '\n';
}
