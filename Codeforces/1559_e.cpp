#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998244353;

const int N = 1e5;

int l[51], r[51], cnt[N + 1];

int mod(int x) {
  return (x % MOD + MOD) % MOD;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  for (int j = 1; j <= N; j++) {
    int s = m;
    vector<int> a(n + 1);
    bool skip = 0;
    for (int i = 1; i <= n; i++) {
      a[i] = r[i] / j - (l[i] - 1) / j - 1;
      s -= (l[i] + j - 1) / j * j;
      if (a[i] == -1) {
        skip = 1;
        break;
      }
    }
    if (s < 0 || skip) continue;
    int t = s / j;
    vector<vector<int>> dp(n + 1, vector<int>(t + 1)), sum(n + 1, vector<int>(t + 1));
    dp[0][0] = 1;
    for (int j = 0; j <= t; j++) {
      sum[0][j] = 1;
    }
    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= t; j++) {
      (dp[i][j] += sum[i - 1][j]) %= MOD;
      if (j > a[i]) {
        dp[i][j] -= sum[i - 1][j - a[i] - 1];
        dp[i][j] = mod(dp[i][j]);
      }
      sum[i][j] = dp[i][j];
      if (j) (sum[i][j] += sum[i][j - 1]) %= MOD;
    }
    for (int i = 0; i <= t; i++) {
      (cnt[j] += dp[n][i]) %= MOD;
    }
  }
  for (int i = N; i >= 2; i--) {
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        cnt[j] -= cnt[i];
        cnt[j] = mod(cnt[j]);
        if (j != 1 && j * j != i) {
          cnt[i / j] -= cnt[i];
          cnt[i / j] = mod(cnt[i / j]);
        }
      }
    }
  }
  cout << cnt[1] << '\n';
}
