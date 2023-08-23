#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int a[N][N], dp[N][N];

int min(int a, int b, int c) {
  return min(a, min(b, c));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if (a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1] && a[i][j] == a[i - 1][j - 1]) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
    }
    else dp[i][j] = 1;
    ans = max(ans, dp[i][j]);
  }
  cout << ans << '\n';
}
