#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int C = 10005;

int v[N], l[N], dp[N][C];

int main() {
  int c, k, n;
  cin >> c >> k >> n;
  int vmax = 0;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> l[i];
    vmax = max(vmax, v[i]);
  }
  if (vmax > c) {
    cout << 0 << '\n';
    return 0;
  }
  dp[0][0] = 0;
  for (int j = 1; j <= c; j++) {
    dp[0][j] = -1e9;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= c; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= v[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + l[i] * k - v[i]);
    }
  }
  cout << dp[n][c] << '\n';
}