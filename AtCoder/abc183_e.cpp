#include <bits/stdc++.h>
using namespace std;

#define int long long
#define right def_right

const int N = 2005;
const int MOD = 1e9 + 7;

char a[N][N];
int dp[N][N], right[N][N], down[N][N], dig[N][N];

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
  }
  dp[1][1] = right[1][1] = down[1][1] = dig[1][1] = 1;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if ((i == 1 && j == 1) || a[i][j] == '#') continue;
    dp[i][j] = (right[i][j - 1] + down[i - 1][j] + dig[i - 1][j - 1]) % MOD;
    right[i][j] = (dp[i][j] + right[i][j - 1]) % MOD;
    down[i][j]  = (dp[i][j] + down[i - 1][j]) % MOD;
    dig[i][j]   = (dp[i][j] + dig[i - 1][j - 1]) % MOD;
  }
  cout << dp[n][m] << '\n';
}
