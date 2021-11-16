#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
const int K = 25;
const int MOD = 1e9 + 7;

int n, k;
int a[N], dat[K][N][K], mask[N], cnt[K];

void divi(int l, int r, int lev) {
  if (l == r) return;
  int m = (l + r) / 2;
  for (int t = 1; t <= k; t++) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = m; i >= l; i--) {
      for (int j = a[i]; j <= k; j++) {
        (cnt[a[i]] += cnt[j]) %= MOD;
      }
      if (a[i] == t) cnt[t]++;
      for (int j = 1; j <= k; j++) {
        (dat[lev][i][t] += cnt[j]) %= MOD;
      }
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = m + 1; i <= r; i++) {
      for (int j = a[i]; j >= 1; j--) {
        (cnt[a[i]] += cnt[j]) %= MOD;
      }
      if (a[i] == t) cnt[t]++;
      for (int j = 1; j <= k; j++) {
        (dat[lev][i][t] += cnt[j]) %= MOD;
      }
    }
  }
  for (int i = m + 1; i <= r; i++) {
    mask[i] ^= (1 << lev);
  }
  divi(l, m, lev + 1);
  divi(m + 1, r, lev + 1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("nondec.in" , "r", stdin );
  freopen("nondec.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  divi(1, n, 0);
  int q; cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << 2 << '\n';
    }
    else {
      int ans = 1, bits = __builtin_ctz(mask[l] ^ mask[r]);
      for (int i = 1; i <= k; i++) {
        (ans += dat[bits][l][i]) %= MOD;
        (ans += dat[bits][r][i]) %= MOD;
      }
      for (int i = 1; i <= k; i++)
      for (int j = i; j <= k; j++) {
        (ans += ((long long) dat[bits][l][i] * dat[bits][r][j]) % MOD) %= MOD;
      }
      cout << ans << '\n';
    }
  }
}