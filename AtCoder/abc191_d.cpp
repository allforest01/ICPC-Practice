#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

double sqr(double x) {
  return x * x;
}

double dist(double x, double y, double a, double b) {
  return sqrt(sqr(x - a) + sqr(y - b));
}

double cal(double x, double y, double rad, double i) {
  double l, r, sl, sr;
  l = -2e5; r = x;
  while (l <= r) {
    double m = floor((l + r) / 2);
    if (dist(x, y, m, i) <= rad) {
      r = m - 1;
      sl = m;
    }
    else l = m + 1;
  }
  l = x; r = 2e5;
  while (l <= r) {
    double m = floor((l + r) / 2);
    if (dist(x, y, m, i) <= rad) {
      l = m + 1;
      sr = m;
    }
    else r = m - 1;
  }
  return sr - sl + 1;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  double x, y, r;
  cin >> x >> y >> r;
  double ans = 0;
  for (double i = ceil(y - r); i <= floor(y + r); i++) {
    ans += cal(x, y, r, i);
  }
  cout << fixed << setprecision(0) << ans << endl;
}
