#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

int main() {
  cin.tie(0)->sync_with_stdio(0);
  double n; cin >> n;
  double x0, y0, xh, yh;
  cin >> x0 >> y0 >> xh >> yh;
  double xm = (x0 + xh) / 2;
  double ym = (y0 + yh) / 2;
  double th = 2 * PI / n;
  double x1 = (x0 - xm) * cos(th) - (y0 - ym) * sin(th) + xm;
  double y1 = (x0 - xm) * sin(th) + (y0 - ym) * cos(th) + ym;
  cout << setprecision(10) << fixed;
  cout << x1 << ' ' << y1 << '\n';
}
