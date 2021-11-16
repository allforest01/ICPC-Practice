#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll mod(ll x) {
  return (x % MOD + MOD) % MOD;
}

ll binPow(ll a, ll b) {
  if (b == 0) return 1;
  ll t = binPow(a, b / 2);
  t = mod(t * t);
  if (b % 2) return mod(t * a);
  return t;
}

ll modDiv(ll a, ll b) {
  return mod(a * binPow(b, MOD - 2));
}

ll fact(ll n) {
  ll ret = 1;
  for (ll i = 1; i <= n; i++) {
    ret = mod(ret * i);
  }
  return ret;
}

ll comb(ll n, ll r) {
  return modDiv(fact(n), mod(fact(r) * fact(n - r)));
}

int Main() {
  int n;
  string s;
  cin >> n >> s;
  ll zero = 0, pairOne = 0;
  vector<bool> blocked(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') zero++;
    if (i > 0 && !blocked[i - 1] && s[i - 1] == '1' && s[i] == '1') {
      pairOne++;
      blocked[i] = 1;
    }
  }
  cout << comb(pairOne + zero, pairOne) << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
