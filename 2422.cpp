#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  int l = 1, r = 1e12, ans = -1;
  auto check = [&](int x) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += min(x / i, n);
    }
    return cnt >= (n * n) / 2 + 1;
  };
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      r = x - 1;
    }
    else l = x + 1;
  }
  cout << ans << '\n';
}
