#include <bits/stdc++.h>
using namespace std;

#define taskname "KMULT"

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

const int N = 10005;
const int K = 105;

int n, k;
int a[N], dp[N][K];

void input() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = (a[i] % k + k) % k;
  }
}

void optimize() {
  dp[1][a[1]] = 1;
  for (int i = 2; i <= n; i++)
  for (int j = 0; j < k; j++) {
    dp[i][j] = dp[i - 1][(j + a[i]) % k] || dp[i - 1][(j - a[i] + k) % k];
  }
  cout << dp[n][0] << '\n';
}

void trace() {
  string res;
  int i = n, j = 0;
  while (i > 1) {
    if (dp[i - 1][(j + a[i]) % k]) {
      res += '-';
      j = (j + a[i]) % k;
    }
    else {
      res += '+';
      j = (j - a[i] + k) % k;
    }
    i--;
  }
  reverse(res.begin(), res.end());
  cout << res << '\n';
}

signed main() {
  ioset();
  input();
  optimize();
  if (dp[n][0]) trace();
}
