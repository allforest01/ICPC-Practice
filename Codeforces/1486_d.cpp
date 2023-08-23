#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1, r = n, ans = -1;
  auto check = [&](int x) {
    vector<int> d(n + 1);
    set<int> s;
    for (int i = 1; i <= n; i++) {
      d[i] = d[i - 1] + (a[i] >= x ? 1 : -1);
      if (i - k >= 0) {
        s.insert(d[i - k]);
        if (d[i] - *s.begin() > 0) return true;
      }
    }
    return false;
  };
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
