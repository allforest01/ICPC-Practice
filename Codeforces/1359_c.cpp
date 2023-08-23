#include <bits/stdc++.h>
using namespace std;

#define int long long

void Main() {
  int h, c, t;
  cin >> h >> c >> t;
  int l = 0, r = 1e6, ans = 2;
  int tu = h + c, mau = 2;
  auto myLess = [](int a_tu, int a_mau, int b_tu, int b_mau, int t)->bool {
    return abs(a_tu * b_mau - t * a_mau * b_mau) < abs(b_tu * a_mau - t * a_mau * b_mau);
  };
  auto check = [&](int x)->void {
    int f_tu = h * (x + 1) + c * x, f_mau = 2 * x + 1;
    if (myLess(f_tu, f_mau, tu, mau, t)) {
      tu = f_tu, mau = f_mau;
      ans = x * 2 + 1;
    }
  };
  while (l <= r) {
    int x = (l + r) / 2;
    check(x);
    int f_tu = h * (x + 1) + c * x, f_mau = 2 * x + 1;
    if (t * f_mau <= f_tu) l = x + 1; else r = x - 1;
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
