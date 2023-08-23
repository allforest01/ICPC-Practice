#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long pow(long long a, long long b) {
  if (b == 0) return 1;
  long long t = pow(a, b / 2);
  t = (t * t) % MOD;
  if (b % 2) return (t * a) % MOD;
  return t;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n, p;
  cin >> n >> p;
  cout << (pow(p - 2, n - 1) * (p - 1)) % MOD << '\n';
}
