#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long mod(long long x) {
  return (x % MOD + MOD) % MOD;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    sum = mod(sum * 2 + a[i - 1]);
    ans += mod(a[i] * mod(sum + a[i]));
    ans %= MOD;
  }
  cout << ans << '\n';
}
