#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int a[N], b[N], dp[N][N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if (a[i] == b[j]) {
      dp[i][j] = 1;
      if (i >= 2 && j >= 2) dp[i][j] += dp[i - 2][j - 2];
    }
    else {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  cout << dp[n][m] << '\n';
}