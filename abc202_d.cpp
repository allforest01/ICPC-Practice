#include <bits/stdc++.h>
using namespace std;

long long fact(long long x) {
  long long ret = 1;
  for (long long i = 1; i <= x; i++) {
    ret *= i;
  }
  return ret;
}

long long comb(long long n, long long k) {
  long long ret = 1;
  k = min(k, n - k);
  for (long long i = 1; i <= k; i++) {
    ret = ret * (n - k + i);
    ret = ret / i;
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long a, b, s;
  cin >> a >> b >> s;
  long long k = a + b;
  s--;
  vector<long long> pos(b + 1);
  for (long long i = 1; i <= b; i++) {
    for (long long j = pos[i - 1] + 1; j <= k - (b - i); j++) {
      long long tk = k - j;
      long long tb = b - (i - 1);
      long long cl = (tk >= tb) ? comb(tk, tb) : 0;
      if (tb < 0 || s >= cl) {
        pos[i] = j;
        s = s - cl;
        break;
      }
    }
  }
  vector<char> res(k + 1, 'a');
  for (int i = 1; i <= b; i++) {
    res[pos[i]] = 'b';
  }
  for (int i = 1; i <= k; i++) {
    cout << res[i];
  }
  cout << '\n';
}
