#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define hash myHash

const int K = 15;
const int N = 3005;

const int BASE = 311;
const ll  MOD  = 1e9 + 7;

int n, q; string s;
ll hash[N], basePow[N];
int ans[K], f[N][N], dp[2][N][N];

ll getHash(int l, int r) {
  return (hash[r] - (hash[l - 1] * basePow[r - l + 1]) % MOD + MOD) % MOD;
}

void chmax(int &a, int b) {
  if (a < b) a = b;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> q >> s;
  n = s.size();
  s = '#' + s;
  basePow[0] = 1;
  for (int i = 1; i <= n; i++) {
    hash[i] = (hash[i - 1] * BASE + s[i]) % MOD;
    basePow[i] = (basePow[i - 1] * BASE) % MOD;
  }
  for (int i = 1; i + 1 <= n; i++)
  for (int j = i + 1; j <= n; j++) {
    int l = 1, r = n - j + 1;
    while (l <= r) {
      int x = (l + r) / 2;
      if (i + x - 1 <= n && j + x - 1 <= n
        && getHash(i, i + x - 1) == getHash(j, j + x - 1)) {
          f[i][j] = dp[0][i][j] = x;
          l = x + 1;
      }
      else r = x - 1;
    }
    if (f[i][j] >= j - i) chmax(ans[0], j - i);
  }
  for (int k = 1; k <= 10; k++) {
    for (int i = 1; i + 1 <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      int len = dp[(k + 1) % 2][i][j];
      int si = i + len;
      int sj = j + len;
      if (si > n || sj > n) {
        dp[k % 2][i][j] = dp[(k + 1) % 2][i][j];
      }
      else {
        dp[k % 2][i][j] = dp[(k + 1) % 2][i][j] + 1 + f[si + 1][sj + 1];
      }
      if (dp[k % 2][i][j] >= j - i) chmax(ans[k], j - i);
    }
  }
  while (q--) {
    int k; cin >> k;
    cout << ans[k] << '\n';
  }
}
