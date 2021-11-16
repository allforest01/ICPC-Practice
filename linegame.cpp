#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

long long a[N], dp[N][2];

int main() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][0] = 0;
  dp[0][1] = -1e12;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - a[i]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i]);
  }
  cout << dp[n][1] << '\n';
}