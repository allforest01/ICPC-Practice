#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<double> x(n), v(n);
  for (auto &i : x) cin >> i;
  for (auto &i : v) cin >> i;
  auto f = [&](double m)->double {
    double ret = 0;
    for (int i = 0; i < n; i++) {
      ret = max(ret, abs(m - x[i]) / v[i]);
    }
    return ret;
  };
  int cnt = 100;
  double l = 1, r = 1e9;
  while (cnt--) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double f1 = f(m1), f2 = f(m2);
    if (f2 < f1 + EPS) l = m1;
    else if (f1 < f2 + EPS) r = m2;
    else l = m1, r = m2;
  }
  cout << setprecision(10) << fixed;
  cout << f((l + r) / 2) << '\n';
}
