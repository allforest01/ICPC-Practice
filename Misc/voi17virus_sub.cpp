#include <bits/stdc++.h>
using namespace std;

#define hash myHash

typedef long long ll;

const int K = 15;
const int N = 3005;

const int BASE = 311;
const ll  MOD  = 1e9 + 7;

int n, q; string s;
int query[K], ans[K];
ll hash[N], basePow[N];
int f[N][N], dp[2][N][N];

void chmax(int &a, int b) {
  if (a < b) a = b;
}

ll getHash(int l, int r) {
  return (hash[r] - (hash[l - 1] * basePow[r - l + 1]) % MOD + MOD) % MOD;
}

namespace sub1 {
  void Main() {
    for (int i = 1; i + 1 <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (j + (j - i) - 1 > n) continue;
      int cnt = 0;
      for (int k = 1; i + k - 1 < j; k++) {
        if (s[i + k - 1] != s[j + k - 1]) cnt++;
      }
      if (cnt <= 10) chmax(ans[cnt], j - i);
    }
    for (int i = 1; i <= 10; i++) {
      chmax(ans[i], ans[i - 1]);
    }
  }
};

namespace sub2 {
  void Main() {
    for (int i = 1; i + 1 <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      int len = j - i;
      if (j + len - 1 > n) continue;
      if (getHash(i, i + len - 1) == getHash(j, j + len - 1)) {
        chmax(ans[0], j - i);
      }
    }
  }
};

namespace sub3 {
  void Main() {
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
          dp[k % 2][i][j] = len;
        }
        else {
          dp[k % 2][i][j] = len + 1 + f[si + 1][sj + 1];
        }
        if (dp[k % 2][i][j] >= j - i) chmax(ans[k], j - i);
      }
    }
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> q >> s;
  n = s.size();
  s = '#' + s;
  bool all_zero = true;
  for (int i = 1; i <= q; i++) {
    cin >> query[i];
    if (query[i]) all_zero = false;
  }
  basePow[0] = 1;
  for (int i = 1; i <= n; i++) {
    hash[i] = (hash[i - 1] * BASE + s[i]) % MOD;
    basePow[i] = (basePow[i - 1] * BASE) % MOD;
  }
  if (n <= 300) sub1::Main();
  else if (n <= 3000 && all_zero) sub2::Main();
  else sub3::Main();
  for (int i = 1; i <= q; i++) {
    cout << ans[query[i]] << '\n';
  }
}
