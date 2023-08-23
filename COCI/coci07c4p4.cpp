#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t, n;
  cin >> t >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(t + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= t; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= a[i] && dp[i - 1][j - a[i]]) {
        dp[i][j] = 1;
      }
    }
  }
  int in = n, it = t;
  vector<int> d(n + 1, -1);
  while (!dp[in][it] && it > 0) it--;
  while (it > 0) {
    if (dp[in][it] == dp[in - 1][it]) in--;
    else {
      d[in] = it - a[in];
      it -= a[in];
      in--;
    }
  }
  int s = 0;
  for (int i = 1; i <= n; i++) {
    if (d[i] == -1) {
      d[i] = s;
      s += a[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << d[i] << ' ';
  }
  cout << '\n';
}
