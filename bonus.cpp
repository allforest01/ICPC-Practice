#include <bits/stdc++.h>
using namespace std;

const int N = 4005;

int a[N], dp[N][N];

int main() {
  int n, d;
  cin >> n >> d;
  for (int i = 1; i <= n * 2; i++) {
    cin >> a[i];
  }
  for (int k = 2; k <= n * 2; k++) {
    for (int i = 1; i + k - 1 <= n * 2; i++) {
      int j = i + k - 1;
      if (abs(a[i] - a[j]) <= d) {
        dp[i][j] = dp[i + 1][j - 1] + 1;
      }
      else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << dp[1][n * 2] << '\n';
}
