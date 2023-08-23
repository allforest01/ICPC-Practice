#include <bits/stdc++.h>
using namespace std;

#define ar array
#define int long long

int mod(int x, int MOD) {
  return (x % MOD + MOD) % MOD;
}

int modpow(int a, int b, int MOD) {
  if (b == 0) return 1;
  int t = modpow(a, b / 2, MOD);
  t = (t * t) % MOD;
  if (b % 2) return (t * a) % MOD;
  return t;
}

int modinv(int x, int MOD) {
  return modpow(x, MOD - 2, MOD);
}

struct strHash {
  const int BASE = 9937;
  const int MOD1 = 1e9 + 7;
  const int MOD2 = 1e9 + 9;

  int n; vector<int> hash1, hash2;
  strHash(string s) {
    n = s.size();
    s = '#' + s;
    hash1.resize(n + 1); hash1[0] = 1;
    hash2.resize(n + 1); hash2[0] = 1;
    for (int i = 1; i <= n; i++) {
      hash1[i] = (hash1[i - 1] * (BASE + s[i])) % MOD1;
      hash2[i] = (hash2[i - 1] * (BASE + s[i])) % MOD2;
    }
  }
  ar<int,2> get(int l, int r) {
    l++; r++;
    return {
      (hash1[r] * modinv(hash1[l - 1], MOD1)) % MOD1,
      (hash2[r] * modinv(hash2[l - 1], MOD2)) % MOD2
    };
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  string a, b;
  cin >> a >> b;
  int sz_a = a.size(), sz_b = b.size();
  strHash hash_a(a), hash_b(b);
  int ans = 0;
  for (int i = 0; i + sz_a - 1 < sz_b; i++) {
    if (hash_b.get(i, i + sz_a - 1) == hash_a.get(0, sz_a - 1)) {
      ans++;
      cout << i << '\n';
    }
  }
  cout << ans << '\n';
}
