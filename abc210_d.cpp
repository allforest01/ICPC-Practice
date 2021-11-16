#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

long long a[N][N], dp[N][N];

void chmin(long long &a, long long b) {
  if (a > b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, c;
  cin >> n >> m >> c;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
  }
  long long ans = 1e15;
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + c;
    chmin(ans, a[i][j] + dp[i][j]);
    chmin(dp[i][j], a[i][j]);
  }
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++)
  for (int j = m; j >= 1; j--) {
    dp[i][j] = min(dp[i - 1][j], dp[i][j + 1]) + c;
    chmin(ans, a[i][j] + dp[i][j]);
    chmin(dp[i][j], a[i][j]);
  }
  cout << ans << '\n';
}
