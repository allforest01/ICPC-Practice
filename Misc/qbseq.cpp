#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int a[N], dp[N][55];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= k;
  }
  dp[0][0] = 0;
  for (int i = 1; i < k; i++) {
    dp[0][i] = -1e9;
  }
  for (int i = 1; i <= n; i++)
  for (int j = 0; j < k; j++) {
    dp[i][j] = max(dp[i - 1][j],
    dp[i - 1][(j - a[i] + k) % k] + 1);
  }
  cout << dp[n][0] << '\n';
}