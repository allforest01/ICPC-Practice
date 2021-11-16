#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int a[N][N], dp[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= i; j++) {
    cin >> a[i][j];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
    if (i == n) ans = max(ans, dp[i][j]);
  }
  cout << ans << '\n';
}
