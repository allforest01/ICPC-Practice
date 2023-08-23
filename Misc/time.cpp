#include <bits/stdc++.h>
using namespace std;

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> nums(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
  }
  vector<array<int,2>> edges(n);
  for (auto &e : edges) {
    cin >> e[0] >> e[1];
  }
  int ans = 0;
  vector<int> dp(n + 1, 1e9); dp[1] = 0;
  for (int day = 1; day <= 1000; day++) {
    vector<int> cur_dp(n + 1, 1e9);
    for (auto &e : edges) {
      chmax(cur_dp[e[0]], dp[e[1]] + nums[e[0]]);
      chmax(cur_dp[e[1]], dp[e[0]] + nums[e[1]]);
    }
    for (int i = 1; i <= n; i++) {
      chmax(ans, dp[i] - c * day * day);
    }
  }
  cout << ans << '\n';
}
