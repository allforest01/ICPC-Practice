#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(5));
  for (auto &i : a) for (auto &j : i) cin >> j;
  auto check = [&](int m) {
    vector<int> v(n), ch(1 << 5);
    ch[0] = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        if (a[i][j] >= m) v[i] ^= (1 << j);
      }
      for (int j = v[i]; j; j = (j - 1) & v[i]) {
        ch[j] = true;
      }
    }
    for (int i = 0; i + 1 < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (ch[((1 << 5) - 1) ^ (v[i] | v[j])]) return true;
    }
    return false;
  };
  int l = 1, r = 1e9, ans = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(m)) {
      ans = m;
      l = m + 1;
    }
    else r = m - 1;
  }
  cout << ans << '\n';
}
