#include <bits/stdc++.h>
using namespace std;

int main() {
  // input
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (auto &i : v) {
    cin >> i;
    i %= m;
  }
  sort(v.begin(), v.end());
  // compress
  vector<int> a, c;
  for (int i = 0; i < n; i++) {
    if (!a.size() || a.back() != v[i]) {
      a.push_back(v[i]);
      c.push_back(1);
    }
    else c.back()++;
  }
  n = a.size();
  // dynamic programing
  vector<vector<long long>> dp(3, vector<long long>(m));
  for (int i = 0; i < n; i++) {
    dp[0][a[i]] = c[i];
  }
  for (int k = 0; k <= 1; k++) {
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        dp[k + 1][(j * a[i]) % m] += dp[k][j] * c[i];
      }
    }
  }
  cout << dp[2][0] << '\n';
}
