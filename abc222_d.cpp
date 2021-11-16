#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
const int MOD = 998244353;

int a[N], b[N], dp[N][N], sum[N][N];

int main() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int j = 0; j <= 3000; j++) {
    sum[0][j] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = a[i]; j <= b[i]; j++) {
      dp[i][j] = sum[i][j] = sum[i - 1][j];
      if (i == n) (ans += dp[i][j]) %= MOD;
    }
    for (int j = 1; j <= 3000; j++) {
      (sum[i][j] += sum[i][j - 1]) %= MOD;
    }
  }
  cout << ans << '\n';
}