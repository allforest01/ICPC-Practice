#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

const int N = 105;
const int K = 100005;

int a[N];
ll dp[N][K], ps[N][K];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][0] = 1;
  for (int j = 0; j <= k; j++) {
    ps[0][j] = 1;
  }
  for (int i = 1; i <= n; i++)
  for (int j = 0; j <= k; j++) {
    dp[i][j] = ps[i - 1][j];
    if (j - a[i] - 1 >= 0) {
      dp[i][j] -= ps[i - 1][j - a[i] - 1];
      if (dp[i][j] < 0) dp[i][j] += MOD;
    }
    ps[i][j] = dp[i][j];
    if (j > 0) {
      ps[i][j] += ps[i][j - 1];
      if (ps[i][j] >= MOD) ps[i][j] -= MOD;
    }
  }
  cout << dp[n][k] << '\n';
}