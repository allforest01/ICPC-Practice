#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int dp[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string a, b;
  cin >> a >> b;
  int na = a.size(), nb = b.size();
  a = '#' + a;
  b = '#' + b;
  for (int i = 1; i <= na; i++)
  for (int j = 1; j <= nb; j++) {
    if (a[i] == b[j]) {
      dp[i][j] = dp[i - 1][j - 1] + 1;
    }
    else {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  cout << dp[na][nb] << '\n';
}
