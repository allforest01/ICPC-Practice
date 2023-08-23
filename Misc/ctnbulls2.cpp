#include <bits/stdc++.h>
using namespace std;

const int MOD = 2111992;

const int N = 100005;

int dp[N][5];

signed main() {
  int n, k;
  cin >> n >> k;
  dp[1][0] = dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    if (i > k + 1) {
      dp[i][1] = (dp[i - k - 1][0] + dp[i - k - 1][1]) % MOD;
    }
    else {
      dp[i][1] = 1;
    }
  }
  cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
}