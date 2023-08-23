#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int c = 0, h = 0, o = 0, k = 0, u = 0, d = 0, a = 0, i = 0;
  for (auto &_ : s) {
    switch (_) {
      case 'c': {
        c++;
        c %= MOD;
        break;
      }
      case 'h': {
        h += c;
        h %= MOD;
        break;
      }
      case 'o': {
        o += h;
        o %= MOD;
        break;
      }
      case 'k': {
        k += o;
        k %= MOD;
        break;
      }
      case 'u': {
        u += k;
        u %= MOD;
        break;
      }
      case 'd': {
        d += u;
        d %= MOD;
        break;
      }
      case 'a': {
        a += d;
        a %= MOD;
        break;
      }
      case 'i': {
        i += a;
        i %= MOD;
        break;
      }
    }
  }
  cout << i << '\n';
}
