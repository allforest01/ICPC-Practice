#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int a[N][N], dp[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    a[l][r]++;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i + k - 1 <= n; i++) {
      int j = i + k - 1;
      dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + a[i][j];
    }
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << dp[l][r] << '\n';
  }
}
