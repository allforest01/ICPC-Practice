#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int N = 1005;

int a[N], dp[N];

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      if (a[i] > a[j] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}
