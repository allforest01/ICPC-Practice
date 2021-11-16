#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, m, l;
  cin >> n >> m >> l;
  vector<array<int,3>> a(n);
  for (auto &i : a) {
    cin >> i[0] >> i[1] >> i[2];
  }
  int ans = 2e9;
  for (int mask = 0; mask < (1 << n); mask++) {
    int sl = 0, sr = 0, sp = 0;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        sl += a[i][0];
        sr += a[i][1];
        sp += a[i][2];
      }
    }
    if (sl <= l && l <= sr) {
      ans = min(ans, sp);
    }
  }
  if (ans == 2e9 || ans > m) {
    cout << "IMPOSSIBLE" << '\n';
  }
  else cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    Main();
  }
}
