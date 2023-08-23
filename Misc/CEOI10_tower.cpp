#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1000005;
const int MOD = 1e9 + 9;

int a[N], dp[N];

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, d;
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, greater<int>());
  dp[0] = 1;
  for (int i = 1, j = 1; i <= n; i++) {
    while (a[j] > a[i] + d) j++;
    dp[i] += (dp[i - 1] * (i - j + 1)) % MOD;
    dp[i] %= MOD;
  }
  cout << dp[n] << '\n';
}
