#include <bits/stdc++.h>
using namespace std;

const int MOD = 14062008;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<bool> broken(n + 1);
  for (int i = 1; i <= k; i++) {
    int x; cin >> x;
    broken[x] = true;
  }
  vector<int> dp(n + 1);
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (broken[i]) continue;
    (dp[i] += dp[i - 1]) %= MOD;
    if (i > 2) (dp[i] += dp[i - 2]) %= MOD;
  }
  cout << dp[n] << '\n';
}
