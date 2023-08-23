#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll binpow(ll a, ll b) {
  if (b == 0) return 1;
  ll t = binpow(a, b / 2);
  if (t == -1 || t > 1e9) return -1;
  t = t * t;
  if (b % 2) return t * a;
  return t;
}

bool isPrime(ll x) {
  if (x <= 1) return false;
  for (ll i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  ll n; cin >> n;
  for (ll i = 2; i <= 60; i++) {
    ll t = exp(log(n) / i);
    for (ll j = max(0ll, t - 10); j <= t + 10; j++) {
      if (binpow(j, i) == n && isPrime(j)) {
        cout << j << ' ' << i << '\n';
        return 0;
      }
    }
  }
  cout << 0 << '\n';
}
