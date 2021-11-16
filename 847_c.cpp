#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int p = 0, s = 0;
  while (s + (p + 1) <= k) s += (++p);
  int m = k - s;
  int sum = p + 1 + (m != 0);
  if (n < sum) {
    cout << "Impossible" << '\n';
    return 0;
  }
  string res;
  for (int i = 0; i < p; i++) {
    if (m - 1 == i) res += "()";
    res += '(';
  }
  for (int i = 0; i < p; i++) {
    res += ')';
  }
  res = '(' + res + ')';
  for (int i = 0; i < n - sum; i++) {
    res += "()";
  }
  cout << res << '\n';
}
