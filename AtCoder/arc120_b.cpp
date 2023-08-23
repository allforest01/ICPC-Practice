#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto &i : s) {
    cin >> i;
  }
  int ans = 1;
  for (int i = 0; i < n + m - 1; i++) {
    int ti = min(i, n - 1), tj = max(i - (n - 1), 0LL);
    vector<char> v;
    while (ti >= 0 && tj < m) {
      v.push_back(s[ti][tj]);
      ti--; tj++;
    }
    bool redFlag = 0, blueFlag = 0;
    for (int k = 0; k < (int) v.size(); k++) {
      if (v[k] == 'R') redFlag  = 1;
      if (v[k] == 'B') blueFlag = 1;
    }
    if (redFlag && blueFlag) {
      cout << 0 << '\n';
      return 0;
    }
    if (!redFlag && !blueFlag) {
      (ans *= 2LL) %= 998244353LL;
    }
  }
  cout << ans << '\n';
}
