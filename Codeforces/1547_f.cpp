#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  vector<int> a(n);
  vector<vector<int>> sp(n * 2, vector<int>(20));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sp[i][0] = sp[i + n][0] = a[i];
  }
  for (int j = 1; j < 20; j++) {
    for (int i = 0; i + (1 << j) - 1 < 2 * n; i++) {
      sp[i][j] = __gcd(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
      // cout << "i j sp[i][j] = " << i << ' ' << j << ' ' << sp[i][j] << '\n';
    }
  }
  auto get = [&](int p, int len) -> int {
    int d = 0;
    while ((1 << (d + 1)) <= len) d++;
    return __gcd(sp[p][d], sp[p + len - (1 << d)][d]);
  };
  auto check = [&](int cnt) {
    for (int i = 0; i < n; i++) {
      a[i] = get(i, cnt + 1);
    }
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] != a[i + 1]) return 0;
    }
    return 1;
  };
  int l = 0, r = n, ans = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(m)) {
      ans = m;
      r = m - 1;
    }
    else l = m + 1;
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
