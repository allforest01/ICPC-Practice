#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  vector<int> dp(n + 1, -1e9);
  dp[0] = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= k; j++) {
    if (i >= j) {
      dp[i] = max(dp[i], dp[i - j] + a[i]);
      ans = max(ans, dp[i]);
    }
  }
  cout << dp[n] << '\n';
}
