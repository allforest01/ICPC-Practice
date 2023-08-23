#include <bits/stdc++.h>
using namespace std;

#define Bit(x, k) (((x) >> (k)) & 1)

const int MOD = 1e9 + 7;

const int N = 105;
const int M = 15;

int n, m, k;
int a[N][M], dp[N][M];

int check(int mask) {
  for (int i = 0; i + 2 < m; i++)  {
    if (Bit(mask, i) && Bit(mask, i + 1)) return 0;
  }
  return 1;
}

int get(int mask, int j) {
  if (j > 0 && Bit(mask, j - 1)) return j - 1;
  if (j < m && Bit(mask, j)) return j + 1;
  return j;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      for (int mask = 0; mask < (1 << (m - 1)); mask++) {
        if (check(mask)) {
          (dp[i][j] += dp[i - 1][get(mask, j)]) %= MOD;
        }
      }
    }
  }
  cout << dp[n][k - 1] << '\n';
}
