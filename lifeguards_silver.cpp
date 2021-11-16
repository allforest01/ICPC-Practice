#include <bits/stdc++.h>
using namespace std;

#define int long long

void chmax(int &a, int b) {
  if (a < b) a = b;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("lifeguards.in" , "r", stdin );
  freopen("lifeguards.out", "w", stdout);
  int n; cin >> n;
  vector<pair<int,int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin() + 1, a.end());
  vector<vector<int>> lp(n + 1, vector<int>(2));
  vector<vector<int>> dp(n + 1, vector<int>(2));
  int ans = 0;
  dp[0][1] = INT_MIN;
  for (int i = 1; i <= n; i++) {
    lp[i][0] = max(lp[i - 1][0], a[i].first);
    dp[i][0] = dp[i - 1][0] + max(a[i].second - lp[i][0], 0LL);
    chmax(lp[i][0], a[i].second);
    int p1 = INT_MAX; if (i >= 2) p1 = max(lp[i - 2][0], a[i].first);
    int d1 = INT_MIN; if (i >= 2) d1 = dp[i - 2][0] + max(a[i].second - p1, 0LL);
    int p2 = max(lp[i - 1][1], a[i].first);
    int d2 = dp[i - 1][1] + max(a[i].second - p2, 0LL);
    if (d1 > d2) {
      chmax(lp[i][1], max(p1, a[i].second));
      dp[i][1] = d1;
    }
    else {
      chmax(lp[i][1], max(p2, a[i].second));
      dp[i][1] = d2;
    }
    ans = max(ans, dp[i][1]);
  }
  cout << ans << '\n';
}
