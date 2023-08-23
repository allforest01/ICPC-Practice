#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b) {
  if (b == 0) return 1;
  ll t = binpow(a, b / 2);
  t = (t * t) % MOD;
  if (b % 2) return (t * a) % MOD;
  return t;
}

ll modinv(ll n) {
  return binpow(n, MOD - 2);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n; cin >> n;
  ll ret = 1;
  for (ll i = 2; i <= n; i++) {
    ret *= ((n + i) * modinv(i)) % MOD;
    ret %= MOD;
  }
  cout << ret << '\n';
}
