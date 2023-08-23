#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

double compen(double a, double x) {
  return a + x - min(a, 2 * x);
}

double expval(vector<double> &a, double x) {
  double sum = 0;
  for (int i = 0; i < (int)(a.size()); i++) {
    sum += compen(a[i], x);
  }
  return sum / a.size();
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<double> a(n);
  double l = 0, r = 0;
  for (auto &i : a) {
    cin >> i;
    r = max(r, i);
  }
  int cnt = 100;
  while (cnt --> 0) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    if (expval(a, m1) + EPS > expval(a, m2)) l = m1;
    else r = m2;
  }
  cout << setprecision(10) << fixed;
  cout << expval(a, (l + r) / 2) << '\n';
}
