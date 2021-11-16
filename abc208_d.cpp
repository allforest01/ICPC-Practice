#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 405;

int dp[N][N];

void chmin(int &a, int b) {
  if (a > b) a = b;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < N; i++)
  for (int j = 0; j < N; j++) {
    if (i == j) dp[i][j] = 0;
    else dp[i][j] = 1e12;
  }
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    dp[u][v] = c;
  }
  int ans = 0;
  for (int k = 1; k <= n; k++)
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    chmin(dp[i][j], dp[i][k] + dp[k][j]);
    if (dp[i][j] < 1e12) ans += dp[i][j];
  }
  cout << ans << '\n';
}
