#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int cb = 0, cs = 0, cc = 0;
  for (auto &i : s) {
    if (i == 'B') cb++;
    if (i == 'S') cs++;
    if (i == 'C') cc++;
  }
  int nb, ns, nc, pb, ps, pc, dr;
  cin >> nb >> ns >> nc >> pb >> ps >> pc >> dr;
  auto check = [&](int x) {
    int tr = dr;
    tr -= max((cb * x) - nb, 0LL) * pb;
    tr -= max((cs * x) - ns, 0LL) * ps;
    tr -= max((cc * x) - nc, 0LL) * pc;
    return tr >= 0;
  };
  int l = 0, r = 1e15, ans = -1;
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
