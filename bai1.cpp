#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int cnt2[N], cnt5[N], dp[N][N][N * 30];

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    long long x; cin >> x;
    while (x % 2 == 0) {
      x /= 2;
      cnt2[i]++;
    }
    while (x % 5 == 0) {
      x /= 5;
      cnt5[i]++;
    }
  }
  for (int i = 0; i < N; i++)
  for (int j = 0; j < N; j++)
  for (int k = 0; k < N * 30; k++) {
    dp[i][j][k] = -1e9;
  }
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 0; j <= min(i, k); j++)
  for (int l = 0; l <= 30 * n; l++) {
    dp[i][j][l] = dp[i - 1][j][l];
    if (j >= 1 && l >= cnt2[i]) {
      chmax(dp[i][j][l], dp[i - 1][j - 1][l - cnt2[i]] + cnt5[i]);
    }
  }
  int ans = 0;
  for (int l = 0; l <= 30 * n; l++) {
    ans = max(ans, min(l, dp[n][k][l]));
  }
  cout << ans << '\n';
}
