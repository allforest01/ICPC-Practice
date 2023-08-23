#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ONE(x, k) ((x) | (1 << (k)))
#define XOR(x, k) ((x) ^ (1 << (k)))
#define GET(x, k) (((x) >> (k)) & 1)
#define all(x) (x).begin(),(x).end()

const int N = 2005;
const int MOD = 998244353;

int n, a[N], dp[N][N][20];

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    a[i + 1] = s[i] - 'A';
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][1 << a[i]][a[i]] = 1;
    for (int mask = 0; mask < (1 << 10); mask++) {
      if (!GET(mask, a[i])) continue;
      for (int j = 0; j < 10; j++) {
        if (j == a[i]) continue;
        (dp[i][mask][a[i]] += dp[i - 1][XOR(mask, a[i])][j]) %= MOD;
      }
      (dp[i][mask][a[i]] += dp[i - 1][mask][a[i]]) %= MOD;
    }
    for (int mask = 0; mask < (1 << 10); mask++) {
      for (int j = 0; j < 10; j++) {
        (dp[i][mask][j] += dp[i - 1][mask][j]) %= MOD;
        if (i == n) (ans += dp[i][mask][j]) %= MOD;
      }
    }
  }
  cout << ans << '\n';
}
