#include <bits/stdc++.h>
using namespace std;

void chmin(int &a, int b) {
  if (a > b) a = b;
}

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> w(n + 1), v(n + 1);
  int V = 0;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
    V += v[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(V + 1, 1e9));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 0; j <= V; j++) {
    dp[i][j] = dp[i - 1][j];
    if (j >= v[i]) chmin(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
  }
  while (dp[n][V] > W) V--;
  cout << V << '\n';
}