#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const ll BASE = 331;

ll mod(ll x) {
  return (x % MOD + MOD) % MOD;
}

ll binpow(ll a, ll b) {
  if (b == 0) return 1LL;
  ll t = binpow(a, b / 2);
  t = mod(t * t);
  if (b % 2) return mod(t * a);
  return t;
}

ll getHash(vector<ll> &hash, int l, int len) {
  int r = l + len - 1;
  return mod(hash[r] - mod(hash[l - 1] * binpow(BASE, len)));
}

void Main() {
  string s, t;
  cin >> s >> t;
  string r = s;
  reverse(r.begin(), r.end());
  int n = s.size(), nt = t.size();
  s = '$' + s;
  t = '$' + t;
  r = '$' + r;
  vector<ll> hash(n + 1), hasht(nt + 1), hashr(n + 1);
  for (int i = 1; i <= n; i++) {
    hash[i] = mod(s[i] + hash[i - 1] * BASE);
  }
  for (int i = 1; i <= nt; i++) {
    hasht[i] = mod(t[i] + hasht[i - 1] * BASE);
  }
  for (int i = 1; i <= n; i++) {
    hashr[i] = mod(r[i] + hashr[i - 1] * BASE);
  }
  /*for (int i = 1; i <= n - 2; i++) {
    cout << s.substr(i, 3) << ' ' << getHash(hash, i, 3) << '\n';
  }
  for (int i = 1; i <= nt - 2; i++) {
    cout << t.substr(i, 3) << ' ' << getHash(hasht, i, 3) << '\n';
  }*/
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= nt; j++) {
      if (i + j - 1 <= n && i + j - 2 - (nt - j) + 1 >= 1) {
        ll fs = getHash(hash, i, j);
        ll ft = getHash(hasht, 1, j);
        int p = i + j - 2;
        int rp = n - p + 1;
        ll ss = getHash(hashr, rp, nt - j);
        ll st = getHash(hasht, 1 + j, nt - j);
        if (fs == ft && ss == st) {
          cout << "YES" << '\n';
          return;
        }
      }
    }
  }
  cout << "NO" << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
