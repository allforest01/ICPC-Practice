#include <bits/stdc++.h>
using namespace std;

#define int long long

void Main() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<array<int, 20>> sp(n + 1);
  for (int i = 1; i < n; i++) {
    sp[i][0] = abs(a[i + 1] - a[i]);
  }
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i + (1 << j) - 1 < n; i++) {
      sp[i][j] = __gcd(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
    }
  }
  auto get = [&](int l, int len)->int {
    int r = l + len - 1, t = 0;
    while ((1 << (t + 1)) <= len) t++;
    return __gcd(sp[l][t], sp[r - (1 << t) + 1][t]);
  };
  auto check = [&](int x)->bool {
    for (int i = 1; i + x - 1 <= n; i++) {
      if (get(i, x - 1) != 1) return true;
    }
    return false;
  };
  int l = 2, r = n, ans = 1;
  while (l <= r) {
    int x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      l = x + 1;
    }
    else r = x - 1;
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
