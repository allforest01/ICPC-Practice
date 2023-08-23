#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MOD = 1e9 + 7;

long long a[N], sum[N][2], cnt[N][2];

long long mod(long long x) {
  return (x % MOD + MOD) % MOD;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sum[1][0] = a[1];
  cnt[1][0] =    1;
  for (int i = 2; i <= n; i++) {
    cnt[i][0] = mod(cnt[i - 1][0] + cnt[i - 1][1]);
    cnt[i][1] =     cnt[i - 1][0];
    sum[i][0] = mod(mod(  a[i] * cnt[i][0]) + sum[i - 1][0] + sum[i - 1][1]);
    sum[i][1] = mod(mod(- a[i] * cnt[i][1]) + sum[i - 1][0]);
  }
  cout << mod(sum[n][0] + sum[n][1]) << '\n';
}
