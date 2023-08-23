#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  long long a = 0, b = 0, c = 0, d = 1;
  for (int i = 0; i < s.size(); i++) {
    long long ta, tb, tc;
    if (s[i] == 'A') (a += d) %= MOD;
    if (s[i] == 'B') (b += a) %= MOD;
    if (s[i] == 'C') (c += b) %= MOD;
    if (s[i] == '?') {
      ta = (a * 3 + d) % MOD;
      tb = (b * 3 + a) % MOD;
      tc = (c * 3 + b) % MOD;
      (d *= 3) %= MOD;
      a = ta;
      b = tb;
      c = tc;
    }
  }
  cout << c << '\n';
}
