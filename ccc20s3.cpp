#include <bits/stdc++.h>
using namespace std;

#define int long long

const int BASE = 9973;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

int mod1(int x) {
  return (x % MOD1 + MOD1) % MOD1;
}

int modpow1(int a, int b) {
  if (b == 0) return 1;
  int t = modpow1(a, b / 2);
  t = (t * t) % MOD1;
  if (b % 2) return (t * a) % MOD1;
  return t;
}

int mod2(int x) {
  return (x % MOD2 + MOD2) % MOD2;
}

int modpow2(int a, int b) {
  if (b == 0) return 1;
  int t = modpow2(a, b / 2);
  t = (t * t) % MOD2;
  if (b % 2) return (t * a) % MOD2;
  return t;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  string a, b;
  cin >> a >> b;
  int na = a.size(), nb = b.size();
  a = '#' + a + '#';
  b = '#' + b + '#';
  vector<int> hash1(nb + 1), hash2(nb + 1);
  for (int i = 1; i <= nb; i++) {
    hash1[i] = (hash1[i - 1] * BASE + b[i]) % MOD1;
    hash2[i] = (hash2[i - 1] * BASE + b[i]) % MOD2;
  }
  auto getHash = [&hash1, &hash2](int l, int r)->array<int,2> {
    return {
      mod1(hash1[r] - hash1[l - 1] * modpow1(BASE, r - l + 1)),
      mod2(hash2[r] - hash2[l - 1] * modpow2(BASE, r - l + 1))
    };
  };
  set<array<int,2>> seen;
  vector<int> cnt_a(26), cnt_b(26);
  for (int i = 1; i <= na; i++) {
    cnt_a[a[i] - 'a']++;
  }
  for (int i = 1; i < na; i++) {
    cnt_b[b[i] - 'a']++;
  }
  for (int i = na; i <= nb; i++) {
    if (i > na) cnt_b[b[i - na] - 'a']--;
    cnt_b[b[i] - 'a']++;
    auto t = getHash(i - na + 1, i);
    if (cnt_a == cnt_b) seen.insert(t);
  }
  cout << seen.size() << '\n';
}
