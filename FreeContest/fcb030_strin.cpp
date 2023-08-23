#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MOD = 1e9 + 7;

long long dp[N][5];

int main() {
  int n; cin >> n;
  dp[1][0] = dp[1][1] = dp[1][2] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= 2; j++)
    for (int k = 0; k <= 2; k++) {
      (dp[i][j] += dp[i - 1][k]) %= MOD;
    }
    dp[i][1] = (dp[i][1] - dp[i - 1][1] + MOD) % MOD;
  }
  cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << '\n';
}
