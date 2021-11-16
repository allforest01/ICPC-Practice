#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  long long g = gcd(a, b);
  return a / g * b;
}

void Main() {
  long long n; cin >> n;
  long long ans = 0, t = 1;
  for (int i = 1; i <= 40; i++) {
    t = lcm(t, i);
    long long a = n / t;
    long long b = n / lcm(t, i + 1);
    (ans += (((a - b) % MOD) * (i + 1)) % MOD) %= MOD;
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
