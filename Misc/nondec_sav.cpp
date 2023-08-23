#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
const int K = 25;
const int MOD = 1e9 + 7;

int n, k;
int a[N], dat[K][N][K], mask[N], dp[N][K];

void divi(int l, int r, int lev) {
  if (l == r) return;
  int m = (l + r) / 2;
  for (int t = 1; t <= k; t++) {
    for (int i = l; i <= r; i++) {
      memset(dp[i], 0, sizeof(dp[i]));
    }
    if (a[m] == t) dp[m][t] = dat[lev][m][t] = 1;
    for (int i = m - 1; i >= l; i--) {
      if (a[i] == t) dp[i][t]++;
      for (int j = k; j >= 1; j--) {
        (dp[i][j] += dp[i + 1][j]) %= MOD;
        if (j >= a[i]) {
          (dp[i][a[i]] += dp[i + 1][j]) %= MOD;
        }
        (dat[lev][i][t] += dp[i][j]) %= MOD;
      }
    }
    if (a[m + 1] == t) dp[m + 1][t] = dat[lev][m + 1][t] = 1;
    for (int i = m + 2; i <= r; i++) {
      if (a[i] == t) dp[i][t]++;
      for (int j = 1; j <= k; j++) {
        (dp[i][j] += dp[i - 1][j]) %= MOD;
        if (j <= a[i]) {
          (dp[i][a[i]] += dp[i - 1][j]) %= MOD;
        }
        (dat[lev][i][t] += dp[i][j]) %= MOD;
      }
    }
  }
  for (int i = l; i <= m; i++)
  for (int t = 1; t <= k; t++) {
    (dat[lev][i][t] += dat[lev][i][t - 1]) %= MOD;
  }
  for (int i = m + 1; i <= r; i++) {
    mask[i] ^= (1 << lev);
  }
  divi(l, m, lev + 1);
  divi(m + 1, r, lev + 1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("nondec.in" , "r", stdin );
  freopen("nondec.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  divi(1, n, 0);
  int q; cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << 2 << '\n';
    }
    else {
      int ans = 1, bits = __builtin_ctz(mask[l] ^ mask[r]);
      (ans += dat[bits][l][k]) %= MOD;
      for (int i = 1; i <= k; i++) {
        (ans += dat[bits][r][i]) %= MOD;
      }
      for (int i = 1; i <= k; i++) {
        (ans += ((long long) dat[bits][l][i] * dat[bits][r][i]) % MOD) %= MOD;
      }
      cout << ans << '\n';
    }
  }
}