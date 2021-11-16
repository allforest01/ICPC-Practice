#include <bits/stdc++.h>
using namespace std;

#define int long long

const int BASE = 331;
const int MOD = 1e9 + 7;

int modpow(int a, int b) {
  if (b == 0) return 1;
  int t = modpow(a, b / 2);
  t = (t * t) % MOD;
  if (b % 2) return (t * a) % MOD;
  return t;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  string s;
  cin >> s;
  s = '#' + s + '#';
  vector<int> hash(n + 1);
  for (int i = 1; i <= n; i++) {
    hash[i] = (hash[i - 1] * BASE + s[i]) % MOD;
  }
  reverse(s.begin(), s.end());
  vector<int> hrev(n + 1);
  for (int i = 1; i <= n; i++) {
    hrev[i] = (hrev[i - 1] * BASE + s[i]) % MOD;
  }
  auto getHash = [](vector<int> &hash, int l, int r) {
    return (hash[r] - hash[l - 1] * modpow(BASE, r - l + 1) + MOD * MOD) % MOD;
  };
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    {
      int l = 1, r = min(i, n - i + 1);
      while (l <= r) {
        int x = (l + r) / 2;
        int lf = getHash(hash, i - x + 1, i);
        int ri = getHash(hrev, n - (i + x - 1) + 1, n - i + 1);
        if (lf == ri) {
          ans = max(ans, x * 2 - 1);
          l = x + 1;
        }
        else r = x - 1;
      }
    }
    {
      int l = 1, r = min(i, n - i);
      while (l <= r) {
        int x = (l + r) / 2;
        int lf = getHash(hash, i - x + 1, i);
        int ri = getHash(hrev, n - (i + x) + 1, n - (i + 1) + 1);
        if (lf == ri) {
          ans = max(ans, x * 2);
          l = x + 1;
        }
        else r = x - 1;
      }
    }
  }
  cout << ans << '\n';
}
