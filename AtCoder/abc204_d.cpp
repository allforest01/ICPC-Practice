#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int S = 100005;

int a[N], dp[N][S];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= a[i] && dp[i - 1][j - a[i]]) dp[i][j] = 1;
    }
  }
  int ans = sum;
  for (int j = 0; j <= sum; j++) {
    if (dp[n][j]) {
      ans = min(ans, max(j, sum - j));
    }
  }
  cout << ans << '\n';
}
