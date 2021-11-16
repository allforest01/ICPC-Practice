#include <bits/stdc++.h>
using namespace std;

void chmin(int &a, int b) {
  if (a > b) a = b;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), dp(n + 1, 2e9);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[1] = 0;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= k; j++) {
    if (i + j > n) break;
    chmin(dp[i + j], abs(a[i + j] - a[i]) + dp[i]);
  }
  cout << dp[n] << '\n';
}
