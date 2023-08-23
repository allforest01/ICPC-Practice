#include <bits/stdc++.h>
using namespace std;

#define int long long

const int BASE = 331;
const int MOD = 1e9 + 7;

int mod(int x) {
  return (x % MOD + MOD) % MOD;
}

int modpow(int a, int b) {
  if (b == 0) return 1;
  int t = modpow(a, b / 2);
  t = mod(t * t);
  if (b % 2) return mod(t * a);
  return t;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  string sa, sb;
  cin >> sa >> sb;
  int na = sa.size(), nb = sb.size();
  sa = '#' + sa;
  sb = '#' + sb;
  auto genHash = [](string &s, vector<int> &h, int n) {
    for (int i = 1; i <= n; i++) {
      h[i] = mod(h[i - 1] * BASE + s[i]);
    }
  };
  auto getHash = [](vector<int> &h, int l, int r) {
    return mod(h[r]  - mod(h[l - 1] * modpow(BASE, r - l + 1)));
  };
  vector<int> ha(na + 1), hb(nb + 1);
  genHash(sa, ha, na);
  genHash(sb, hb, nb);
  for (int i = 1; i + nb - 1 <= na; i++) {
    if (getHash(ha, i, i + nb - 1) == getHash(hb, 1, nb)) {
      cout << i << ' ';
    }
  }
  cout << '\n';
}
