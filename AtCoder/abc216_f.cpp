#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5001;
const int MOD = 998244353;

int a[N], b[N];
int dp[N][N];
vector<int> ma[N];

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    ma[a[i]].push_back(b[i]);
  }
  int ans = 0;
  dp[0][0] = 1;
  for (int i = 1; i < N; i++)
  for (int j = 0; j < N; j++) {
    dp[i][j] = dp[i - 1][j];
    for (auto &k : ma[i]) {
      if (j >= k) {
        (dp[i][j] += dp[i - 1][j - k]) %= MOD;
        if (i >= k) {
          (ans += dp[i][j - k]) %= MOD;
          if (dp[i][j - k]) {
            cout << i << ' ' << k << ' ' << j << '\n';
          }
        }
      }
    }
  }
  cout << ans << '\n';
}
