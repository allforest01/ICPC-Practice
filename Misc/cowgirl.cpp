#include <bits/stdc++.h>
using namespace std;

int dp[35][70];

int BIT(int k) {
  return (1 << k);
}

bool BIT(int n, int k) {
  return (n & (1 << k));
}

void Main() {
  memset(dp, 0, sizeof(dp));
  int n, m;
  cin >> n >> m;
  if (m > n) swap(n, m);
  for (int j = 0; j < BIT(m); j++) {
    dp[1][j] = 1;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < BIT(m); j++) {
      for (int k = 0; k < BIT(m); k++) {
        bool ok = 1;
        for (int l = 1; l < m; l++) {
          if (BIT(j, l) == BIT(j, l - 1) && BIT(j, l) == BIT(k, l)
          && BIT(j, l) == BIT(k, l - 1)) {
            ok = 0;
            break;
          }
        }
        if (!ok) continue;
        dp[i][j] += dp[i - 1][k];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < BIT(m); i++) {
    ans += dp[n][i];
  }
  cout << ans << '\n';
}

int main() {
  int T; cin >> T;
  while (T--) Main();
}