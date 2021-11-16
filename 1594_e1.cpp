#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long binpow(long long a, long long b) {
  if (b == 0) return 1LL;
  long long t = binpow(a, b / 2);
  t = (t * t) % MOD;
  if (b % 2) return (t * a) % MOD;
  return t;
}

int main() {
  long long n; cin >> n;
  vector<long long> dp(n + 1);
  dp[1] = 6;
  for (long long i = 2; i <= n; i++) {
    dp[i] = (dp[i - 1] * binpow(2, (1LL << i))) % MOD;
  }
  cout << dp[n] << '\n';
}