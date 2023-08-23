#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n + 1), dp(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    dp[i] = abs(a[i] - a[i - 1]) + dp[i - 1];
    if (i > 2) dp[i] = min(dp[i], abs(a[i] - a[i - 2]) + dp[i - 2]);
  }
  cout << dp[n] << '\n';
}
