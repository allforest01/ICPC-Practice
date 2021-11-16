#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int modpow(int a, int b) {
  if (b == 0) return 1;
  int t = modpow(a, b / 2);
  t = (t * t) % MOD;
  if (b % 2) return (t * a) % MOD;
  return t;
}

void Main() {
  int n, k;
  cin >> n >> k;
  vector<array<int,2>> dp(n + 1);
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
  }
  vector<int> dp2(k + 1);
  dp2[0] = 1;
  for (int i = 1; i <= k; i++) {
    if (n % 2 == 0) {
      dp2[i] = (dp[n][0] - 1) * dp2[i - 1] + modpow(2, (i - 1) * n);
      dp2[i] %= MOD;
    }
    else {
      dp2[i] = dp[n][0] * dp2[i - 1] + dp2[i - 1];
      dp2[i] %= MOD;
    }
  }
  cout << dp2[k] << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
