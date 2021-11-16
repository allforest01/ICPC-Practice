#include <bits/stdc++.h>
using namespace std;

#define taskname "CARRAYS"

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

#define int long long

const int N = 1000005;
const int MOD = 1e9 + 7;

int f[N], s[N];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  f[1] = s[1] = m;
  for (int i = 2; i <= k - 1; i++) {
    f[i] = (f[i - 1] * m) % MOD;
    s[i] = (s[i - 1] + f[i]) % MOD;
  }
  for (int i = k; i <= n; i++) {
    f[i] = ((m - 1) * (s[i - 1] - s[i - k] + MOD)) % MOD;
    s[i] = (s[i - 1] + f[i]) % MOD;
  }
  int all = 1;
  for (int i = 1; i <= n; i++) {
    (all *= m) %= MOD;
  }
  cout << (all - f[n] + MOD) % MOD << '\n';
}

signed main() {
  ioset();
  solve();
}

