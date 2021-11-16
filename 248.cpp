#include <bits/stdc++.h>
using namespace std;

const int N = 255;

set<int> dp[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("248.in" , "r", stdin );
  freopen("248.out", "w", stdout);
  int n; cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    dp[i][i].insert(x);
    ans = max(ans, x);
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++) {
        for (auto l : dp[i][k]) {
          if (dp[k + 1][j].count(l)) {
            dp[i][j].insert(l + 1);
            ans = max(ans, l + 1);
          }
        }
      }
    }
  }
  cout << ans << '\n';
}
