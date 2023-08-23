#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string a;
  cin >> a;
  string b = a;
  reverse(b.begin(), b.end());
  int n = a.size();
  a = '#' + a;
  b = '#' + b;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
    else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  }
  int i = n, j = n;
  string res;
  while (i > 0 && j > 0) {
    if (a[i] == b[j]) {
      res += a[i];
      i--;
      j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1]) i--;
    else j--;
  }
  cout << res << '\n';
}
