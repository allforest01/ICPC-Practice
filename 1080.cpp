#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

ll cal(ll n, ll m) {
  if (n == 0 || m == 0) return 0;
  if (n > m) swap(n, m);
  int ret = 1;
  for (int i = 1; i <= n; i++) {
    ret *= m + i;
    ret /= i;
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int n = s.size();
  s = '$' + s;
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
  for (int i = 1; i <= n; i++) {
    dp[i][i - 1] = 1;
  }
  for (int k = 2; k <= n; k++) {
    for (int i = 1; i + k - 1 <= n; i++) {
      int j = i + k - 1;
      if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
      for (int l = i; l < j; l++) {
        if (i == 1 && l == 2 && j == 6) {
          cout << "> " << dp[i][l] << ' ' << dp[l + 1][j] << '\n';
        }
        dp[i][j] += cal(dp[i][l], dp[l + 1][j]) % MOD;
        dp[i][j] %= MOD;
      }
    }
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    cout << dp[i][j] << " \n"[j == n];
  }
}
