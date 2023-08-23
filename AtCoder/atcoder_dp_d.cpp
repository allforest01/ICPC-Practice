#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void chmax(ll &a, ll b) {
  if (a < b) a = b;
}

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> w(n + 1), v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(W + 1));
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= W; j++) {
    dp[i][j] = dp[i - 1][j];
    if (j >= w[i]) chmax(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
  }
  cout << dp[n][W] << '\n';
}