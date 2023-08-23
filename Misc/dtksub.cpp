#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct strHash {
  ll Base, Mod; vector<ll> Hash, bPow;
  void init(string s, ll _Base, ll _Mod) {
    Base = _Base; Mod = _Mod;
    int n = s.size();
    Hash.resize(n); bPow.resize(n);
    Hash[0] = s[0]; bPow[0] = 1;
    for (int i = 1; i < n; i++) {
      Hash[i] = (Hash[i - 1] * Base + s[i]) % Mod;
      bPow[i] = (bPow[i - 1] * Base) % Mod;
    }
  }
  ll get(int l, int r) {
    if (l == 0) return Hash[r];
    return (Hash[r] - (Hash[l - 1] * bPow[r - l + 1]) % Mod + Mod) % Mod;
  }
};

int n, k; string s;
strHash hash1;

bool check(int x) {
  map<ll,int> cnt;
  for (int i = 0; i + x - 1 < n; i++) {
    if (++cnt[hash1.get(i, i + x - 1)] == k) return true;
  }
  return false;
}

int main() {
  cin >> n >> k >> s;
  hash1.init(s, 311, 1e9 + 7);
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      l = x + 1;
    }
    else r = x - 1;
  }
  cout << ans << '\n';
}
