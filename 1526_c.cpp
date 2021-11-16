#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int N = 2005;

int a[N], dp[N][N];

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++)
  for (int j = 0; j <= n; j++) {
    dp[i][j] = -1e16;
  }
  dp[0][0] = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 0; j <= i; j++) {
    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    if (j >= 1 && dp[i - 1][j - 1] + a[i] >= 0) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i]);
    }
    if (dp[i][j] >= 0) ans = max(ans, j);
  }
  cout << ans << endl;
}
