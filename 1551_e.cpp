#include <bits/stdc++.h>
using namespace std;

void chmax(int &a, int b) {
  if (a < b) a = b;
}

void Main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = INT_MAX;
  vector<vector<int>> dp(n + 1, vector<int>(n + 2));
  for (int i = 1; i <= n; i++)
  for (int j = 0; j <= i; j++) {
    dp[i][j] = dp[i - 1][j] + (a[i] == i - j);
    if (j > 0) chmax(dp[i][j], dp[i - 1][j - 1]);
    if (dp[i][j] >= k) ans = min(ans, j);
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
