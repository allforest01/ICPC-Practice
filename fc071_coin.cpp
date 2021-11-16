#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, p;
  cin >> n >> p;
  vector<int> dp(2); dp[0] = 1;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    vector<int> prv_dp = dp;
    if (x % 2) {
      (dp[1] += prv_dp[0]) %= MOD;
      (dp[0] += prv_dp[1]) %= MOD;
    }
    else {
      (dp[0] += prv_dp[0]) %= MOD;
      (dp[1] += prv_dp[1]) %= MOD;
    }
  }
  cout << dp[p] << '\n';
}
