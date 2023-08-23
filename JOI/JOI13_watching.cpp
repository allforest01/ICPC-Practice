#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, p, q;
  cin >> n >> p >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (n - p - q <= 0) {
    cout << 1 << '\n';
    return 0;
  }
  sort(a.begin() + 1, a.end());
  auto check = [&](int m) {
    vector<vector<int>> dp(n + 1, vector<int>(p + 1, 1e9));
    for (int i = 0; i <= p; i++) {
      dp[0][i] = 0;
    }
    int pp = 1, pq = 1;
    for (int i = 1; i <= n; i++) {
      while (a[i] - a[pp] + 1 >     m) pp++;
      while (a[i] - a[pq] + 1 > 2 * m) pq++;
      dp[i][0] = dp[pq - 1][0] + 1;
      for (int j = 1; j <= p; j++) {
        dp[i][j] = min(dp[pq - 1][j] + 1, dp[pp - 1][j - 1]);
      }
    }
    return (dp[n][p] <= q);
  };
  int l = 1, r = 1e9, ans = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(m)) {
      ans = m;
      r = m - 1;
    }
    else l = m + 1;
  }
  cout << ans << '\n';
}
