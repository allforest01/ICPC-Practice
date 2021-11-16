#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll circle_area_div_pi(ll r) {
  return r * r;
}

void Main() {
  ll r1, r2, r3;
  cin >> r1 >> r2 >> r3;
  ll pos = circle_area_div_pi(r2 - r3);
  ll ins = 0, out = 0;
  if (r1 > r3) ins = circle_area_div_pi(r1 - r3);
  if (r2 - r1 > r3 * 2) {
    out = circle_area_div_pi(r2 - r3) - circle_area_div_pi(r1 + r3);
  }
  cout << setprecision(3) << fixed;
  cout << double(out + ins) / pos << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
