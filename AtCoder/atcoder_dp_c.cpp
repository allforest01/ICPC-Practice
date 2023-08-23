#include <bits/stdc++.h>
using namespace std;

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  int n; cin >> n;
  vector<array<int,4>> a(n + 1), dp(n + 1);
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= 3; j++) {
    cin >> a[i][j];
  }
  for (int j = 1; j <= 3; j++) {
    dp[1][j] = a[1][j];
  }
  for (int i = 2; i <= n; i++)
  for (int j = 1; j <= 3; j++)
  for (int k = 1; k <= 3; k++) {
    if (j == k) continue;
    chmax(dp[i][j], dp[i - 1][k] + a[i][j]);
  }
  cout << max(dp[n][1], max(dp[n][2], dp[n][3])) << '\n';
}