#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int N = 105;

int a[N][N], dp[N][N];

void chmax(int &a, int b) {
  if (a < b) a = b;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
  }
  int ans = INT_MIN;
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      dp[i][j] = a[i][j] + dp[i][j - 1];
      if (i > 1) chmax(dp[i][j],  a[i][j] + dp[i - 1][j - 1]);
      if (i < n) chmax(dp[i][j],  a[i][j] + dp[i + 1][j - 1]);
      if (j == m) chmax(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
}
