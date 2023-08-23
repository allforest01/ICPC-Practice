#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = '#' + a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  dp[0][1] = 1;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if (a[i][j] == '#') continue;
    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
  }
  cout << dp[n][m] << '\n';
}